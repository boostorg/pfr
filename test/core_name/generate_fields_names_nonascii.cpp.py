# Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


# Initial implementation by Bela Schaum, https://github.com/schaumb
# The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
#

############################################################################################################################

import sys
import string

TEMPLATE = """#include <boost/pfr/core_name.hpp>

#include <boost/core/lightweight_test.hpp>

namespace testing {

struct Aggregate {
    int _%ARG%;
};

void test_get_name() {
    BOOST_TEST_EQ( ((boost::pfr::get_name<0, Aggregate>())), "_%ARG%");
}

void test_names_as_array() {
    const auto expected = std::array<std::string_view, 1>{
        "_%ARG%"
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
"""

############################################################################################################################

sys.stdout.reconfigure(encoding='utf-8')
print(TEMPLATE.replace('%ARG%', (b'\xcf\x80').decode('utf-8')))