// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <type_traits>

struct Aggregate {};
using NonAggregate = int;

template<class T>
struct is_implicitly_reflectable : std::false_type
{};

template<>
struct is_implicitly_reflectable<Aggregate> : std::true_type
{};

template<class T, class E=void>
struct tag_of_fallback {
    using type = int; // unknown
};

template<class T>
struct tag_of_fallback<T, std::enable_if_t<std::is_same<T,T>::value>>
{
    using type = std::conditional_t<
        is_implicitly_reflectable<T>::value
      , std::true_type
      , std::false_type
    >;
};

static_assert(tag_of_fallback<Aggregate>::type::value == true, "");
static_assert(tag_of_fallback<NonAggregate>::type::value == false, "");

int main() { }
