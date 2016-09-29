// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_CORE_HPP
#define BOOST_PFR_CORE_HPP

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
{
    template <class... Arg>
    constexpr tuple_base(Arg&&... v) noexcept
        : base_from_member<I, Tail>{ std::forward<Arg>(v) }...
    {}


    constexpr tuple_base() noexcept = default;
    constexpr tuple_base(tuple_base&&) noexcept = default;
    constexpr tuple_base(const tuple_base&) noexcept = default;

    static constexpr std::size_t size_v = sizeof...(I);
};
/*
template <class T>
struct tuple_base< std::index_sequence<0>, T >
    : base_from_member<0, T>
{
    template <class Arg>
    constexpr tuple_base(Arg&& v)
        : base_from_member<0, T>{ std::forward<Arg>(v) }
    {}

    static constexpr std::size_t size_v = 1;
};*/

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

template <std::size_t N, class T>
constexpr T&& get_impl(base_from_member<N, T>&& t) noexcept {
    return std::forward<T>(t.value);
}

template <class ...Values>
using tuple = tuple_base<
        std::make_index_sequence<sizeof...(Values)>,
        Values...
    >;

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
    return get_impl<N>(std::move(t));
}

template <size_t I, class T>
using tuple_element = std::remove_reference< decltype(
        ::boost::pfr::detail::sequence_tuple::get<I>( std::declval<T>() )
    ) >;


} // namespace sequence_tuple





template <std::size_t I, std::size_t N>
struct print_impl {
    template <class Stream, class T>
    static void print (Stream& out, const T& value) {
        if (!!I) out << ", ";
        out << boost::pfr::detail::sequence_tuple::get<I>(value);
        print_impl<I + 1, N>::print(out, value);
    }
};

template <std::size_t I>
struct print_impl<I, I> {
    template <class Stream, class T> static void print (Stream&, const T&) noexcept {}
};


template <std::size_t I, std::size_t N>
struct read_impl {
    template <class Stream, class T>
    static void read (Stream& in, const T& value) {
        char ignore = {};
        if (!!I) {
            in >> ignore;
            if (ignore != ',') in.setstate(Stream::failbit);
            in >> ignore;
            if (ignore != ' ')  in.setstate(Stream::failbit);
        }
        in >> boost::pfr::detail::sequence_tuple::get<I>(value);
        read_impl<I + 1, N>::read(in, value);
    }
};

template <std::size_t I>
struct read_impl<I, I> {
    template <class Stream, class T> static void read (Stream&, const T&) {}
};


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

    constexpr std::size_t count_from_opening_till_matching_parenthis_seq(std::size_t from, std::size_t opening_parenthis, std::size_t closing_parenthis) const noexcept {
        if (data[from] != opening_parenthis) {
            return 0;
        }
        std::size_t unclosed_parnthesis = 0;
        std::size_t count = 0;
        for (; ; ++from) {
            if (data[from] == opening_parenthis) {
                ++ unclosed_parnthesis;
            } else if (data[from] == closing_parenthis) {
                -- unclosed_parnthesis;
            }
            ++ count;

            if (unclosed_parnthesis == 0) {
                return count;
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


template <class T> constexpr size_array<sizeof(T) * 3> fields_count_and_type_ids_with_zeros() noexcept;
template <class T> constexpr auto flat_array_of_type_ids() noexcept;

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
template <class Type> constexpr size_array<sizeof(Type) * 3> type_to_id(identity<Type>, std::enable_if_t<!std::is_enum<Type>::value && !std::is_empty<Type>::value>* = 0) noexcept;

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
constexpr std::size_t tuple_begin_tag               = 24;
constexpr std::size_t tuple_end_tag                 = 25;

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
constexpr size_array<sizeof(Type) * 3> type_to_id(identity<Type>, std::enable_if_t<!std::is_enum<Type>::value && !std::is_empty<Type>::value>*) noexcept {
    constexpr auto  t = flat_array_of_type_ids<Type>();
    size_array<sizeof(Type) * 3> result {{tuple_begin_tag}};
    constexpr bool requires_tuplening = (
        (t.count_nonzeros() != 1)  || (t.count_nonzeros() == t.count_from_opening_till_matching_parenthis_seq(0, tuple_begin_tag, tuple_end_tag))
    );

    if (requires_tuplening) {
        for (std::size_t i = 0; i < t.size(); ++i)
            result.data[i + 1] = t.data[i];
        result.data[result.size() - 1] = tuple_end_tag;
    } else {
        for (std::size_t i = 0; i < t.size(); ++i)
            result.data[i] = t.data[i];
    }
    return result;
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
    static_assert(!Index, "References are not supported");
    return nullptr;
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
template <std::size_t N, class T> struct is_single_field_and_aggregate_initializable: std::false_type {};
template <class T> struct is_single_field_and_aggregate_initializable<1, T>: std::integral_constant<
    bool, !std::is_constructible<T, ubiq_constructor_except<T>>::value
> {};


///////////////////// Hand-made is_aggregate_initializable_n<T> trait:
template <class T, std::size_t N>
struct is_aggregate_initializable_n {
    template <std::size_t ...I>
    static constexpr bool is_not_constructible_n(std::index_sequence<I...>) noexcept {
        return !std::is_constructible<T, decltype(ubiq_constructor{I})...>::value
            || is_single_field_and_aggregate_initializable<N, T>::value
        ;
    }

    static constexpr bool value =
           std::is_empty<T>::value
        || std::is_fundamental<T>::value
        || is_not_constructible_n(std::make_index_sequence<N>{})
    ;
};

///////////////////// Returns array of typeids and zeros if construtor of a type accepts sizeof...(I) parameters, substitution failure otherwise
template <class T, std::size_t N, std::size_t... I>
constexpr auto flat_type_to_array_of_type_ids(std::size_t* types, std::index_sequence<I...>) noexcept
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

    constexpr auto offsets = get_type_offsets<T, N, I...>();
    T tmp{ ubiq_val{types + get<I>(offsets) * 3}... };
    (void)tmp;
    (void)offsets; // If type is empty offsets are not used
    return nullptr;
}

///////////////////// Methods for detecting max parameters for construction of T
template <class T, std::size_t N>
constexpr void detect_fields_count(std::size_t& count, size_t_<N>, size_t_<N>, long) noexcept {
    // Hand-made is_aggregate<T> trait:
    // Aggregates could be constructed from `decltype(ubiq_constructor{I})...` but report that there's no constructor from `decltype(ubiq_constructor{I})...`
    // Special case for N == 1: `std::is_constructible<T, ubiq_constructor>` returns true if N == 1 and T is copy/move constructible.
    static_assert(
        is_aggregate_initializable_n<T, N>::value,
        "Types with user specified constructors (non-aggregate types) are not supported."
    );

    count = N;
}

template <class T, std::size_t Begin, std::size_t Middle>
constexpr void detect_fields_count(std::size_t& count, size_t_<Begin>, size_t_<Middle>, int) noexcept;

template <class T, std::size_t Begin, std::size_t Middle>
constexpr auto detect_fields_count(std::size_t& count, size_t_<Begin>, size_t_<Middle>, long) noexcept
    -> decltype( flat_type_to_array_of_type_ids<T, Middle>(nullptr, std::make_index_sequence<Middle>()) )
{
    constexpr std::size_t next = Middle + (Middle - Begin + 1) / 2;
    detect_fields_count<T>(count, size_t_<Middle>{}, size_t_<next>{}, 1L);
    return nullptr;
}

template <class T, std::size_t Begin, std::size_t Middle>
constexpr void detect_fields_count(std::size_t& count, size_t_<Begin>, size_t_<Middle>, int) noexcept {
    constexpr std::size_t next = (Begin + Middle) / 2;
    detect_fields_count<T>(count, size_t_<Begin>{}, size_t_<next>{}, 1L);
}

///////////////////// Returns non-flattened fields count
template <class T>
constexpr std::size_t fields_count() noexcept {
    std::size_t res = 0u;
    constexpr std::size_t next = sizeof(T) / 2 + 1;
    detect_fields_count<T>(res, size_t_<0>{}, size_t_<next>{}, 1L);
    return res;
}

///////////////////// Returns array of typeids and zeros
template <class T>
constexpr size_array<sizeof(T) * 3> fields_count_and_type_ids_with_zeros() noexcept {
    size_array<sizeof(T) * 3> types{};
    constexpr std::size_t N = fields_count<T>();
    flat_type_to_array_of_type_ids<T, N>(types.data, std::make_index_sequence<N>());
    return types;
}

///////////////////// Returns array of typeids without zeros
template <class T>
constexpr auto flat_array_of_type_ids() noexcept {
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

template <class T, std::size_t First, std::size_t... I>
constexpr auto as_flat_tuple_impl(std::index_sequence<First, I...>) noexcept;

template <class T>
constexpr auto as_flat_tuple_impl(std::index_sequence<>) noexcept {
    return sequence_tuple::tuple<>{};
}

template <std::size_t Increment, std::size_t... I>
constexpr auto increment_index_sequence(std::index_sequence<I...>) noexcept {
    return std::index_sequence<I + Increment...>{};
}

template <class T, std::size_t V, std::size_t I>
constexpr auto prepare_subtuples(size_t_<V>, size_t_<I>) noexcept {
    return typeid_conversions::id_to_type(size_t_<V>{});
}

struct end_cleanup_tag{};

template <class T, std::size_t I>
constexpr end_cleanup_tag prepare_subtuples(size_t_<typeid_conversions::tuple_end_tag>, size_t_<I>) noexcept {
    return end_cleanup_tag{};
}

template <class T, std::size_t I>
constexpr auto prepare_subtuples(size_t_<typeid_conversions::tuple_begin_tag>, size_t_<I>) noexcept {
    constexpr auto a = flat_array_of_type_ids<T>();
    constexpr std::size_t subtuple_size = a.count_from_opening_till_matching_parenthis_seq(I, typeid_conversions::tuple_begin_tag, typeid_conversions::tuple_end_tag);
    static_assert(subtuple_size > 2, "Internal error while representing nested field as tuple");
    constexpr auto seq = std::make_index_sequence<subtuple_size - 2>{};
    return as_flat_tuple_impl<T>( increment_index_sequence<I + 1>(seq) );
}


constexpr size_array<0> make_array() noexcept {
    return {};
}

template <std::size_t... I>
constexpr auto make_array(std::index_sequence<I...>) noexcept {
    return size_array<sizeof...(I)>{{I...}};
}

template <std::size_t... I0, std::size_t... I1, class... Others>
constexpr auto make_array(std::index_sequence<I0...>, std::index_sequence<I1...>, Others... vals) noexcept {
    return make_array(std::index_sequence<I0..., I1...>{}, vals...);
}

template <std::size_t... I0, std::size_t... I1, std::size_t... I2, class... Others>
constexpr auto make_array(std::index_sequence<I0...>, std::index_sequence<I1...>, std::index_sequence<I2...>, Others... vals) noexcept {
    return make_array(std::index_sequence<I0..., I1..., I2...>{}, vals...);
}

template <std::size_t... I0, std::size_t... I1, std::size_t... I2, std::size_t... I3, class... Others>
constexpr auto make_array(std::index_sequence<I0...>, std::index_sequence<I1...>, std::index_sequence<I2...>, std::index_sequence<I3...>, Others... vals) noexcept {
    return make_array(std::index_sequence<I0..., I1..., I2..., I3...>{}, vals...);
}

template <std::size_t N, std::size_t I>
constexpr auto empty_or_sequence(size_t_<N>, size_t_<I>) noexcept {
    return increment_index_sequence<1 + I>(std::make_index_sequence<N - 1>{});
}

template <std::size_t I>
constexpr std::index_sequence<> empty_or_sequence(size_t_<0>, size_t_<I>) noexcept {
    return {};
}

template <class ArrayFrom, class ArraySkips>
constexpr ArrayFrom remove_skips(ArrayFrom indexes_plus_1, const ArraySkips& skips) noexcept { // TODO: optimize
    for (std::size_t i = 0; i < skips.size(); ++i) {
        indexes_plus_1.data[ skips.data[i] ] = 0;
    }
    return indexes_plus_1;
}

template <std::size_t N, class Array>
constexpr size_array<N> resize_dropping_zeros_and_decrementing(size_t_<N>, const Array& a) noexcept {
    size_array<N> result{};
    std::size_t result_indx = 0;
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (a.data[i]) {
            result.data[result_indx] = static_cast<std::size_t>(a.data[i] - 1);
            ++ result_indx;
        }
    }

    return result;
}

template <class T, class SubtuplesUncleanupped, std::size_t First, std::size_t... I, std::size_t... INew>
constexpr auto as_flat_tuple_impl_drop_helpers(std::index_sequence<First, I...>, std::index_sequence<INew...>) noexcept {
    constexpr auto a = flat_array_of_type_ids<T>();
    (void)a; // `a` is unused if T is an empty type

    constexpr auto skips_in_subtuples = make_array(
        empty_or_sequence(
            size_t_<a.count_from_opening_till_matching_parenthis_seq(First, typeid_conversions::tuple_begin_tag, typeid_conversions::tuple_end_tag) >{}, size_t_<First - First>{}
        ),
        empty_or_sequence(
            size_t_<a.count_from_opening_till_matching_parenthis_seq(I, typeid_conversions::tuple_begin_tag, typeid_conversions::tuple_end_tag) >{}, size_t_<I - First>{}
        )...
    );

    constexpr auto indexes_in_subtuples_uncleanuped = make_array(std::index_sequence<1, 1 + I - First...>{});
    constexpr auto indexes_plus_1_and_zeros_as_skips_in_subtuples = remove_skips(indexes_in_subtuples_uncleanuped, skips_in_subtuples);
    constexpr auto new_size = size_t_<indexes_plus_1_and_zeros_as_skips_in_subtuples.count_nonzeros()>{};
    constexpr auto indexes_in_subtuples = resize_dropping_zeros_and_decrementing(new_size, indexes_plus_1_and_zeros_as_skips_in_subtuples);

    return sequence_tuple::tuple<
        typename sequence_tuple::tuple_element<indexes_in_subtuples.data[INew], SubtuplesUncleanupped>::type...
    >{};
}

template <class Array>
constexpr std::size_t count_skips_in_array(std::size_t begin_index, std::size_t end_index, const Array& a) noexcept {
    std::size_t skips = 0;
    for (std::size_t i = begin_index; i < end_index; ++i) {
        if (a.data[i] == typeid_conversions::tuple_begin_tag) {
            const std::size_t this_tuple_size = a.count_from_opening_till_matching_parenthis_seq(i, typeid_conversions::tuple_begin_tag, typeid_conversions::tuple_end_tag) - 1;
            skips += this_tuple_size;
            i += this_tuple_size - 1;
        }
    }

    return skips;
}

template <class T, std::size_t First, std::size_t... I>
constexpr auto as_flat_tuple_impl(std::index_sequence<First, I...>) noexcept {
    constexpr auto a = flat_array_of_type_ids<T>();
    (void)a; // `a` is unused if T is an empty type

    typedef sequence_tuple::tuple<
        decltype(prepare_subtuples<T>(size_t_< get<First>(a) >{}, size_t_<First>{})),
        decltype(prepare_subtuples<T>(size_t_< get<I>(a) >{},     size_t_<I>{}))...
    > subtuples_uncleanuped_t;

    return as_flat_tuple_impl_drop_helpers<T, subtuples_uncleanuped_t>(
        std::index_sequence<First, I...>{},
        std::make_index_sequence< 1 + sizeof...(I) - count_skips_in_array(First, First + sizeof...(I), a) >{}
    );
}

template <class T>
constexpr auto internal_tuple_with_same_alignment() noexcept {
    typedef typename std::remove_cv<T>::type type;

    static_assert(std::is_pod<type>::value, "Not applyable");
    static_assert(!std::is_reference<type>::value, "Not applyable");
    constexpr auto res = as_flat_tuple_impl<type>(
        std::make_index_sequence< decltype(flat_array_of_type_ids<type>())::size() >()
    );

    static_assert(
        std::alignment_of<decltype(res)>::value == std::alignment_of<type>::value,
        "Alignment check failed, probably your structure has user-defined alignment for the whole structure or for some of the fields."
    );
    static_assert(sizeof(res) == sizeof(type), "Size check failed, probably your structure has bitfields or user-defined alignment.");

    return res;
}

template <class T>
using internal_tuple_with_same_alignment_t = decltype( internal_tuple_with_same_alignment<T>() );

/// @cond
#ifdef __GNUC__
#define MAY_ALIAS __attribute__((__may_alias__))
#else
#define MAY_ALIAS
#endif
/// @endcond

template <class Tuple, std::size_t Begin, std::size_t Size>
constexpr auto make_flat_tuple_of_references(Tuple&& t, size_t_<Begin>, size_t_<Size>) noexcept;

template <class Tuple, std::size_t Begin>
constexpr detail::sequence_tuple::tuple<> make_flat_tuple_of_references(Tuple&& t, size_t_<Begin>, size_t_<0>) noexcept;

template <class Tuple, std::size_t Begin>
constexpr auto make_flat_tuple_of_references(Tuple&& t, size_t_<Begin>, size_t_<1>) noexcept;

template <class... T>
constexpr auto as_tuple_with_references(T&&... args) noexcept {
    return detail::sequence_tuple::tuple<T&...>{ std::forward<T>(args)... };
}

template <class... T>
constexpr decltype(auto) as_tuple_with_references(detail::sequence_tuple::tuple<T...>& t) noexcept {
    return make_flat_tuple_of_references(t, size_t_<0>{}, size_t_<detail::sequence_tuple::tuple<T...>::size_v>{});
}

template <class... T>
constexpr decltype(auto) as_tuple_with_references(const detail::sequence_tuple::tuple<T...>& t) noexcept {
    return make_flat_tuple_of_references(t, size_t_<0>{}, size_t_<detail::sequence_tuple::tuple<T...>::size_v>{});
}



template <class Tuple1, std::size_t... I1, class Tuple2, std::size_t... I2>
constexpr auto my_tuple_cat_impl(Tuple1&& t1, std::index_sequence<I1...>, Tuple2&& t2, std::index_sequence<I2...>) noexcept {
    return as_tuple_with_references(
        detail::sequence_tuple::get<I1>( std::forward<Tuple1>(t1) )...,
        detail::sequence_tuple::get<I2>( std::forward<Tuple2>(t2) )...
    );
}

template <class Tuple1, class Tuple2>
constexpr auto my_tuple_cat(Tuple1& t1, Tuple2& t2) noexcept {
    return my_tuple_cat_impl(
        t1, std::make_index_sequence< Tuple1::size_v >{},
        t2, std::make_index_sequence< Tuple2::size_v >{}
    );
}

template <class Tuple, std::size_t Begin, std::size_t Size>
constexpr auto make_flat_tuple_of_references(Tuple&& t, size_t_<Begin>, size_t_<Size>) noexcept {
    constexpr std::size_t next_size = Size / 2;
    auto t1 = make_flat_tuple_of_references(std::forward<Tuple>(t), size_t_<Begin>{}, size_t_<next_size>{});
    auto t2 = make_flat_tuple_of_references(std::forward<Tuple>(t), size_t_<Begin + Size / 2>{}, size_t_<Size - next_size>{});
    return my_tuple_cat(
        t1, t2
    );
}

template <class Tuple, std::size_t Begin>
constexpr detail::sequence_tuple::tuple<> make_flat_tuple_of_references(Tuple&& /*t*/, size_t_<Begin>, size_t_<0>) noexcept {
    return detail::sequence_tuple::tuple<>{};
}

template <class Tuple, std::size_t Begin>
constexpr auto make_flat_tuple_of_references(Tuple&& t, size_t_<Begin>, size_t_<1>) noexcept {
    return as_tuple_with_references(
        detail::sequence_tuple::get<Begin>(std::forward<Tuple>(t))
    );
}

template <class T>
decltype(auto) tie_as_flat_tuple(const T& val) noexcept {
    MAY_ALIAS const auto* const t = reinterpret_cast<const detail::internal_tuple_with_same_alignment_t<T>*>( std::addressof(val) );
    return make_flat_tuple_of_references(*t, size_t_<0>{}, size_t_<detail::internal_tuple_with_same_alignment_t<T>::size_v>{});
}

template <class T>
decltype(auto) tie_as_flat_tuple(const volatile T& val) noexcept {
    MAY_ALIAS const volatile auto* const t = reinterpret_cast<const volatile detail::internal_tuple_with_same_alignment_t<T>*>( std::addressof(val) );
    return make_flat_tuple_of_references(*t, size_t_<0>{}, size_t_<detail::internal_tuple_with_same_alignment_t<T>::size_v>{});
}

template <class T>
decltype(auto) tie_as_flat_tuple(volatile T& val) noexcept {
    MAY_ALIAS volatile auto* const t = reinterpret_cast<volatile detail::internal_tuple_with_same_alignment_t<T>*>( std::addressof(val) );
    return make_flat_tuple_of_references(*t, size_t_<0>{}, size_t_<detail::internal_tuple_with_same_alignment_t<T>::size_v>{});
}

template <class T>
decltype(auto) tie_as_flat_tuple(T& val) noexcept {
    MAY_ALIAS auto* const t = reinterpret_cast<detail::internal_tuple_with_same_alignment_t<T>*>( std::addressof(val) );
    return make_flat_tuple_of_references(*t, size_t_<0>{}, size_t_<detail::internal_tuple_with_same_alignment_t<T>::size_v>{});
}

#undef MAY_ALIAS

template <class T, std::size_t... I>
constexpr auto make_stdtuple_from_tietuple(const T& t, std::index_sequence<I...>) noexcept {
    return std::make_tuple(
        boost::pfr::detail::sequence_tuple::get<I>(t)...
    );
}

template <class T, std::size_t... I>
constexpr auto make_stdtiedtuple_from_tietuple(const T& t, std::index_sequence<I...>) noexcept {
    return std::tie(
        boost::pfr::detail::sequence_tuple::get<I>(t)...
    );
}

} // namespace detail

#ifdef __clang__
#   pragma clang diagnostic pop
#endif



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

/// \brief Has a static const member variable `value` that constins fields count in a T.
/// Works for any T that supports aggregate initialization even if T is not POD.
/// \flattening{Flattens} only multidimensional arrays.
///
/// \b Example:
/// \code
///     std::array<int, boost::pfr::tuple_size<my_structure>::value > a;
/// \endcode
template <class T>
using tuple_size = detail::size_t_< detail::fields_count<T>() >;


/// \brief `tuple_size_v` is a template variable that contains fields count in a T and
/// works for any T that supports aggregate initialization even if T is not POD.
/// \flattening{Flattens} only multidimensional arrays.
///
/// \b Example:
/// \code
///     std::array<int, boost::pfr::tuple_size_v<my_structure> > a;
/// \endcode
template <class T>
constexpr std::size_t tuple_size_v = tuple_size<T>::value;


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

#endif // BOOST_PFR_CORE_HPP
