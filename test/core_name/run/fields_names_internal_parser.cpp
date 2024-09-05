// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#include <boost/pfr/core_name.hpp>
#include <string_view>

#include <boost/core/lightweight_test.hpp>

namespace testing {

constexpr std::string_view fake_func_name = " ******************** [fake_text1->fake_text2->fake_text3] **********";

void test_general()
{
    namespace detail = boost::pfr::detail;
    using detail::backward;
    BOOST_TEST_EQ(detail::make_core_name_skip(23, 12, "").apply(fake_func_name), "fake_text1->fake_text2->fake_text3");
    BOOST_TEST_EQ(detail::make_core_name_skip(23, 12, backward("->")).apply(fake_func_name), "fake_text3");
    BOOST_TEST_EQ(detail::make_core_name_skip(23, 12, "->").apply(fake_func_name), "fake_text2->fake_text3");
    BOOST_TEST_EQ(detail::make_core_name_skip(23, 12, backward("->")).apply(fake_func_name), "fake_text3");
    BOOST_TEST_EQ(detail::make_core_name_skip(23, 12, "->").apply(fake_func_name), "fake_text2->fake_text3");
}

void test_identity_parser()
{
    namespace detail = boost::pfr::detail;
    using detail::backward;
    BOOST_TEST_EQ(detail::make_core_name_skip(0, 0, backward("")).apply(fake_func_name), fake_func_name);
    BOOST_TEST_EQ(detail::make_core_name_skip(0, 0, "").apply(fake_func_name), fake_func_name);
}

}  // namespace testing

int main() {
    testing::test_general();
    testing::test_identity_parser();

    return boost::report_errors();
}

