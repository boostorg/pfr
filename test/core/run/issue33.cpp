// Copyright (c) 2018-2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Test case for https://github.com/boostorg/pfr/issues/33

#include <iostream>
#include <memory>
#include <vector>
#include <boost/pfr.hpp>
#include <boost/core/lightweight_test.hpp>

struct TestStruct {
    std::vector<std::unique_ptr<int>> vec;
};


int main() {
    TestStruct temp;
    temp.vec.emplace_back();

// FIXME: https://github.com/boostorg/pfr/issues/131
#if defined(__clang__) && __cplusplus >= 202002L

# if BOOST_PFR_USE_LOOPHOLE == 0 && BOOST_PFR_USE_CPP17 == 0
#   error This test should fail on classic engine
#endif

#else
    boost::pfr::for_each_field(temp, [](const auto& value) {
        BOOST_TEST_EQ(value.size(), 1);
    });
#endif

    return boost::report_errors();
}
