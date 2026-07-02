#include <boost/pfr/core.hpp>

// Structs whose only field is a C-style array.  Without the C++20 fix,
// brace elision in T{ubiq...} lets individual array elements absorb separate
// ubiq values, so fields_count returns the array element count instead of 1.
//
// Note: structs that mix an array field with other fields (e.g.
// struct { int arr[4]; int x; }) are not tested here because the ubiq-based
// field-count probe cannot directly initialize an array member in
// parenthesized aggregate init (arrays are not copy-constructible), so the
// count would be wrong in both C++17 and C++20 modes for such types.

struct single_int_array  { int  data[4];  };
struct single_char_array { char buf[16];  };
struct single_big_array  { int  data[32]; };

int main() {
#if BOOST_PFR_USE_CPP20
    static_assert(boost::pfr::tuple_size_v<single_int_array>  == 1, "single_int_array");
    static_assert(boost::pfr::tuple_size_v<single_char_array> == 1, "single_char_array");
    static_assert(boost::pfr::tuple_size_v<single_big_array>  == 1, "single_big_array");
#endif
}
