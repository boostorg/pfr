// Copyright (c) 2025-2026 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core.hpp>

#include <cassert>
#include <string>
#include <vector>

struct Sample {
	std::string x;
	std::vector<int> y;
	std::string z;
};

int main() {
#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_CPP26
    static_assert(boost::pfr::index_of(&Sample::x) == 0);
    static_assert(boost::pfr::index_of(&Sample::y) == 1);
    static_assert(boost::pfr::index_of(&Sample::z) == 2);
#else
    assert(boost::pfr::index_of(&Sample::x) == 0);
    assert(boost::pfr::index_of(&Sample::y) == 1);
    assert(boost::pfr::index_of(&Sample::z) == 2);
#endif
}
