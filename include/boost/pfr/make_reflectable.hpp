// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_MAKE_REFLECTABLE_HPP
#define BOOST_PFR_MAKE_REFLECTABLE_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/core.hpp>
#include <boost/pfr/view.hpp>

#include <boost/pfr/traits.hpp>
#include <boost/pfr/tuple_size.hpp>
#include <type_traits>
#include <utility>

/// \file boost/pfr/make_reflectable.hpp
/// TODO: desc
///
/// \b Synopsis:

// TODO: need failed tests for passing reference to structure and reference to view into make_reflectable
// TODO: use index_sequence from detail::index_sequence

namespace boost { namespace pfr {

template<class T, class... U, std::enable_if_t<!boost::pfr::is_view<T>::value>* = nullptr>
constexpr T make_reflectable(U&&... u) {
    static_assert(!boost::pfr::is_reference<T>::value, "====================> Boost.PFR: Can't return a reference to anything");
    return T{std::forward<U>(u)...};
}

template<class T, class... U, std::enable_if_t<boost::pfr::is_view<T>::value>* = nullptr>
constexpr T make_reflectable(U&&... u) {
    using underlying_type = detail::remove_cvref_t<decltype(std::declval<T>().value)>;
    static_assert(!boost::pfr::is_reference<T>::value, "====================> Boost.PFR: Can't return a reference to anything");
    return boost::pfr::view(underlying_type{std::forward<U>(u)...});
}

namespace detail {
template<class T, class F, std::size_t... I>
constexpr T make_reflectable_impl(F&& make_element_func, std::index_sequence<I...>) {
    return boost::pfr::make_reflectable<T>(make_element_func(size_t_<I>{})...);
}
} // namespace detail

template<class T, class F>
constexpr T make_reflectable(F&& make_element_func) {
    constexpr std::size_t fields_count
                = boost::pfr::tuple_size_v<std::remove_reference_t<T>>;
    return detail::make_reflectable_impl<T>(std::forward<F>(make_element_func),
                                            std::make_index_sequence<fields_count>());
}

}} // namespace boost::pfr

#endif // BOOST_PFR_MAKE_REFLECTABLE_HPP

