// Copyright (c) 2016-2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_DETECTORS_HPP
#define BOOST_PFR_DETAIL_DETECTORS_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

namespace boost { namespace pfr { namespace detail {
///////////////////// `value` is true if Detector<Tleft, Tright> does not compile (SFINAE)
    template <template <class, class> class Detector, class Tleft, class Tright>
    struct not_appliable {
        struct success{};
        template <class Tl, class Tr> static Detector<Tl, Tr> detector_impl(long) noexcept;
        template <class Tl, class Tr> static success detector_impl(int) noexcept;

        static constexpr bool value = std::is_same<
            decltype(detector_impl<Tleft, Tright>(1L)),
            success
        >::value;
    };

///////////////////// Detectors for different operators
    template <class T1, class T2> using comp_eq_detector = decltype(std::declval<T1>() == std::declval<T2>());
    template <class T1, class T2> using comp_ne_detector = decltype(std::declval<T1>() != std::declval<T2>());
    template <class T1, class T2> using comp_lt_detector = decltype(std::declval<T1>() <  std::declval<T2>());
    template <class T1, class T2> using comp_le_detector = decltype(std::declval<T1>() <= std::declval<T2>());
    template <class T1, class T2> using comp_gt_detector = decltype(std::declval<T1>() >  std::declval<T2>());
    template <class T1, class T2> using comp_ge_detector = decltype(std::declval<T1>() >= std::declval<T2>());
    template <class S, class T> using ostreamable_detector = decltype(std::declval<S>() << std::declval<T>());
    template <class S, class T> using istreamable_detector = decltype(std::declval<S>() >> std::declval<T>());

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_DETECTORS_HPP

