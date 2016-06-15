// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#if __cplusplus < 201402L
#   error C++14 is required for this header.
#endif

#include <type_traits>
#include <utility>      // metaprogramming stuff
#include <tuple>
#include <iosfwd>       // stream operators

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wmissing-braces"
#   pragma clang diagnostic ignored "-Wundefined-inline"
#   pragma clang diagnostic ignored "-Wundefined-internal"
#   pragma clang diagnostic ignored "-Wmissing-field-initializers"
#endif

namespace boost { namespace pfr {

namespace detail {

///////////////////// General utility stuff
template <std::size_t Index>
using size_t_ = std::integral_constant<std::size_t, Index >;

template <class T> struct identity{
    typedef T type;
};



// TODO: this is a helper class for binding to references,
// and it is neither tested nor used...
template <class T>
class reference_wrapper {
public:
  // types
  typedef T type;

  // construct/copy/destroy
  constexpr reference_wrapper() noexcept;   // Must be undefined
  reference_wrapper(T& ref) noexcept : ptr(std::addressof(ref)) {}
  reference_wrapper(T&&) = delete;
  constexpr reference_wrapper(const reference_wrapper&) noexcept = default;

  // assignment
  constexpr reference_wrapper& operator=(const reference_wrapper& x) noexcept = default;

  // access
  constexpr operator const T& () const noexcept { return *ptr; }

  T* ptr;
};

///////////////////// Tuple that holds it's values in the supplied order
namespace sequence_tuple {

template <std::size_t N, class T>
struct base_from_member {
    T value;
};

template <class I, class ...Tail>
struct tuple_base;

template <std::size_t... I, class ...Tail>
struct tuple_base< std::index_sequence<I...>, Tail... >
    : base_from_member<I , Tail>...
{};

template <std::size_t N, class T>
constexpr T& get_impl(base_from_member<N, T>& t) noexcept {
    return t.value;
}

template <std::size_t N, class T>
constexpr const T& get_impl(const base_from_member<N, T>& t) noexcept {
    return t.value;
}

template <std::size_t N, class T>
constexpr volatile T& get_impl(volatile base_from_member<N, T>& t) noexcept {
    return t.value;
}

template <std::size_t N, class T>
constexpr const volatile T& get_impl(const volatile base_from_member<N, T>& t) noexcept {
    return t.value;
}

template <class ...Values>
struct tuple: tuple_base<
        std::make_index_sequence<sizeof...(Values)>,
        Values...
    >
{
    static constexpr std::size_t size_v = sizeof...(Values);
};

template <std::size_t N, class ...T>
constexpr decltype(auto) get(tuple<T...>& t) noexcept {
    static_assert(N < tuple<T...>::size_v, "Tuple index out of bounds");
    return get_impl<N>(t);
}

template <std::size_t N, class ...T>
constexpr decltype(auto) get(const tuple<T...>& t) noexcept {
    static_assert(N < tuple<T...>::size_v, "Tuple index out of bounds");
    return get_impl<N>(t);
}

template <std::size_t N, class ...T>
constexpr decltype(auto) get(const volatile tuple<T...>& t) noexcept {
    static_assert(N < tuple<T...>::size_v, "Tuple index out of bounds");
    return get_impl<N>(t);
}

template <std::size_t N, class ...T>
constexpr decltype(auto) get(volatile tuple<T...>& t) noexcept {
    static_assert(N < tuple<T...>::size_v, "Tuple index out of bounds");
    return get_impl<N>(t);
}

template <std::size_t N, class ...T>
constexpr decltype(auto) get(tuple<T...>&& t) noexcept {
    static_assert(N < tuple<T...>::size_v, "Tuple index out of bounds");
    return std::move(
        get_impl<N>(t)
    );
}

template <size_t I, class T>
using tuple_element = std::remove_reference< decltype(
        ::boost::pfr::detail::sequence_tuple::get<I>( std::declval<T>() )
    ) >;

} // namespace sequence_tuple

using sequence_tuple::get;
using sequence_tuple::tuple;


///////////////////// Array that has the constexpr
template <std::size_t N>
struct size_array {                         // libc++ misses constexpr on operator[]
    typedef std::size_t type;
    std::size_t data[N];

    static constexpr std::size_t size() noexcept { return N; }

    constexpr std::size_t count_nonzeros() const noexcept {
        std::size_t count = 0;
        for (std::size_t i = 0; i < size(); ++i) {
            if (data[i]) {
                ++ count;
            }
        }
        return count;
    }
};

template <>
struct size_array<0> {                         // libc++ misses constexpr on operator[]
    typedef std::size_t type;
    std::size_t data[1];

    static constexpr std::size_t size() noexcept { return 0; }

    constexpr std::size_t count_nonzeros() const noexcept {
        return 0;
    }
};

template <std::size_t I, std::size_t N>
constexpr std::size_t get(const size_array<N>& a) noexcept {
    static_assert(I < N, "Array index out of bounds");
    return a.data[I];
}


template <class T> constexpr size_array<sizeof(T)> fields_count_and_type_ids_with_zeros(std::enable_if_t<!std::is_empty<T>::value>* = 0) noexcept;
template <class T> constexpr size_array<0> fields_count_and_type_ids_with_zeros(std::enable_if_t<std::is_empty<T>::value>* = 0) noexcept;

///////////////////// All the stuff for representing Type as integer and converting integer back to type
namespace typeid_conversions {

///////////////////// Helper constants and typedefs
constexpr std::size_t native_types_mask = 31;
constexpr std::size_t bits_per_extension = 3;
constexpr std::size_t extension_maks = (
    static_cast<std::size_t>((1 << bits_per_extension) - 1)
        << static_cast<std::size_t>(sizeof(std::size_t) * 8 - bits_per_extension)
);
constexpr std::size_t native_ptr_type = (
    static_cast<std::size_t>(1)
        << static_cast<std::size_t>(sizeof(std::size_t) * 8 - bits_per_extension)
);
constexpr std::size_t native_const_ptr_type = (
    static_cast<std::size_t>(2)
        << static_cast<std::size_t>(sizeof(std::size_t) * 8 - bits_per_extension)
);

constexpr std::size_t native_const_volatile_ptr_type = (
    static_cast<std::size_t>(3)
        << static_cast<std::size_t>(sizeof(std::size_t) * 8 - bits_per_extension)
);

constexpr std::size_t native_volatile_ptr_type = (
    static_cast<std::size_t>(4)
        << static_cast<std::size_t>(sizeof(std::size_t) * 8 - bits_per_extension)
);

constexpr std::size_t native_ref_type = (
    static_cast<std::size_t>(5)
        << static_cast<std::size_t>(sizeof(std::size_t) * 8 - bits_per_extension)
);

template <std::size_t Index, std::size_t Extension>
using if_extension = std::enable_if_t< (Index & extension_maks) == Extension >*;

///////////////////// Helper functions
template <std::size_t Unptr>
constexpr std::size_t type_to_id_extension_apply(std::size_t ext) noexcept {
    constexpr std::size_t native_id = (Unptr & native_types_mask);
    constexpr std::size_t extensions = (Unptr & ~native_types_mask);
    static_assert(
        !((extensions >> bits_per_extension) & native_types_mask),
        "Too many extensions for a single field (something close to `int************************** p;` is in the POD type)."
    );

    return (extensions >> bits_per_extension) | native_id | ext;
}

template <std::size_t Index>
using remove_1_ext = size_t_<
    ((Index & ~native_types_mask) << bits_per_extension) | (Index & native_types_mask)
>;


///////////////////// Forward declarations

template <class Type> constexpr std::size_t type_to_id(identity<Type*>) noexcept;
template <class Type> constexpr std::size_t type_to_id(identity<const Type*>) noexcept;
template <class Type> constexpr std::size_t type_to_id(identity<const volatile Type*>) noexcept;
template <class Type> constexpr std::size_t type_to_id(identity<volatile Type*>) noexcept;
template <class Type> constexpr std::size_t type_to_id(identity<Type&>) noexcept;
template <class Type> constexpr std::size_t type_to_id(identity<Type>, std::enable_if_t<std::is_enum<Type>::value>* = 0) noexcept;
template <class Type> constexpr std::size_t type_to_id(identity<Type>, std::enable_if_t<std::is_empty<Type>::value>* = 0) noexcept;
template <class Type> constexpr size_array<sizeof(Type)> type_to_id(identity<Type>, std::enable_if_t<!std::is_enum<Type>::value && !std::is_empty<Type>::value>* = 0) noexcept;

template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_const_ptr_type> = 0) noexcept;
template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_ptr_type> = 0) noexcept;
template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_const_volatile_ptr_type> = 0) noexcept;
template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_volatile_ptr_type> = 0) noexcept;
template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_ref_type> = 0) noexcept;


///////////////////// Definitions of type_to_id and id_to_type for fundamental types
/// @cond
#define BOOST_MAGIC_GET_REGISTER_TYPE(Type, Index)              \
    constexpr std::size_t type_to_id(identity<Type>) noexcept { \
        return Index;                                           \
    }                                                           \
    constexpr Type id_to_type( size_t_<Index > ) noexcept {     \
        Type res{};                                             \
        return res;                                             \
    }                                                           \
    /**/
/// @endcond


// Register all base types here
BOOST_MAGIC_GET_REGISTER_TYPE(unsigned char         , 1)
BOOST_MAGIC_GET_REGISTER_TYPE(unsigned short        , 2)
BOOST_MAGIC_GET_REGISTER_TYPE(unsigned int          , 3)
BOOST_MAGIC_GET_REGISTER_TYPE(unsigned long         , 4)
BOOST_MAGIC_GET_REGISTER_TYPE(unsigned long long    , 5)
BOOST_MAGIC_GET_REGISTER_TYPE(signed char           , 6)
BOOST_MAGIC_GET_REGISTER_TYPE(short                 , 7)
BOOST_MAGIC_GET_REGISTER_TYPE(int                   , 8)
BOOST_MAGIC_GET_REGISTER_TYPE(long                  , 9)
BOOST_MAGIC_GET_REGISTER_TYPE(long long             , 10)
BOOST_MAGIC_GET_REGISTER_TYPE(char                  , 11)
BOOST_MAGIC_GET_REGISTER_TYPE(wchar_t               , 12)
BOOST_MAGIC_GET_REGISTER_TYPE(char16_t              , 13)
BOOST_MAGIC_GET_REGISTER_TYPE(char32_t              , 14)
BOOST_MAGIC_GET_REGISTER_TYPE(float                 , 15)
BOOST_MAGIC_GET_REGISTER_TYPE(double                , 16)
BOOST_MAGIC_GET_REGISTER_TYPE(long double           , 17)
BOOST_MAGIC_GET_REGISTER_TYPE(bool                  , 18)
BOOST_MAGIC_GET_REGISTER_TYPE(void*                 , 19)
BOOST_MAGIC_GET_REGISTER_TYPE(const void*           , 20)
BOOST_MAGIC_GET_REGISTER_TYPE(volatile void*        , 21)
BOOST_MAGIC_GET_REGISTER_TYPE(const volatile void*  , 22)
BOOST_MAGIC_GET_REGISTER_TYPE(std::nullptr_t        , 23)

#undef BOOST_MAGIC_GET_REGISTER_TYPE

///////////////////// Definitions of type_to_id and id_to_type for types with extensions and nested types
template <class Type>
constexpr std::size_t type_to_id(identity<Type*>) noexcept {
    constexpr auto unptr = type_to_id(identity<Type>{});
    static_assert(
        std::is_same<const std::size_t, decltype(unptr)>::value,
        "Pointers to user defined types are not supported."
    );
    return type_to_id_extension_apply<unptr>(native_ptr_type);
}

template <class Type>
constexpr std::size_t type_to_id(identity<const Type*>) noexcept {
    constexpr auto unptr = type_to_id(identity<Type>{});
    static_assert(
        std::is_same<const std::size_t, decltype(unptr)>::value,
        "Const pointers to user defined types are not supported."
    );
    return type_to_id_extension_apply<unptr>(native_const_ptr_type);
}

template <class Type>
constexpr std::size_t type_to_id(identity<const volatile Type*>) noexcept {
    constexpr auto unptr = type_to_id(identity<Type>{});
    static_assert(
        std::is_same<const std::size_t, decltype(unptr)>::value,
        "Const volatile pointers to user defined types are not supported."
    );
    return type_to_id_extension_apply<unptr>(native_const_volatile_ptr_type);
}

template <class Type>
constexpr std::size_t type_to_id(identity<volatile Type*>) noexcept {
    constexpr auto unptr = type_to_id(identity<Type>{});
    static_assert(
        std::is_same<const std::size_t, decltype(unptr)>::value,
        "Volatile pointers to user defined types are not supported."
    );
    return type_to_id_extension_apply<unptr>(native_volatile_ptr_type);
}

template <class Type>
constexpr std::size_t type_to_id(identity<Type&>) noexcept {
    constexpr auto unptr = type_to_id(identity<Type>{});
    static_assert(
        std::is_same<const std::size_t, decltype(unptr)>::value,
        "References to user defined types are not supported."
    );
    return type_to_id_extension_apply<unptr>(native_ref_type);
}

template <class Type>
constexpr std::size_t type_to_id(identity<Type>, std::enable_if_t<std::is_enum<Type>::value>*) noexcept {
    return type_to_id(identity<typename std::underlying_type<Type>::type >{});
}

template <class Type>
constexpr std::size_t type_to_id(identity<Type>, std::enable_if_t<std::is_empty<Type>::value>*) noexcept {
    static_assert(!std::is_empty<Type>::value, "Empty classes/structures as members are not supported.");
    return 0;
}

template <class Type>
constexpr size_array<sizeof(Type)> type_to_id(identity<Type>, std::enable_if_t<!std::is_enum<Type>::value && !std::is_empty<Type>::value>*) noexcept {
    return fields_count_and_type_ids_with_zeros<Type>();
}



template <std::size_t Index>
constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_ptr_type>) noexcept {
    typedef decltype( id_to_type(remove_1_ext<Index>()) )* res_t;
    return res_t{};
}

template <std::size_t Index>
constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_const_ptr_type>) noexcept {
    typedef const decltype( id_to_type(remove_1_ext<Index>()) )* res_t;
    return res_t{};
}

template <std::size_t Index>
constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_const_volatile_ptr_type>) noexcept {
    typedef const volatile decltype( id_to_type(remove_1_ext<Index>()) )* res_t;
    return res_t{};
}


template <std::size_t Index>
constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_volatile_ptr_type>) noexcept {
    typedef volatile decltype( id_to_type(remove_1_ext<Index>()) )* res_t;
    return res_t{};
}


template <std::size_t Index>
constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_ref_type>) noexcept {
    typedef reference_wrapper<decltype( id_to_type(remove_1_ext<Index>()) )> res_t;
    return res_t{};
}

} // namespace typeid_conversions

///////////////////// Structure that remembers types as integers on a `constexpr operator Type()` call
struct ubiq_val {
    std::size_t* ref_;

    template <class T>
    constexpr void assign(const T& typeids) const noexcept {
        for (std::size_t i = 0; i < T::size(); ++i)
            ref_[i] = typeids.data[i];
    }

    constexpr void assign(std::size_t val) const noexcept {
        ref_[0] = val;
    }

    template <class Type>
    constexpr operator Type() const noexcept {
        constexpr auto typeids = typeid_conversions::type_to_id(identity<Type>{});
        assign(typeids);
        return Type{};
    }
};

///////////////////// Structure that remembers types as integers on a `constexpr operator Type&()` call
// Not used right now
struct ubiq_ref {
    std::size_t* ref_;

    template <class T>
    constexpr void assign(const T& ) const noexcept {
        static_assert(!sizeof(T), "References to structures are not allowed");
    }

    constexpr void assign(std::size_t val) const noexcept {
        ref_[0] = val;
    }

    template <class Type>
    constexpr operator Type&() const noexcept {
        constexpr auto typeids = typeid_conversions::type_to_id(identity<Type&>{});
        assign(typeids);
        Type local{};
        return local;
    }
};

///////////////////// Structure that can be converted to reference to anything
struct ubiq_constructor {
    std::size_t ignore;
    template <class Type> constexpr operator Type&() const noexcept; // Undefined
};

///////////////////// Structure that can be converted to reference to anything except reference to T
template <class T>
struct ubiq_constructor_except {
    std::size_t ignore;

    template <class Type> constexpr operator std::enable_if_t<!std::is_same<T, Type>::value, Type&> () const noexcept; // Undefined
};

///////////////////// Structure that remembers size of the type on a `constexpr operator Type()` call
struct ubiq_sizes {
    std::size_t& ref_;

    template <class Type>
    constexpr operator Type() const noexcept {
        ref_ = sizeof(Type);
        return Type{};
    }
};

///////////////////// Returns array of (offsets without accounting alignments). Required for keeping places for nested type ids
template <class T, std::size_t N, std::size_t... I>
constexpr size_array<N> get_type_offsets() noexcept {
    typedef size_array<N> array_t;
    array_t sizes{};
    T tmp{ ubiq_sizes{sizes.data[I]}... };
    (void)tmp;

    array_t offsets{{0}};
    for (std::size_t i = 1; i < N; ++i)
        offsets.data[i] = offsets.data[i - 1] + sizes.data[i - 1];

    return offsets;
}

template <class T, std::size_t... I>
constexpr std::false_type has_reference_members(
        std::size_t* misc,
        decltype(T{ ubiq_sizes{misc[I]}... })* = 0
    ) noexcept;


template <class T, std::size_t... I>
constexpr std::true_type has_reference_members(void*) noexcept;

// `std::is_constructible<T, ubiq_constructor_except<T>>` consumes a lot of time, so we made a separate lazy trait for it.
template <std::size_t N, class T> struct is_single_field_aggregate_uninitializable: std::false_type {};
template <class T> struct is_single_field_aggregate_uninitializable<1, T>: std::is_constructible<T, ubiq_constructor_except<T>> {};

///////////////////// Returns array of typeids and zeros if construtor of a type accepts sizeof...(I) parameters, substitution failure otherwise
template <class T, std::size_t N, std::size_t... I>
constexpr auto type_to_array_of_type_ids(std::size_t* types, std::index_sequence<I...>) noexcept
    -> typename std::add_pointer<decltype(T{ ubiq_constructor{I}... })>::type
{
    static_assert(
        !decltype(has_reference_members<T, I...>(types))::value,
        "Reference members are not supported."
    );

    static_assert(
        N <= sizeof(T),
        "Bit fields are not supported."
    );

    // Hand-made is_aggregate<T> trait:
    // Aggregates could be constructed from `decltype(ubiq_constructor{I})...` but report that there's no constructor from `decltype(ubiq_constructor{I})...`
    // Special case for N == 1: `std::is_constructible<T, ubiq_constructor>` returns true if N == 1 and T is copy/move constructible.
    static_assert(
        std::is_array<T>::value || std::is_fundamental<T>::value
                || !std::is_constructible<T, decltype(ubiq_constructor{I})...>::value
                || !is_single_field_aggregate_uninitializable<N, T>::value,
        "Types with user specified constructors (non-aggregate types) are not supported."
    );

    constexpr auto offsets = get_type_offsets<T, N, I...>();
    T tmp{ ubiq_val{types + get<I>(offsets)}... };
    (void)tmp;
    return nullptr;
}

///////////////////// Methods for detecting max parameters for construction of T, return array of typeids and zeros
template <class T, std::size_t N>
constexpr void detect_fields_count_and_type_ids(std::size_t* types, size_t_<N>, size_t_<N>, long) noexcept {
    type_to_array_of_type_ids<T, N>(types, std::make_index_sequence<N>());
}

template <class T, std::size_t Begin, std::size_t Middle>
constexpr void detect_fields_count_and_type_ids(std::size_t* types, size_t_<Begin>, size_t_<Middle>, int) noexcept;

template <class T, std::size_t Begin, std::size_t Middle>
constexpr auto detect_fields_count_and_type_ids(std::size_t* types, size_t_<Begin>, size_t_<Middle>, long) noexcept
    -> decltype( type_to_array_of_type_ids<T, Middle>(types, std::make_index_sequence<Middle>()) )
{
    constexpr std::size_t next = Middle + (Middle - Begin + 1) / 2;
    detect_fields_count_and_type_ids<T>(types, size_t_<Middle>{}, size_t_<next>{}, 1L);
    return nullptr;
}

template <class T, std::size_t Begin, std::size_t Middle>
constexpr void detect_fields_count_and_type_ids(std::size_t* types, size_t_<Begin>, size_t_<Middle>, int) noexcept {
    constexpr std::size_t next = (Begin + Middle) / 2;
    detect_fields_count_and_type_ids<T>(types, size_t_<Begin>{}, size_t_<next>{}, 1L);
}



///////////////////// Returns array of typeids and zeros
template <class T>
constexpr size_array<sizeof(T)> fields_count_and_type_ids_with_zeros(std::enable_if_t<!std::is_empty<T>::value>*) noexcept {
    size_array<sizeof(T)> types{};
    constexpr std::size_t next = sizeof(T) / 2 + 1;
    detect_fields_count_and_type_ids<T>(types.data, size_t_<1>{}, size_t_<next>{}, 1L);
    return types;
}

template <class T>
constexpr size_array<0> fields_count_and_type_ids_with_zeros(std::enable_if_t<std::is_empty<T>::value>*) noexcept {
    return size_array<0>{0};
}

///////////////////// Returns array of typeids without zeros
template <class T>
constexpr auto array_of_type_ids() noexcept {
    constexpr auto types = fields_count_and_type_ids_with_zeros<T>();
    constexpr std::size_t count = types.count_nonzeros();
    size_array<count> res{};
    std::size_t j = 0;
    for (std::size_t i = 0; i < decltype(types)::size(); ++i) {
        if (types.data[i]) {
            res.data[j] = types.data[i];
            ++ j;
        }
    }

    return res;
}

///////////////////// Convert array of typeids into sequence_tuple::tuple
template <class T, std::size_t... I>
constexpr auto as_tuple_impl(std::index_sequence<I...>) noexcept {
    constexpr auto a = array_of_type_ids<T>();
    return tuple<
        decltype(typeid_conversions::id_to_type(
            size_t_<get<I>(a)>{}
        ))...
    >{};
}

template <class T>
constexpr tuple<> as_tuple_impl(std::index_sequence<>) noexcept {
    return tuple<>{};
}

template <class T>
constexpr auto as_tuple() noexcept {
    typedef typename std::remove_cv<T>::type type;

    static_assert(std::is_pod<type>::value, "Not applyable");
    static_assert(!std::is_reference<type>::value, "Not applyable");
    constexpr auto res = as_tuple_impl<type>(
        std::make_index_sequence< decltype(array_of_type_ids<type>())::size() >()
    );

    static_assert(
        std::alignment_of<decltype(res)>::value == std::alignment_of<type>::value,
        "Alignment check failed, probably your structure has user-defined alignment for the whole structure or for some of the fields."
    );
    static_assert(sizeof(res) == sizeof(type), "Size check failed, probably your structure has bitfields or user-defined alignment.");

    return res;
}

template <class T>
using as_tuple_t = decltype( as_tuple<T>() );

template <class T, std::size_t... I>
auto flat_make_tuple_impl(const T& t, std::index_sequence<I...>) noexcept {
    return std::make_tuple(
        sequence_tuple::get<I>(t)...
    );
}

template <class T, std::size_t... I>
auto flat_tie_impl(T& t, std::index_sequence<I...>) noexcept {
    return std::tie(
        sequence_tuple::get<I>(t)...
    );
}

template <class From, class To>
struct teleport_extents {
    typedef To type;
};

template <class From, class To>
struct teleport_extents<const From, To> {
    typedef const To type;
};

template <class From, class To>
struct teleport_extents<const volatile From, To> {
    typedef const volatile To type;
};

template <class From, class To>
struct teleport_extents<volatile From, To> {
    typedef volatile To type;
};

} // namespace detail

#ifdef __clang__
#   pragma clang diagnostic pop
#endif

/// @cond
#ifdef __GNUC__
#define MAY_ALIAS __attribute__((__may_alias__))
#else
#define MAY_ALIAS
#endif
/// @endcond

/// \brief Returns reference or const reference to a field with index `I` in \flattening{flattened} T.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s {10, 11};
///     assert(boost::pfr::get<0>(s) == 10);
///     boost::pfr::get<1>(s) = 0;
/// \endcode
template <std::size_t I, class T>
decltype(auto) get(const T& val) noexcept {
    MAY_ALIAS const auto* const t = reinterpret_cast<const detail::as_tuple_t<T>*>( std::addressof(val) );
    return detail::sequence_tuple::get<I>(*t);
}


/// \overload get
template <std::size_t I, class T>
decltype(auto) get(T& val /* @cond */, std::enable_if_t< std::is_trivially_assignable<T, T>::value>* = 0/* @endcond */ ) noexcept {
    MAY_ALIAS auto* const t = reinterpret_cast<detail::as_tuple_t<T>*>( std::addressof(val) );
    return detail::sequence_tuple::get<I>(*t);
}


/// \brief `flat_tuple_element` has a `typedef type-of-a-field-with-index-I-in-\flattening{flattened}-T type;`
///
/// \b Example:
/// \code
///     std::vector<  boost::pfr::flat_tuple_element<0, my_structure>::type  > v;
/// \endcode
template <std::size_t I, class T>
using flat_tuple_element = detail::teleport_extents<
        T,
        typename detail::sequence_tuple::tuple_element<I, detail::as_tuple_t<T> >::type
    >;


/// \brief Type of a field with index `I` in \flattening{flattened} `T`
///
/// \b Example:
/// \code
///     std::vector<  boost::pfr::flat_tuple_element_t<0, my_structure>  > v;
/// \endcode
template <std::size_t I, class T>
using flat_tuple_element_t = typename flat_tuple_element<I, T>::type;


/// \brief has a member `value` that constins fields count in a \flattening{flattened} T.
///
/// \b Example:
/// \code
///     std::array<int, boost::pfr::flat_tuple_size<my_structure>::value > a;
/// \endcode
template <class T>
using flat_tuple_size = detail::size_t_< detail::as_tuple_t<T>::size_v >;


/// \brief `flat_tuple_size_v` is a template variable that constins fields count in a \flattening{flattened} T.
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
///     assert(get<0>(t) == 10);
/// \endcode
template <class T>
auto flat_make_tuple(const T& val) noexcept {
    typedef detail::as_tuple_t<T> internal_tuple_t;
    MAY_ALIAS const internal_tuple_t& t = *reinterpret_cast<const internal_tuple_t*>( std::addressof(val) );
    return detail::flat_make_tuple_impl(
        t,
        std::make_index_sequence< internal_tuple_t::size_v >()
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
///     flat_tie(s) = std::tuple<int, short>{10, 11};
///     assert(s.s == 11);
/// \endcode
template <class T>
auto flat_tie(T& val /* @cond */, std::enable_if_t< std::is_trivially_assignable<T, T>::value>* = 0 /* @endcond */) noexcept {
    typedef detail::as_tuple_t<T> internal_tuple_t;
    MAY_ALIAS internal_tuple_t& t = *reinterpret_cast<internal_tuple_t*>( std::addressof(val) );
    return detail::flat_tie_impl(
        t,
        std::make_index_sequence< internal_tuple_t::size_v >()
    );
}

#undef MAY_ALIAS


namespace detail {
    template <std::size_t I, std::size_t N>
    struct flat_print_impl {
        template <class Stream, class T>
        static void print (Stream& out, const T& value) {
            if (!!I) out << ", ";
            out << ::boost::pfr::get<I>(value);
            flat_print_impl<I + 1, N>::print(out, value);
        }
    };

    template <std::size_t I>
    struct flat_print_impl<I, I> {
        template <class Stream, class T> static void print (Stream&, const T&) noexcept {}
    };
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
    detail::flat_print_impl<0, flat_tuple_size_v<T> >::print(out, value);
    out << '}';
}


namespace detail {
    template <std::size_t I, std::size_t N>
    struct flat_read_impl {
        template <class Stream, class T>
        static void read (Stream& in, T& value) {
            char ignore = {};
            if (!!I) {
                in >> ignore;
                if (ignore != ',') in.setstate(Stream::failbit);
                in >> ignore;
                if (ignore != ' ')  in.setstate(Stream::failbit);
            }
            in >> ::boost::pfr::get<I>(value);
            flat_read_impl<I + 1, N>::read(in, value);
        }
    };

    template <std::size_t I>
    struct flat_read_impl<I, I> {
        template <class Stream, class T> static void read (Stream&, const T&) {}
    };
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
    detail::flat_read_impl<0, flat_tuple_size_v<T> >::read(in, value);

    in >> parenthis;
    if (parenthis != '}') in.setstate(std::basic_istream<Char, Traits>::failbit);

    in.flags(prev_flags);
    in.exceptions(prev_exceptions);
}

}} // namespace boost::pfr
