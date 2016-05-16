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
        ::detail::sequence_tuple::get<I>( std::declval<T>() )
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
using if_extension = typename std::enable_if< (Index & extension_maks) == Extension >::type*;

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
template <class Type> constexpr std::size_t type_to_id(identity<Type>, typename std::enable_if<std::is_enum<Type>::value>::type* = 0) noexcept;
template <class Type> constexpr std::size_t type_to_id(identity<Type>, typename std::enable_if<std::is_empty<Type>::value>::type* = 0) noexcept;
template <class Type> constexpr size_array<sizeof(Type)> type_to_id(identity<Type>, typename std::enable_if<!std::is_enum<Type>::value && !std::is_empty<Type>::value>::type* = 0) noexcept;
    
template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_const_ptr_type> = 0) noexcept;
template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_ptr_type> = 0) noexcept;
template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_const_volatile_ptr_type> = 0) noexcept;
template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_volatile_ptr_type> = 0) noexcept;
template <std::size_t Index> constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_ref_type> = 0) noexcept;


///////////////////// Definitions of type_to_id and id_to_type for fundamental types
#define BOOST_MAGIC_GET_REGISTER_TYPE(Type, Index)              \
    constexpr std::size_t type_to_id(identity<Type>) noexcept { \
        return Index;                                           \
    }                                                           \
    constexpr Type id_to_type( size_t_<Index > ) noexcept {     \
        Type res{};                                             \
        return res;                                             \
    }                                                           \
    /**/


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
constexpr std::size_t type_to_id(identity<Type>, typename std::enable_if<std::is_enum<Type>::value>::type*) noexcept {
    return type_to_id(identity<typename std::underlying_type<Type>::type >{});
}

template <class Type>
constexpr std::size_t type_to_id(identity<Type>, typename std::enable_if<std::is_empty<Type>::value>::type*) noexcept {
    static_assert(!std::is_empty<Type>::value, "Empty classes/structures as POD members are not supported.");
    return 0;
}

template <class Type>
constexpr size_array<sizeof(Type)> type_to_id(identity<Type>, typename std::enable_if<!std::is_enum<Type>::value && !std::is_empty<Type>::value>::type*) noexcept {
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

///////////////////// Returns array of typeids and zeros if construtor of a type accepts sizeof...(I) parameters, substitution failure otherwise
template <class T, std::size_t N, std::size_t... I>
constexpr auto type_to_array_of_type_ids(std::size_t* types) noexcept
    -> typename std::add_pointer<decltype(T{ ubiq_constructor{I}... })>::type
{
    static_assert(
        !decltype(has_reference_members<T, I...>(types))::value,
        "Reference members are not supported."
    );

    constexpr auto offsets = get_type_offsets<T, N, I...>();
    T tmp{ ubiq_val{types + get<I>(offsets)}... };
    (void)tmp;
    return nullptr;
}

///////////////////// Methods for detecting max parameters for construction of T, return array of typeids and zeros
template <class T, std::size_t N, std::size_t... I>
constexpr void detect_fields_count_and_type_ids(std::size_t* types, size_t_<N>, size_t_<N>, std::index_sequence<I...>, long) noexcept {
    type_to_array_of_type_ids<T, N, I...>(types);
}

template <class T, std::size_t Begin, std::size_t Middle, std::size_t... I>
constexpr void detect_fields_count_and_type_ids(std::size_t* types, size_t_<Begin>, size_t_<Middle>, std::index_sequence<I...>, int) noexcept;

template <class T, std::size_t Begin, std::size_t Middle, std::size_t... I>
constexpr auto detect_fields_count_and_type_ids(std::size_t* types, size_t_<Begin>, size_t_<Middle>, std::index_sequence<I...>, long) noexcept
    -> decltype( type_to_array_of_type_ids<T, Middle, I...>(types) )
{
    constexpr std::size_t next = Middle + (Middle - Begin + 1) / 2;
    detect_fields_count_and_type_ids<T>(types, size_t_<Middle>{}, size_t_<next>{}, std::make_index_sequence<next>(), 1L);
    return nullptr;
}

template <class T, std::size_t Begin, std::size_t Middle, std::size_t... I>
constexpr void detect_fields_count_and_type_ids(std::size_t* types, size_t_<Begin>, size_t_<Middle>, std::index_sequence<I...>, int) noexcept {
    constexpr std::size_t next = Begin + (Middle - Begin) / 2;
    detect_fields_count_and_type_ids<T>(types, size_t_<Begin>{}, size_t_<next>{}, std::make_index_sequence<next>(), 1L);
}



///////////////////// Returns array of typeids and zeros
template <class T>
constexpr size_array<sizeof(T)> fields_count_and_type_ids_with_zeros(std::enable_if_t<!std::is_empty<T>::value>*) noexcept {
    size_array<sizeof(T)> types{};
    constexpr std::size_t next = sizeof(T) / 2  + 1;
    detect_fields_count_and_type_ids<T>(types.data, size_t_<1>{}, size_t_<next>{}, std::make_index_sequence<next>{}, 1L);
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

    static_assert(sizeof(res) == sizeof(type), "size check failed");
    static_assert(
        std::alignment_of<decltype(res)>::value == std::alignment_of<type>::value,
        "alignment check failed"
    );

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

#ifdef __GNUC__
#define MAY_ALIAS __attribute__((__may_alias__))
#else
#define MAY_ALIAS
#endif

/// Returns const reference to a field with index `I` in flattened `T`.
/// Example usage: flat_get<0>(my_structure());
template <std::size_t I, class T>
decltype(auto) flat_get(const T& val) noexcept {
    MAY_ALIAS const auto* const t = reinterpret_cast<const detail::as_tuple_t<T>*>( std::addressof(val) );
    return detail::sequence_tuple::get<I>(*t);
}


/// Returns reference to a field with index `I` in flattened `T`.
/// Requires: `T` must not have const fields.
/// Example usage: flat_get<0>(my_structure());
template <std::size_t I, class T>
decltype(auto) flat_get(T& val, typename std::enable_if< std::is_trivially_assignable<T, T>::value>::type* = 0) noexcept {
    MAY_ALIAS auto* const t = reinterpret_cast<detail::as_tuple_t<T>*>( std::addressof(val) );
    return detail::sequence_tuple::get<I>(*t);
}


/// `flat_tuple_element` has a `typedef type-of-a-field-with-index-I-in-flattened-T type;`
/// Example usage: std::vector<  flat_tuple_element<0, my_structure>::type  > v;
template <std::size_t I, class T>
using flat_tuple_element = detail::teleport_extents<
        T,
        typename detail::sequence_tuple::tuple_element<I, detail::as_tuple_t<T> >::type
    >;


/// Type of a field with index `I` in flattened `T`
/// Example usage: std::vector<  flat_tuple_element_t<0, my_structure>  > v;
template <std::size_t I, class T>
using flat_tuple_element_t = typename flat_tuple_element<I, T>::type;


/// `flat_tuple_size` has a member `value` that constins fields count in a flattened `T`.
/// Example usage: std::array<int, flat_tuple_size<my_structure>::value > a;
template <class T>
using flat_tuple_size = detail::size_t_< detail::as_tuple_t<T>::size_v >;


/// `flat_tuple_size_v` is a template variable that constins fields count in a flattened `T`.
/// Example usage: std::array<int, flat_tuple_size_v<my_structure> > a;
template <class T>
constexpr std::size_t flat_tuple_size_v = flat_tuple_size<T>::value;


/// Creates an `std::tuple` from a flattened T.
/// Example usage: 
///     struct my_struct { int i, short s; };
///     my_struct s {10, 11};
///     std::tuple<int, short> t = flat_make_tuple(s);
///     assert(get<0>(t) == 10);
template <class T>
auto flat_make_tuple(const T& val) noexcept {
    typedef detail::as_tuple_t<T> internal_tuple_t;
    MAY_ALIAS const internal_tuple_t& t = *reinterpret_cast<const internal_tuple_t*>( std::addressof(val) );
    return detail::flat_make_tuple_impl(
        t,
        std::make_index_sequence< internal_tuple_t::size_v >()
    );
}


/// Creates an `std::tuple` with lvalue references to fields of a flattened T.
/// Example usage: 
///     struct my_struct { int i, short s; };
///     my_struct s;
///     flat_tie(s) = std::tuple<int, short>{10, 11};
///     assert(s.s == 11);
template <class T>
auto flat_tie(T& val, typename std::enable_if< std::is_trivially_assignable<T, T>::value>::type* = 0 ) noexcept {
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
            out << flat_get<I>(value);
            flat_print_impl<I + 1, N>::print(out, value);
        }
    };

    template <std::size_t I>
    struct flat_print_impl<I, I> {
        template <class Stream, class T> static void print (Stream&, const T&) noexcept {}
    };
}

/// Writes to `out` the POD `value`
/// Example usage: 
///     struct my_struct { int i, short s; };
///     my_struct s{12, 13};
///     flat_write(std::cout, s); // outputs '{12, 13}'
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
            in >> flat_get<I>(value);
            flat_read_impl<I + 1, N>::read(in, value);
        }
    };
    
    template <std::size_t I>
    struct flat_read_impl<I, I> {
        template <class Stream, class T> static void read (Stream&, const T&) {}
    };
}

/// Reads POD `value` from stream `in`
/// Example usage: 
///     struct my_struct { int i, short s; };
///     my_struct s;
///     std::stringstream ss;
///     ss << "{ 12, 13 }";
///     ss >> s;
///     assert(s.i == 12);
///     assert(s.i == 13);
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


namespace detail {
    template <std::size_t I, std::size_t N>
    struct equal_impl {
        template <class T, class U>
        static bool cmp(const T& v1, const U& v2) noexcept {
            return flat_get<I>(v1) == flat_get<I>(v2)
                && equal_impl<I + 1, N>::cmp(v1, v2);
        }
    };

    template <std::size_t N>
    struct equal_impl<N, N> {
        template <class T, class U>
        static bool cmp(const T&, const U&) noexcept {
            return flat_tuple_size_v<T> == flat_tuple_size_v<U>;
        }
    };

    template <std::size_t I, std::size_t N>
    struct less_impl {
        template <class T, class U>
        static bool cmp(const T& v1, const U& v2) noexcept {
            return flat_get<I>(v1) < flat_get<I>(v2)
                || (flat_get<I>(v1) == flat_get<I>(v2) && less_impl<I + 1, N>::cmp(v1, v2));
        }
    };

    template <std::size_t N>
    struct less_impl<N, N> {
        template <class T, class U>
        static bool cmp(const T&, const U&) noexcept {
            return flat_tuple_size_v<T> < flat_tuple_size_v<U>;
        }
    };

///////////////////// `value` is true if Detector<Tleft, Tright> does not compile (SFINAE)
    template <template <class, class> class Detector, class Tleft, class Tright>
    struct not_appliable {
        struct success{};
        template <class Tl, class Tr> static Detector<Tl, Tr> detector_impl(long) noexcept;
        template <class Tl, class Tr> static success detector_impl(int) noexcept;
        
        static constexpr bool value = std::is_same<
            decltype(detector_impl<Tleft, Tright>(1L)),
            success 
        >::value;
    };

///////////////////// Detectors for different operators
    template <class T1, class T2> using comp_eq_detector = decltype(std::declval<T1>() == std::declval<T2>());
    template <class T1, class T2> using comp_ne_detector = decltype(std::declval<T1>() != std::declval<T2>());
    template <class T1, class T2> using comp_lt_detector = decltype(std::declval<T1>() <  std::declval<T2>());
    template <class T1, class T2> using comp_le_detector = decltype(std::declval<T1>() <= std::declval<T2>());
    template <class T1, class T2> using comp_gt_detector = decltype(std::declval<T1>() >  std::declval<T2>());
    template <class T1, class T2> using comp_ge_detector = decltype(std::declval<T1>() >= std::declval<T2>());
    template <class S, class T> using ostreamable_detector = decltype(std::declval<S>() << std::declval<T>());
    template <class S, class T> using istreamable_detector = decltype(std::declval<S>() >> std::declval<T>());

///////////////////// Helper typedef that it used by all the enable_not_*_comp_t
    template <template <class, class> class Detector, class T>
    using enable_not_comp_base_t = typename std::enable_if<
        not_appliable<Detector, T const&, T const&>::value && std::is_pod<T>::value,
        bool
    >::type;

///////////////////// std::enable_if_t like functions that enable only if types do not support operation and are PODs
    template <class T> using enable_not_eq_comp_t = enable_not_comp_base_t<comp_eq_detector, T>;
    template <class T> using enable_not_ne_comp_t = enable_not_comp_base_t<comp_ne_detector, T>;
    template <class T> using enable_not_lt_comp_t = enable_not_comp_base_t<comp_lt_detector, T>;
    template <class T> using enable_not_le_comp_t = enable_not_comp_base_t<comp_le_detector, T>;
    template <class T> using enable_not_gt_comp_t = enable_not_comp_base_t<comp_gt_detector, T>;
    template <class T> using enable_not_ge_comp_t = enable_not_comp_base_t<comp_ge_detector, T>;

    template <class Stream, class Type>
    using enable_not_ostreamable_t = typename std::enable_if<
        not_appliable<ostreamable_detector, Stream&, Type const&>::value && std::is_pod<Type>::value,
        Stream&
    >::type;

    template <class Stream, class Type>
    using enable_not_istreamable_t = typename std::enable_if<
        not_appliable<istreamable_detector, Stream&, Type&>::value && std::is_pod<Type>::value,
        Stream&
    >::type;
    
///////////////////// Define min_element and to avoid inclusion of <algorithm>
    constexpr std::size_t min_size(std::size_t x, std::size_t y) noexcept {
        return x < y ? x : y;
    }
}

///////////////////// Comparisons

/// flat_equal_to<>
template <class T = void> struct flat_equal_to {
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::equal_impl<0, flat_tuple_size_v<T> >::cmp(x, y);
    }
};

template <> struct flat_equal_to<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::equal_impl<
            0, 
            detail::min_size(flat_tuple_size_v<T>, flat_tuple_size_v<U>)
        >::cmp(x, y);
    }

    typedef std::true_type is_transparent;
};

/// flat_not_equal<>
template <class T = void> struct flat_not_equal {
    bool operator()(const T& x, const T& y) const noexcept {
        return !flat_equal_to<T>{}(x, y);
    }
};

template <> struct flat_not_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return !flat_equal_to<void>{}(x, y);
    }

    typedef std::true_type is_transparent;
};

/// flat_greater<>
template <class T = void> struct flat_greater {
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::less_impl<0, flat_tuple_size_v<T> >::cmp(y, x);
    }
};

template <> struct flat_greater<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::less_impl<
            0, 
            detail::min_size(flat_tuple_size_v<T>, flat_tuple_size_v<U>)
        >::cmp(y, x);
    }

    typedef std::true_type is_transparent;
};

/// flat_less<>
template <class T = void> struct flat_less {
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::less_impl<0, flat_tuple_size_v<T> >::cmp(x, y);
    }
};

template <> struct flat_less<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::less_impl<
            0, 
            detail::min_size(flat_tuple_size_v<T>, flat_tuple_size_v<U>)
        >::cmp(x, y);
    }

    typedef std::true_type is_transparent;
};

/// flat_greater_equal<>
template <class T = void> struct flat_greater_equal {
    bool operator()(const T& x, const T& y) const noexcept {
        return !flat_less<T>{}(x, y);
    }
};

template <> struct flat_greater_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return !flat_less<>{}(x, y);
    }

    typedef std::true_type is_transparent;
};

/// flat_less_equal<>
template <class T = void> struct flat_less_equal {
    bool operator()(const T& x, const T& y) const noexcept {
        return !flat_greater<T>{}(x, y);
    }
};

template <> struct flat_less_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return !flat_greater<>{}(x, y);
    }

    typedef std::true_type is_transparent;
};


/// Contains comparison operators and stream operators for any POD types that does not have it's own operators.
/// If POD is comparable or streamable using it's own operator or it's conversion operator, then the original operator is be used.
///
/// Example usage:
///     struct comparable_struct {      // No operators defined for that structure
///         int i; short s; char data[7]; bool bl; int a,b,c,d,e,f;
///     };
///     using namespace pod_ops;
///
///     comparable_struct s1 {0, 1, "Hello", false, 6,7,8,9,10,11};
///     comparable_struct s2 {0, 1, "Hello", false, 6,7,8,9,10,11111};
///     assert(s1 < s2);
///     std::cout << s1 << std::endl; // Outputs: {0, 1, H, e, l, l, o, , , 0, 6, 7, 8, 9, 10, 11}
namespace pod_ops {
    ///////////////////// Comparisons
    template <class T>
    inline detail::enable_not_eq_comp_t<T> operator==(const T& lhs, const T& rhs) noexcept {
        return flat_equal_to<T>{}(lhs, rhs);
    }
    
    template <class T>
    inline detail::enable_not_ne_comp_t<T> operator!=(const T& lhs, const T& rhs) noexcept {
        return flat_not_equal<T>{}(lhs, rhs);
    }

    template <class T>
    inline detail::enable_not_lt_comp_t<T> operator<(const T& lhs, const T& rhs) noexcept {
        return flat_less<T>{}(lhs, rhs);
    }

    template <class T>
    inline detail::enable_not_gt_comp_t<T> operator>(const T& lhs, const T& rhs) noexcept {
        return flat_greater<T>{}(lhs, rhs);
    }

    template <class T>
    inline detail::enable_not_le_comp_t<T> operator<=(const T& lhs, const T& rhs) noexcept {
        return flat_less_equal<T>{}(lhs, rhs);
    }

    template <class T>
    inline detail::enable_not_ge_comp_t<T> operator>=(const T& lhs, const T& rhs) noexcept {
        return flat_greater_equal<T>{}(lhs, rhs);
    }

    ///////////////////// basic_ostream operator <<
    template <class Char, class Traits, class T>
    detail::enable_not_ostreamable_t<std::basic_ostream<Char, Traits>, T> operator<<(std::basic_ostream<Char, Traits>& out, const T& value)
    {
        flat_write(out, value);
        return out;
    }

    ///////////////////// basic_istream operator >>
    template <class Char, class Traits, class T>
    detail::enable_not_istreamable_t<std::basic_istream<Char, Traits>, T> operator>>(std::basic_istream<Char, Traits>& in, T& value)
    {
        flat_read(in, value);
        return in;
    }
} // pod_ops
