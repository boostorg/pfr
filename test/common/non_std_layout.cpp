// Copyright (c) 2018-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifdef BOOST_PFR_TEST_FLAT
#   include <boost/pfr/flat/tuple_size.hpp>
#elif defined(BOOST_PFR_TEST_PRECISE)
#   include <boost/pfr/precise/tuple_size.hpp>
#else
#   error Misused test
#endif


struct non_standard_layout_member {
private:
    int i = 0;

public:
    int j = 1;
};

struct test_with_non_st_layout {
    non_standard_layout_member m;
    double d;
    float f;
};

int main() {
#ifdef BOOST_PFR_TEST_FLAT
    return boost::pfr::flat_tuple_size<test_with_non_st_layout>::value;
#else
    static_assert(boost::pfr::tuple_size<test_with_non_st_layout>::value == 3, "");
#endif
}

