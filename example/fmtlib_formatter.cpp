// Copyright (c) 2023 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr.hpp>
#include <fmt/format.h>
#include <type_traits>

namespace boost::pfr {
    struct fmtlib_tag;
}

template<class T> struct fmt::formatter<T, char, std::enable_if_t<
    boost::pfr::is_reflectable<T, boost::pfr::fmtlib_tag>::value>>
{
    constexpr auto parse(format_parse_context& ctx) -> format_parse_context::iterator {
        auto it = ctx.begin(), end = ctx.end();

        if (it != end && *it != '}') throw_format_error("invalid format");

        return it;
    }

    auto format(const T& t, format_context& ctx) const -> format_context::iterator {
        using namespace boost::pfr;

        auto out = ctx.out();

        *out++ = '{';

        const char* div = "";
        constexpr auto names = names_as_array<T>();

        for_each_field(t, [&](const auto& field, auto I) {
            out = fmt::format_to(out, "{}", std::exchange(div, ","));
            out = fmt::format_to(out, " .{}={}", names[I], field);
            });

        out = fmt::format_to(out, "{}", std::strlen(div) == 0 ? "}" : " }");

        return out;
    }
};

struct point
{
    int x, y;
};

struct color
{
    unsigned char r, g, b;
};

struct line
{
    color clr;
    point first, last;
};

template<> struct boost::pfr::is_reflectable<point, boost::pfr::fmtlib_tag> : std::integral_constant<bool, true> {};
template<> struct boost::pfr::is_reflectable<color, boost::pfr::fmtlib_tag> : std::integral_constant<bool, true> {};
template<> struct boost::pfr::is_reflectable<line, boost::pfr::fmtlib_tag> : std::integral_constant<bool, true> {};

int main()
{
    fmt::print("{}\n", line{ { 255, 192, 16 }, { 1, 2 }, { 3, 4 } });
}

