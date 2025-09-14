// Copyright (c) 2025-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Test from https://github.com/boostorg/pfr/issues/173

#include <boost/pfr/core.hpp>
#include <boost/pfr/core_name.hpp>
#include <boost/pfr/traits.hpp>

#include <string_view>

struct LongPointerTest {
    long* OwningThread;
};

struct VoidPointerTest {
    void* OwningThread;
};

int main() {
    static_assert(boost::pfr::get_name<0, LongPointerTest>() == "OwningThread");

    // No known workaround for MSVC
#if !defined(_MSC_VER) || _MSC_VER > 1944
    static_assert(boost::pfr::get_name<0, VoidPointerTest>() == "OwningThread");
#endif
}

