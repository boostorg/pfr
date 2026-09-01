// Copyright (c) 2025-2026 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_IS_CONSTEXPR_DEFAULT_CONSTRUCTIBLE_HPP
#define BOOST_PFR_IS_CONSTEXPR_DEFAULT_CONSTRUCTIBLE_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#if !defined(BOOST_USE_MODULES) || defined(BOOST_PFR_INTERFACE_UNIT)

#if !defined(BOOST_PFR_INTERFACE_UNIT)
#include <type_traits>
#endif

namespace boost { namespace pfr {

namespace detail {
    template <class T, int = (static_cast<void>(T{}), 0)>
    constexpr std::true_type is_constexpr_default_constructible(long) noexcept {
        return {};
    }

    template <class T>
    constexpr std::false_type is_constexpr_default_constructible(int) noexcept {
        return {};
    }
}  // namespace detail

BOOST_PFR_BEGIN_MODULE_EXPORT

template <class T>
struct is_constexpr_default_constructible
    : decltype(detail::is_constexpr_default_constructible<T>(1L))
{};

template <class T>
constexpr bool is_constexpr_default_constructible_v
    = decltype(detail::is_constexpr_default_constructible<T>(1L))::value;

BOOST_PFR_END_MODULE_EXPORT

}}  // namespace boost::pfr

#endif  // #if !defined(BOOST_USE_MODULES) || defined(BOOST_PFR_INTERFACE_UNIT)

#endif  // BOOST_PFR_IS_CONSTEXPR_DEFAULT_CONSTRUCTIBLE_HPP
