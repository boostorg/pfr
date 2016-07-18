// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// This is an auto generated header. Modify pfr/misc/generate_cpp17.py instead.   ////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_PFR_CORE17_GENERATED_HPP
#define BOOST_PFR_CORE17_GENERATED_HPP

#pragma once

#if __cplusplus < 201606L /* Oulu meeting, not the exact value */
#   error C++17 is required for this header.
#endif

#include <boost/pfr/core.hpp>

namespace boost { namespace pfr { namespace detail {

template <class... Args>
constexpr auto make_tuple_of_references(Args&&... args) noexcept {
  return sequence_tuple::tuple<Args&...>{ std::forward<Args>(args)... };
}

template <class T>
constexpr auto as_tuple_impl(T&& /*val*/, size_t_<0>) noexcept {
  return sequence_tuple::tuple<>{};
}


template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<1>) noexcept {
  auto& [
     a0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<2>) noexcept {
  auto& [
     a0, a1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<3>) noexcept {
  auto& [
     a0, a1, a2
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<4>) noexcept {
  auto& [
     a0, a1, a2, a3
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<5>) noexcept {
  auto& [
     a0, a1, a2, a3, a4
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<6>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<7>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<8>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<9>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<10>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<11>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<12>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<13>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<14>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<15>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<16>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<17>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<18>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<19>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<20>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<21>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<22>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<23>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<24>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<25>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<26>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<27>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<28>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<29>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<30>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<31>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<32>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<33>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<34>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<35>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<36>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<37>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<38>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<39>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<40>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<41>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<42>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<43>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<44>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<45>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<46>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<47>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<48>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<49>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<50>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<51>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<52>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<53>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<54>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<55>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<56>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<57>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<58>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<59>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<60>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<61>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<62>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<63>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<64>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<65>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<66>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<67>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<68>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<69>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<70>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<71>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<72>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<73>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<74>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<75>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<76>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<77>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<78>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<79>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<80>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<81>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<82>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<83>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<84>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<85>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<86>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<87>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<88>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<89>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<90>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<91>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<92>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<93>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<94>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<95>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<96>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<97>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95,a96
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95,a96
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<98>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95,a96,a97
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95,a96,a97
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<99>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95,a96,a97,a98
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95,a96,a97,a98
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<100>) noexcept {
  auto& [
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95,a96,a97,a98,a99
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
     a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
    a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,
    a60,a61,a62,a63,a64,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80,a81,a82,a83,a84,a85,a86,a87,a88,a89,
    a90,a91,a92,a93,a94,a95,a96,a97,a98,a99
  );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
constexpr auto as_tuple(const T& val) noexcept {
  typedef size_t_<fields_count<T>()> fields_count_tag;
  return detail::as_tuple_impl(val, fields_count_tag{});
}

template <class T>
constexpr auto as_tuple(T& val) noexcept {
  typedef size_t_<fields_count<T>()> fields_count_tag;
  return detail::as_tuple_impl(val, fields_count_tag{});
}

template <class T>
using as_tuple_t = decltype( ::boost::pfr::detail::as_tuple(std::declval<T&>()) );

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_CORE17_GENERATED_HPP

