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
#include <boost/pfr/detail/fake_object.hpp>
#include <type_traits>
#include <string_view>
#include <array>
#include <memory> // for std::addressof

namespace boost { namespace pfr { namespace detail {

struct core_name_skip {
    std::size_t size_at_begin;
    std::size_t size_at_end;
    bool more_at_runtime;
    bool is_backward;
    std::string_view until_runtime;

    consteval std::string_view fail() const noexcept {
        return "";
    }

    consteval std::string_view apply(std::string_view sv) const noexcept {
        sv.remove_prefix((std::min)(size_at_begin, sv.size()));
        sv.remove_suffix((std::min)(size_at_end, sv.size()));
        if (!more_at_runtime) {
            if (!until_runtime.empty())
                return fail(); ///< useless skip condition
            return sv;
        }
        else {
            // so, we're asked to skip more
            if (until_runtime.empty())
                return fail(); ///< condition to skip more wasn't specified
            const auto found = is_backward ? sv.rfind(until_runtime)
                                             : sv.find(until_runtime);
                                             ;
            const auto cut_until = found + until_runtime.size();
            const auto safe_cut_until = (std::min)(cut_until, sv.size());
            return sv.substr(safe_cut_until);
        }
    }
};

struct backward {
    explicit consteval backward(std::string_view value) noexcept
        : value(value)
    {}

    std::string_view value;
};

consteval core_name_skip make_core_name_skip(std::size_t size_at_begin,
                                             std::size_t size_at_end,
                                             bool more_at_runtime,
                                             std::string_view until_runtime) noexcept
{
    return core_name_skip{size_at_begin, size_at_end, more_at_runtime, false, until_runtime};
}

consteval core_name_skip make_core_name_skip(std::size_t size_at_begin,
                                             std::size_t size_at_end,
                                             bool more_at_runtime,
                                             backward until_runtime) noexcept
{
    return core_name_skip{size_at_begin, size_at_end, more_at_runtime, true, until_runtime.value};
}

consteval core_name_skip make_core_name_skip(std::size_t size_at_begin,
                                             std::size_t size_at_end,
                                             auto until_runtime) noexcept
{
    return detail::make_core_name_skip(size_at_begin, size_at_end, true, until_runtime);
}

template <bool Condition>
consteval void assert_compile_time_legths() noexcept {
    static_assert(
        Condition,
        "====================> Boost.PFR: Extraction of field name is misconfigured for your compiler. "
        "Please define BOOST_PFR_CORE_NAME_PARSING to correct values. See section "
        "Limitations of field's names reflection' of the documentation for more information."
    );
}

template <class T>
consteval void failed_to_get_function_name() noexcept {
    static_assert(
        sizeof(T) && false,
        "====================> Boost.PFR: Extraction of field name could not detect your compiler. "
        "Please make the BOOST_PFR_FUNCTION_SIGNATURE macro use "
        "correct compiler macro for getting the whole function name. "
        "Define BOOST_PFR_CORE_NAME_PARSING to correct value after that."
    );
}

// it might be compilation failed without this workaround sometimes
// See https://github.com/llvm/llvm-project/issues/41751 for details
template <class>
consteval std::string_view clang_workaround(std::string_view value) noexcept
{
    return value;
}

template <class MsvcWorkaround, auto ptr>
consteval auto name_of_field_impl() noexcept {
    constexpr std::string_view sv = detail::clang_workaround<MsvcWorkaround>(BOOST_PFR_FUNCTION_SIGNATURE);
    if constexpr (sv.empty()) {
        detail::failed_to_get_function_name<MsvcWorkaround>();
        return detail::make_stdarray<char>(0);
    } else {
        constexpr auto skip = detail::make_core_name_skip BOOST_PFR_CORE_NAME_PARSING;
        static_assert(
            skip.more_at_runtime || skip.until_runtime.empty(),
            "====================> Boost.PFR: Parser configured in a wrong way. "
            "It wasn't requested to skip more, but such skip condition was specified in vain. "
            "Please read your definition of BOOST_PFR_CORE_NAME_PARSING macro patiently "
            "and fix it."
        );
        constexpr auto fn = skip.apply(sv);
        auto res = std::array<char, fn.size()+1>{};
        detail::assert_compile_time_legths<!fn.empty()>();

        auto* out = res.begin();
        for (auto x: fn) {
            *out = x;
            ++out;
        }

        return res;
    }
}

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundefined-var-template"

// clang 16 and earlier don't support address of non-static member as template parameter
// but fortunately it's possible to use C++20 non-type template parameters in another way
// even in clang 16 and more older clangs
// all we need is to wrap pointer into 'clang_wrapper_t' and then pass it into template
template <class T>
struct clang_wrapper_t {
    T v;
};
template <class T>
clang_wrapper_t(T) -> clang_wrapper_t<T>;

template <class T>
constexpr auto make_clang_wrapper(const T& arg) noexcept {
    return clang_wrapper_t{arg};
}

#else

template <class T>
constexpr const T& make_clang_wrapper(const T& arg) noexcept {
    // It's everything OK with address of non-static member as template parameter support on this compiler
    // so we don't need a wrapper here, just pass the pointer into template
    return arg;
}

#endif

// Without passing 'T' into 'name_of_field_impl' different fields from different structures might have the same name!
// See https://developercommunity.visualstudio.com/t/__FUNCSIG__-outputs-wrong-value-with-C/10458554 for details
template <class T, std::size_t I>
constexpr auto stored_name_of_field = detail::name_of_field_impl<T, detail::make_clang_wrapper(std::addressof(detail::sequence_tuple::get<I>(
    detail::tie_as_tuple(fake_object<T>)
)))>();

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

    return detail::tie_as_names_tuple_impl<T>(detail::make_index_sequence<detail::fields_count<T>()>{});
}

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE_NAME20_STATIC_HPP

