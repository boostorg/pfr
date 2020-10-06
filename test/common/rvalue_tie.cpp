// Copyright (c) 2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <string>

#ifdef BOOST_PFR_TEST_FLAT
#include <boost/pfr/flat/core.hpp>
template <class T>
auto pfr_tie(T&& x) {
    return boost::pfr::flat_structure_tie(std::forward<T>(x));
}
#endif

#ifdef BOOST_PFR_TEST_PRECISE
#include <boost/pfr/precise/core.hpp>
template <class T>
auto pfr_tie(T&& x) {
    return boost::pfr::structure_tie(std::forward<T>(x));
}
#endif

struct test_struct {
    int i;
    std::string s;
};

int main() {
    pfr_tie(test_struct{1, "test"});
}
