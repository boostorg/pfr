// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/pfr/traits.hpp>
#include <type_traits>  // for std::true_type, std::false_type and std::is_aggregate

namespace boost { namespace pfr {
    struct boost_fusion_tag;
    struct boost_json_tag;
}}

struct Aggregate {};
using Nonaggregate = int;

#if defined(__cpp_lib_is_aggregate)
static_assert(std::is_aggregate<Aggregate>::value && !std::is_aggregate<Nonaggregate>::value, "");
#endif

using Reflectable = short;
struct Nonrefrectable {};

using ReflectableBoostFusion = short;
struct NonrefrectableBoostFusion {};

using ReflectableBoostJson = short;
struct NonrefrectableBoostJson {};

namespace boost { namespace pfr {
    template<class All> struct is_reflectable<Reflectable, All> : std::true_type {};
    template<class All> struct is_reflectable<Nonrefrectable, All> : std::false_type {};
    template<> struct is_reflectable<ReflectableBoostFusion, boost_fusion_tag> : std::true_type {};
    template<> struct is_reflectable<NonrefrectableBoostFusion, boost_fusion_tag> : std::false_type {};
    template<> struct is_reflectable<ReflectableBoostJson, boost_json_tag> : std::true_type {};
    template<> struct is_reflectable<NonrefrectableBoostJson, boost_json_tag> : std::false_type {};
}}


#if BOOST_PFR_ENABLE_IMPLICIT_REFLECTION
template<class T, class Tag>
void assert_reflectable() {
    static_assert(boost::pfr::is_implicitly_reflectable_v<T, Tag>, "");
    static_assert(boost::pfr::is_implicitly_reflectable_v<const T, Tag>, "");
    static_assert(boost::pfr::is_implicitly_reflectable_v<volatile T, Tag>, "");
    static_assert(boost::pfr::is_implicitly_reflectable_v<const volatile T, Tag>, "");
}

template<class T, class Tag>
void assert_non_reflectable() {
    static_assert(!boost::pfr::is_implicitly_reflectable_v<T, Tag>, "");
    static_assert(!boost::pfr::is_implicitly_reflectable_v<const T, Tag>, "");
    static_assert(!boost::pfr::is_implicitly_reflectable_v<volatile T, Tag>, "");
    static_assert(!boost::pfr::is_implicitly_reflectable_v<const volatile T, Tag>, "");
}
#endif  // #if BOOST_PFR_ENABLE_IMPLICIT_REFLECTION

int main() {
#if BOOST_PFR_ENABLE_IMPLICIT_REFLECTION
    std::cout << "Implicit reflection is available in this platform.." << std::endl;
    {
        using tag = boost::pfr::boost_json_tag;
        assert_reflectable<Aggregate, tag>();
        assert_non_reflectable<Nonaggregate, tag>();
        assert_reflectable<Reflectable, tag>();
        assert_non_reflectable<Nonrefrectable, tag>();
        assert_reflectable<ReflectableBoostJson, tag>();
        assert_non_reflectable<NonrefrectableBoostJson, tag>();
    }

    {
        using tag = boost::pfr::boost_fusion_tag;
        assert_reflectable<Aggregate, tag>();
        assert_non_reflectable<Nonaggregate, tag>();
        assert_reflectable<Reflectable, tag>();
        assert_non_reflectable<Nonrefrectable, tag>();
        assert_reflectable<ReflectableBoostFusion, tag>();
        assert_non_reflectable<NonrefrectableBoostFusion, tag>();
    }
#endif  // #if BOOST_PFR_ENABLE_IMPLICIT_REFLECTION
}

