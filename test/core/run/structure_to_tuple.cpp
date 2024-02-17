// Copyright (c) 2020-2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/core/lightweight_test.hpp>

#include <boost/pfr/core.hpp>

namespace some {
    struct struct1{ int i; };
    struct struct2{ int i; short s;  };
}


void test_single_field() {
    {
        some::struct1 s{1};
        auto s_tuple = boost::pfr::structure_to_tuple(s);
        BOOST_TEST_EQ(std::get<0>(s_tuple), 1);

        static_assert(std::is_same<
            std::tuple<int>, decltype(s_tuple)
        >::value, "");
    }
    {
        const some::struct1 s{1};
        auto s_tuple = boost::pfr::structure_to_tuple(s);
        BOOST_TEST_EQ(std::get<0>(s_tuple), 1);

        static_assert(std::is_same<
            std::tuple<int>, decltype(s_tuple)
        >::value, "");
    }
}


void test_two_fields() {
    {
        some::struct2 s{1, 2};
        auto s_tuple = boost::pfr::structure_to_tuple(s);
        BOOST_TEST_EQ(std::get<0>(s_tuple), 1);
        BOOST_TEST_EQ(std::get<1>(s_tuple), 2);

        static_assert(std::is_same<
            std::tuple<int, short>, decltype(s_tuple)
        >::value, "");
    }
    {
        const some::struct2 s{1, 2};
        auto s_tuple = boost::pfr::structure_to_tuple(s);
        BOOST_TEST_EQ(std::get<0>(s_tuple), 1);
        BOOST_TEST_EQ(std::get<1>(s_tuple), 2);

        static_assert(std::is_same<
            std::tuple<int, short>, decltype(s_tuple)
        >::value, "");
    }
}

// Test from https://github.com/boostorg/pfr/issues/155
void test_throwing_field() {
#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE
    struct throw_on_copy {
        throw_on_copy() = default;
        throw_on_copy(const throw_on_copy&){ throw 42; }
    };

    struct throwing_struct {
        int i;
        throw_on_copy s;
    };

    throwing_struct s {10, {}};
    try {
        std::tuple<int, throw_on_copy> t = boost::pfr::structure_to_tuple(s);
        BOOST_TEST(false); // the above line should throw
        (void)t;
    } catch (...) {}
#endif
}

int main() {
    test_single_field();
    test_two_fields();
    test_throwing_field();

    return boost::report_errors();
}


