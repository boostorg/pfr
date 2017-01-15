#!/usr/bin/python

# Copyright (c) 2016 Antony Polukhin
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

############################################################################################################################

import sys
import string

# Skipping some letters that mey produce keywords or are hard to read 
ascii_letters = string.ascii_letters.replace("o", "").replace("O", "").replace("i", "").replace("I", "")

PROLOGUE = """// Copyright (c) 2016-2017 Antony Polukhin
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

#if BOOST_PFR_USE_CPP17
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

"""

############################################################################################################################
EPILOGUE = """
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

#endif // BOOST_PFR_DETAIL_CORE17_GENERATED_HPP
"""

############################################################################################################################

indexes = ""
print PROLOGUE
funcs_count = 100 if len(sys.argv) == 1 else int(sys.argv[1])
max_args_on_a_line = len(ascii_letters)
for i in xrange(funcs_count):
    if i == 0:
        indexes = "    "
    elif i % max_args_on_a_line == 0:
        indexes += ",\n    "
    else:
        indexes += ","

    if i >= max_args_on_a_line:
        indexes += ascii_letters[i / max_args_on_a_line - 1] 
    indexes += ascii_letters[i % max_args_on_a_line]

    print "template <class T>"
    print "constexpr auto as_tuple_impl(T&& val, size_t_<" + str(i + 1) + ">) noexcept {"
    if i < max_args_on_a_line:
        print "  auto& [" + indexes.strip() + "] = std::forward<T>(val);"
        print "  return ::boost::pfr::detail::make_tuple_of_references(" + indexes.strip() + ");"
    else:
        print "  auto& ["
        print indexes
        print "  ] = std::forward<T>(val);"
        print ""
        print "  return ::boost::pfr::detail::make_tuple_of_references("
        print indexes
        print "  );"

    print "}\n"

print EPILOGUE
