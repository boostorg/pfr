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
    a0,b0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<3>) noexcept {
  auto& [
    a0,b0,c0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<4>) noexcept {
  auto& [
    a0,b0,c0,d0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<5>) noexcept {
  auto& [
    a0,b0,c0,d0,e0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<6>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<7>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<8>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<9>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<10>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<11>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<12>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<13>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<14>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<15>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<16>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<17>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<18>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<19>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<20>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<21>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<22>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<23>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<24>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<25>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<26>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<27>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<28>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<29>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<30>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<31>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<32>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<33>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<34>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<35>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<36>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<37>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<38>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<39>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<40>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<41>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<42>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<43>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<44>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<45>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<46>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<47>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<48>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<49>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<50>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<51>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<52>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<53>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<54>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<55>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<56>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<57>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<58>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<59>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<60>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<61>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<62>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<63>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<64>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<65>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<66>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<67>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<68>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<69>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<70>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<71>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<72>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<73>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<74>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<75>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<76>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<77>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<78>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<79>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<80>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<81>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<82>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<83>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<84>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<85>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<86>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<87>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<88>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<89>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<90>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<91>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<92>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<93>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<94>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<95>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<96>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<97>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1,S1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1,S1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<98>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1,S1,T1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1,S1,T1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<99>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1,S1,T1,U1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1,S1,T1,U1
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<100>) noexcept {
  auto& [
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1,S1,T1,U1,V1
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a0,b0,c0,d0,e0,f0,g0,h0,i0,j0,k0,l0,m0,n0,o0,p0,q0,r0,s0,t0,u0,v0,w0,x0,y0,z0,A0,B0,C0,D0,E0,F0,G0,H0,I0,J0,K0,L0,M0,N0,O0,P0,Q0,R0,S0,T0,U0,V0,W0,X0,Y0,Z0,
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1,A1,B1,C1,D1,E1,F1,G1,H1,I1,J1,K1,L1,M1,N1,O1,P1,Q1,R1,S1,T1,U1,V1
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

