// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_CONFIG_HPP
#define BOOST_PFR_DETAIL_CONFIG_HPP
#pragma once

#include <boost/pfr/detail/config_safe.hpp>

#if BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON != BOOST_PFR_LACK_OF_SUPPORTS_REASON_ALL_RIGHT
#   if BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON == BOOST_PFR_LACK_OF_SUPPORTS_REASON_REQUIRES_MORE_MODERN_MSVC_COMPILER
#      error Boost.PFR library requires more modern MSVC compiler.
#   elif BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON == BOOST_PFR_LACK_OF_SUPPORTS_REASON_REQUIRES_AT_LEAST_CPP14
#      error Boost.PFR library requires at least C++14.
#   elif BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON == BOOST_PFR_LACK_OF_SUPPORTS_REASON_REQUIRES_STDCPPLATEST_OR_STDCPP17_FLAGS_ON_YOUR_COMPILER
#      error Boost.PFR library requires /std:c++latest or /std:c++17 flags on your compiler.
#   else
#      error Boost.PFR library unsupported.
#   endif
#endif

#endif // BOOST_PFR_DETAIL_CONFIG_HPP
