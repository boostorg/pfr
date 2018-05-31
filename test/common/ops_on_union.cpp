// Copyright (c) 2018 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <string>

#ifdef BOOST_PFR_TEST_FLAT
#include <boost/pfr/flat/ops.hpp>
using namespace boost::pfr::flat_ops;
#endif

#ifdef BOOST_PFR_TEST_PRECISE
#include <boost/pfr/precise/ops.hpp>
using namespace boost::pfr::ops;
#endif

union test_union {
    const char* c;
    int i;
};

int main() {
    test_union v{""};
    return v == v;
}
