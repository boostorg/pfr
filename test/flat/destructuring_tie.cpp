// Copyright (c) 2018 Adam Butcher, Antony Polukhin
// Copyright (c) 2019-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/flat/core.hpp>
#include <boost/core/lightweight_test.hpp>

struct point {
   int x, y;
};

auto line(point a, point b) {
   struct {
      int timestamp;
      point a, b;
   } res = {123456, a, b};
   return res;
}

#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE

int main() {
    auto l = line({1, 2}, {3, 4});
    int t, a, b, c, d;
    using namespace boost::pfr;
    using std::ignore;

    flat_tie_from_structure (t, a, b, c, d) = l;
    BOOST_TEST_EQ(t, 123456);
    BOOST_TEST_EQ(a, 1);
    BOOST_TEST_EQ(b, 2);
    BOOST_TEST_EQ(c, 3);
    BOOST_TEST_EQ(d, 4);

    flat_tie_from_structure (ignore, ignore, a, b, c) = l;
    BOOST_TEST_EQ(a, 2);
    BOOST_TEST_EQ(b, 3);
    BOOST_TEST_EQ(c, 4);

    flat_tie_from_structure (ignore, a, b, c, ignore) = l;
    BOOST_TEST_EQ(a, 1);
    BOOST_TEST_EQ(b, 2);
    BOOST_TEST_EQ(c, 3);

    return boost::report_errors();
}

#else // C++14 without loophole

#include <iostream>
int main(int, char** argv) {
   std::cerr << argv[0] << ": Not supported in C++14 without reflection loophole.\n";
}

#endif
