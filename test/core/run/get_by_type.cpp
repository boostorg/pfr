// Copyright (c) 2020-2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#include <boost/pfr/core.hpp>

#include <boost/core/lightweight_test.hpp>

namespace testing {

namespace {

struct Aggregate {
    int a;
    const int b;
    double c;
    double d;
    short e;
};

void test_get_by_type() {
#if BOOST_PFR_USE_CPP17
    Aggregate t{1, 2, 3.4, 5.6, 7};

    BOOST_TEST_EQ(boost::pfr::get<int>(t), 1);
    BOOST_TEST_EQ(boost::pfr::get<const int>(t), 2);
    BOOST_TEST_EQ(boost::pfr::get<short>(t), 7);

    boost::pfr::get<int>(t) = 11;
    boost::pfr::get<short>(t) = 77;
#endif
}

void test_const_get_by_type() {
#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE
    const Aggregate t{1, 2, 3.4, 5.6, 7};
    BOOST_TEST_EQ(boost::pfr::get<short>(t), 7);
#endif
}

void test_get_by_type_pod() {
    struct PodAggregate {
      int i;
      short s;
    };

    PodAggregate pod{1, 2};
    BOOST_TEST_EQ(boost::pfr::get<int>(pod), 1);
    BOOST_TEST_EQ(boost::pfr::get<short>(pod), 2);
}

} // anonymous namespace


} // namespace testing

int main() {
    testing::test_get_by_type();
    testing::test_const_get_by_type();
    testing::test_get_by_type_pod();

    return boost::report_errors();
}


