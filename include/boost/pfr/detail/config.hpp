// Copyright (c) 2016-2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_CONFIG_HPP
#define BOOST_PFR_DETAIL_CONFIG_HPP
#pragma once

// Reminder:
//  * MSVC++ 14.0 _MSC_VER == 1900 (Visual Studio 2015)
//  * MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)

#if __cplusplus < 201402L && (!defined(_MSC_VER) || _MSC_VER <= 1900)
#   error Boost.PFR library requires C++14.
#endif

#ifndef BOOST_PFR_USE_LOOPHOLE
#   define BOOST_PFR_USE_LOOPHOLE 1
#endif

#ifndef BOOST_PFR_USE_CPP17
#   ifdef __cpp_structured_bindings
#       define BOOST_PFR_USE_CPP17 1
#   else
#       define BOOST_PFR_USE_CPP17 0
#   endif
#endif

#endif // BOOST_PFR_DETAIL_CONFIG_HPP
