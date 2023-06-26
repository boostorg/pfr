// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#ifndef BOOST_PFR_DETAIL_CORE_NAME_HPP
#define BOOST_PFR_DETAIL_CORE_NAME_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

// Each core_name provides `TODO:` and
// `TODO:` functions.
//
// The whole functional of extracting field's names is build on top of those
// two functions.
#if BOOST_PFR_ENABLE_GETTING_NAMES
#include <boost/pfr/detail/core_name20_static.hpp>
#else
#include <boost/pfr/detail/core_name14_disabled.hpp>
#endif

#endif // BOOST_PFR_DETAIL_CORE_NAME_HPP

