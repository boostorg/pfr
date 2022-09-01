// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core.hpp>
#include <type_traits>
#include <string>

struct B
{
    int one;
    char two;
    short third;
};

struct S {};

// don't do it in your application code!
namespace boost { namespace pfr {
template <>
struct tuple_size<S> : std::integral_constant<std::size_t, 20> {};
template <std::size_t I>
struct tuple_element<I, S> {
  static_assert(I==0, "");
  using type = std::string;
};
}} // namespace boost::pfr


int main() {
  {
    static_assert(boost::pfr::tuple_size_v<B> == 3, "");
    static_assert(boost::pfr::tuple_size_v<const B> == 3, "");
    static_assert(boost::pfr::tuple_size_v<volatile B> == 3, "");
    static_assert(boost::pfr::tuple_size_v<const volatile B> == 3, "");
    
    static_assert(boost::pfr::tuple_size_v<S> == 20, "");
    static_assert(boost::pfr::tuple_size_v<const S> == 20, "");
    static_assert(boost::pfr::tuple_size_v<volatile S> == 20, "");
    static_assert(boost::pfr::tuple_size_v<const volatile S> == 20, "");
  }

  {
    {
      static_assert(std::is_same< boost::pfr::tuple_element_t<0, B>, int >::value, "");
      static_assert(std::is_same< boost::pfr::tuple_element_t<1, B>, char >::value, "");
      static_assert(std::is_same< boost::pfr::tuple_element_t<2, B>, short >::value, "");
      
      static_assert(std::is_same< boost::pfr::tuple_element_t<0, const B>, const int >::value, "");
      static_assert(std::is_same< boost::pfr::tuple_element_t<1, const B>, const char >::value, "");
      static_assert(std::is_same< boost::pfr::tuple_element_t<2, const B>, const short >::value, "");
      
      static_assert(std::is_same< boost::pfr::tuple_element_t<0, volatile B>, volatile int >::value, "");
      static_assert(std::is_same< boost::pfr::tuple_element_t<1, volatile B>, volatile char >::value, "");
      static_assert(std::is_same< boost::pfr::tuple_element_t<2, volatile B>, volatile short >::value, "");
      
      static_assert(std::is_same< boost::pfr::tuple_element_t<0, const volatile B>, const volatile int >::value, "");
      static_assert(std::is_same< boost::pfr::tuple_element_t<1, const volatile B>, const volatile char >::value, "");
      static_assert(std::is_same< boost::pfr::tuple_element_t<2, const volatile B>, const volatile short >::value, "");
    }

    static_assert(std::is_same< boost::pfr::tuple_element_t<0, S>, std::string >::value, "");
    static_assert(std::is_same< boost::pfr::tuple_element_t<0, const S>, const std::string >::value, "");
    static_assert(std::is_same< boost::pfr::tuple_element_t<0, volatile S>, volatile std::string >::value, "");
    static_assert(std::is_same< boost::pfr::tuple_element_t<0, const volatile S>, const volatile std::string >::value, "");
  }
}

