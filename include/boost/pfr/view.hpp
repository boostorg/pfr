// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_VIEW_HPP
#define BOOST_PFR_VIEW_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/core.hpp>

// TODO: here must be external link to boost::fusion::at_c, x3::*

/// \file boost/pfr/view.hpp
/// Contains View manipulator \forcedlink{view} for types.
/// If type is reflectable using its own library, then the library's reflection is used.
///
/// \b Example:
/// \code
///     #include <boost/spirit/home/x3.hpp>
///     #include <boost/fusion/adapted/boost_pfr.hpp> // contains inclusion of `boost/pfr/view.hpp` inside
///
///     namespace x3 = boost::spirit::x3;
///
///     struct adaptable_struct {      // No BOOST_FUSION_ADAPT_STRUCT defined for that structure
///         double f; int s;
///     };
///     // ...
///
///    adaptable_struct s;
///    const std::string str = "3.141 10";
///    x3::phrase_parse(str.begin(),
///                     str.end(),
///                     x3::double_ >> x3::int_,
///                     x3::blank,
///                     boost::pfr::view(s));
///    std::cout << s.f << ", " << s.s; // Outputs: 3.141, 10
/// \endcode
///
/// \podview for other ways to use Boost.PFR with other libraries and more details.
///
/// \b Synopsis:

namespace boost { namespace pfr {

template<std::size_t I, class T>
constexpr decltype(auto) get( detail::view_impl<T>& t ) noexcept {
    return boost::pfr::get<I>(t.value);
}

template<std::size_t I, class T>
constexpr decltype(auto) get( detail::view_impl<T>&& t ) noexcept {
    return boost::pfr::get<I>(std::forward<T>(t.value));
}

template<std::size_t I, class T>
constexpr decltype(auto) get( const detail::view_impl<T>& t ) noexcept {
    return boost::pfr::get<I>(t.value);
}

template<std::size_t I, class T>
constexpr decltype(auto) get( const detail::view_impl<T>&& t ) noexcept {
    return boost::pfr::get<I>(std::forward<T>(t.value));
}

template<std::size_t I, class T>
struct tuple_element<I, detail::view_impl<T> >
    : boost::pfr::tuple_element<I, std::remove_reference_t<T>>
{};

// TODO: fix unspecified in the docs
template <class T>
constexpr auto structure_to_tuple(detail::view_impl<T>& t) noexcept {
    return boost::pfr::structure_to_tuple(t.value);
}

template <class T>
constexpr auto structure_to_tuple(detail::view_impl<T>&& t) noexcept {
    return boost::pfr::structure_to_tuple(std::forward<T>(t.value));
}

template <class T>
constexpr auto structure_to_tuple(const detail::view_impl<T>& t) noexcept {
    return boost::pfr::structure_to_tuple(t.value);
}

template <class T>
constexpr auto structure_to_tuple(const detail::view_impl<T>&& t) noexcept {
    return boost::pfr::structure_to_tuple(std::forward<T>(t.value));
}

template <class T>
constexpr auto structure_tie(detail::view_impl<T>& t) noexcept {
    return boost::pfr::structure_tie(t.value);
}

template <class T>
constexpr auto structure_tie(detail::view_impl<T>&& t) noexcept {
    return boost::pfr::structure_tie(std::forward<T>(t.value));
}

template <class T>
constexpr auto structure_tie(const detail::view_impl<T>& t) noexcept {
    return boost::pfr::structure_tie(t.value);
}

template <class T>
constexpr auto structure_tie(const detail::view_impl<T>&& t) noexcept {
    return boost::pfr::structure_tie(std::forward<T>(t.value));
}

template <class T, class F>
void for_each_field(detail::view_impl<T>& t, F&& func) {
    boost::pfr::for_each_field(t.value, func);
}

template <class T, class F>
void for_each_field(detail::view_impl<T>&& t, F&& func) {
    boost::pfr::for_each_field(std::forward<T>(t.value), func);
}

template <class T, class F>
void for_each_field(const detail::view_impl<T>& t, F&& func) {
    boost::pfr::for_each_field(t.value, func);
}

template <class T, class F>
void for_each_field(const detail::view_impl<T>&& t, F&& func) {
    boost::pfr::for_each_field(std::forward<T>(t.value), func);
}

template <class T>
struct tuple_size<detail::view_impl<T>>
    : boost::pfr::tuple_size<std::remove_reference_t<T>>
{};

/// View manupulator to access \aggregate `value` from other library that expects tuple-like interface.
///
/// \b Example:
/// \code
///     struct my_struct { int i; short s; };
///     my_struct s{ 12, 13 };
///     assert(boost::fusion::at_c<0>(boost::pfr::view(s)) == 12);
///     assert(boost::fusion::at_c<1>(boost::pfr::view(s)) == 13);
/// \endcode
template <class T>
auto view(T&& value) noexcept; // TODO: impl


/// \brief Type of \forcedlink{view}'s result with \aggregate `T` passed.
///
/// \b Example:
/// \code
///     boost::spirit::x3::rule<class adaptable, boost::pfr::view_t<adaptable_struct> > const adaptable = "adaptable";
/// \endcode
template<class T>
using view_t = decltype(boost::pfr::view(std::declval<T>()));

}} // namespace boost::pfr

#endif // BOOST_PFR_VIEW_HPP

