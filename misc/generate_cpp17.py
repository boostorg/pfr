# Copyright (c) 2016 Antony Polukhin
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

######################################################################################################################
PROLOGUE = """// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// This is an auto generated header. Modify pfr/misc/generate_cpp17.py instead.   //////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_PFR_CORE17_GENERATED_HPP
#define BOOST_PFR_CORE17_GENERATED_HPP

#pragma once

#if __cplusplus < 201606L /* Oulu meeting, not the exact value */
#   error C++17 is required for this header.
#endif

#include <boost/pfr/core.hpp>

namespace boost { namespace pfr { namespace detail {

template <class T>
constexpr decltype(auto) as_tuple_impl(const T& val, size_t_<0>) noexcept {
    return sequence_tuple::tuple<>{};
}

template <class T>
constexpr decltype(auto) as_tuple_impl(T& val, size_t_<0>) noexcept {
    return sequence_tuple::tuple<>{};
}

"""

######################################################################################################################
EPILOGUE = """
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
constexpr decltype(auto) as_tuple(const T& val) noexcept {
    typedef size_t_<fields_count<T>()> fields_count_tag;
    return detail::as_tuple_impl(val, fields_count_tag{});
}

template <class T>
constexpr decltype(auto) as_tuple(T& val) noexcept {
    typedef size_t_<fields_count<T>()> fields_count_tag;
    return detail::as_tuple_impl(val, fields_count_tag{});
}

}}} // namespace boost::pfr

#endif // BOOST_PFR_CORE17_GENERATED_HPP
"""

######################################################################################################################

indexes = []
print PROLOGUE
for i in xrange(50):
    indexes += [str(i)]
    for signature in ("const T& val", "T& val"):
        print "template <class T>"
        print "constexpr decltype(auto) as_tuple_impl(" + signature + ", size_t_<" + str(i + 1) + ">) noexcept {"
        print "    auto& [a" + ", a".join(indexes) + "] = val;"
        print "    return sequence_tuple::tuple<decltype(a" + "), decltype(a".join(indexes) + ")>{"
        print "        a" + ", a".join(indexes)
        print "    };"
        print "}\n"

print EPILOGUE
