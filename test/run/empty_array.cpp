// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core.hpp>
#include <boost/core/lightweight_test.hpp>

int main() {
    using type = int[0];
    static_assert(boost::pfr::tuple_size<type>::value == 0, "");

    // MSVC fails to create empty array
#if !defined(_MSC_VER)
    std::size_t control = 0;
    type v = {};
    boost::pfr::for_each_field(v, [&control](auto&&) {
        ++control;
    });
    BOOST_TEST_EQ(control, 0);
#endif
    return boost::report_errors();
}

