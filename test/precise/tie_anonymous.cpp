// Copyright (c) 2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/core/lightweight_test.hpp>

#include <boost/pfr/precise/ops.hpp>

namespace testing {

struct non_anon {
    int i;
};

namespace {

struct anon {
    non_anon a;
    non_anon b;
};

void test_in_anon_ns() {
    anon x{{1}, {2}};
    
    auto v = boost::pfr::structure_tie(x);
    
    BOOST_TEST_EQ(std::get<0>(v).i, 1);
    BOOST_TEST_EQ(std::get<1>(v).i, 2);
}

} // anonymous namespace

void test_in_non_non_ns() {
    anon x{{1}, {2}};
    
    auto v = boost::pfr::structure_tie(x);
    
    BOOST_TEST_EQ(std::get<0>(v).i, 1);
    BOOST_TEST_EQ(std::get<1>(v).i, 2);
}

} // namespace testing

int main() {
    testing::test_in_anon_ns();
    testing::test_in_non_non_ns();

    return boost::report_errors();
}


