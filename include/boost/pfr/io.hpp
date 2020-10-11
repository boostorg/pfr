// Copyright (c) 2016-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_IO_HPP
#define BOOST_PFR_IO_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/detail/detectors.hpp>
#include <boost/pfr/io_fields.hpp>

/// \file boost/pfr/io.hpp
/// Contains stream operators for types.
/// If type is streamable using its own operator or its conversion operator, then the original operator is used.
///
/// Just write \b using \b namespace \b ops; and operators will be available in scope.
///
/// \b Requires: C++17 or \constexprinit{C++14 constexpr aggregate intializable type}.
///
/// \b Example:
/// \code
///     #include <boost/pfr/ops.hpp>
///     struct comparable_struct {      // No operators defined for that structure
///         int i; short s; char data[7]; bool bl; int a,b,c,d,e,f;
///     };
///     // ...
///
///     comparable_struct s1 {0, 1, "Hello", false, 6,7,8,9,10,11};
///     boost::pfr::write(std::cout, s1);  // Outputs: {0, 1, H, e, l, l, o, , , 0, 6, 7, 8, 9, 10, 11}
/// \endcode
///
/// \podops for other ways to define operators and more details.
///
/// \b This \b header \b contains:
namespace boost { namespace pfr {

namespace detail {

///////////////////// Helper typedefs that are used by all the ops
    template <class Stream, class Type>
    using enable_not_ostreamable_t = typename std::enable_if<
        not_appliable<ostreamable_detector, Stream&, Type const&>::value,
        Stream&
    >::type;

    template <class Stream, class Type>
    using enable_not_istreamable_t = typename std::enable_if<
        not_appliable<istreamable_detector, Stream&, Type&>::value,
        Stream&
    >::type;

    template <class Stream, class Type>
    using enable_ostreamable_t = typename std::enable_if<
        !not_appliable<ostreamable_detector, Stream&, Type const&>::value,
        Stream&
    >::type;

    template <class Stream, class Type>
    using enable_istreamable_t = typename std::enable_if<
        !not_appliable<istreamable_detector, Stream&, Type&>::value,
        Stream&
    >::type;

} // namespace detail

template <class Char, class Traits, class T>
detail::enable_not_ostreamable_t<std::basic_ostream<Char, Traits>, T> write(std::basic_ostream<Char, Traits>& out, const T& value) {
    boost::pfr::write_fields(out, value);
    return out;
}

template <class Char, class Traits, class T>
detail::enable_ostreamable_t<std::basic_ostream<Char, Traits>, T> write(std::basic_ostream<Char, Traits>& out, const T& value) {
    return out << value;
}

template <class Char, class Traits, class T>
detail::enable_not_istreamable_t<std::basic_istream<Char, Traits>, T> read(std::basic_istream<Char, Traits>& in, T& value) {
    boost::pfr::read_fields(in, value);
    return in;
}

template <class Char, class Traits, class T>
detail::enable_istreamable_t<std::basic_istream<Char, Traits>, T> read(std::basic_istream<Char, Traits>& in, T& value) {
    return in >> value;
}

}} // namespace boost::pfr

#endif // BOOST_PFR_IO_HPP
