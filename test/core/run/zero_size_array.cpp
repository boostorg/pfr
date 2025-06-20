// Copyright (c) 2025-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Test that PFR works with GCCs "Arrays of Length Zero" extension

#include <boost/pfr/core.hpp>

#include <tuple>

#if defined(__GNUC__) && (BOOST_PFR_USE_LOOPHOLE || BOOST_PFR_USE_CPP17)
struct zero_array {
    char data[0];
};

struct aggr {
    zero_array a;
};

static_assert(sizeof(zero_array) == 0);
static_assert(sizeof(aggr) == 0);

int main() {
    aggr a;
    const auto result = boost::pfr::structure_tie(a);
    static_assert(std::tuple_size<decltype(result)>::value == 1);
    return sizeof(std::get<0>(result).data);
}
#else
int main() {}
#endif

