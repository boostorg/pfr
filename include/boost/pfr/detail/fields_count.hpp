// Copyright (c) 2016-2022 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_FIELDS_COUNT_HPP
#define BOOST_PFR_DETAIL_FIELDS_COUNT_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>
#include <boost/pfr/detail/make_integer_sequence.hpp>
#include <boost/pfr/detail/size_t_.hpp>
#include <boost/pfr/detail/unsafe_declval.hpp>

#include <climits>      // CHAR_BIT
#include <type_traits>
#include <utility>      // metaprogramming stuff

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wmissing-braces"
#   pragma clang diagnostic ignored "-Wundefined-inline"
#   pragma clang diagnostic ignored "-Wundefined-internal"
#   pragma clang diagnostic ignored "-Wmissing-field-initializers"
#endif

namespace boost { namespace pfr { namespace detail {

///////////////////// Structure that can be converted to reference to anything
struct ubiq_lref_constructor {
    std::size_t ignore;
    template <class Type> constexpr operator Type&() const && noexcept {  // tweak for template_unconstrained.cpp like cases
        return detail::unsafe_declval<Type&>();
    }

    template <class Type> constexpr operator Type&() const & noexcept {  // tweak for optional_chrono.cpp like cases
        return detail::unsafe_declval<Type&>();
    }
};

///////////////////// Structure that can be converted to rvalue reference to anything
struct ubiq_rref_constructor {
    std::size_t ignore;
    template <class Type> /*constexpr*/ operator Type() const && noexcept {  // Allows initialization of rvalue reference fields and move-only types
        return detail::unsafe_declval<Type>();
    }
};


#ifndef __cpp_lib_is_aggregate
///////////////////// Hand-made is_aggregate_initializable_n<T> trait

// Structure that can be converted to reference to anything except reference to T
template <class T, bool IsCopyConstructible>
struct ubiq_constructor_except {
    std::size_t ignore;
    template <class Type> constexpr operator std::enable_if_t<!std::is_same<T, Type>::value, Type&> () const noexcept; // Undefined
};

template <class T>
struct ubiq_constructor_except<T, false> {
    std::size_t ignore;
    template <class Type> constexpr operator std::enable_if_t<!std::is_same<T, Type>::value, Type&&> () const noexcept; // Undefined
};


// `std::is_constructible<T, ubiq_constructor_except<T>>` consumes a lot of time, so we made a separate lazy trait for it.
template <std::size_t N, class T> struct is_single_field_and_aggregate_initializable: std::false_type {};
template <class T> struct is_single_field_and_aggregate_initializable<1, T>: std::integral_constant<
    bool, !std::is_constructible<T, ubiq_constructor_except<T, std::is_copy_constructible<T>::value>>::value
> {};

// Hand-made is_aggregate<T> trait:
// Before C++20 aggregates could be constructed from `decltype(ubiq_?ref_constructor{I})...` but type traits report that
// there's no constructor from `decltype(ubiq_?ref_constructor{I})...`
// Special case for N == 1: `std::is_constructible<T, ubiq_?ref_constructor>` returns true if N == 1 and T is copy/move constructible.
template <class T, std::size_t N>
struct is_aggregate_initializable_n {
    template <std::size_t ...I>
    static constexpr bool is_not_constructible_n(std::index_sequence<I...>) noexcept {
        return (!std::is_constructible<T, decltype(ubiq_lref_constructor{I})...>::value && !std::is_constructible<T, decltype(ubiq_rref_constructor{I})...>::value)
            || is_single_field_and_aggregate_initializable<N, T>::value
        ;
    }

    static constexpr bool value =
           std::is_empty<T>::value
        || std::is_array<T>::value
        || std::is_fundamental<T>::value
        || is_not_constructible_n(detail::make_index_sequence<N>{})
    ;
};

#endif // #ifndef __cpp_lib_is_aggregate

///////////////////// Detect aggregates with inheritance
template <class Derived, class U>
constexpr bool static_assert_non_inherited() noexcept {
    static_assert(
            !std::is_base_of<U, Derived>::value,
            "====================> Boost.PFR: Boost.PFR: Inherited types are not supported."
    );
    return true;
}

template <class Derived>
struct ubiq_lref_base_asserting {
    template <class Type> constexpr operator Type&() const &&  // tweak for template_unconstrained.cpp like cases
        noexcept(detail::static_assert_non_inherited<Derived, Type>())  // force the computation of assert function
    {
        return detail::unsafe_declval<Type&>();
    }

    template <class Type> constexpr operator Type&() const &  // tweak for optional_chrono.cpp like cases
        noexcept(detail::static_assert_non_inherited<Derived, Type>())  // force the computation of assert function
    {
        return detail::unsafe_declval<Type&>();
    }
};

template <class Derived>
struct ubiq_rref_base_asserting {
    template <class Type> /*constexpr*/ operator Type() const &&  // Allows initialization of rvalue reference fields and move-only types
        noexcept(detail::static_assert_non_inherited<Derived, Type>())  // force the computation of assert function
    {
        return detail::unsafe_declval<Type>();
    }
};

template <class T, std::size_t I0, std::size_t... I, class /*Enable*/ = typename std::enable_if<std::is_copy_constructible<T>::value>::type>
constexpr auto assert_first_not_base(std::index_sequence<I0, I...>) noexcept
    -> typename std::add_pointer<decltype(T{ ubiq_lref_base_asserting<T>{}, ubiq_lref_constructor{I}... })>::type
{
    return nullptr;
}

template <class T, std::size_t I0, std::size_t... I, class /*Enable*/ = typename std::enable_if<!std::is_copy_constructible<T>::value>::type>
constexpr auto assert_first_not_base(std::index_sequence<I0, I...>) noexcept
    -> typename std::add_pointer<decltype(T{ ubiq_rref_base_asserting<T>{}, ubiq_rref_constructor{I}... })>::type
{
    return nullptr;
}

template <class T>
constexpr void* assert_first_not_base(std::index_sequence<>) noexcept
{
    return nullptr;
}

///////////////////// Helper for SFINAE on fields count
template <class T, std::size_t... I, class /*Enable*/ = typename std::enable_if<std::is_copy_constructible<T>::value>::type>
constexpr auto enable_if_constructible_helper(std::index_sequence<I...>) noexcept
    -> typename std::add_pointer<decltype(T{ ubiq_lref_constructor{I}... })>::type;

template <class T, std::size_t... I, class /*Enable*/ = typename std::enable_if<!std::is_copy_constructible<T>::value>::type>
constexpr auto enable_if_constructible_helper(std::index_sequence<I...>) noexcept
    -> typename std::add_pointer<decltype(T{ ubiq_rref_constructor{I}... })>::type;

// Note that this takes O(N) compile time and memory!
template <class T, std::size_t N, class /*Enable*/ = decltype( enable_if_constructible_helper<T>(detail::make_index_sequence<N>()) ) >
using enable_if_constructible_helper_t = std::size_t;

///////////////////// Helpers for range size detection
template <std::size_t Begin, std::size_t Last>
using is_one_element_range = std::integral_constant<bool, Begin == Last>;

using multi_element_range = std::false_type;
using one_element_range = std::true_type;

///////////////////// Fields count binary search.
// Template instantiation: depth is O(log(result)), count is O(log(result)), cost is O(result * log(result)).
template <class T, std::size_t Begin, std::size_t Middle>
constexpr std::size_t fields_count_binary_search(detail::one_element_range, long) noexcept {
    static_assert(
        Begin == Middle,
        "====================> Boost.PFR: Internal logic error."
    );
    return Begin;
}

template <class T, std::size_t Begin, std::size_t Middle>
constexpr std::size_t fields_count_binary_search(detail::multi_element_range, int) noexcept;

template <class T, std::size_t Begin, std::size_t Middle>
constexpr auto fields_count_binary_search(detail::multi_element_range, long) noexcept
    -> detail::enable_if_constructible_helper_t<T, Middle>
{
    constexpr std::size_t next_v = Middle + (Middle - Begin + 1) / 2;
    return detail::fields_count_binary_search<T, Middle, next_v>(detail::is_one_element_range<Middle, next_v>{}, 1L);
}

template <class T, std::size_t Begin, std::size_t Middle>
constexpr std::size_t fields_count_binary_search(detail::multi_element_range, int) noexcept {
    constexpr std::size_t next_v = Begin + (Middle - Begin) / 2;
    return detail::fields_count_binary_search<T, Begin, next_v>(detail::is_one_element_range<Begin, next_v>{}, 1L);
}

template <class T, std::size_t Begin, std::size_t I = 1>
constexpr std::size_t fields_count_upper_bound(int) noexcept {
    return Begin + I;
}

template <class T, std::size_t Begin, std::size_t I = 1>
constexpr auto fields_count_upper_bound(long) noexcept
    -> detail::enable_if_constructible_helper_t<T, Begin + I>
{
    return detail::fields_count_upper_bound<T, Begin, I * 2>(1L);
}

template <class T, std::size_t Begin = 0>
constexpr std::size_t fields_count_binary_search_unbounded() noexcept
{
    constexpr std::size_t last = detail::fields_count_upper_bound<T, Begin>(1L);
    constexpr std::size_t middle = (Begin + last + 1) / 2;
    return detail::fields_count_binary_search<T, Begin, middle>(detail::is_one_element_range<Begin, middle>{}, 1L);
}

///////////////////// Fields count lower bound linear search.
// Template instantiation: depth is O(log(result)), count is O(result), cost is O(result^2).
template <class T, std::size_t N>
constexpr auto fields_count_lower_bound_remember(long) noexcept
    -> detail::enable_if_constructible_helper_t<T, N>
{
    return N;
}

template <class T, std::size_t N>
constexpr std::size_t fields_count_lower_bound_remember(int) noexcept {
    return 0;
}

template <class T, std::size_t Begin, std::size_t Last, class RangeSize, std::size_t Result>
constexpr std::size_t fields_count_lower_bound(RangeSize, size_t_<Result>) noexcept {
    return Result;
}

template <class T, std::size_t Begin, std::size_t Last>
constexpr std::size_t fields_count_lower_bound(detail::one_element_range, size_t_<0> = {}) noexcept {
    static_assert(
        Begin == Last,
        "====================> Boost.PFR: Internal logic error."
    );
    return detail::fields_count_lower_bound_remember<T, Begin>(1L);
}

template <class T, std::size_t Begin, std::size_t Last>
constexpr std::size_t fields_count_lower_bound(detail::multi_element_range, size_t_<0> = {}) noexcept {
    // Binary partition to limit template depth.
    constexpr std::size_t middle = Begin + (Last - Begin) / 2;
    constexpr std::size_t result_maybe = detail::fields_count_lower_bound<T, Begin, middle>(
        detail::is_one_element_range<Begin, middle>{}
    );
    return detail::fields_count_lower_bound<T, middle + 1, Last>(
        detail::is_one_element_range<middle + 1, Last>{},
        size_t_<result_maybe>{}
    );
}

template <class T, std::size_t Begin = 1, std::size_t Result>
constexpr std::size_t fields_count_lower_bound_unbounded(size_t_<Result>) noexcept {
    return Result;
}

template <class T, std::size_t Begin = 1>
constexpr std::size_t fields_count_lower_bound_unbounded(size_t_<0> = {}) noexcept
{
    constexpr std::size_t last = Begin * 2 - 1;
    constexpr std::size_t result_maybe = detail::fields_count_lower_bound<T, Begin, last>(
        detail::is_one_element_range<Begin, last>{}
    );
    return detail::fields_count_lower_bound_unbounded<T, last + 1>(size_t_<result_maybe>{});
}

///////////////////// Choosing between array size, unbounded binary search, and linear search followed by unbounded binary search.
template <class T>
constexpr auto fields_count_dispatch(long, long) noexcept
    -> typename std::enable_if<std::is_array<T>::value, std::size_t>::type
{
    return sizeof(T) / sizeof(typename std::remove_all_extents<T>::type);
}

template <class T>
constexpr auto fields_count_dispatch(long, int) noexcept
    -> decltype(sizeof(T{}))
{
    return detail::fields_count_binary_search_unbounded<T>();
}

template <class T>
constexpr std::size_t fields_count_dispatch(int, int) noexcept {
    // T is not default aggregate initializable. This means that at least one of the members is not default-constructible.
    // Use linear search to find the smallest valid initializer, after which we unbounded binary search for the largest.
    constexpr std::size_t begin = detail::fields_count_lower_bound_unbounded<T>();
    return detail::fields_count_binary_search_unbounded<T, begin>();
}

///////////////////// Returns fields count
template <class T>
constexpr std::size_t fields_count() noexcept {
    using type = std::remove_cv_t<T>;

    static_assert(
        !std::is_reference<type>::value,
        "====================> Boost.PFR: Attempt to get fields count on a reference. This is not allowed because that could hide an issue and different library users expect different behavior in that case."
    );

#if !BOOST_PFR_HAS_GUARANTEED_COPY_ELISION
    static_assert(
        std::is_copy_constructible<std::remove_all_extents_t<type>>::value || (
            std::is_move_constructible<std::remove_all_extents_t<type>>::value
            && std::is_move_assignable<std::remove_all_extents_t<type>>::value
        ),
        "====================> Boost.PFR: Type and each field in the type must be copy constructible (or move constructible and move assignable)."
    );
#endif  // #if !BOOST_PFR_HAS_GUARANTEED_COPY_ELISION

    static_assert(
        !std::is_polymorphic<type>::value,
        "====================> Boost.PFR: Type must have no virtual function, because otherwise it is not aggregate initializable."
    );

#ifdef __cpp_lib_is_aggregate
    static_assert(
        std::is_aggregate<type>::value             // Does not return `true` for built-in types.
        || std::is_scalar<type>::value,
        "====================> Boost.PFR: Type must be aggregate initializable."
    );
#endif

// Can't use the following. See the non_std_layout.cpp test.
//#if !BOOST_PFR_USE_CPP17
//    static_assert(
//        std::is_standard_layout<type>::value,   // Does not return `true` for structs that have non standard layout members.
//        "Type must be aggregate initializable."
//    );
//#endif

    constexpr std::size_t result = detail::fields_count_dispatch<type>(1L, 1L);
    detail::assert_first_not_base<type>(detail::make_index_sequence<result>{});

#ifndef __cpp_lib_is_aggregate
    static_assert(
        is_aggregate_initializable_n<type, result>::value,
        "====================> Boost.PFR: Types with user specified constructors (non-aggregate initializable types) are not supported."
    );
#endif

    static_assert(
        result != 0 || std::is_empty<type>::value || std::is_fundamental<type>::value || std::is_reference<type>::value,
        "====================> Boost.PFR: If there's no other failed static asserts then something went wrong. Please report this issue to the github along with the structure you're reflecting."
    );

    return result;
}

}}} // namespace boost::pfr::detail

#ifdef __clang__
#   pragma clang diagnostic pop
#endif

#endif // BOOST_PFR_DETAIL_FIELDS_COUNT_HPP
