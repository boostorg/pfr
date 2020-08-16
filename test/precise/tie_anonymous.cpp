// Copyright (c) 2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/core/lightweight_test.hpp>

#include <boost/pfr/precise/ops.hpp>

#include <string>

#if defined(__has_include)
#   if __has_include(<optional>)
#       include <optional>
#   endif
#endif

namespace some {
    struct struct1{ int i; };
    struct struct2{ int i; };
}

namespace testing {

namespace {

#ifdef __cpp_lib_optional
struct anon_with_optional {
    std::string a;
    std::optional<some::struct1> b;
    std::optional<some::struct2> c;

};

struct other_anon_with_optional {
    std::string a;
    int b;
    std::optional<anon_with_optional> c;
    std::optional<some::struct2> d;

};
#endif

struct other_anon {
    int data;
};

struct anon {
    other_anon a;
    other_anon b;
};

void test_in_anon_ns() {
    anon x{{1}, {2}};
    
    auto v = boost::pfr::structure_tie(x);
    
    BOOST_TEST_EQ(std::get<0>(v).data, 1);
    BOOST_TEST_EQ(std::get<1>(v).data, 2);

#ifdef __cpp_lib_optional
    other_anon_with_optional opt{"test", {}, {}, {}};
    auto opt_val = boost::pfr::structure_tie(opt);
    BOOST_TEST_EQ(std::get<0>(opt_val), "test");
#endif
}

} // anonymous namespace

void test_in_non_non_ns() {
    anon x{{1}, {2}};
    
    auto v = boost::pfr::structure_tie(x);
    
    BOOST_TEST_EQ(std::get<0>(v).data, 1);
    BOOST_TEST_EQ(std::get<1>(v).data, 2);

#ifdef __cpp_lib_optional
    other_anon_with_optional opt{"test again", {}, {}, {}};
    auto opt_val = boost::pfr::structure_tie(opt);
    BOOST_TEST_EQ(std::get<0>(opt_val), "test again");
#endif
}

} // namespace testing

int main() {
    testing::test_in_anon_ns();
    testing::test_in_non_non_ns();

    return boost::report_errors();
}


