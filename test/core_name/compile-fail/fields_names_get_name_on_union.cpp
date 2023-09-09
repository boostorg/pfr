// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#include <boost/pfr/core_name.hpp>

union test_union {
    const char* c;
    int i;
};

int main() {
    (void)boost::pfr::get_name<0, test_union>(); // Must be a compile time error
}


