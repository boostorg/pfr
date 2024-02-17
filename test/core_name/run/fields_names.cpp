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

namespace {
    struct inside_unnamed_ns {
        int hidden;
    };
}

struct {
    int unnamed_first;
    float unnamed_second;
} unnamed{};

typedef typename std::remove_reference<decltype(unnamed)>::type unnamed_t;

void test_get_name_by_id() {
    BOOST_TEST_EQ( ((boost::pfr::get_name<0, Aggregate>())), "member1");
    BOOST_TEST_EQ( ((boost::pfr::get_name<1, Aggregate>())), "this_is_a_name");
    BOOST_TEST_EQ( ((boost::pfr::get_name<2, Aggregate>())), "c");
    BOOST_TEST_EQ( ((boost::pfr::get_name<3, Aggregate>())), "Forth");

    BOOST_TEST_EQ( ((boost::pfr::get_name<0, A>())), "first");
    BOOST_TEST_EQ( ((boost::pfr::get_name<1, A>())), "second");
}

void test_get_name_by_id_without_linkage() {
// Disabling for MSVC as it gives a hard error on using local types:
///
// error C7631:
// 'boost::pfr::detail::do_not_use_PFR_with_local_types<testing::unnamed_t>':
// variable with internal linkage declared but not defined
#ifndef _MSC_VER
    struct function_local {
        int val;
    };

    BOOST_TEST_EQ( ((boost::pfr::get_name<0, unnamed_t>())), "unnamed_first");
    BOOST_TEST_EQ( ((boost::pfr::get_name<1, unnamed_t>())), "unnamed_second");

    BOOST_TEST_EQ( ((boost::pfr::get_name<0, inside_unnamed_ns>())), "hidden");

    BOOST_TEST_EQ( ((boost::pfr::get_name<0, function_local>())), "val");
#endif
}

void test_get_name_by_type() {
// FIXME: implement this
//     using char_ref = std::reference_wrapper<char>;
//     BOOST_TEST_EQ( ((boost::pfr::get_name<int, Aggregate>())), "member1");
//     BOOST_TEST_EQ( ((boost::pfr::get_name<nonconstexpr, Aggregate>())), "this_is_a_name");
//     BOOST_TEST_EQ( ((boost::pfr::get_name<char_ref, Aggregate>())), "c");
}

void test_get_name_by_type_without_linkage() {
// FIXME: implement this
//     BOOST_TEST_EQ( ((boost::pfr::get_name<int, unnamed_t>())), "unnamed_first");
//     BOOST_TEST_EQ( ((boost::pfr::get_name<float, unnamed_t>())), "unnamed_second");
//     BOOST_TEST_EQ( ((boost::pfr::get_name<int, inside_unnamed_ns>())), "hidden");
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

void test_names_as_array_without_linkage() {
// Disabling for MSVC as it gives a hard error on using local types:
///
// error C7631:
// 'boost::pfr::detail::do_not_use_PFR_with_local_types<testing::unnamed_t>':
// variable with internal linkage declared but not defined
#ifndef _MSC_VER
    const auto expected = std::array<std::string_view, 2>{
        "unnamed_first",
        "unnamed_second"
    };
    const auto value = boost::pfr::names_as_array<unnamed_t>();
    BOOST_TEST_EQ(expected.size(), value.size());
    for (std::size_t i=0;i<expected.size();++i) {
        BOOST_TEST_EQ(value[i], expected[i]);
    }
#endif
}

void test_names_as_array_for_empty() {
    const auto value = boost::pfr::names_as_array<empty>();
    BOOST_TEST_EQ(value.size(), 0);
    BOOST_TEST_EQ(value.empty(), true);
}

} // namespace testing

int main() {
    testing::test_get_name_by_id();
    testing::test_get_name_by_id_without_linkage();
    testing::test_get_name_by_type();
    testing::test_get_name_by_type_without_linkage();
    testing::test_names_as_array();
    testing::test_names_as_array_without_linkage();
    testing::test_names_as_array_for_empty();

    return boost::report_errors();
}


