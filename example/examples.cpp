// Copyright 2016 Antony Polukhin

// Distributed under the Boost Software License, Version 1.0.
// (See the accompanying file LICENSE_1_0.txt
// or a copy at <http://www.boost.org/LICENSE_1_0.txt>.)

#include <cassert>

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


#include <iostream>
#include <boost/type_index.hpp>

namespace quick_examples_ns {

//[pfr_quick_examples_structures
struct foo {
    int integer;
    double real;
    
    void operator +=(int v) {
        integer += v * 10;
        real += v * 100;
    }
};

struct bar {
    char character;
    foo f;
};

bar var{'A', {777, 3.141593}};
//]
    
inline std::ostream& operator<<(std::ostream& os, const bar& b) {
    return os << '{' << b.character << ", {" << b.f.integer << ", " << b.f.real << "}}";
}

void test_examples() {
  {
    bar var{'A', {777, 3.141593}};
    
//[pfr_quick_examples_flat_for_each
    // incrementing each field on 1:
    boost::pfr::flat_for_each_field(var, [](auto& field) {
        field += 1;
    });
//]
    
    std::cout << "flat_for_each_field outputs:\n" << var << '\n';
  }
    
  {  
    bar var{'A', {777, 3.141593}};
    
//[pfr_quick_examples_for_each    
    // incrementing first field on 1 and calling foo::operator+= for second field:
    boost::pfr::for_each_field(var, [](auto& field) {
        field += 1;
    });
//]
    
    std::cout << "flat_for_each_field outputs:\n" << var << '\n';
  }



  
  {
    bar var{'A', {777, 3.141593}};
    
//[pfr_quick_examples_flat_for_each_idx  
    boost::pfr::flat_for_each_field(var, [](const auto& field, std::size_t idx) {
        std::cout << idx << ": " << boost::typeindex::type_id_runtime(field) << '\n';
    });
//]
  }
    
  {
    bar var{'A', {777, 3.141593}};

//[pfr_quick_examples_for_each_idx  
    boost::pfr::for_each_field(var, [](const auto& field, std::size_t idx) {
        std::cout << idx << ": " << boost::typeindex::type_id_runtime(field) << '\n';
    });
//]
  }


  {
//[pfr_quick_examples_tuple_size
    std::cout << "tuple_size: " << boost::pfr::tuple_size<bar>::value << '\n';
//]
  }
    
  {    
//[pfr_quick_examples_flat_tuple_size
    std::cout << "flat_tuple_size: " << boost::pfr::flat_tuple_size<bar>::value << '\n';
//]
  }

#if __cplusplus >= 201606L /* Oulu meeting, not the exact value */
  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_get_1
    boost::pfr::get<1>(var) = foo{1, 2}; // C++17 is required
//]
    std::cout << "boost::pfr::get<1>(var) outputs:\n" << var << '\n';
  }
#endif

  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_flat_get_1
    boost::pfr::flat_get<1>(var) = 1;
//]
    std::cout << "boost::pfr::flat_get<1>(var) outputs:\n" << var << '\n';
  }
  
  
  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_get_2
    boost::pfr::get<1>(var.f) = 42.01;
//]
    std::cout << "boost::pfr::get<1>(var.f) outputs:\n" << var << '\n';
  }

  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_flat_get_2
    boost::pfr::flat_get<1>(var.f) = 42.01;
//]
    std::cout << "boost::pfr::flat_get<1>(var.f) outputs:\n" << var << '\n';
  }
}

} // namespace for_each_field_ex

int main() {
    example_get();
    quick_examples_ns::test_examples();
}
