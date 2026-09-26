#ifndef BOOST_PFR_DETAIL_FOR_EACH_NAME_HPP
#define BOOST_PFR_DETAIL_FOR_EACH_NAME_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/detail/core_name.hpp>

#if BOOST_PFR_CORE_NAME_ENABLED

#if !defined(BOOST_PFR_INTERFACE_UNIT)
#include <cstddef>
#include <string_view>
#include <type_traits>
#include <utility>
#endif

namespace boost { namespace pfr { namespace detail {

template <class T, std::size_t I, class F>
constexpr void for_each_name_apply(F& func) {
    constexpr std::string_view name = detail::get_name<T, I>();
    if constexpr (std::is_invocable_v<F&, std::string_view, std::integral_constant<std::size_t, I>>) {
        func(name, std::integral_constant<std::size_t, I>{});
    } else {
        func(name);
    }
}

template <class T, class F, std::size_t... I>
constexpr void for_each_name_impl(F& func, std::index_sequence<I...>) {
    (detail::for_each_name_apply<T, I>(func), ...);
}

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_CORE_NAME_ENABLED

#endif // BOOST_PFR_DETAIL_FOR_EACH_NAME_HPP
