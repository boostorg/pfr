#!/usr/bin/python

# Copyright (c) 2016 Antony Polukhin
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

############################################################################################################################

import sys

PROLOGUE = """// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// This is an auto generated header. Modify pfr/misc/generate_cpp17.py instead.   ////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_PFR_CORE17_GENERATED_HPP
#define BOOST_PFR_CORE17_GENERATED_HPP

#pragma once

#if __cplusplus < 201606L /* Oulu meeting, not the exact value */
#   error C++17 is required for this header.
#endif

#include <boost/pfr/core.hpp>

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

#endif // BOOST_PFR_CORE17_GENERATED_HPP
"""

############################################################################################################################

indexes = ""
print PROLOGUE
funcs_count = 100 if len(sys.argv) == 1 else int(sys.argv[1])
for i in xrange(funcs_count):
    if i == 0:
        indexes = "    "
    elif i % 30 == 0:
        indexes += ",\n    "
    else:
        indexes += ","

    indexes += ("a" + str(i)).rjust(3 if funcs_count < 101 else 4, ' ')

    print "template <class T>"
    print "constexpr auto as_tuple_impl(T&& val, size_t_<" + str(i + 1) + ">) noexcept {"
    print "  auto& ["
    print indexes
    print "  ] = std::forward<T>(val);"
    print ""
    print "  return ::boost::pfr::detail::make_tuple_of_references("
    print indexes
    print "  );"
    print "}\n"

print EPILOGUE
