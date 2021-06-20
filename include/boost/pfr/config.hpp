// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_CONFIG_HPP
#define BOOST_PFR_CONFIG_HPP
#pragma once

#include <boost/pfr/detail/config_safe.hpp>

#if BOOST_PFR_CUR_LACK_OF_SUPPORTS_REASON != BOOST_PFR_LACK_OF_SUPPORTS_REASON_ALL_RIGHT
#define BOOST_NO_PFR
#endif

#endif //BOOST_PFR_CONFIG_HPP
