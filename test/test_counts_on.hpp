// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_TEST_TEST_COUNTS_ON_HPP
#define BOOST_PFR_TEST_TEST_COUNTS_ON_HPP

#include <boost/pfr/core.hpp>

template <class T1, std::size_t CountInT, std::size_t CountHelpers>
void test_counts_on_multiple_chars_impl_1() {
    using namespace boost::pfr;
    struct t1_c { T1 v1; char c[CountHelpers]; };
    static_assert(flat_tuple_size_v<t1_c> == CountInT + CountHelpers, "");

    struct t1_s { T1 v1; short s[CountHelpers]; };
    static_assert(flat_tuple_size_v<t1_s> == CountInT + CountHelpers, "");

    struct t1_i { T1 v1; int i[CountHelpers]; };
    static_assert(flat_tuple_size_v<t1_i> == CountInT + CountHelpers, "");

    struct t1_p { T1 v1; void* p[CountHelpers]; };
    static_assert(flat_tuple_size_v<t1_p> == CountInT + CountHelpers, "");

    struct t1_ll { T1 v1; long long ll[CountHelpers]; };
    static_assert(flat_tuple_size_v<t1_ll> == CountInT + CountHelpers, "");


    struct rt1_c { char c[CountHelpers]; T1 v1; };
    static_assert(flat_tuple_size_v<rt1_c> == CountInT + CountHelpers, "");

    struct rt1_s { short s[CountHelpers]; T1 v1; };
    static_assert(flat_tuple_size_v<rt1_s> == CountInT + CountHelpers, "");

    struct rt1_i { int i[CountHelpers]; T1 v1; };
    static_assert(flat_tuple_size_v<rt1_i> == CountInT + CountHelpers, "");

    struct rt1_p { void* p[CountHelpers]; T1 v1; };
    static_assert(flat_tuple_size_v<rt1_p> == CountInT + CountHelpers, "");

    struct rt1_ll { long long ll[CountHelpers]; T1 v1; };
    static_assert(flat_tuple_size_v<rt1_ll> == CountInT + CountHelpers, "");
}

template <class T1, std::size_t CountInT>
void test_counts_on_multiple_chars_impl() {
    using namespace boost::pfr;

    struct t1_0 { T1 v1; };
    static_assert(flat_tuple_size_v<t1_0> == CountInT, "");
    static_assert(flat_tuple_size_v<T1> == CountInT, "");
    static_assert(flat_tuple_size_v<std::conditional_t<std::is_fundamental<T1>::value, T1*, void*> > == 1, "");


    static_assert(flat_tuple_size_v<T1[5]> == CountInT*5, "");

    test_counts_on_multiple_chars_impl_1<T1, CountInT, 1>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 2>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 3>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 4>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 5>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 6>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 7>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 8>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 9>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 10>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 11>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 12>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 13>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 14>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 15>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 16>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 17>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 18>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 19>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 20>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 23>();
    test_counts_on_multiple_chars_impl_1<T1, CountInT, 24>();
}

template <class T>
void test_counts_on_multiple_chars() {
    test_counts_on_multiple_chars_impl<T, 1>();

    struct t2 { T v1; T v2; };
    test_counts_on_multiple_chars_impl<t2, 2>();
    test_counts_on_multiple_chars_impl<T[2], 2>();

    test_counts_on_multiple_chars_impl<T[3], 3>();
    test_counts_on_multiple_chars_impl<T[4], 4>();

    struct t8 { T v1; T v2; T v3; T v4; T v5; T v6; T v7; T v8; };
    test_counts_on_multiple_chars_impl<t8, 8>();
}

#endif


