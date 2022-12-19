// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/traits.hpp>

struct NotView {
  int first;
  int second;
};

int main() {
    static_assert(!boost::pfr::is_view_v<NotView>, "");
    //static_assert(boost::pfr::is_view_v<View>, "");
}

