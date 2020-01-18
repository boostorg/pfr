// Copyright (c) 2016-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifdef BOOST_PFR_TEST_FLAT
#   include <boost/pfr/flat/global_ops.hpp>
#elif defined(BOOST_PFR_TEST_PRECISE)
#   include <boost/pfr/precise/global_ops.hpp>
#else
#   error Misused test
#endif


#include <boost/core/lightweight_test.hpp>

#include <iostream>
#include <typeinfo>
#include <tuple>
#include <sstream>
#include <set>
#include <string>
#include <unordered_set>


#define BOOST_HASH_NO_EXTENSIONS
#include <boost/container_hash/hash.hpp>

template <class T>
void test_comparable_struct() {
    T s1 {0, 1, false, 6,7,8,9,10,11};
    T s2 = s1;
    T s3 {0, 1, false, 6,7,8,9,10,11111};
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

    std::cout << empty{};
    BOOST_TEST(empty{} == empty{});
}

struct adl_hash {
    template <class T>
    std::size_t operator()(const T& val) const {
        using namespace boost;
        return hash_value(val);
    }
};

template <class Comparator>
void test_with_contatiners() {
    struct testing { bool b1, b2; int i; };

    std::set<testing, Comparator > t{
        {true, true, 100},
        {false, true, 100},
        {true, false, 100},
        {true, true, 101}
    };

    BOOST_TEST(t.find({true, true, 100}) != t.end());
    BOOST_TEST_EQ(t.count({true, true, 100}), 1u);

    std::unordered_set<testing, adl_hash> us(t.begin(), t.end());
    BOOST_TEST_EQ(us.size(), t.size());
}


namespace foo {
struct comparable_struct {
    int i; short s; bool bl; int a,b,c,d,e,f;
};
}


void test_implicit_conversions() {
    std::stringstream ss;
    ss << std::true_type{};
    BOOST_TEST_EQ(ss.str(), "{}"); // Breaks implicit conversion :(
}

int main() {
    test_comparable_struct<foo::comparable_struct>();

    struct local_comparable_struct {
        int i; short s; bool bl; int a,b,c,d,e,f;
    };

    test_comparable_struct<local_comparable_struct>();

    test_empty_struct();
#ifndef BOOST_CLANG
    // TODO: Fails for unknown reason on Clang
    test_with_contatiners<std::less<>>();
    test_with_contatiners<std::greater<>>();
#endif
    test_implicit_conversions();

    return boost::report_errors();
}


