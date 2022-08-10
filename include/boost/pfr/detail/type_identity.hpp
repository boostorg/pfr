// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_TYPE_IDENTITY_HPP
#define BOOST_PFR_DETAIL_TYPE_IDENTITY_HPP

#include <boost/pfr/detail/config.hpp>

#include <type_traits>  // for possible std::type_identity

namespace boost { namespace pfr { namespace detail {
  
#if defined(__cpp_lib_type_identity)
template< class T >
using type_identity = std::type_identity<T>;
#else
template< class T >
struct type_identity_impl {
    using type = T;
};

template< class T >
using type_identity = type_identity_impl<T>;
#endif

}}} // namespace boost::pfr::detail


#endif // BOOST_PFR_DETAIL_TYPE_IDENTITY_HPP