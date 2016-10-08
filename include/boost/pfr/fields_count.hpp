// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_FIELDS_COUNT_HPP
#define BOOST_PFR_FIELDS_COUNT_HPP

#pragma once

#if __cplusplus < 201402L
#   error C++14 is required for this header.
#endif

#include <type_traits>
#include <utility>      // metaprogramming stuff

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wmissing-braces"
#   pragma clang diagnostic ignored "-Wundefined-inline"
#   pragma clang diagnostic ignored "-Wundefined-internal"
#   pragma clang diagnostic ignored "-Wmissing-field-initializers"
#endif

namespace boost { namespace pfr {

namespace detail {

///////////////////// General utility stuff
template <std::size_t Index>
using size_t_ = std::integral_constant<std::size_t, Index >;

///////////////////// Structure that can be converted to reference to anything
struct ubiq_constructor {
    std::size_t ignore;
    template <class Type> constexpr operator Type() const noexcept; // Undefined
};

///////////////////// Structure that can be converted to reference to anything except reference to T
template <class T>
struct ubiq_constructor_except {
    template <class Type> constexpr operator std::enable_if_t<!std::is_same<T, Type>::value, Type&> () const noexcept; // Undefined
};

///////////////////// Hand-made is_aggregate_initializable_n<T> trait:

// `std::is_constructible<T, ubiq_constructor_except<T>>` consumes a lot of time, so we made a separate lazy trait for it.
template <std::size_t N, class T> struct is_single_field_and_aggregate_initializable: std::false_type {};
template <class T> struct is_single_field_and_aggregate_initializable<1, T>: std::integral_constant<
    bool, !std::is_constructible<T, ubiq_constructor_except<T>>::value
> {};

template <class T, std::size_t N>
struct is_aggregate_initializable_n {
    template <std::size_t ...I>
    static constexpr bool is_not_constructible_n(std::index_sequence<I...>) noexcept {
        return !std::is_constructible<T, decltype(ubiq_constructor{I})...>::value
            || is_single_field_and_aggregate_initializable<N, T>::value
        ;
    }

    static constexpr bool value =
           std::is_empty<T>::value
        || std::is_fundamental<T>::value
        || is_not_constructible_n(std::make_index_sequence<N>{})
    ;
};

///////////////////// Methods for detecting max parameters for construction of T

template <class T, std::size_t... I>
constexpr auto enable_if_constructible_helper(std::index_sequence<I...>) noexcept
    -> typename std::add_pointer<decltype(T{ ubiq_constructor{I}... })>::type;

template <class T, std::size_t N>
constexpr void detect_fields_count(std::size_t& count, size_t_<N>, size_t_<N>, long) noexcept {
    // Hand-made is_aggregate<T> trait:
    // Aggregates could be constructed from `decltype(ubiq_constructor{I})...` but report that there's no constructor from `decltype(ubiq_constructor{I})...`
    // Special case for N == 1: `std::is_constructible<T, ubiq_constructor>` returns true if N == 1 and T is copy/move constructible.
    static_assert(
        is_aggregate_initializable_n<T, N>::value,
        "Types with user specified constructors (non-aggregate types) are not supported."
    );

    count = N;
}

template <class T, std::size_t Begin, std::size_t Middle>
constexpr void detect_fields_count(std::size_t& count, size_t_<Begin>, size_t_<Middle>, int) noexcept;

template <class T, std::size_t Begin, std::size_t Middle>
constexpr auto detect_fields_count(std::size_t& count, size_t_<Begin>, size_t_<Middle>, long) noexcept
    -> decltype( enable_if_constructible_helper<T>(std::make_index_sequence<Middle>()) )
{
    constexpr std::size_t next = Middle + (Middle - Begin + 1) / 2;
    detect_fields_count<T>(count, size_t_<Middle>{}, size_t_<next>{}, 1L);
    return nullptr;
}

template <class T, std::size_t Begin, std::size_t Middle>
constexpr void detect_fields_count(std::size_t& count, size_t_<Begin>, size_t_<Middle>, int) noexcept {
    constexpr std::size_t next = (Begin + Middle) / 2;
    detect_fields_count<T>(count, size_t_<Begin>{}, size_t_<next>{}, 1L);
}

///////////////////// Returns non-flattened fields count
template <class T>
constexpr std::size_t fields_count() noexcept {
    std::size_t res = 0u;
    constexpr std::size_t next = sizeof(T) / 2 + 1;
    detect_fields_count<T>(res, size_t_<0>{}, size_t_<next>{}, 1L);
    return res;
}

} // namespace detail

#ifdef __clang__
#   pragma clang diagnostic pop
#endif

/// \brief Has a static const member variable `value` that constins fields count in a T.
/// Works for any T that supports aggregate initialization even if T is not POD.
/// \flattening{Flattens} only multidimensional arrays.
///
/// \b Example:
/// \code
///     std::array<int, boost::pfr::tuple_size<my_structure>::value > a;
/// \endcode
template <class T>
using tuple_size = detail::size_t_< boost::pfr::detail::fields_count<T>() >;


/// \brief `tuple_size_v` is a template variable that contains fields count in a T and
/// works for any T that supports aggregate initialization even if T is not POD.
/// \flattening{Flattens} only multidimensional arrays.
///
/// \b Example:
/// \code
///     std::array<int, boost::pfr::tuple_size_v<my_structure> > a;
/// \endcode
template <class T>
constexpr std::size_t tuple_size_v = tuple_size<T>::value;

}} // namespace boost::pfr

#endif // BOOST_PFR_FIELDS_COUNT_HPP
