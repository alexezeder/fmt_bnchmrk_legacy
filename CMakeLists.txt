cmake_minimum_required(VERSION 3.14)
project(fmt_test)

add_subdirectory(benchmark)
add_subdirectory(fmt-fix-print_with_fmt_compile)

add_executable(fmt_test
    main.cpp
)
target_include_directories(fmt_test PRIVATE include)
target_link_libraries(fmt_test PRIVATE benchmark::benchmark fmt::fmt-header-only)
