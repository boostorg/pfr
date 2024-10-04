// Copyright (c) 2023-2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/detail/fields_count.hpp>

int main() {
    return static_cast<int>(boost::pfr::detail::fields_count<BOOST_PFR_RUN_TEST_ON>());
}
