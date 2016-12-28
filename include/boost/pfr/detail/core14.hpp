// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_CORE14_HPP
#define BOOST_PFR_DETAIL_CORE14_HPP

#if __cplusplus < 201402L
#   error C++14 is required for this header.
#endif

#include <type_traits>
#include <utility>      // metaprogramming stuff

#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/tuple_size.hpp>

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wmissing-braces"
#   pragma clang diagnostic ignored "-Wundefined-inline"
#   pragma clang diagnostic ignored "-Wundefined-internal"
#   pragma clang diagnostic ignored "-Wmissing-field-initializers"
#endif

namespace boost { namespace pfr { namespace detail {

///////////////////// General utility stuff

template <class T> struct identity{
    typedef T type;
};

template <class T>
constexpr T construct_helper() noexcept { // adding const here allows to deal with copyable only types
    return {};
}

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
        return construct_helper<Type>();                        \
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
    constexpr auto t = flat_array_of_type_ids<Type>();
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
    return construct_helper<res_t>();
}

template <std::size_t Index>
constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_const_ptr_type>) noexcept {
    typedef const decltype( id_to_type(remove_1_ext<Index>()) )* res_t;
    return construct_helper<res_t>();
}

template <std::size_t Index>
constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_const_volatile_ptr_type>) noexcept {
    typedef const volatile decltype( id_to_type(remove_1_ext<Index>()) )* res_t;
    return construct_helper<res_t>();
}


template <std::size_t Index>
constexpr auto id_to_type(size_t_<Index >, if_extension<Index, native_volatile_ptr_type>) noexcept {
    typedef volatile decltype( id_to_type(remove_1_ext<Index>()) )* res_t;
    return construct_helper<res_t>();
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
        return construct_helper<Type>();
    }
};

///////////////////// Structure that remembers size of the type on a `constexpr operator Type()` call
struct ubiq_sizes {
    std::size_t& ref_;

    template <class Type>
    constexpr operator Type() const noexcept {
        ref_ = sizeof(Type);
        return construct_helper<Type>();
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

///////////////////// Returns array of typeids and zeros if construtor of a type accepts sizeof...(I) parameters, substitution failure otherwise
template <class T, std::size_t N, std::size_t... I>
constexpr auto flat_type_to_array_of_type_ids(std::size_t* types, std::index_sequence<I...>) noexcept
    -> typename std::add_pointer<decltype(T{ ubiq_constructor{I}... })>::type
{
    static_assert(
        N <= sizeof(T),
        "Bit fields are not supported."
    );

    constexpr auto offsets = get_type_offsets<T, N, I...>();
    T tmp{ ubiq_val{types + get<I>(offsets) * 3}... };
    (void)types;
    (void)tmp;
    (void)offsets; // If type is empty offsets are not used
    return nullptr;
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
constexpr sequence_tuple::tuple<> as_flat_tuple_impl(std::index_sequence<>) noexcept {
    return sequence_tuple::tuple<>{};
}

template <std::size_t Increment, std::size_t... I>
constexpr auto increment_index_sequence(std::index_sequence<I...>) noexcept {
    return std::index_sequence<I + Increment...>{};
}

template <class T, std::size_t V, std::size_t I, std::size_t SubtupleLength>
constexpr auto prepare_subtuples(size_t_<V>, size_t_<I>, size_t_<SubtupleLength>) noexcept {
    static_assert(SubtupleLength == 0, "Internal error while representing nested field as tuple");
    return typeid_conversions::id_to_type(size_t_<V>{});
}

template <class T, std::size_t I, std::size_t SubtupleLength>
constexpr auto prepare_subtuples(size_t_<typeid_conversions::tuple_end_tag>, size_t_<I>, size_t_<SubtupleLength>) noexcept {
    static_assert(sizeof(T) == 0, "Internal error while representing nested field as tuple");
    return int{};
}

template <class T, std::size_t I, std::size_t SubtupleLength>
constexpr auto prepare_subtuples(size_t_<typeid_conversions::tuple_begin_tag>, size_t_<I>, size_t_<SubtupleLength>) noexcept {
    static_assert(SubtupleLength > 2, "Internal error while representing nested field as tuple");
    constexpr auto seq = std::make_index_sequence<SubtupleLength - 2>{};
    return as_flat_tuple_impl<T>( increment_index_sequence<I + 1>(seq) );
}


template <class Array>
constexpr Array remove_subtuples(Array indexes_plus_1, const Array& subtuple_lengths) noexcept {
    for (std::size_t i = 0; i < subtuple_lengths.size(); ++i) {
        if (subtuple_lengths.data[i]) {
            const std::size_t skips_count = subtuple_lengths.data[i];
            for (std::size_t j = i + 1; j < skips_count + i; ++j) {
                indexes_plus_1.data[j] = 0;
            }
            i += skips_count - 1;
        }
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

template <class T, std::size_t First, std::size_t... I, std::size_t... INew>
constexpr auto as_flat_tuple_impl_drop_helpers(std::index_sequence<First, I...>, std::index_sequence<INew...>) noexcept {
    constexpr auto a = flat_array_of_type_ids<T>();

    constexpr size_array<sizeof...(I) + 1> subtuples_length {{
        a.count_from_opening_till_matching_parenthis_seq(First, typeid_conversions::tuple_begin_tag, typeid_conversions::tuple_end_tag),
        a.count_from_opening_till_matching_parenthis_seq(I, typeid_conversions::tuple_begin_tag, typeid_conversions::tuple_end_tag)...
    }};

    constexpr size_array<sizeof...(I) + 1> type_indexes_with_subtuple_internals {{ 1, 1 + I - First...}};
    constexpr auto type_indexes_plus_1_and_zeros_as_skips = remove_subtuples(type_indexes_with_subtuple_internals, subtuples_length);
    constexpr auto new_size = size_t_<type_indexes_plus_1_and_zeros_as_skips.count_nonzeros()>{};
    constexpr auto type_indexes = resize_dropping_zeros_and_decrementing(new_size, type_indexes_plus_1_and_zeros_as_skips);

    typedef sequence_tuple::tuple<
        decltype(prepare_subtuples<T>(
            size_t_< a.data[ First + type_indexes.data[INew] ]          >{},    // id of type
            size_t_< First + type_indexes.data[INew]                    >{},    // index of current id in `a`
            size_t_< subtuples_length.data[ type_indexes.data[INew] ]   >{}     // if id of type is tuple, then length of that tuple
        ))...
    > subtuples_uncleanuped_t;

    return subtuples_uncleanuped_t{};
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
    constexpr std::size_t count_of_I = sizeof...(I);

    return as_flat_tuple_impl_drop_helpers<T>(
        std::index_sequence<First, I...>{},
        std::make_index_sequence< 1 + count_of_I - count_skips_in_array(First, First + count_of_I, a) >{}
    );
}

template <class T>
constexpr auto internal_tuple_with_same_alignment() noexcept {
    typedef typename std::remove_cv<T>::type type;


#ifdef BOOST_PFR_RELAX_POD_REQUIREMENT
    static_assert(std::is_standard_layout<type>::value, "Not applyable");
    static_assert(std::is_move_constructible<type>::value || std::is_array<type>::value, "Not applyable");
#else
    static_assert(std::is_pod<type>::value, "Not applyable");
#endif

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


///////////////////// Flattening
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
constexpr auto my_tuple_cat_impl(const Tuple1& t1, std::index_sequence<I1...>, const Tuple2& t2, std::index_sequence<I2...>) noexcept {
    return as_tuple_with_references(
        detail::sequence_tuple::get<I1>(t1)...,
        detail::sequence_tuple::get<I2>(t2)...
    );
}

template <class Tuple1, class Tuple2>
constexpr auto my_tuple_cat(const Tuple1& t1, const Tuple2& t2) noexcept {
    return my_tuple_cat_impl(
        t1, std::make_index_sequence< Tuple1::size_v >{},
        t2, std::make_index_sequence< Tuple2::size_v >{}
    );
}

template <class Tuple, std::size_t Begin, std::size_t Size>
constexpr auto make_flat_tuple_of_references(Tuple&& t, size_t_<Begin>, size_t_<Size>) noexcept {
    constexpr std::size_t next_size = Size / 2;
    return my_tuple_cat(
        make_flat_tuple_of_references(std::forward<Tuple>(t), size_t_<Begin>{}, size_t_<next_size>{}),
        make_flat_tuple_of_references(std::forward<Tuple>(t), size_t_<Begin + Size / 2>{}, size_t_<Size - next_size>{})
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


/// @cond
#ifdef __GNUC__
#define MAY_ALIAS __attribute__((__may_alias__))
#else
#define MAY_ALIAS
#endif
/// @endcond

template <class T>
decltype(auto) tie_as_flat_tuple(const T& val) noexcept {
    MAY_ALIAS const auto* const t = reinterpret_cast<const internal_tuple_with_same_alignment_t<T>*>( std::addressof(val) );
    return make_flat_tuple_of_references(*t, size_t_<0>{}, size_t_<detail::internal_tuple_with_same_alignment_t<T>::size_v>{});
}

template <class T>
decltype(auto) tie_as_flat_tuple(const volatile T& val) noexcept {
    MAY_ALIAS const volatile auto* const t = reinterpret_cast<const volatile internal_tuple_with_same_alignment_t<T>*>( std::addressof(val) );
    return make_flat_tuple_of_references(*t, size_t_<0>{}, size_t_<detail::internal_tuple_with_same_alignment_t<T>::size_v>{});
}

template <class T>
decltype(auto) tie_as_flat_tuple(volatile T& val) noexcept {
    MAY_ALIAS volatile auto* const t = reinterpret_cast<volatile internal_tuple_with_same_alignment_t<T>*>( std::addressof(val) );
    return make_flat_tuple_of_references(*t, size_t_<0>{}, size_t_<detail::internal_tuple_with_same_alignment_t<T>::size_v>{});
}

template <class T>
decltype(auto) tie_as_flat_tuple(T& val) noexcept {
    MAY_ALIAS auto* const t = reinterpret_cast<internal_tuple_with_same_alignment_t<T>*>( std::addressof(val) );
    return make_flat_tuple_of_references(*t, size_t_<0>{}, size_t_<detail::internal_tuple_with_same_alignment_t<T>::size_v>{});
}

#undef MAY_ALIAS

#ifdef __clang__
#   pragma clang diagnostic pop
#endif

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE14_HPP
