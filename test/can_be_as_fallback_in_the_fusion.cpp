// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <type_traits>
#include <boost/pfr/traits.hpp>

struct Aggregate {};
using NonAggregate = int;

namespace boost { namespace pfr {
    struct boost_fusion_tag;
}}

template<class T, class E=void>
struct tag_of_fallback : std::false_type {
};

template<class T>
struct tag_of_fallback<T, std::enable_if_t<std::is_same<T,T>::value>>
{
    using type = std::conditional_t<
        boost::pfr::is_implicitly_reflectable<T, boost::pfr::boost_fusion_tag>::value
      , std::true_type
      , std::false_type
    >;
};

static_assert(tag_of_fallback<Aggregate>::type{} == true, "");
static_assert(tag_of_fallback<NonAggregate>::type{} == false, "");

int main() { }
