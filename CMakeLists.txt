cmake_minimum_required(VERSION 3.21)
project(fmt_test)

set(BENCHMARK_ENABLE_TESTING OFF)
add_subdirectory(benchmark)

add_subdirectory(fmt_vanilla)
add_subdirectory(fmt_modified)

add_executable(fmt_vanilla_test
    main.cpp
    test_functions.cpp
)
target_link_libraries(fmt_vanilla_test PRIVATE benchmark::benchmark fmt_vanilla::fmt)

add_executable(fmt_vanilla_header_only_test
    main.cpp
    test_functions.cpp
)
target_link_libraries(fmt_vanilla_header_only_test PRIVATE benchmark::benchmark fmt_vanilla::fmt-header-only)

add_executable(fmt_modified_test
    main.cpp
    test_functions.cpp
)
target_link_libraries(fmt_modified_test PRIVATE benchmark::benchmark fmt_modified::fmt)

add_executable(fmt_modified_header_only_test
    main.cpp
    test_functions.cpp
)
target_link_libraries(fmt_modified_header_only_test PRIVATE benchmark::benchmark fmt_modified::fmt-header-only)
