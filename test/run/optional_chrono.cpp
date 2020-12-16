// Copyright (c) 2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/core/lightweight_test.hpp>

#include <boost/pfr/core.hpp>

#include <chrono>

#include <optional>

struct struct_with_optional {
    std::optional<std::chrono::seconds> a;
    std::optional<std::chrono::milliseconds> b;
    std::optional<std::chrono::microseconds> c;
    std::optional<std::chrono::nanoseconds> d;
    std::optional<std::chrono::steady_clock::duration> e;
    std::optional<std::chrono::system_clock::duration> f;
};

int main() {
    struct_with_optional val{
        std::chrono::seconds{1},
        std::chrono::seconds{2},
        std::chrono::seconds{3},
        std::chrono::seconds{4},
        std::chrono::seconds{5},
        std::chrono::seconds{6},
    };

    using boost::pfr::get;
    BOOST_TEST(get<0>(val) == std::chrono::seconds{1});
    BOOST_TEST(get<1>(val) == std::chrono::seconds{2});
    BOOST_TEST(get<2>(val) == std::chrono::seconds{3});
    BOOST_TEST(get<3>(val) == std::chrono::seconds{4});
    BOOST_TEST(get<3>(val) > std::chrono::seconds{0});
    BOOST_TEST(get<3>(val) > std::chrono::seconds{0});

    return boost::report_errors();
}

