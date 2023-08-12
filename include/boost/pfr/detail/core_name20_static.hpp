// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#ifndef BOOST_PFR_DETAIL_CORE_NAME20_STATIC_HPP
#define BOOST_PFR_DETAIL_CORE_NAME20_STATIC_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>
#include <boost/pfr/detail/core.hpp>
#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/detail/make_integer_sequence.hpp>
#include <boost/pfr/detail/fields_count.hpp>
#include <type_traits>
#include <string_view>
#include <array>
#include <algorithm> // for std::ranges::copy

namespace boost { namespace pfr { namespace detail {

// TODO: move it outside
template <class... Args>
constexpr auto make_sequence_tuple(Args... args) noexcept {
    return sequence_tuple::tuple<Args...>{ args... };
}

template <auto& ptr> 
consteval auto name_of_field_impl() noexcept {
#ifdef _MSC_VER
    constexpr std::string_view sv = __FUNCSIG__;
    constexpr auto last = sv.find_last_not_of(" >(", sv.size() - 6);
#else
    constexpr std::string_view sv = __PRETTY_FUNCTION__;
    constexpr auto last = sv.find_last_not_of(" ])");
#endif
    constexpr auto first = sv.find_last_of(":", last);
    auto res = std::array<char, last - first + 1>{};
    std::ranges::copy(sv.begin()+first+1,
                      sv.begin()+last+1,
                      res.begin());
    return res;
}

template <typename T>
extern const T fake_object;

template <class T, std::size_t I>
constexpr auto stored_name_of_field = name_of_field_impl<detail::sequence_tuple::get<I>(
    detail::tie_as_tuple(fake_object<T>) 
)>();

template <class T, std::size_t... I>
constexpr auto tie_as_names_tuple_impl(std::index_sequence<I...>) noexcept {
    return detail::make_sequence_tuple(std::string_view{stored_name_of_field<T, I>.data()}...);
}

template <class T, std::size_t I>
constexpr std::string_view get_name() noexcept {
    static_assert(
        !std::is_union<T>::value,
        "====================> Boost.PFR: For safety reasons it is forbidden to reflect unions. See `Reflection of unions` section in the docs for more info."
    );
    static_assert(
        sizeof(T) && BOOST_PFR_USE_CPP17,
        "====================> Boost.PFR: Extraction of field's names is allowed only when the BOOST_PFR_USE_CPP17 macro enabled."
   );
   
   return stored_name_of_field<T, I>.data();  
}

template <class T>
constexpr auto tie_as_names_tuple() noexcept {
    static_assert(
        !std::is_union<T>::value,
        "====================> Boost.PFR: For safety reasons it is forbidden to reflect unions. See `Reflection of unions` section in the docs for more info."
    );
    static_assert(
        sizeof(T) && BOOST_PFR_USE_CPP17,
        "====================> Boost.PFR: Extraction of field's names is allowed only when the BOOST_PFR_USE_CPP17 macro enabled."
    );

    return tie_as_names_tuple_impl<T>(detail::make_index_sequence<detail::fields_count<T>()>{});
}

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE_NAME20_STATIC_HPP

