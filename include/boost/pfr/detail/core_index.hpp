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

#include <memory>

namespace boost {
namespace pfr {
namespace detail {
template<class T, class TMember>
auto class_of(TMember T::*) -> T;

template <class T, auto ptr>
constexpr auto index_impl(T const &val) {
  auto found  = false;
  auto result = 0;

  for_each_field(
      val, [&]<std::size_t index>(auto &&member, std::integral_constant<std::size_t, index>) {
        if (std::addressof(member) == std::addressof(val.*ptr)) {
          found  = true;
          result = index;
        }
      });

  if (!found) {
    // What to do here?
  }

  return result;
}
}
} // namespace pfr
} // namespace boost

#endif // BOOST_PFR_DETAIL_CORE_INDEX_HPP
