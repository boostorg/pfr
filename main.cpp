// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/type_index.hpp>
#include <tuple>
#include <sstream>
#include "magic_get.hpp"

template <std::size_t I, class T>
void print(T& f) {
    std::cout << flat_get<I>(f) << "\t\t" 
        << boost::typeindex::type_id< flat_tuple_element_t<I, T> >()
        << std::endl;
}


struct make_my_life_harder { int a0; short a1; };
struct make_my_life_even_more_harder { unsigned int b0; unsigned short b1; make_my_life_harder cr;};
struct foo {
    unsigned char v0;
    unsigned int v1;
    unsigned short v2;
    unsigned long long v3;
    unsigned char v4and5[2];
    int v6;
    std::size_t v7;
    int* v8;
    const void* v9;
    int const**const volatile**volatile** v10;
    const double v11;
    make_my_life_harder v12and13;
    make_my_life_even_more_harder v14and15andv16and17;
};

void test_print() {
    foo f {
        'A', 11, 12, 13, {'B', 'C'}, 16, 17, 0, 0, 0, 30.1
        , {18, 19}
        , {20, 21, {22, 23}}
    };
    print<0>(f);  print<1>(f);  print<2>(f);
    print<3>(f);  print<4>(f);  print<5>(f);
    print<6>(f);  print<7>(f);  print<8>(f);
    print<9>(f);  print<10>(f); print<11>(f);
    print<12>(f); print<13>(f); print<14>(f);
    print<15>(f); print<16>(f); print<17>(f);
    static_assert(flat_tuple_size_v<foo> == 18, "failed tuple size check");
    
    int a[] = {0, 1, 2, 3};
    std::cout << '\n' << flat_get<1>(a) << std::endl;
    
    int b[2][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}};
    std::cout << flat_get<4>(b) << std::endl;
     
    int i = 777;
    std::cout << flat_get<0>(i) << std::endl;
}

#include <cassert>
void test_runtime(const foo& f) {
    assert( flat_get<0>(f) == f.v0);
    assert( flat_get<1>(f) == f.v1);
    assert( flat_get<2>(f) == f.v2);
    assert( flat_get<3>(f) == f.v3);
    assert( flat_get<4>(f) == f.v4and5[0]);
    assert( flat_get<5>(f) == f.v4and5[1]);
    assert( flat_get<6>(f) == f.v6);
    assert( flat_get<7>(f) == f.v7);
    assert( flat_get<8>(f) == f.v8);
    assert( flat_get<9>(f) == f.v9);
    assert( flat_get<10>(f) == f.v10);
    assert( flat_get<11>(f) < f.v11 + 0.001); assert( flat_get<11>(f) > f.v11 - 0.001);
    assert( flat_get<12>(f) == f.v12and13.a0);
    assert( flat_get<13>(f) == f.v12and13.a1);
    assert( flat_get<14>(f) == f.v14and15andv16and17.b0);
    assert( flat_get<15>(f) == f.v14and15andv16and17.b1);
    assert( flat_get<16>(f) == f.v14and15andv16and17.cr.a0);
    assert( flat_get<17>(f) == f.v14and15andv16and17.cr.a1);
}

template <class T>
void test_compiletime() {
    constexpr T f{};
    static_assert(flat_tuple_size_v<foo> == 18, "failed tuple size check");
    static_assert( std::is_same< decltype(flat_get<0>(f)), decltype((f.v0))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<1>(f)), decltype((f.v1))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<2>(f)), decltype((f.v2))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<3>(f)), decltype((f.v3))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<4>(f)), decltype((f.v4and5[0]))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<5>(f)), decltype((f.v4and5[1]))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<6>(f)), decltype((f.v6))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<7>(f)), decltype((f.v7))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<8>(f)), decltype((f.v8))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<9>(f)), decltype((f.v9))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<10>(f)), decltype((f.v10))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<11>(f)), decltype((f.v11))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<12>(f)), decltype((f.v12and13.a0))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<13>(f)), decltype((f.v12and13.a1))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<14>(f)), decltype((f.v14and15andv16and17.b0))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<15>(f)), decltype((f.v14and15andv16and17.b1))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<16>(f)), decltype((f.v14and15andv16and17.cr.a0))>::value, "types missmatch");
    static_assert( std::is_same< decltype(flat_get<17>(f)), decltype((f.v14and15andv16and17.cr.a1))>::value, "types missmatch");
}

template <class T>
constexpr void test_compiletime_array() {
    {
        constexpr T f[20] = {0};
        static_assert(flat_tuple_size_v<decltype(f)> == 20, "failed tuple size check for array");
        static_assert( std::is_same< decltype(flat_get<0>(f)), T const&>::value, "types missmatch");
        static_assert( std::is_same< decltype(flat_get<19>(f)), T const&>::value, "types missmatch");
    }
    {
        constexpr T f[2][10] = {0};
        static_assert(flat_tuple_size_v<decltype(f)> == 20, "failed tuple size check for array");
        static_assert( std::is_same< decltype(flat_get<0>(f)), T const&>::value, "types missmatch");
        static_assert( std::is_same< decltype(flat_get<19>(f)), T const&>::value, "types missmatch");
    }
    {
        constexpr T f[2][5][2] = {0};
        static_assert(flat_tuple_size_v<decltype(f)> == 20, "failed tuple size check for array");
        static_assert( std::is_same< decltype(flat_get<0>(f)), T const&>::value, "types missmatch");
        static_assert( std::is_same< decltype(flat_get<19>(f)), T const&>::value, "types missmatch");
    }
}

//#define TEST_REF
#ifdef TEST_REF

struct with_ref {
    int i;
    int& ref;
};
void test() {
    int ref_me = 1234567890;
    with_ref f { 987654321, ref_me };
    print<0>(f);  print<1>(f);
}
#endif

void test_with_enums() {
    enum class my_enum: unsigned {
        VALUE1 = 17, VALUE2, VALUE3
    };
    struct my_struct { my_enum e; int i; short s; };
    my_struct s {my_enum::VALUE1, 10, 11};
    std::tuple<unsigned, int, short> t = flat_make_tuple(s);
    assert(std::get<0>(t) == 17);
    assert(std::get<1>(t) == 10);
    assert(std::get<2>(t) == 11);
    
    flat_get<1>(s) = 101;
    assert(flat_get<1>(s) == 101);
    flat_get<2>(s) = 111;
    assert(flat_get<2>(s) == 111);
    
    assert(flat_tie(s) == flat_tie(s));
    assert(flat_tie(s) == flat_make_tuple(s));
    assert(flat_tie(s) != t);
    flat_tie(s) = t;
    assert(flat_get<0>(s) == 17);
    assert(flat_get<1>(s) == 10);
    assert(flat_get<2>(s) == 11);
    
    static_assert(std::is_same<
        int, flat_tuple_element_t<1, my_struct>
    >::value, "");
    
    static_assert(std::is_same<
        short, flat_tuple_element_t<2, my_struct>
    >::value, "");
    
    
    static_assert(std::is_same<
        const int, flat_tuple_element_t<1, const my_struct>
    >::value, "");
    
    static_assert(std::is_same<
        volatile short, flat_tuple_element_t<2, volatile my_struct>
    >::value, "");
    
    static_assert(std::is_same<
        const volatile short, flat_tuple_element_t<2, const volatile my_struct>
    >::value, "");

    static_assert(
        3 == flat_tuple_size_v<const volatile my_struct>,
        ""
    );
}

void test_comparable_struct() {
    struct comparable_struct {
        int i; short s; char data[50]; bool bl; int a,b,c,d,e,f;
    };
    using namespace pod_ops;

    comparable_struct s1 {0, 1, "Hello", false, 6,7,8,9,10,11};
    comparable_struct s2 = s1;
    comparable_struct s3 {0, 1, "Hello", false, 6,7,8,9,10,11111};
    assert(s1 == s2);
    assert(s1 <= s2);
    assert(s1 >= s2);
    assert(!(s1 != s2));
    assert(!(s1 == s3));
    assert(s1 != s3);
    assert(s1 < s3);
    assert(s3 > s2);
    assert(s1 <= s3);
    assert(s3 >= s2);

    std::cout << s1 << std::endl;

    comparable_struct s4;
    std::stringstream ss;
    ss.exceptions ( std::ios::failbit);
    ss << s1;
    ss >> s4;
    std::cout << s4 << std::endl;
    assert(s1 == s4);
    int i = 1, j = 2;
    assert(i != j);
}

int main() {
    test_compiletime<foo>();
    test_compiletime_array<int>();
    test_compiletime_array<void*>();
    test_compiletime_array<const void*>();
    test_compiletime_array<char>();
    test_compiletime_array<char const volatile*>();
    {
        foo f {
            'A', 11, 12, 13, {'B', 'C'}, 16, 17, 0, 0, 0, 30.1
            , {18, 19}
            , {20, 21, {22, 23}}
        };
        test_runtime(f);
    }
    {
        foo f {
            '\0', 12437, 1212, 13, {'1', '7'}, 163, 1723, 0, 0, 0, 3000.1
            , {-18, -19}
            , {656565, 65535, {-22, -23}}
        };
        test_runtime(f);
    }

    test_with_enums();
    test_comparable_struct();

    test_print();
}

