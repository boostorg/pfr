// Copyright 2016-2020 Antony Polukhin

// Distributed under the Boost Software License, Version 1.0.
// (See the accompanying file LICENSE_1_0.txt
// or a copy at <http://www.boost.org/LICENSE_1_0.txt>.)

#include <cassert>


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
void print(const T& value) {
    const char* sep = "";

    boost::pfr::for_each_field(value, [&](const auto& v) {
        std::cerr << std::exchange(sep, ", ");
        print_each(std::cerr, v);
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

    print(x);
    std::cerr << " != ";
    print(y);
}

} // namespace my_testing
//] [/pfr_sample_printing]


//[pfr_example_get
/*`
    The following example shows how to access structure fields by index using [funcref boost::pfr::get].

    Let's define some structure:
*/
#include <boost/pfr/core.hpp>

struct foo {            // defining structure
    int some_integer;
    char c;
};

/*`
    We can access fields of that structure by index:
*/
foo f {777, '!'};
auto& r1 = boost::pfr::get<0>(f); // accessing field with index 0, returns reference to `foo::some_integer`
auto& r2 = boost::pfr::get<1>(f); // accessing field with index 1, returns reference to `foo::c`
//] [/pfr_example_get]

//[pfr_example_tuple_size
/*`
    The following example shows how to count fields using [classref boost::pfr::tuple_size].
*/
#include <boost/pfr/core.hpp>

struct foo2 {            // defining structure
    int some_integer;
    char c;
    short some_other_field;
};


static_assert(
    boost::pfr::tuple_size<foo2>::value        // returns total count of fields in `foo2`
    == 3, ""
);

static_assert(
    boost::pfr::tuple_size<int[100]>::value    // works with arrays too!
    == 100, ""
);
//] [/pfr_example_tuple_size]


struct foo_printing_test {std::uint8_t a, b;};
foo_printing_test get_foo_printing_test() { return foo_printing_test{42, 24}; }

int main() {
    my_testing::test_eq(
        foo_printing_test{42, 22},
        get_foo_printing_test()
    );
}
