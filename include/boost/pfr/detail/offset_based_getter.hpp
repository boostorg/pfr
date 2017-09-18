// Copyright (c) 2017 Chris beck
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_OFFSET_BASED_GETTER_HPP
#define BOOST_PFR_DETAIL_OFFSET_BASED_GETTER_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <type_traits>
#include <utility>
#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/detail/size_array.hpp>


namespace boost { namespace pfr { namespace detail {

// Metafunction that replaces tuple<T1, T2, T3, ...> with
// tuple<std::aligned_storage_t<sizeof(T1), alignof(T1)>, std::aligned_storage<sizeof(T2), alignof(T2)>, ...>
//
// The point is, the new tuple is "layout compatible" in the sense that members have the same offsets,
// but this tuple is constexpr constructible.

template <typename T>
struct tuple_of_aligned_storage;

template <typename... Ts>
struct tuple_of_aligned_storage<sequence_tuple::tuple<Ts...>> {
  using type = sequence_tuple::tuple<std::aligned_storage_t<sizeof(Ts), alignof(Ts)>...>;
};

// Note: If pfr has a typelist also, could also have an overload for that here

template <typename T>
using tuple_of_aligned_storage_t = typename tuple_of_aligned_storage<T>::type;

/***
 * Given a structure type and its sequence of members, we want to build a function
 * object "getter" that implements a version of `std::get` using offset arithmetic
 * and reinterpret_cast.
 */

template <typename T, typename S>
class offset_based_getter {
  static_assert(sizeof(T) == sizeof(S), "Member sequence does not indicate correct size for struct type!");
  static_assert(alignof(T) == alignof(S), "Member sequence does not indicate correct alignment for struct type!");

  // Get type of idx'th member
  template <std::size_t idx>
  using index_t = typename sequence_tuple::tuple_element<idx, S>::type;
  
  // Get offset of idx'th member
  template <std::size_t idx>
  static std::ptrdiff_t offset() {
    constexpr tuple_of_aligned_storage_t<S> layout{};
    // TODO: Do modern compilers optimize `layout` object out of the binary?
    // Ideally this pointer diff reduces to a constant and this call gets inlined.
    // But since we are doing reinterpret cast, I don't think we can use `constexpr` to ensure that.
    // However, since layout is a tuple of `char[]` basically, and has trivial initialization and is never accessed,
    // it seems quite plausible to me taking the address will be optimized to a constant.
    // Also that this is not undefined behavior if T and S indeed are layout compatible,
    // since S and layout are definitely layout compatible.

    return reinterpret_cast<const char *>(&sequence_tuple::get<idx>(layout)) - reinterpret_cast<const char *>(&layout);
  }

  // Encapsulates offset arithmetic and reinterpret_cast
  template <std::size_t idx>
  index_t<idx> * get_pointer(T * t) const {
    return reinterpret_cast<index_t<idx> *>(reinterpret_cast<char *>(t) + offset<idx>());
  }

  template <std::size_t idx>
  const index_t<idx> * get_pointer(const T * t) const {
    return reinterpret_cast<const index_t<idx> *>(reinterpret_cast<const char *>(t) + offset<idx>());
  }

public:
  template <std::size_t idx>
  index_t<idx> & get(T & t) const {
    return *get_pointer<idx>(&t);
  }

  template <std::size_t idx>
  index_t<idx> const & get(T const & t) const {
    return *get_pointer<idx>(&t);
  }

  template <std::size_t idx>
  index_t<idx> && get(T && t) const {
    return std::move(*get_pointer<idx>(&t));
  }
};


}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_OFFSET_LIST_HPP
