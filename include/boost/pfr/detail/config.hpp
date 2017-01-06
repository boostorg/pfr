// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_CONFIG_HPP
#define BOOST_PFR_DETAIL_CONFIG_HPP
#pragma once

#if __cplusplus < 201402L && (!defined(_MSVC_LANG) || _MSVC_LANG < 201402L)
#   error Boost.PFR library requires C++14.
#endif


#ifndef BOOST_PFR_USE_CPP17
#   if __cplusplus > 201606L /* Oulu meeting, not the exact value */
#       define BOOST_PFR_USE_CPP17 1
#   else
#       define BOOST_PFR_USE_CPP17 0
#   endif
#endif

#endif // BOOST_PFR_DETAIL_CONFIG_HPP
