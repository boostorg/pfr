// Copyright (c) 2018 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/flat/tuple_size.hpp>
#include <boost/pfr/precise/tuple_size.hpp>

struct X {
    X() = default;
    X(X&&) = default;
    X(const X&) = delete;

    X& operator=(X&&) = default;
    X& operator=(const X&) = delete;
};

struct test_lvalue_ref_and_movable {
    X x;
    char& c;
};

int main() {
#ifdef BOOST_PFR_TEST_FLAT
    return boost::pfr::flat_tuple_size<test_lvalue_ref_and_movable>::value;
#else
    return boost::pfr::tuple_size<test_lvalue_ref_and_movable>::value;
#endif
}

