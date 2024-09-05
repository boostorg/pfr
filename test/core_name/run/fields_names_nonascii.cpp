// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov, Antony Polukhin.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/* Tesing non-ASCII field names, so we have to add th following suppression:
boost-no-inspect
*/

#include <boost/pfr/core_name.hpp>

#include <boost/core/lightweight_test.hpp>

namespace testing {

struct Aggregate {
    int _πривет_мир;
};

void test_get_name() {
    BOOST_TEST_EQ( ((boost::pfr::get_name<0, Aggregate>())), "_πривет_мир");
}

void test_names_as_array() {
    const auto expected = std::array<std::string_view, 1>{
        "_πривет_мир"
    };
    const auto value = boost::pfr::names_as_array<Aggregate>();
    BOOST_TEST_EQ(expected.size(), value.size());
    for (std::size_t i=0;i<expected.size();++i) {
        BOOST_TEST_EQ(value[i], expected[i]);
    }
}


} // namespace testing

int main() {
    testing::test_get_name();
    testing::test_names_as_array();

    return boost::report_errors();
}

