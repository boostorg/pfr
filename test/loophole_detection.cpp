// Copyright (c) 2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Detection of type loophole.
// Inspired by the blog post: http://alexpolt.github.io/type-loophole.html

#include <type_traits>

template <unsigned> struct tag{};

template <class T, unsigned N>
struct loophole_t {
  friend auto loophole(tag<N>) { return T{}; };
};

auto loophole(tag<0>);

int main() {
   sizeof(loophole_t<unsigned, 0>);
   static_assert( std::is_same<unsigned, decltype( loophole(tag<0>{}) ) >::value, "");
}
