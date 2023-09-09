// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#include <boost/pfr/core_name.hpp>

#include <boost/core/lightweight_test.hpp>
#include <functional> // for std::reference_wrapper
#include <string>

namespace testing {

struct nonconstexpr {
    nonconstexpr() {};
};

struct Aggregate {
    int member1;
    nonconstexpr this_is_a_name;
    std::reference_wrapper<char> c;
    std::string Forth;
};

struct A {
    int first;
    int second;
};

struct empty {};

void test_get_name_by_id() {
    BOOST_TEST_EQ( ((boost::pfr::get_name<0, Aggregate>())), "member1");
    BOOST_TEST_EQ( ((boost::pfr::get_name<1, Aggregate>())), "this_is_a_name");
    BOOST_TEST_EQ( ((boost::pfr::get_name<2, Aggregate>())), "c");
    BOOST_TEST_EQ( ((boost::pfr::get_name<3, Aggregate>())), "Forth");

    BOOST_TEST_EQ( ((boost::pfr::get_name<0, A>())), "first");
    BOOST_TEST_EQ( ((boost::pfr::get_name<1, A>())), "second");
}

void test_get_name_by_type() {
// FIXME: implement this
//     using char_ref = std::reference_wrapper<char>;
//     BOOST_TEST_EQ( ((boost::pfr::get_name<int, Aggregate>())), "member1");
//     BOOST_TEST_EQ( ((boost::pfr::get_name<nonconstexpr, Aggregate>())), "this_is_a_name");
//     BOOST_TEST_EQ( ((boost::pfr::get_name<char_ref, Aggregate>())), "c");
}

void test_names_as_array() {
    const auto expected = std::array<std::string_view, 4>{
        "member1",
        "this_is_a_name",
        "c",
        "Forth"
    };
    const auto value = boost::pfr::names_as_array<Aggregate>();
    BOOST_TEST_EQ(expected.size(), value.size());
    for (std::size_t i=0;i<expected.size();++i) {
        BOOST_TEST_EQ(value[i], expected[i]);
    }
}

void test_names_as_array_for_empty() {
    const auto value = boost::pfr::names_as_array<empty>();
    BOOST_TEST_EQ(value.size(), 0);
    BOOST_TEST_EQ(value.empty(), true);
}

} // namespace testing

int main() {
    testing::test_get_name_by_id();
    testing::test_get_name_by_type();
    testing::test_names_as_array();
    testing::test_names_as_array_for_empty();

    return boost::report_errors();
}


