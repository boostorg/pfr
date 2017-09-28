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

template <std::size_t Index>
using size_t_ = std::integral_constant<std::size_t, Index >;

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
 *
 * typename U should be a user-defined struct
 * typename S should be a sequence_tuple which is layout compatible with U
 */

template <typename U, typename S>
class offset_based_getter {
  static_assert(sizeof(U) == sizeof(S), "Member sequence does not indicate correct size for struct type!");
  static_assert(alignof(U) == alignof(S), "Member sequence does not indicate correct alignment for struct type!");

  static_assert(!std::is_const<U>::value, "const should be stripped from user-defined type when using offset_based_getter or overload resolution will be ambiguous later, this indicates an error within pfr");
  static_assert(!std::is_reference<U>::value, "reference should be stripped from user-defined type when using offset_based_getter or overload resolution will be ambiguous later, this indicates an error within pfr");
  static_assert(!std::is_volatile<U>::value, "volatile should be stripped from user-defined type when using offset_based_getter or overload resolution will be ambiguous later. this indicates an error within pfr");

  // Get type of idx'th member
  template <std::size_t idx>
  using index_t = typename sequence_tuple::tuple_element<idx, S>::type;
  
  // Get offset of idx'th member
  template <std::size_t idx>
  static std::ptrdiff_t offset() {
    constexpr tuple_of_aligned_storage_t<S> layout{};
    // TODO: Do all targetted compilers optimize `layout` object out of the binary? (gcc and clang seem to do so)
    // Ideally this pointer diff reduces to a constant and this call gets inlined.
    // But since we are doing reinterpret cast, I don't think we can use `constexpr` to ensure that.
    //
    // However, since layout is a tuple of `char[]` basically, and has trivial initialization and is never accessed,
    // I think that it will get optimized out -- any write to its memory is a dead store.
    //
    // Also: this is not undefined behavior if U and S indeed are layout compatible,
    // since S and layout have the same offsets for each corresponding members.
    //
    // It might be better if layout is a static constexpr object, and we take constexpr pointers to its members
    // in this offset function. Then we do reinterpret_cast of the constexpr pointers and take their difference.
    // It might make it even easier for the compiler to optimize this fcn to a constant,
    // since the pointers are also constant expressions then.

    return reinterpret_cast<const char *>(&sequence_tuple::get<idx>(layout)) - reinterpret_cast<const char *>(&layout);
  }

  // Encapsulates offset arithmetic and reinterpret_cast
  template <std::size_t idx>
  index_t<idx> * get_pointer(U * u) const {
    return reinterpret_cast<index_t<idx> *>(reinterpret_cast<char *>(u) + offset<idx>());
  }

  template <std::size_t idx>
  const index_t<idx> * get_pointer(const U * u) const {
    return reinterpret_cast<const index_t<idx> *>(reinterpret_cast<const char *>(u) + offset<idx>());
  }

  template <std::size_t idx>
  volatile index_t<idx> * get_pointer(volatile U * u) const {
    return reinterpret_cast<volatile index_t<idx> *>(reinterpret_cast<volatile char *>(u) + offset<idx>());
  }

  template <std::size_t idx>
  const volatile index_t<idx> * get_pointer(const volatile U * u) const {
    return reinterpret_cast<const volatile index_t<idx> *>(reinterpret_cast<const volatile char *>(u) + offset<idx>());
  }

public:
  template <std::size_t idx>
  index_t<idx> & get(U & u, size_t_<idx>) const {
    return *get_pointer<idx>(&u);
  }

  template <std::size_t idx>
  index_t<idx> const & get(U const & u, size_t_<idx>) const {
    return *get_pointer<idx>(&u);
  }

  template <std::size_t idx>
  index_t<idx> volatile & get(U volatile & u, size_t_<idx>) const {
    return *get_pointer<idx>(&u);
  }

  template <std::size_t idx>
  index_t<idx> const volatile & get(U const volatile & u, size_t_<idx>) const {
    return *get_pointer<idx>(&u);
  }

  /*
  This overload was similarly commented out in cast_to_layout_compatible
  
  template <std::size_t idx>
  index_t<idx> && get(U && u, size_t_<idx>) const {
    return std::move(*get_pointer<idx>(&u));
  }
  */
};


}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_OFFSET_LIST_HPP
