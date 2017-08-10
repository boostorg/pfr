// Copyright (c) 2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/flat/tuple_size.hpp>
#include <boost/pfr/precise/tuple_size.hpp>

class test_with_protected {
protected:
    int i;
    char c;

public:
    double d;
    float f;
};

int main() {
#ifdef BOOST_PFR_TEST_FLAT
    return boost::pfr::flat_tuple_size<test_with_protected>::value;
#else

#ifndef __cpp_lib_is_aggregate
#   error No known way to detect protected fields.
#endif

    return boost::pfr::tuple_size<test_with_protected>::value;
#endif
}

