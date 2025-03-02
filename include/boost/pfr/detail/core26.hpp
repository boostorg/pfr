// Copyright (c) 2016-2025 Antony Polukhin
// Copyright (c) 2025 Jean-Michaël Celerier
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_CORE26_HPP
#define BOOST_PFR_DETAIL_CORE26_HPP
#pragma once

#include <boost/pfr/detail/sequence_tuple.hpp>
namespace boost::pfr::detail {

template<class T>
constexpr auto tie_as_tuple(T &val) noexcept
{
    static_assert(!std::is_union<T>::value,
                  "====================> Boost.PFR: For safety reasons it is forbidden to reflect "
                  "unions. See `Reflection of unions` section in the docs for more info.");
    auto &&[... members] = std::forward<T>(val);
    return sequence_tuple::tuple<std::add_lvalue_reference_t<decltype(members)>...>{members...};
}

} // namespace boost::pfr::detail
#endif
