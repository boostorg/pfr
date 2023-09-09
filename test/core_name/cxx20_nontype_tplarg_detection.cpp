// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

template <auto p>
class X {};

template <class T>
struct Store
{
    T v;
};

template <class T>
Store(T) -> Store<T>;

struct S
{
    int m;
} s;

X<Store{&s.m}> x4;

int main() {}


