// Copyright (c) 2017 Antony Polukhin.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_FLATTEN_TUPLE_RECURSIVELY_HPP
#define BOOST_PFR_DETAIL_FLATTEN_TUPLE_RECURSIVELY_HPP

#include <boost/pfr/detail/config.hpp>

#include <type_traits>
#include <utility>

#include <boost/pfr/detail/sequence_tuple.hpp>

namespace boost { namespace pfr { namespace detail {

// Forward declarations:
template <class T> auto flatten_tuple_recursively(T&& val) noexcept;
template <class T> auto tie_as_tuple(T&& val) noexcept;

template <class T>
auto tie_or_value(T&& val, std::enable_if_t<std::is_class< std::remove_reference_t<T> >::value>* = 0) noexcept {
    return flatten_tuple_recursively(
        tie_as_tuple(std::forward<T>(val))
    );
}

template <class T>
decltype(auto) tie_or_value(T&& val, std::enable_if_t<!std::is_class< std::remove_reference_t<T> >::value && !std::is_array< std::remove_reference_t<T> >::value>* = 0) noexcept {
    return std::forward<T>(val);
}

template <class T, std::size_t... I>
auto flatten_tuple_recursively_impl(T&& tup, std::index_sequence<I...> ) noexcept {
    return sequence_tuple::tuple<
        decltype(tie_or_value(sequence_tuple::get<I>(std::forward<T>(tup))))...
    >{tie_or_value(sequence_tuple::get<I>(std::forward<T>(tup)))...};
}

template <class T>
auto flatten_tuple_recursively(T&& tup) noexcept {
    using indexes = std::make_index_sequence<T::size_v>;
    return flatten_tuple_recursively_impl(std::forward<T>(tup), indexes{});
}

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_FLATTEN_TUPLE_RECURSIVELY_HPP

