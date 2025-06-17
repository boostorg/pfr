# Copyright 2020 Peter Dimov
# Copyright (c) 2016-2025 Antony Polukhin
#
# Distributed under the Boost Software License, Version 1.0.
# https://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5...3.31)

project(boost_pfr VERSION "${BOOST_SUPERPROJECT_VERSION}" LANGUAGES CXX)

if (BOOST_USE_MODULES)
    add_library(boost_pfr)
    target_sources(boost_pfr PUBLIC
        FILE_SET modules_public TYPE CXX_MODULES FILES modules/boost_pfr.cppm
    )

    target_compile_features(boost_pfr PUBLIC cxx_std_20)
    target_compile_definitions(boost_pfr PUBLIC BOOST_USE_MODULES)
    if (CMAKE_CXX_COMPILER_IMPORT_STD)
        target_compile_definitions(boost_pfr PRIVATE BOOST_PFR_USE_STD_MODULE)
        message(STATUS "Using `import std;`")
    else()
        message(STATUS "`import std;` is not available")
    endif()
    target_include_directories(boost_pfr PUBLIC include)
else()
    add_library(boost_pfr INTERFACE)
    target_include_directories(boost_pfr INTERFACE include)
endif()

add_library(Boost::pfr ALIAS boost_pfr)

enable_testing()
if (BUILD_TESTING AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")
    add_subdirectory(test)
endif()

if (BOOST_USE_MODULES AND BUILD_TESTING)
    add_executable(boost_pfr_module_usage modules/usage_sample.cpp)
    target_link_libraries(boost_pfr_module_usage PRIVATE Boost::pfr)
    add_test(NAME boost_pfr_module_usage COMMAND boost_pfr_module_usage)

    # Make sure that mixing includes and imports is fine for different TU
    add_executable(boost_pfr_module_usage_mu modules/usage_test_mu1.cpp modules/usage_test_mu2.cpp)
    target_link_libraries(boost_pfr_module_usage_mu PRIVATE Boost::pfr)
    add_test(NAME boost_pfr_module_usage_mu COMMAND boost_pfr_module_usage_mu)
endif()

