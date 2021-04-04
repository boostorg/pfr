// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <utility>

struct Point { int x, y; };

int main()
{
    const auto [x, y] = Point{};
    (void)x; (void)y;
}
