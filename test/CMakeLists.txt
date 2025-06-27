# Copyright  (c) 2016-2025 Antony Polukhin
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

if(NOT TARGET tests)
  add_custom_target(tests)
endif()

file(GLOB CORE_RUN_FILES "core/run/*.cpp")
foreach (testsourcefile ${CORE_RUN_FILES})
    get_filename_component(testname ${testsourcefile} NAME_WLE)
    add_executable(pfr_core_${testname} ${testsourcefile})
    target_link_libraries(pfr_core_${testname} Boost::pfr Boost::core Boost::container_hash)
    target_include_directories(pfr_core_${testname} PRIVATE ../../../)
    add_test(NAME pfr_core_${testname} COMMAND pfr_core_${testname})
    add_dependencies(tests pfr_core_${testname})
endforeach()

file(GLOB CORE_NAME_RUN_FILES "core_name/run/*.cpp")
foreach (testsourcefile ${CORE_NAME_RUN_FILES})
    get_filename_component(testname ${testsourcefile} NAME_WLE)
    add_executable(pfr_corename_${testname} ${testsourcefile})
    target_compile_features(pfr_corename_${testname} PUBLIC cxx_std_20)
    target_link_libraries(pfr_corename_${testname} Boost::pfr Boost::core Boost::container_hash)
    target_include_directories(pfr_corename_${testname} PRIVATE ../../../)
    add_test(NAME pfr_corename_${testname} COMMAND pfr_corename_${testname})
    add_dependencies(tests pfr_corename_${testname})
endforeach()
