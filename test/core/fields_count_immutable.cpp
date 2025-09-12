// Copyright (c) 2025-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Test from https://github.com/boostorg/pfr/issues/126

#include <boost/pfr.hpp>

struct NoCopy {
    NoCopy() = default;
    NoCopy(NoCopy const&) = delete;
    NoCopy(NoCopy&&) = delete;
    NoCopy& operator=(NoCopy&&) = delete;
    NoCopy& operator=(NoCopy const&) = delete;
};

struct Group {
    NoCopy m;
    NoCopy m2;
    NoCopy m3;
    NoCopy m4;
};

Group ReturnGroup() { return {};}

int main()
{   
#ifdef __cpp_lib_is_aggregate
    static_assert(std::is_aggregate_v<Group>, "Group is totally an aggregate");
#endif
    static_assert(BOOST_PFR_HAS_GUARANTEED_COPY_ELISION, "Compiler implements mandatory copy elision");
    Group aggregate_init_test{{}, {}, {}, {}};
    Group elision_test = ReturnGroup();
    return  boost::pfr::tuple_size_v<Group>;
}

