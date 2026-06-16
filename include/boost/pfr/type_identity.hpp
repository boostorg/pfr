// Copyright (c) 2021-2023 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_TYPE_IDENTITY_HPP
#define BOOST_PFR_TYPE_IDENTITY_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

namespace boost { namespace pfr {

template< class T >
struct type_identity {
    using type = T;
};

}} // namespace boost::pfr


#endif // BOOST_PFR_TYPE_IDENTITY_HPP
