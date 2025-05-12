// Copyright (c) 2020-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#include <boost/pfr/core.hpp>

#include <boost/core/lightweight_test.hpp>

namespace testing {

namespace {

struct other_anon {
    int data;
};

struct anon {
    other_anon a;
    const other_anon b;
};

void test_get_in_anon_ns_const_field() {
    anon x{{1}, {2}};

    BOOST_TEST_EQ(boost::pfr::get<0>(x).data, 1);
    static_assert(std::is_same<
        decltype(boost::pfr::get<0>(x)),
        other_anon&
    >::value, "");

    BOOST_TEST_EQ(boost::pfr::get<1>(x).data, 2);
    static_assert(std::is_same<
        decltype(boost::pfr::get<1>(x)),
        const other_anon&
    >::value, "");
}

} // anonymous namespace


} // namespace testing

int main() {
    testing::test_get_in_anon_ns_const_field();

    return boost::report_errors();
}
