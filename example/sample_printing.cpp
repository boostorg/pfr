// Copyright 2016-2020 Antony Polukhin

// Distributed under the Boost Software License, Version 1.0.
// (See the accompanying file LICENSE_1_0.txt
// or a copy at <http://www.boost.org/LICENSE_1_0.txt>.)

//[pfr_sample_printing
/*`
    The following example shows how to customize printing and write your own testing helper for structures:
*/
#include <boost/pfr.hpp>
#include <iostream>

namespace my_testing {

template <class T>
void print_each(std::ostream& out, const T& v) { out << v; }
void print_each(std::ostream& out, std::uint8_t v) { out << static_cast<unsigned>(v); }
void print_each(std::ostream& out, std::int8_t v) { out << static_cast<int>(v); }

template <class T>
void print(std::ostream& out, const T& value) {
    const char* sep = "";

    boost::pfr::for_each_field(value, [&](const auto& v) {
        out << std::exchange(sep, ", ");
        print_each(out, v);
    });
}

/// Usage:
///     struct foo {std::uint8_t a, b;};
///     foo get_foo();
///     ...
///     test_eq(foo{42, 22}, get_foo());
///
/// Output:
///     42, 22 != 42, 24
template <class T>
void test_eq(const T& x, const T& y) {
    using namespace boost::pfr::ops;
    if (x == y) return;

    print(std::cerr, x);
    std::cerr << " != ";
    print(std::cerr, y);
}

} // namespace my_testing
//] [/pfr_sample_printing]


#include <sstream>

int main() {
    struct foo {std::uint8_t a, b;};
    
    std::ostringstream oss;
    my_testing::print(oss, foo{42, 22});
    
    if (oss.str() != "42, 22") {
        my_testing::print(oss, foo{42, 22});
        return 1;
    }
    
    return 0;
}
