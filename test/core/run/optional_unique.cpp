// Copyright (c) 2025-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Test from https://github.com/boostorg/pfr/issues/110

#include <memory>
#include <optional>

#include <boost/pfr/core.hpp>

struct optional_linked_list {
	int value;
	std::optional<std::unique_ptr<optional_linked_list>> next;
};

int main() {
    static_assert(boost::pfr::tuple_size_v<optional_linked_list> == 2);
}

