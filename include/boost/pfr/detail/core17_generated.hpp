// Copyright (c) 2016-2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// This is an auto generated header. Modify pfr/misc/generate_cpp17.py instead.   ////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_PFR_DETAIL_CORE17_GENERATED_HPP
#define BOOST_PFR_DETAIL_CORE17_GENERATED_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#if !BOOST_PFR_USE_CPP17
#   error C++17 is required for this header.
#endif

#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/detail/fields_count.hpp>

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
constexpr auto as_tuple_impl(T&& val, size_t_<1>, std::enable_if_t<std::is_class< std::remove_cv_t<std::remove_reference_t<T>> >::value>* = 0) noexcept {
  auto& [a] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a);
}


template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<1>, std::enable_if_t<!std::is_class< std::remove_cv_t<std::remove_reference_t<T>> >::value>* = 0) noexcept {
  return ::boost::pfr::detail::make_tuple_of_references( std::forward<T>(val) );
}


template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<2>) noexcept {
  auto& [a,b] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<3>) noexcept {
  auto& [a,b,c] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<4>) noexcept {
  auto& [a,b,c,d] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<5>) noexcept {
  auto& [a,b,c,d,e] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<6>) noexcept {
  auto& [a,b,c,d,e,f] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<7>) noexcept {
  auto& [a,b,c,d,e,f,g] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<8>) noexcept {
  auto& [a,b,c,d,e,f,g,h] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<9>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<10>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<11>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<12>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<13>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<14>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<15>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<16>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<17>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<18>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<19>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<20>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<21>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<22>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<23>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<24>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<25>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<26>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<27>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<28>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<29>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<30>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<31>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<32>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<33>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<34>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<35>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<36>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<37>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<38>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<39>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<40>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<41>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<42>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<43>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<44>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<45>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<46>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<47>) noexcept {
  auto& [a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z] = std::forward<T>(val);
  return ::boost::pfr::detail::make_tuple_of_references(a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z);
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<48>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<49>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<50>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<51>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<52>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<53>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<54>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<55>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<56>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<57>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<58>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<59>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<60>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<61>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<62>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<63>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<64>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<65>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<66>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<67>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<68>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<69>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<70>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<71>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<72>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<73>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<74>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<75>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<76>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<77>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<78>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<79>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<80>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<81>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<82>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<83>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<84>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<85>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<86>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<87>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<88>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<89>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<90>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<91>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<92>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<93>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<94>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<95>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<96>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<97>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb,bc
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb,bc
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<98>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb,bc,bd
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb,bc,bd
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<99>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb,bc,bd,be
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb,bc,bd,be
  );
}

template <class T>
constexpr auto as_tuple_impl(T&& val, size_t_<100>) noexcept {
  auto& [
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb,bc,bd,be,bf
  ] = std::forward<T>(val);

  return ::boost::pfr::detail::make_tuple_of_references(
    a,b,c,d,e,f,g,h,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,J,K,L,M,N,P,Q,R,S,U,V,W,X,Y,Z,
    aa,ab,ac,ad,ae,af,ag,ah,aj,ak,al,am,an,ap,aq,ar,as,at,au,av,aw,ax,ay,az,aA,aB,aC,aD,aE,aF,aG,aH,aJ,aK,aL,aM,aN,aP,aQ,aR,aS,aU,aV,aW,aX,aY,aZ,
    ba,bb,bc,bd,be,bf
  );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
constexpr auto as_tuple(const T& val) noexcept {
  typedef size_t_<fields_count<T>()> fields_count_tag;
  return boost::pfr::detail::as_tuple_impl(val, fields_count_tag{});
}

template <class T>
constexpr auto as_tuple(T& val) noexcept {
  typedef size_t_<fields_count<T>()> fields_count_tag;
  return boost::pfr::detail::as_tuple_impl(val, fields_count_tag{});
}

template <class T>
using as_tuple_t = decltype( ::boost::pfr::detail::as_tuple(std::declval<T&>()) );

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE17_GENERATED_HPP

