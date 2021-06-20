// Copyright (c) 2016-2021 Antony Polukhin
// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_CONFIG_SAFE_HPP
#define BOOST_PFR_DETAIL_CONFIG_SAFE_HPP
#pragma once

#include <type_traits> // to get non standard platform macro definitions (__GLIBCXX__ for example)

#define BOOST_PFR_LACK_OF_SUPPORTS_REASON_ALL_RIGHT 0
#define BOOST_PFR_LACK_OF_SUPPORTS_REASON_REQUIRES_MORE_MODERN_MSVC_COMPILER                         1
#define BOOST_PFR_LACK_OF_SUPPORTS_REASON_REQUIRES_AT_LEAST_CPP14                                    2
#define BOOST_PFR_LACK_OF_SUPPORTS_REASON_REQUIRES_STDCPPLATEST_OR_STDCPP17_FLAGS_ON_YOUR_COMPILER   3




#ifdef BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON
#   error Boost.PFR it is forbidden to set a service value of the macro BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON in the user's side code
#endif


// Reminder:
//  * MSVC++ 14.2 _MSC_VER == 1927 <- Loophole is known to work (Visual Studio ????)
//  * MSVC++ 14.1 _MSC_VER == 1916 <- Loophole is known to NOT work (Visual Studio 2017)
//  * MSVC++ 14.0 _MSC_VER == 1900 (Visual Studio 2015)
//  * MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)

#if defined(_MSC_VER)
#   if !defined(_MSVC_LANG) || _MSC_VER <= 1900
#       define BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON BOOST_PFR_LACK_OF_SUPPORTS_REASON_REQUIRES_MORE_MODERN_MSVC_COMPILER
#   endif
#elif __cplusplus < 201402L
#   define BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON BOOST_PFR_LACK_OF_SUPPORTS_REASON_REQUIRES_AT_LEAST_CPP14
#endif

#ifndef BOOST_PFR_USE_LOOPHOLE
#   if defined(_MSC_VER)
#       if _MSC_VER >= 1927
#           define BOOST_PFR_USE_LOOPHOLE 1
#       else
#           define BOOST_PFR_USE_LOOPHOLE 0
#       endif
#   elif defined(__clang_major__) && __clang_major__ >= 8
#       define BOOST_PFR_USE_LOOPHOLE 0
#   else
#       define BOOST_PFR_USE_LOOPHOLE 1
#   endif
#endif

#ifndef BOOST_PFR_USE_CPP17
#   ifdef __cpp_structured_bindings
#       define BOOST_PFR_USE_CPP17 1
#   elif defined(_MSVC_LANG)
#       if _MSVC_LANG >= 201703L
#           define BOOST_PFR_USE_CPP17 1
#       else
#           define BOOST_PFR_USE_CPP17 0
#       endif
#   else
#       define BOOST_PFR_USE_CPP17 0
#   endif
#endif

#if (!BOOST_PFR_USE_CPP17 && !BOOST_PFR_USE_LOOPHOLE)
#   if (defined(_MSC_VER) && _MSC_VER < 1916) ///< in Visual Studio 2017 v15.9 PFR library with classic engine normally works
#      ifndef BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON
#         define BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON BOOST_PFR_LACK_OF_SUPPORTS_REASON_REQUIRES_STDCPPLATEST_OR_STDCPP17_FLAGS_ON_YOUR_COMPILER
#      endif
#   endif
#endif

#ifndef BOOST_PFR_USE_STD_MAKE_INTEGRAL_SEQUENCE
// Assume that libstdc++ since GCC-7.3 does not have linear instantiation depth in std::make_integral_sequence
#   if defined( __GLIBCXX__) && __GLIBCXX__ >= 20180101
#       define BOOST_PFR_USE_STD_MAKE_INTEGRAL_SEQUENCE 1
#   elif defined(_MSC_VER)
#       define BOOST_PFR_USE_STD_MAKE_INTEGRAL_SEQUENCE 1
//# elif other known working lib
#   else
#       define BOOST_PFR_USE_STD_MAKE_INTEGRAL_SEQUENCE 0
#   endif
#endif

#ifndef BOOST_PFR_HAS_GUARANTEED_COPY_ELISION
#   if  defined(__cpp_guaranteed_copy_elision) && (!defined(_MSC_VER) || _MSC_VER > 1928)
#       define BOOST_PFR_HAS_GUARANTEED_COPY_ELISION 1
#   else
#       define BOOST_PFR_HAS_GUARANTEED_COPY_ELISION 0
#   endif
#endif

#if defined(__has_cpp_attribute)
#   if __has_cpp_attribute(maybe_unused)
#       define BOOST_PFR_MAYBE_UNUSED [[maybe_unused]]
#   endif
#endif

#ifndef BOOST_PFR_MAYBE_UNUSED
#   define BOOST_PFR_MAYBE_UNUSED
#endif

#ifndef BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON
#define BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON BOOST_PFR_LACK_OF_SUPPORTS_REASON_ALL_RIGHT
#endif

#endif //BOOST_PFR_DETAIL_CONFIG_SAFE_HPP
