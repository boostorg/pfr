// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifndef BOOST_PFR_PRECISE_CORE_HPP
#define BOOST_PFR_PRECISE_CORE_HPP

#include <type_traits>
#include <utility>      // metaprogramming stuff

#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/detail/io.hpp>
#include <boost/pfr/detail/stdtuple.hpp>

#if __cplusplus >= 201606L /* Oulu meeting, not the exact value */
#   include <boost/pfr/detail/core17.hpp>
#else
#   include <boost/pfr/detail/core14.hpp>
#endif

namespace boost { namespace pfr {

/// \brief Has a static const member variable `value` that constins fields count in a T.
/// Works for any T that supports aggregate initialization even if T is not POD.
/// \flattening{Flattens} only multidimensional arrays.
///
/// \b Requires: C++14.
///
/// \b Example:
/// \code
///     std::array<int, boost::pfr::tuple_size<my_structure>::value > a;
/// \endcode
template <class T>
using tuple_size = detail::size_t_< boost::pfr::detail::fields_count<T>() >;


/// \brief `tuple_size_v` is a template variable that contains fields count in a T and
/// works for any T that supports aggregate initialization even if T is not POD.
/// \flattening{Flattens} only multidimensional arrays.
///
/// \b Requires: C++14.
///
/// \b Example:
/// \code
///     std::array<int, boost::pfr::tuple_size_v<my_structure> > a;
/// \endcode
template <class T>
constexpr std::size_t tuple_size_v = tuple_size<T>::value;

/// \brief Returns reference or const reference to a field with index `I` in aggregate T.
///
/// \b Requires: C++17 or \simplepod{C++14 simple POD}.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s {10, 11};
///     assert(boost::pfr::get<0>(s) == 10);
///     boost::pfr::get<1>(s) = 0;
/// \endcode
template <std::size_t I, class T>
constexpr decltype(auto) get(const T& val) noexcept {
    return detail::sequence_tuple::get<I>( detail::as_tuple(val) );
}


/// \overload get
template <std::size_t I, class T>
constexpr decltype(auto) get(T& val) noexcept {
    return detail::sequence_tuple::get<I>( detail::as_tuple(val) );
}


/// \brief `tuple_element` has a `typedef type-of-a-field-with-index-I-in-aggregate-T type;`
///
/// \b Requires: C++17 or \simplepod{C++14 simple POD}.
///
/// \b Example:
/// \code
///     std::vector<  boost::pfr::tuple_element<0, my_structure>::type  > v;
/// \endcode
template <std::size_t I, class T>
using tuple_element = typename detail::sequence_tuple::tuple_element<I, detail::as_tuple_t<T> >::type;


/// \brief Type of a field with index `I` in aggregate `T`.
///
/// \b Requires: C++17 or \simplepod{C++14 simple POD}.
///
/// \b Example:
/// \code
///     std::vector<  boost::pfr::tuple_element_t<0, my_structure>  > v;
/// \endcode
template <std::size_t I, class T>
using tuple_element_t = typename tuple_element<I, T>::type;


/// \brief Creates an `std::tuple` from an aggregate T.
///
/// \b Requires: C++17 or \simplepod{C++14 simple POD}.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s {10, 11};
///     std::tuple<int, short> t = make_tuple(s);
///     assert(get<0>(t) == 10);
/// \endcode
template <class T>
constexpr auto structure_to_tuple(const T& val) noexcept {
    typedef detail::as_tuple_t<T> internal_tuple_t;

    return detail::make_stdtuple_from_tietuple(
        detail::as_tuple(val),
        std::make_index_sequence< internal_tuple_t::size_v >()
    );
}


/// \brief Creates an `std::tuple` with lvalue references to fields of an aggregate T.
///
/// \b Requires: C++17 or \simplepod{C++14 simple POD}.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s;
///     tie(s) = std::tuple<int, short>{10, 11};
///     assert(s.s == 11);
/// \endcode
template <class T>
constexpr auto structure_tie(T& val) noexcept {
    typedef detail::as_tuple_t<T> internal_tuple_t;

    return detail::make_stdtiedtuple_from_tietuple(
        detail::as_tuple(val),
        std::make_index_sequence< internal_tuple_t::size_v >()
    );
}


/// \brief Writes aggregate `value` to `out`
///
/// \b Requires: C++17 or \simplepod{C++14 simple POD}.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s{12, 13};
///     write(std::cout, s); // outputs '{12, 13}'
/// \endcode
template <class Char, class Traits, class T>
void write(std::basic_ostream<Char, Traits>& out, const T& value) {
    out << '{';
    detail::print_impl<0, tuple_size_v<T> >::print(out, detail::as_tuple(value));
    out << '}';
}

/// Reads aggregate `value` from stream `in`
///
/// \b Requires: C++17 or \simplepod{C++14 simple POD}.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s;
///     std::stringstream ss;
///     ss << "{ 12, 13 }";
///     ss >> s;
///     assert(s.i == 12);
///     assert(s.i == 13);
/// \endcode
template <class Char, class Traits, class T>
void read(std::basic_istream<Char, Traits>& in, T& value) {
    const auto prev_exceptions = in.exceptions();
    in.exceptions( typename std::basic_istream<Char, Traits>::iostate(0) );
    const auto prev_flags = in.flags( typename std::basic_istream<Char, Traits>::fmtflags(0) );

    char parenthis = {};
    in >> parenthis;
    if (parenthis != '{') in.setstate(std::basic_istream<Char, Traits>::failbit);
    detail::read_impl<0, tuple_size_v<T> >::read(in, detail::as_tuple(value));

    in >> parenthis;
    if (parenthis != '}') in.setstate(std::basic_istream<Char, Traits>::failbit);

    in.flags(prev_flags);
    in.exceptions(prev_exceptions);
}

}} // namespace boost::pfr

#endif // BOOST_PFR_PRECISE_CORE_HPP
