// Copyright (c) 2016-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// To compile manually use a command like the folowing:
// clang++ -I ../include -std=c++20 --precompile -x c++-module pfr.cppm

module;

#define BOOST_PFR_INTERFACE_UNIT
#include <boost/pfr.hpp>

export module boost.pfr;

export namespace boost::pfr {

// core.hpp
using pfr::get;
using pfr::tuple_element;
using pfr::tuple_element_t;
using pfr::structure_to_tuple;
using pfr::structure_tie;
using pfr::for_each_field;
using pfr::tie_from_structure;

// core_name.hpp
using pfr::get_name;
using pfr::names_as_array;
using pfr::for_each_field_with_name;

// functors.hpp
using pfr::equal_to;
using pfr::not_equal;
using pfr::greater;
using pfr::less;
using pfr::greater_equal;
using pfr::less_equal;
using pfr::hash;

// io.hpp and io_fields.hpp
namespace detail {
    using detail::operator<<;
    using detail::operator>>;
}  // namespace detail
using pfr::io;
using pfr::io_fields;

// ops.hpp
using pfr::eq;
using pfr::ne;
using pfr::lt;
using pfr::gt;
using pfr::le;
using pfr::ge;
using pfr::hash_value;

// ops_fields.hpp
using pfr::eq_fields;
using pfr::ne_fields;
using pfr::lt_fields;
using pfr::gt_fields;
using pfr::le_fields;
using pfr::ge_fields;
using pfr::hash_fields;

// traits.hpp
using pfr::is_reflectable;
using pfr::is_implicitly_reflectable;
using pfr::is_implicitly_reflectable_v;

// tuple_size.hpp
using pfr::tuple_size;
using pfr::tuple_size_v;

}
