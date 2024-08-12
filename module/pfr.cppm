// Copyright (c) 2016-2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Compile via
// clang++-15 -I /data/code/boost/ -std=c++20 --precompile -x c++-module module/pfr.cppm

#define BOOST_PFR_BEGIN_MODULE_EXPORT export {
#define BOOST_PFR_END_MODULE_EXPORT }

#ifndef BOOST_PFR_HAS_STD_MODULE
module;
#include <array>
#include <cstddef>
#include <memory>
#include <functional>
#include <iomanip>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <iostream>
#include <variant>
#endif

export module Boost.PFR;

#ifdef BOOST_PFR_HAS_STD_MODULE
import std;
#endif

#include <boost/pfr/config.hpp>
#include <boost/pfr/core.hpp>
#include <boost/pfr/core_name.hpp>
#include <boost/pfr/functions_for.hpp>
#include <boost/pfr/functors.hpp>
#include <boost/pfr/io_fields.hpp>
#include <boost/pfr/io.hpp>
#include <boost/pfr/ops_fields.hpp>
#include <boost/pfr/ops.hpp>
#include <boost/pfr/traits_fwd.hpp>
#include <boost/pfr/traits.hpp>
#include <boost/pfr/tuple_size.hpp>
