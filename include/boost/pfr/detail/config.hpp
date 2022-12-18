// Copyright (c) 2016-2022 Antony Polukhin
// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_CONFIG_HPP
#define BOOST_PFR_DETAIL_CONFIG_HPP
#pragma once

#include <boost/pfr/config.hpp>

#if BOOST_NO_PFR

#error Boost.PFR library is not supported in your environment.             \
       Try one of the possible solutions:                                  \
       1. try to take away an '-DBOOST_NO_PFR=1', if it exists             \
       2. enable C++14;                                                    \
       3. enable C++17;                                                    \
       4. update your compiler;                                            \
       or disable this error by '-DBOOST_NO_PFR=0' if you really know what are you doing.

#endif // BOOST_NO_PFR

#endif // BOOST_PFR_DETAIL_CONFIG_HPP

