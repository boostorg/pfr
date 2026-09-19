// Copyright (c) 2024 Uy Ha
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_PFR_DETAIL_CORE_INDEX_HPP
#define BOOST_PFR_DETAIL_CORE_INDEX_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>
#include <boost/pfr/detail/for_each_field_impl.hpp>

#include <type_traits>

namespace boost {
namespace pfr {
namespace detail {
template <typename T, typename TMember>
auto class_of(TMember T::*) -> T;

template <typename T, auto ptr, std::size_t index>
constexpr auto index_fn();

template <class T, auto ptr, std::size_t index = 0, bool out_of_bound = index >= tuple_size_v<T>>
  requires std::is_member_object_pointer_v<decltype(ptr)>
struct index_impl {};

template <class T, auto ptr, std::size_t index>
  requires std::is_member_object_pointer_v<decltype(ptr)>
struct index_impl<T, ptr, index, false> : decltype(index_fn<T, ptr, index>()) {};

template <typename T, auto ptr, std::size_t index>
constexpr auto index_fn() {
  if constexpr (index < tuple_size_v<T>) {
    using Class                = decltype(class_of(ptr));
    constexpr auto pfr_address = std::addressof(boost::pfr::get<index>(fake_object<Class>));
    constexpr auto mem_address = std::addressof(fake_object<Class>.*ptr);

    if constexpr (std::is_same_v<decltype(pfr_address), decltype(mem_address)>) {
      if constexpr (pfr_address == mem_address) {
        return std::integral_constant<std::size_t, index>{};
      } else {
        return index_impl<T, ptr, index + 1>{};
      }
    } else {
      return index_impl<T, ptr, index + 1>{};
    }
  } else {
    return index_impl<T, ptr, index + 1>{};
  }
}
} // namespace pfr
} // namespace boost

#endif // BOOST_PFR_DETAIL_CORE_INDEX_HPP
