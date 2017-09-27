// Copyright (c) 2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/flat/tuple_size.hpp>
#include <boost/pfr/precise/tuple_size.hpp>

struct X {
    X(int) {}
};
struct S { X x0; X x1; int x2; X x3; };

int main() {
#ifdef BOOST_PFR_TEST_PRECISE
    return boost::pfr::tuple_size_v<S>;
#elif defined(BOOST_PFR_TEST_FLAT)
    return boost::pfr::flat_tuple_size_v<S>;
#else
#   error Misused test
#endif
}

