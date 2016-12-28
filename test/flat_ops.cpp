// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/flat/ops.hpp>
#include <boost/core/lightweight_test.hpp>

#include <iostream>
#include <typeinfo>
#include <tuple>
#include <sstream>
#include <set>
#include <string>

template <class T>
void test_comparable_struct() {
    using namespace boost::pfr::flat_ops;

    T s1 {0, 1, "Hello", false, 6,7,8,9,10,11};
    T s2 = s1;
    T s3 {0, 1, "Hello", false, 6,7,8,9,10,11111};
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

    T s4;
    std::stringstream ss;
    ss.exceptions ( std::ios::failbit);
    ss << s1;
    ss >> s4;
    std::cout << s4 << std::endl;
    BOOST_TEST(s1 == s4);
    int i = 1, j = 2;
    BOOST_TEST_NE(i, j);
}

void test_empty_struct() {
    struct empty {};
    using namespace boost::pfr::flat_ops;

    std::cout << empty{};
    BOOST_TEST(empty{} == empty{});
}

void test_implicit_conversions() {
    std::stringstream ss;
    ss << std::true_type{};
    BOOST_TEST_EQ(ss.str(), "1"); // Does not breaks implicit conversion
}


namespace foo {
struct comparable_struct {
    int i; short s; char data[50]; bool bl; int a,b,c,d,e,f;
};
}

int main() {
    test_comparable_struct<foo::comparable_struct>();

    struct local_comparable_struct {
        int i; short s; char data[50]; bool bl; int a,b,c,d,e,f;
    };

    test_comparable_struct<local_comparable_struct>();
    test_empty_struct();
    test_implicit_conversions();

    return boost::report_errors();
}


