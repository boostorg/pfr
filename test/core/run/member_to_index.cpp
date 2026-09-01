// Copyright (c) 2025-2026 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/index_of.hpp>

#include <limits>
#include <string>
#include <vector>

struct Sample {
	std::string x;
	std::vector<int> y;
	std::string z;
};

struct TrivialSample {
	int x;
	short y;
	bool z;
};

template <class T>
int test_if_constexpr_default_constructible(std::false_type) {
    return 0;
}

template <class T>
int test_if_constexpr_default_constructible(std::true_type) {
    if (boost::pfr::index_of(&T::x) != 0) return 31;
    if (boost::pfr::index_of(&T::y) != 1) return 32;
    if (boost::pfr::index_of(&T::z) != 2) return 33;
    return 0;
}

int main() {
#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_CPP26
    static_assert(boost::pfr::index_of(&TrivialSample::x) == 0);
    static_assert(boost::pfr::index_of(&TrivialSample::y) == 1);
    static_assert(boost::pfr::index_of(&TrivialSample::z) == 2);
#endif

    if (boost::pfr::index_of(&Sample::x, {}) != 0) return 1;
    if (boost::pfr::index_of(&Sample::y, {}) != 1) return 2;
    if (boost::pfr::index_of(&Sample::z, {}) != 2) return 3;

    decltype(&Sample::x) mem_ptr = nullptr;
    if (boost::pfr::index_of(mem_ptr, {}) != (std::numeric_limits<std::size_t>::max)()) return 4;

    if (boost::pfr::index_of(&TrivialSample::x) != 0) return 11;
    if (boost::pfr::index_of(&TrivialSample::y) != 1) return 12;
    if (boost::pfr::index_of(&TrivialSample::z) != 2) return 13;

    return test_if_constexpr_default_constructible<Sample>(
        boost::pfr::is_constexpr_default_constructible<Sample>{}
    );
}
