// Copyright 2016-2017 Antony Polukhin

// Distributed under the Boost Software License, Version 1.0.
// (See the accompanying file LICENSE_1_0.txt
// or a copy at <http://www.boost.org/LICENSE_1_0.txt>.)

#include <cassert>


//[pfr_intro
#include <boost/pfr.hpp>

struct nested_t { char c; };
struct foo_t { int i; nested_t nested; };


static_assert(std::is_same<
    boost::pfr::flat_tuple_element_t<1, foo_t>, // Flat reflection.
    char    // `char`, not `nested_t`!
>::value, "");


// Requires C++17 or Loophole enabled:
//<-
#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE //->
static_assert(std::is_same<
    boost::pfr::tuple_element_t<1, foo_t>,      // Precise reflection.
    nested_t
>::value, ""); //<-
#endif //->
//] [/pfr_intro]


//[pfr_example_get
/*`
    The following example shows how to access structure fields by index using [funcref boost::pfr::get].

    Let's define some structure:
*/
#include <boost/pfr/precise/core.hpp>

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
#include <boost/pfr/precise/core.hpp>

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



//[pfr_example_flattening
/*`
[warning All the functions and metafunctions in Boost.PFR that start with `flat_` represent template parameter type as flat structure without static members! ]

Take a look at the `struct my_struct`:
*/
#include <boost/pfr/flat/core.hpp>

struct my_struct_nested { short a1; int a2; };

struct my_struct {
    int a0;
    static const int cvalue = 1000;
    my_struct_nested nested;
    short a3_a4[2];
};

/*` It will be flattened and represented as: */

struct my_struct_flat {
    int     a0;
    short   a1;
    int     a2;
    short   a3;
    short   a4;
};
//] [/pfr_example_flattening]

void example_get() {
//[pfr_example_flattening_2
/*`
It means, that:
*/
boost::pfr::flat_get<2>(my_struct{});   // ... will return `my_struct::my_struct_nested::a2` field.
boost::pfr::flat_get<3>(my_struct{});   // ... will return `my_struct::a3_a4[0]` field.

/*` Exactly the same story with arrays: */

int i[2][2] = {{10, 11}, {12, 13} };
const int& r = boost::pfr::flat_get<1>(i);
assert(r == 11);
//] [/pfr_example_flattening_2]
(void)r;
}


int main() {
    example_get();
}
