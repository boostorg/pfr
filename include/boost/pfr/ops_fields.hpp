// Copyright (c) 2016-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_OPS_FIELDS_HPP
#define BOOST_PFR_OPS_FIELDS_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/core.hpp>
#include <boost/pfr/detail/functional.hpp>

/// \file boost/pfr/ops_fields.hpp
/// Contains field-by-fields comparison and hash functions.
///
/// \b Requires: C++17 or \constexprinit{C++14 constexpr aggregate intializable type}.
///
/// \b Example:
/// \code
///     #include <boost/pfr/ops_fields.hpp>
///     struct comparable_struct {      // No operators defined for that structure
///         int i; short s;
///     };
///     // ...
///
///     comparable_struct s1 {0, 1};
///     comparable_struct s2 {0, 2};
///     assert(boost::pfr::lt_fields(s1, s2));
/// \endcode
///
/// \podops for other ways to define operators and more details.
///
/// \b This \b header \b contains:
namespace boost { namespace pfr {
    template <class T>
    bool eq_fields(const T& lhs, const T& rhs) noexcept {
        return detail::binary_visit<detail::equal_impl>(lhs, rhs);
    }

    template <class T>
    bool ne_fields(const T& lhs, const T& rhs) noexcept {
        return detail::binary_visit<detail::not_equal_impl>(lhs, rhs);
    }

    template <class T>
    bool gt_fields(const T& lhs, const T& rhs) noexcept {
        return detail::binary_visit<detail::greater_impl>(lhs, rhs);
    }

    template <class T>
    bool lt_fields(const T& lhs, const T& rhs) noexcept {
        return detail::binary_visit<detail::less_impl>(lhs, rhs);
    }

    template <class T>
    bool ge_fields(const T& lhs, const T& rhs) noexcept {
        return detail::binary_visit<detail::greater_equal_impl>(lhs, rhs);
    }

    template <class T>
    bool le_fields(const T& lhs, const T& rhs) noexcept {
        return detail::binary_visit<detail::less_equal_impl>(lhs, rhs);
    }

    template <class T>
    std::size_t hash_fields(const T& x) {
        constexpr std::size_t fields_count_val = boost::pfr::detail::fields_count<std::remove_reference_t<T>>();
#if BOOST_PFR_USE_CPP17
        return detail::hash_impl<0, fields_count_val>::compute(detail::tie_as_tuple(x));
#else
        std::size_t result = 0;
        ::boost::pfr::detail::for_each_field_dispatcher(
            x,
            [&result](const auto& lhs) {
                // We can not reuse `fields_count_val` in lambda because compilers had issues with
                // passing constexpr variables into lambdas. Computing is again is the most portable solution.
                constexpr std::size_t fields_count_val_lambda = boost::pfr::detail::fields_count<std::remove_reference_t<T>>();
                result = detail::hash_impl<0, fields_count_val_lambda>::compute(lhs);
            },
            detail::make_index_sequence<fields_count_val>{}
        );

        return result;
#endif
    }
}} // namespace boost::pfr

#endif // BOOST_PFR_OPS_HPP
