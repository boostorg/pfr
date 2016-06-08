// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/global_pod_ops.hpp>
#include <boost/core/lightweight_test.hpp>

#include <iostream>
#include <typeinfo>
#include <tuple>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
#include <boost/unordered_set.hpp>
#include <string>



struct comparable_struct {
    int i; short s; char data[50]; bool bl; int a,b,c,d,e,f;
};

BOOST_PFR_DEFINE_FUNCTIONS_FOR(comparable_struct)


void test_comparable_struct() {
    comparable_struct s1 {0, 1, "Hello", false, 6,7,8,9,10,11};
    comparable_struct s2 = s1;
    comparable_struct s3 {0, 1, "Hello", false, 6,7,8,9,10,11111};
    BOOST_TEST(s1 == s2);
    BOOST_TEST(s1 <= s2);
    BOOST_TEST(s1 >= s2);
    BOOST_TEST(!(s1 != s2));
    BOOST_TEST(!(s1 == s3));
    BOOST_TEST(s1 != s3);
    BOOST_TEST(s1 < s3);
    BOOST_TEST(s3 > s2);
    BOOST_TEST(s1 <= s3);
    BOOST_TEST(s3 >= s2);

    std::cout << s1 << std::endl;

    comparable_struct s4;
    std::stringstream ss;
    ss.exceptions ( std::ios::failbit);
    ss << s1;
    ss >> s4;
    std::cout << s4 << std::endl;
    BOOST_TEST(s1 == s4);
    int i = 1, j = 2;
    BOOST_TEST_NE(i, j);
}

struct empty {};
BOOST_PFR_DEFINE_FUNCTIONS_FOR(empty)

void test_empty_struct() {
    BOOST_TEST(empty{} == empty{});
}

struct testing { bool b1, b2; int i; };
BOOST_PFR_DEFINE_FUNCTIONS_FOR(testing);

template <class Comparator>
void test_with_contatiners() {
    std::set<testing, Comparator > t{
        {true, true, 100},
        {false, true, 100},
        {true, false, 100},
        {true, true, 101}
    };

    BOOST_TEST(t.find({true, true, 100}) != t.end());
    BOOST_TEST_EQ(t.count({true, true, 100}), 1u);

    boost::unordered_set<testing> us(t.begin(), t.end());
    BOOST_TEST_EQ(us.size(), t.size());
}

int main() {
    test_comparable_struct();
    test_empty_struct();
    test_with_contatiners<std::less<>>();
    test_with_contatiners<std::greater<>>();

    return boost::report_errors();
}


