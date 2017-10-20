#!/usr/bin/python

# Copyright (c) 2016-2017 Antony Polukhin
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

############################################################################################################################

import sys
import string

# Skipping some letters that may produce keywords or are hard to read, or shadow template parameters
ascii_letters = string.ascii_letters.replace("o", "").replace("O", "").replace("i", "").replace("I", "").replace("T", "")

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

#if !BOOST_PFR_USE_CPP17
#   error C++17 is required for this header.
#endif

#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/detail/fields_count.hpp>

namespace boost { namespace pfr { namespace detail {

template <class... Args>
constexpr auto make_tuple_of_references(Args&&... args) noexcept {
  return sequence_tuple::tuple<Args&...>{ args... };
}

template <class T>
constexpr auto tie_as_tuple(T& /*val*/, size_t_<0>) noexcept {
  return sequence_tuple::tuple<>{};
}

template <class T>
constexpr auto tie_as_tuple(T& val, size_t_<1>, std::enable_if_t<std::is_class< std::remove_cv_t<T> >::value>* = 0) noexcept {
  auto& [a] = val;
  return ::boost::pfr::detail::make_tuple_of_references(a);
}


template <class T>
constexpr auto tie_as_tuple(T& val, size_t_<1>, std::enable_if_t<!std::is_class< std::remove_cv_t<T> >::value>* = 0) noexcept {
  return ::boost::pfr::detail::make_tuple_of_references( val );
}

"""

############################################################################################################################
EPILOGUE = """
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
constexpr auto tie_as_tuple(T& val) noexcept {
  typedef size_t_<fields_count<T>()> fields_count_tag;
  return boost::pfr::detail::tie_as_tuple(val, fields_count_tag{});
}

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE17_GENERATED_HPP
"""

############################################################################################################################
generate_sfinae_attempts = False


if generate_sfinae_attempts:
    print """
    template <class T, std::size_t I>
    constexpr auto tie_as_tuple(T& val, size_t_<I>) noexcept {
      return tie_as_tuple(val, size_t_<I - 1>{});
    }
    """


indexes = "    a"
print PROLOGUE
funcs_count = 100 if len(sys.argv) == 1 else int(sys.argv[1])
max_args_on_a_line = len(ascii_letters)
for i in xrange(1, funcs_count):
    if i % max_args_on_a_line == 0:
        indexes += ",\n    "
    else:
        indexes += ","

    if i >= max_args_on_a_line:
        indexes += ascii_letters[i / max_args_on_a_line - 1] 
    indexes += ascii_letters[i % max_args_on_a_line]

    print "template <class T>"
    print "constexpr auto tie_as_tuple(T& val, size_t_<" + str(i + 1) + ">) noexcept {"
    if i < max_args_on_a_line:
        print "  auto& [" + indexes.strip() + "] = val;"
        print "  return ::boost::pfr::detail::make_tuple_of_references(" + indexes.strip() + ");"
    else:
        print "  auto& ["
        print indexes
        print "  ] = val;"
        print ""
        print "  return ::boost::pfr::detail::make_tuple_of_references("
        print indexes
        print "  );"

    print "}\n"

    if generate_sfinae_attempts:
        print "template <class T>"
        print "constexpr auto tie_as_tuple(T& val, size_t_<" + str(i + 1) + "> v) noexcept"
        print "  ->decltype( ::boost::pfr::detail::tie_as_tuple0(std::forward<T>(val), v) )"
        print "{ return ::boost::pfr::detail::tie_as_tuple0(std::forward<T>(val), v); }\n"

print EPILOGUE
