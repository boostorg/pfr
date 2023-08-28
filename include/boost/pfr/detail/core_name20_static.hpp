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
#include <boost/pfr/detail/stdarray.hpp>
#include <type_traits>
#include <string_view>
#include <array>
#include <algorithm> // for std::ranges::copy

namespace boost { namespace pfr { namespace detail {

struct core_name_skip {
    std::size_t size_at_begin;
    std::size_t size_at_end;
    bool more_at_runtime;
    std::string_view until_runtime_last;
};

consteval core_name_skip make_core_name_skip(std::size_t size_at_begin,
                                             std::size_t size_at_end,
                                             bool more_at_runtime,
                                             std::string_view until_runtime_last) noexcept
{
    return core_name_skip{size_at_begin, size_at_end, more_at_runtime, until_runtime_last};
}

consteval core_name_skip make_core_name_skip(std::size_t size_at_begin,
                                             std::size_t size_at_end,
                                             std::string_view until_runtime_last) noexcept
{
    return core_name_skip{size_at_begin, size_at_end, true, until_runtime_last};
}

consteval std::string_view apply_core_name_skip(std::string_view sv,
                                                core_name_skip s) noexcept {
    sv.remove_prefix((std::min)(s.size_at_begin, sv.size()));
    sv.remove_suffix((std::min)(s.size_at_end, sv.size()));
    return s.more_at_runtime ? sv.substr((std::min)(sv.rfind(s.until_runtime_last) + s.until_runtime_last.size(), sv.size()))
                             : sv;
                             ;
}

template <bool Condition>
consteval void assert_compile_time_legths() noexcept {
    static_assert(
        Condition,
        "PFRs extraction of field name is misconfigured for your compiler. "
        "Please define BOOST_PFR_CORE_NAME_PARSING to correct values. See section "
        "Limitations of field's names reflection' of the documentation for more information."
    );
}

template <class T>
consteval void failed_to_get_function_name() noexcept {
    static_assert(
        sizeof(T) && false,
        "PFRs extraction of field name could not detect your compiler. "
        "Please make the BOOST_PFR_FUNCTION_SIGNATURE macro use "
        "correct compiler macro for getting the whole function name. "
        "Define BOOST_PFR_CORE_NAME_PARSING to correct value after that."
    );
}

template <typename MsvcWorkaround, auto ptr>
consteval auto name_of_field_impl() noexcept {
    constexpr std::string_view sv = BOOST_PFR_FUNCTION_SIGNATURE;
    if constexpr (sv.empty()) {
        detail::failed_to_get_function_name<MsvcWorkaround>();
        return detail::make_stdarray<char>(0);
    } else {
        constexpr auto skip = detail::make_core_name_skip BOOST_PFR_CORE_NAME_PARSING;
        constexpr auto fn = detail::apply_core_name_skip(sv, skip);
        auto res = std::array<char, fn.size()+1>{};
        detail::assert_compile_time_legths<!fn.empty()>();
        std::ranges::copy(fn, res.begin());
        return res;
    }
}

template <typename T>
extern const T fake_object;

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundefined-var-template"

template<class T>
struct clang_workaround_t {
    T v;
};
template<class T>
clang_workaround_t(T) -> clang_workaround_t<T>;

template<typename T>
constexpr auto clang_workaround(const T& arg) noexcept {
    return clang_workaround_t{arg};
}

#else

template<typename T>
constexpr const T& clang_workaround(const T& arg) noexcept {
    return arg;
}

#endif

// Without passing 'T' into 'name_of_field_impl' different fields from different structures might have the same name!
template <class T, std::size_t I>
constexpr auto stored_name_of_field = name_of_field_impl<T, clang_workaround(&detail::sequence_tuple::get<I>(
    detail::tie_as_tuple(fake_object<T>)
))>();

#ifdef __clang__
#pragma clang diagnostic pop
#endif

template <class T, std::size_t... I>
constexpr auto tie_as_names_tuple_impl(std::index_sequence<I...>) noexcept {
    return detail::sequence_tuple::make_sequence_tuple(std::string_view{stored_name_of_field<T, I>.data()}...);
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

