// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#include <boost/pfr/core_name.hpp>

#include <boost/core/lightweight_test.hpp>

namespace testing {

namespace {

struct {
    int field_of_unnamed_structure;
} unnamed;

void test_get_name() {
    BOOST_TEST_EQ( ((boost::pfr::get_name<0, decltype(unnamed)>())), "field_of_unnamed_structure");
}

void test_names_as_array() {
    const auto expected = std::array<std::string_view, 1>{
        "field_of_unnamed_structure"
    };
    const auto value = boost::pfr::names_as_array<decltype(unnamed)>();
    BOOST_TEST_EQ(expected.size(), value.size());
    for (std::size_t i=0;i<expected.size();++i) {
        BOOST_TEST_EQ(value[i], expected[i]);
    }
}

void test_get_name_for_local_structure() {
    struct A { int a_field_name; };
    BOOST_TEST_EQ( ((boost::pfr::get_name<0, A>())), "a_field_name" );
}

} // anonymous namespace


} // namespace testing

int main() {
    testing::test_get_name();
    testing::test_names_as_array();
    testing::test_get_name_for_local_structure();

    return boost::report_errors();
}


