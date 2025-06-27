# Copyright  (c) 2016-2025 Antony Polukhin
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5...4.0)

project(pfr_subdir_test LANGUAGES CXX)

add_subdirectory(../../../assert boostorg/assert)
add_subdirectory(../../../container_hash boostorg/container_hash)
add_subdirectory(../../../core boostorg/core)
add_subdirectory(../../../config boostorg/config)
add_subdirectory(../../../detail boostorg/detail)
add_subdirectory(../../../describe boostorg/describe)
add_subdirectory(../../../integer boostorg/integer)
add_subdirectory(../../../mp11 boostorg/mp11)
add_subdirectory(../../../static_assert boostorg/static_assert)
add_subdirectory(../../../throw_exception boostorg/throw_exception)
add_subdirectory(../../../type_traits boostorg/type_traits)

add_subdirectory(../../ boostorg/pfr)
