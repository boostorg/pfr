#Magic Get

This C++14 library is meant for accessing structure elements by index and providing other std::tuple like methods for user defined POD types.


### Motivating example
```c++
#include <iostream>
#include "magic_get.hpp"

struct my_struct {
    int i;
    char c;
    double d;
};

int main() {
    my_struct s{100, 'H', 3.141593 };
    std::cout << "my_struct has " << flat_tuple_size<my_struct>::value << " fields: "
        << "{ " << flat_get<0>(s) << ", " << flat_get<1>(s)<< ", " << flat_get<2>(s) << " }\n";
}

```

Output:
my_struct has 3 fields: { 100, H, 3.14159 }


### Flattening
All the methods with prefix `flat_` represent a template parameter type as flat structure without static members:

```c++
// Helper structure.
struct my_struct_nested { short a1; int a2; };

// This structure:
struct my_struct {
    int a0;
    static const cvalue = 1000;
    my_struct_nested nested;
    short a3_a4[2];
};

// will be flattened and represented as:
struct my_struct_flat {
    int     a0;
    short   a1;
    int     a2
    short   a3;
    short   a4
};
```
So that
* `flat_get<2>(my_struct{})` will return `my_struct::my_struct_nested::a2` field
* `flat_get<3>(my_struct{})` will return `my_struct::a3_a4[0]` field

Same story with arrays:
```c++
    int i[2][2] = {{10, 11}, {12, 13} };
    assert(flat_get<1>(i) == 11);
```

### API
```c++
/// Returns const reference to a field with index `I` in flattened `T`.
/// Example usage: flat_get<0>(my_structure());
template <std::size_t I, class T>
decltype(auto) flat_get(const T& val) noexcept;


/// Returns reference to a field with index `I` in flattened `T`.
/// Requires: `T` must not have const fields.
/// Example usage: flat_get<0>(my_structure());
template <std::size_t I, class T>
decltype(auto) flat_get(T& val, typename std::enable_if< std::is_trivially_assignable<T, T>::value>::type* = 0);


/// `flat_tuple_element` has a `typedef type-of-a-field-with-index-I-in-flattened-T type;`
/// Example usage: std::vector<  flat_tuple_element<0, my_structure>::type  > v;
template <std::size_t I, class T>
using flat_tuple_element;


/// Type of a field with index `I` in flattened `T`
/// Example usage: std::vector<  flat_tuple_element_t<0, my_structure>  > v;
template <std::size_t I, class T>
using flat_tuple_element_t = typename flat_tuple_element<I, T>::type;


/// `flat_tuple_size` has a member `value` that constins fields count in a flattened `T`.
/// Example usage: std::array<int, flat_tuple_size<my_structure>::value > a;
template <class T>
using flat_tuple_size;


/// `flat_tuple_size_v` is a template variable that constins fields count in a flattened `T`.
/// Example usage: std::array<int, flat_tuple_size_v<my_structure> > a;
template <class T>
constexpr std::size_t flat_tuple_size_v = flat_tuple_size<T>::value;


/// Creates an `std::tuple` from a flattened T.
/// Example usage: 
///     struct my_struct { int i, short s; };
///     my_struct s {10, 11};
///     std::tuple<int, short> t = flat_to_tuple(s);
///     assert(get<0>(t) == 10);
template <class T>
auto flat_make_tuple(const T& val) noexcept;


/// Creates an `std::tuple` with lvalue references to fields of a flattened T.
/// Example usage: 
///     struct my_struct { int i, short s; };
///     my_struct s;
///     flat_tie(s) = std::tuple<int, short>{10, 11};
///     assert(s.s == 11);
template <class T>
auto flat_tie(T& val, typename std::enable_if< std::is_trivially_assignable<T, T>::value>::type* = 0 ) noexcept;
```

### Requirements and Limitations

* C++14 compatible compiler (GCC-5.0+, Clang, ...)
* T must be POD and must not contain references nor bitfields
* T must not contain pointers to user defined types
* Enums will be returned as their underlying type
* Static variables are ignored


### License

Distributed under the [Boost Software License, Version 1.0](http://boost.org/LICENSE_1_0.txt).
