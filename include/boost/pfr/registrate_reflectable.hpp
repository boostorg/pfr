// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_REGISTRATE_REFLECTABLE_HPP
#define BOOST_PFR_REGISTRATE_REFLECTABLE_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/traits.hpp>

/// \file boost/pfr/registrate_reflectable.hpp
/// Contains BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_ALL, BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_MANY and BOOST_PFR_REGISTRATE_REFLECTABLE macros those mark T as reflectable.
/// \b Example:
/// \code
///     #include <boost/pfr/registrate_reflectable.hpp>
///
///     namespace my_namespace {
///         struct my_struct {      // This structure can be reflectable by Boost.PFR, but by default compiler don't know it
///             int i; short s; char data[7]; bool bl; int a,b,c,d,e,f;
///         };
///     }
///     BOOST_PFR_REGISTRATE_REFLECTABLE(my_namespace::my_struct)
/// \endcode
///
/// \podinteraction for other ways to use Boost.PFR with other libraries and more details.
///
/// \b Synopsis:

/// \def BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_ALL(T)
/// Makes type T reflectable everywhere.
///
/// \b Example:
/// \code
///     #include <boost/pfr/registrate_reflectable.hpp>
///     #include <boost/fusion/adapted/boost_pfr.hpp>
///     #include <boost/fusion/sequence/comparison/less.hpp>
///     #include <boost/fusion/sequence/io.hpp>
///
///     using boost::fusion::operator<<;
///
///     struct reflectable_struct {      // This structure can be reflectable by Boost.PFR, but by default compiler don't know it
///         int i; short s; char data[7]; bool bl; int a,b,c,d,e,f;
///     };
///     BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_ALL(reflectable_struct)
///     // ...
///
///     static_assert(boost::pfr::is_reflectable_v<reflectable_struct>, "");
///     reflectable_struct s1 {0, 1, "Hello", false, 6,7,8,9,10,11};
///     reflectable_struct s2 {0, 1, "Hello", false, 6,7,8,9,10,11111};
///     assert(boost::fusion::less(s1, s2));
///     std::cout << s1 << std::endl; // Outputs: {0, 1, H, e, l, l, o, , , 0, 6, 7, 8, 9, 10, 11}
/// \endcode
///
/// \podinteraction for other ways to use Boost.PFR with other libraries and more details.

#define BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_ALL(T)

/// \def BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_MANY(T, ...)
/// Makes type T reflectable in all __VA_ARGS__ libraries.
///
/// \b Example:
/// \code
///     #include <boost/pfr/registrate_reflectable.hpp>
///     #include <boost/fusion/adapted/boost_pfr.hpp>
///     #include <boost/fusion/sequence/comparison/less.hpp>
///     #include <boost/fusion/sequence/io.hpp>
///
///     using boost::fusion::operator<<;
///
///     struct reflectable_struct {      // This structure can be reflectable by Boost.PFR, but by default compiler don't know it
///         int i; short s; char data[7]; bool bl; int a,b,c,d,e,f;
///     };
///     BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_MANY(reflectable_struct, boost::pfr::boost_fusion_tag)
///     // ...
///
///     static_assert(!boost::pfr::is_reflectable_v<reflectable_struct>, "");                               // isn't reflectable for all
///     static_assert(boost::pfr::is_reflectable_v<reflectable_struct, boost::pfr::boost_fusion_tag>, "");  // it's only reflectable for Boost.Fusion
///     reflectable_struct s1 {0, 1, "Hello", false, 6,7,8,9,10,11};
///     reflectable_struct s2 {0, 1, "Hello", false, 6,7,8,9,10,11111};
///     assert(boost::fusion::less(s1, s2));
///     std::cout << s1 << std::endl; // Outputs: {0, 1, H, e, l, l, o, , , 0, 6, 7, 8, 9, 10, 11}
/// \endcode
///
/// \podinteraction for other ways to use Boost.PFR with other libraries and more details.

#define BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_MANY(T, ...)

// TODO: need link to BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_ALL in the doc

/// \def BOOST_PFR_REGISTRATE_REFLECTABLE(T)
/// This macro is just alias for BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_ALL macro.
///
/// \podinteraction for other ways to use Boost.PFR with other libraries and more details.


#define BOOST_PFR_REGISTRATE_REFLECTABLE(T) BOOST_PFR_REGISTRATE_REFLECTABLE_FOR_ALL(T)

#endif // BOOST_PFR_REGISTRATE_REFLECTABLE_HPP

