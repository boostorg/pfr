// Copyright (c) 2017 Alexandr Poltavsky, Antony Polukhin.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// The Great Type Loophole (C++14)
// Initial implementation by Alexandr Poltavsky, http://alexpolt.github.io
//
// Description: 
//  The Great Type Loophole is a technique that allows to exchange type information with template
//  instantiations. Basically you can assign and read type information during compile time.
//  Here it is used to detect data members of a data type. I described it for the first time in
//  this blog post http://alexpolt.github.io/type-loophole.html .
//
// This technique exploits the http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_active.html#2118
// CWG 2118. Stateful metaprogramming via friend injection
// Note: CWG agreed that such techniques should be ill-formed, although the mechanism for prohibiting them is as yet undetermined.

#ifndef BOOST_PFR_DETAIL_CORE14_LOOPHOLE_HPP
#define BOOST_PFR_DETAIL_CORE14_LOOPHOLE_HPP

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/detail/cast_to_layout_compatible.hpp>
#include <boost/pfr/detail/fields_count.hpp>
#include <boost/pfr/detail/sequence_tuple.hpp>

namespace boost { namespace pfr { namespace detail {

// tag<T,N> generates friend declarations and helps with overload resolution.
// There are two types: one with the auto return type, which is the way we read types later.
// The second one is used in the detection of instantiations without which we'd get multiple
// definitions.

template<typename T, int N>
struct tag {
    friend auto loophole(tag<T,N>);
    constexpr friend int cloophole(tag<T,N>);
};

// The definitions of friend functions.
template<typename T, typename U, int N, bool B>
struct fn_def {
    friend auto loophole(tag<T,N>) { return U{}; }
    constexpr friend int cloophole(tag<T,N>) { return 0; }
};

// This specialization is to avoid multiple definition errors.
template<typename T, typename U, int N>
struct fn_def<T, U, N, true> {};


// This has a templated conversion operator which in turn triggers instantiations.
// Important point, using sizeof seems to be more reliable. Also default template
// arguments are "cached" (I think). To fix that I provide a U template parameter to
// the ins functions which do the detection using constexpr friend functions and SFINAE.
template<typename T, int N>
struct loophole_ubiq {
    template<typename U, int M> static auto ins(...) -> int;
    template<typename U, int M, int = cloophole(tag<T,M>{}) > static auto ins(int) -> char;

    template<typename U, int = sizeof(fn_def<T, U, N, sizeof(ins<U, N>(0)) == sizeof(char)>)>
    constexpr operator U() noexcept;
};


// This is a helper to turn a data structure into a tuple.
template<typename T, typename U>
struct loophole_type_list;

template<typename T, std::size_t... NN>
struct loophole_type_list< T, std::index_sequence<NN...> > {
    using type = sequence_tuple::tuple< decltype(loophole(tag<T, NN>{}))... >;
};


template <class T>
decltype(auto) as_tuple(T&& val) noexcept {
    typedef std::remove_reference_t<T> type;

    using indexes = std::make_index_sequence<fields_count<type>;
    using tuple_type = typename loophole_type_list<type, indexes>::type;

    return cast_to_layout_compatible<tuple_type>(std::forward<T>(val));
}


}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE14_LOOPHOLE_HPP

