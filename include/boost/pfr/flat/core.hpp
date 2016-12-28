// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_FLAT_CORE_HPP
#define BOOST_PFR_FLAT_CORE_HPP

#if __cplusplus < 201402L
#   error C++14 is required for this header.
#endif

#include <type_traits>
#include <utility>      // metaprogramming stuff

#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/detail/io.hpp>
#include <boost/pfr/detail/stdtuple.hpp>
#include <boost/pfr/detail/core14.hpp>

namespace boost { namespace pfr {

/// \brief Returns reference or const reference to a field with index `I` in \flattening{flattened} T.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s {10, 11};
///     assert(boost::pfr::flat_get<0>(s) == 10);
///     boost::pfr::flat_get<1>(s) = 0;
/// \endcode
template <std::size_t I, class T>
decltype(auto) flat_get(const T& val) noexcept {
    return boost::pfr::detail::sequence_tuple::get<I>( boost::pfr::detail::tie_as_flat_tuple(val) );
}


/// \overload flat_get
template <std::size_t I, class T>
decltype(auto) flat_get(T& val /* @cond */, std::enable_if_t< std::is_trivially_assignable<T, T>::value>* = 0/* @endcond */ ) noexcept {
    return boost::pfr::detail::sequence_tuple::get<I>( boost::pfr::detail::tie_as_flat_tuple(val) );
}


/// \brief `flat_tuple_element` has a `typedef type-of-the-field-with-index-I-in-\flattening{flattened}-T type;`
///
/// \b Example:
/// \code
///     std::vector<  boost::pfr::flat_tuple_element<0, my_structure>::type  > v;
/// \endcode
template <std::size_t I, class T>
using flat_tuple_element = std::remove_reference<
        typename boost::pfr::detail::sequence_tuple::tuple_element<I, decltype(boost::pfr::detail::tie_as_flat_tuple(std::declval<T&>())) >::type
    >;


/// \brief Type of a field with index `I` in \flattening{flattened} `T`
///
/// \b Example:
/// \code
///     std::vector<  boost::pfr::flat_tuple_element_t<0, my_structure>  > v;
/// \endcode
template <std::size_t I, class T>
using flat_tuple_element_t = typename flat_tuple_element<I, T>::type;


/// \brief Has a static const member variable `value` that contains fields count in a \flattening{flattened} T.
///
/// \b Example:
/// \code
///     std::array<int, boost::pfr::flat_tuple_size<my_structure>::value > a;
/// \endcode
template <class T>
using flat_tuple_size = boost::pfr::detail::size_t_<decltype(boost::pfr::detail::tie_as_flat_tuple(std::declval<T&>()))::size_v>;


/// \brief `flat_tuple_size_v` is a template variable that contains fields count in a \flattening{flattened} T.
///
/// \b Example:
/// \code
///     std::array<int, boost::pfr::flat_tuple_size_v<my_structure> > a;
/// \endcode
template <class T>
constexpr std::size_t flat_tuple_size_v = flat_tuple_size<T>::value;

/// \brief Creates an `std::tuple` from a \flattening{flattened} T.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s {10, 11};
///     std::tuple<int, short> t = flat_make_tuple(s);
///     assert(flat_get<0>(t) == 10);
/// \endcode
template <class T>
auto flat_structure_to_tuple(const T& val) noexcept {
    return detail::make_stdtuple_from_tietuple(
        detail::tie_as_flat_tuple(val),
        std::make_index_sequence< flat_tuple_size_v<T> >()
    );
}


/// \brief Creates an `std::tuple` with lvalue references to fields of a \flattening{flattened} T.
///
/// \b Requires: `T` must not have const fields.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s;
///     flat_structure_tie(s) = std::tuple<int, short>{10, 11};
///     assert(s.s == 11);
/// \endcode
template <class T>
auto flat_structure_tie(T& val /* @cond */, std::enable_if_t< std::is_trivially_assignable<T, T>::value>* = 0 /* @endcond */) noexcept {
    return detail::make_stdtiedtuple_from_tietuple(
        detail::tie_as_flat_tuple(val),
        std::make_index_sequence< flat_tuple_size_v<T> >()
    );
}

/// \brief Writes \flattening{flattened} POD `value` to `out`
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s{12, 13};
///     flat_write(std::cout, s); // outputs '{12, 13}'
/// \endcode
template <class Char, class Traits, class T>
void flat_write(std::basic_ostream<Char, Traits>& out, const T& value) {
    out << '{';
    detail::print_impl<0, flat_tuple_size_v<T> >::print(out, detail::tie_as_flat_tuple(value));
    out << '}';
}

/// Reads \flattening{flattened} POD `value` from stream `in`
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
void flat_read(std::basic_istream<Char, Traits>& in, T& value) {
    const auto prev_exceptions = in.exceptions();
    in.exceptions( typename std::basic_istream<Char, Traits>::iostate(0) );
    const auto prev_flags = in.flags( typename std::basic_istream<Char, Traits>::fmtflags(0) );

    char parenthis = {};
    in >> parenthis;
    if (parenthis != '{') in.setstate(std::basic_istream<Char, Traits>::failbit);
    detail::read_impl<0, flat_tuple_size_v<T> >::read(in, detail::tie_as_flat_tuple(value));

    in >> parenthis;
    if (parenthis != '}') in.setstate(std::basic_istream<Char, Traits>::failbit);

    in.flags(prev_flags);
    in.exceptions(prev_exceptions);
}

}} // namespace boost::pfr

#endif // BOOST_PFR_FLAT_CORE_HPP
