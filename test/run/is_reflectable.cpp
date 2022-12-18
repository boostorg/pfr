// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/traits.hpp>
#include <type_traits>  // for std::true_type, std::false_type

namespace boost { namespace pfr {
    struct boost_fusion_tag;
    struct boost_json_tag;
}}

struct Reflectable {};
struct Nonrefrectable {};
struct Unknown {};

struct ReflectableBoostFusion {};
struct NonrefrectableBoostFusion {};

struct ReflectableBoostJson {};
struct NonrefrectableBoostJson {};

namespace boost { namespace pfr {
    template<class All> struct is_reflectable<Reflectable, All> : std::true_type {};
    template<class All> struct is_reflectable<Nonrefrectable, All> : std::false_type {};
    template<> struct is_reflectable<ReflectableBoostFusion, boost_fusion_tag> : std::true_type {};
    template<> struct is_reflectable<NonrefrectableBoostFusion, boost_fusion_tag> : std::false_type {};
    template<> struct is_reflectable<ReflectableBoostJson, boost_json_tag> : std::true_type {};
    template<> struct is_reflectable<NonrefrectableBoostJson, boost_json_tag> : std::false_type {};
}}




namespace helpers {
template <class T, class Tag>
constexpr decltype(boost::pfr::is_reflectable<T, Tag>::value) is_reflectability_known(long) {
    return true;
}

template <class T, class Tag>
constexpr bool is_reflectability_known(int) {
    return false;
}
}

template<class T, class Tag>
void assert_reflectable_impl() {
    static_assert(helpers::is_reflectability_known<T, Tag>(1L), "");
    static_assert(boost::pfr::is_reflectable<T, Tag>::value, "");
}

template<class T, class Tag>
void assert_non_reflectable_impl() {
    static_assert(helpers::is_reflectability_known<T, Tag>(1L), "");
    static_assert(!boost::pfr::is_reflectable<T, Tag>::value, "");
}

template<class T, class Tag>
void assert_unknown_impl() {
    static_assert(!helpers::is_reflectability_known<T, Tag>(1L), "");
}

template<class T, class Tag>
void assert_reflectable() {
    assert_reflectable_impl<T, Tag>();
    assert_reflectable_impl<const T, Tag>();
    assert_reflectable_impl<volatile T, Tag>();
    assert_reflectable_impl<const volatile T, Tag>();
}

template<class T, class Tag>
void assert_non_reflectable() {
    assert_non_reflectable_impl<T, Tag>();
    assert_non_reflectable_impl<const T, Tag>();
    assert_non_reflectable_impl<volatile T, Tag>();
    assert_non_reflectable_impl<const volatile T, Tag>();
}

template<class T, class Tag>
void assert_unknown() {
    assert_unknown_impl<T, Tag>();
    assert_unknown_impl<const T, Tag>();
    assert_unknown_impl<volatile T, Tag>();
    assert_unknown_impl<const volatile T, Tag>();
}

int main() {
    {
        using tag = boost::pfr::boost_json_tag;
        assert_reflectable<Reflectable, tag>();
        assert_non_reflectable<Nonrefrectable, tag>();
        assert_unknown<Unknown, tag>();
        assert_unknown<ReflectableBoostFusion, tag>();
        assert_unknown<NonrefrectableBoostFusion, tag>();
        assert_reflectable<ReflectableBoostJson, tag>();
        assert_non_reflectable<NonrefrectableBoostJson, tag>();
    }

    {
        using tag = boost::pfr::boost_fusion_tag;
        assert_reflectable<Reflectable, tag>();
        assert_non_reflectable<Nonrefrectable, tag>();
        assert_unknown<Unknown, tag>();
        assert_reflectable<ReflectableBoostFusion, tag>();
        assert_non_reflectable<NonrefrectableBoostFusion, tag>();
        assert_unknown<ReflectableBoostJson, tag>();
        assert_unknown<NonrefrectableBoostJson, tag>();
    }
}

