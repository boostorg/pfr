// Copyright (c) 2020-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core.hpp>

#include <memory>

#include <boost/core/lightweight_test.hpp>

struct unique_ptrs {
    std::unique_ptr<int> p1;
    std::unique_ptr<int> p2;
};

void test_get_rvalue() {
    unique_ptrs x {
        std::make_unique<int>(42),
        std::make_unique<int>(43),
    };

    // Some _MSC_VER are broken:
    // boost/pfr/detail/fields_count.hpp(469): error C2338: static_assert failed:
    // '====================> Boost.PFR: If there's no other failed static
    // asserts then something went wrong. Please report this issue to the github
    // along with the structure you're reflecting.'
    //
    // No known workaround
#if !defined(_MSC_VER) || _MSC_VER != 1944 || !(BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE)
    auto p = boost::pfr::get<0>(std::move(x));
    BOOST_TEST_EQ(*p, 42);
#endif
}

int main() {
    test_get_rvalue();

    return boost::report_errors();
}
