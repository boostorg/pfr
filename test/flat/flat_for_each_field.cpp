// Copyright (c) 2016-2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/flat/core.hpp>
#include <boost/core/lightweight_test.hpp>

int main() {
    struct nested { int i; short data[3]; };
    struct foo { int i; nested n; };
    std::size_t sum = 0;
    boost::pfr::flat_for_each_field(foo{1, {2, {3, 4, 5}}}, [&sum](auto v) {
        sum += v;
    });
    BOOST_TEST_EQ(sum, 15u);

    sum = 0;
    int array[] = {0, 1, 0, 2, 3, 0, 4, 5};
    boost::pfr::flat_for_each_field(array, [&sum](auto v) {
        sum += v;
    });
    BOOST_TEST_EQ(sum, 15u);


    return boost::report_errors();
}

