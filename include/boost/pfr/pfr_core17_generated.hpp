// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// This is an auto generated header. Modify pfr/misc/generate_cpp17.py instead.   //////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_PFR_CORE17_GENERATED_HPP
#define BOOST_PFR_CORE17_GENERATED_HPP

#pragma once

#if __cplusplus < 201606L /* Oulu meeting, not the exact value */
#   error C++17 is required for this header.
#endif

#include <boost/pfr/core.hpp>

namespace boost { namespace pfr { namespace detail {

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<0>) noexcept {
    return sequence_tuple::tuple<>{};
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<0>) noexcept {
    return sequence_tuple::tuple<>{};
}


template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<1>) noexcept {
    auto& [a0] = val;
    return sequence_tuple::tuple<decltype(a0)>{
        a0
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<1>) noexcept {
    auto& [a0] = val;
    return sequence_tuple::tuple<decltype(a0)>{
        a0
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<2>) noexcept {
    auto& [a0, a1] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1)>{
        a0, a1
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<2>) noexcept {
    auto& [a0, a1] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1)>{
        a0, a1
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<3>) noexcept {
    auto& [a0, a1, a2] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2)>{
        a0, a1, a2
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<3>) noexcept {
    auto& [a0, a1, a2] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2)>{
        a0, a1, a2
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<4>) noexcept {
    auto& [a0, a1, a2, a3] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3)>{
        a0, a1, a2, a3
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<4>) noexcept {
    auto& [a0, a1, a2, a3] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3)>{
        a0, a1, a2, a3
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<5>) noexcept {
    auto& [a0, a1, a2, a3, a4] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4)>{
        a0, a1, a2, a3, a4
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<5>) noexcept {
    auto& [a0, a1, a2, a3, a4] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4)>{
        a0, a1, a2, a3, a4
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<6>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5)>{
        a0, a1, a2, a3, a4, a5
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<6>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5)>{
        a0, a1, a2, a3, a4, a5
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<7>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6)>{
        a0, a1, a2, a3, a4, a5, a6
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<7>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6)>{
        a0, a1, a2, a3, a4, a5, a6
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<8>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7)>{
        a0, a1, a2, a3, a4, a5, a6, a7
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<8>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7)>{
        a0, a1, a2, a3, a4, a5, a6, a7
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<9>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<9>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<10>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<10>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<11>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<11>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<12>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<12>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<13>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<13>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<14>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<14>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<15>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<15>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<16>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<16>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<17>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<17>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<18>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<18>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<19>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<19>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<20>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<20>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<21>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<21>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<22>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<22>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<23>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<23>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<24>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<24>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<25>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<25>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<26>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<26>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<27>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<27>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<28>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<28>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<29>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<29>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<30>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<30>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<31>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<31>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<32>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<32>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<33>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<33>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<34>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<34>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<35>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<35>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<36>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<36>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<37>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<37>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<38>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<38>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<39>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<39>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<40>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<40>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<41>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<41>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<42>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<42>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<43>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<43>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<44>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<44>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<45>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<45>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<46>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<46>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<47>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45), decltype(a46)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<47>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45), decltype(a46)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<48>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45), decltype(a46), decltype(a47)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<48>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45), decltype(a46), decltype(a47)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<49>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45), decltype(a46), decltype(a47), decltype(a48)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<49>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45), decltype(a46), decltype(a47), decltype(a48)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<50>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45), decltype(a46), decltype(a47), decltype(a48), decltype(a49)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49
    };
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<50>) noexcept {
    auto& [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49] = val;
    return sequence_tuple::tuple<decltype(a0), decltype(a1), decltype(a2), decltype(a3), decltype(a4), decltype(a5), decltype(a6), decltype(a7), decltype(a8), decltype(a9), decltype(a10), decltype(a11), decltype(a12), decltype(a13), decltype(a14), decltype(a15), decltype(a16), decltype(a17), decltype(a18), decltype(a19), decltype(a20), decltype(a21), decltype(a22), decltype(a23), decltype(a24), decltype(a25), decltype(a26), decltype(a27), decltype(a28), decltype(a29), decltype(a30), decltype(a31), decltype(a32), decltype(a33), decltype(a34), decltype(a35), decltype(a36), decltype(a37), decltype(a38), decltype(a39), decltype(a40), decltype(a41), decltype(a42), decltype(a43), decltype(a44), decltype(a45), decltype(a46), decltype(a47), decltype(a48), decltype(a49)>{
        a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49
    };
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
constexpr decltype(auto) as_tuple(const T& val) noexcept {
    typedef size_t_<fields_count<T>()> fields_count_tag;
    return detail::as_tuple_impl(val, fields_count_tag{});
}

template <class T>
constexpr decltype(auto) as_tuple(T& val) noexcept {
    typedef size_t_<fields_count<T>()> fields_count_tag;
    return detail::as_tuple_impl(val, fields_count_tag{});
}

}}} // namespace boost::pfr

#endif // BOOST_PFR_CORE17_GENERATED_HPP

