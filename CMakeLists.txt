cmake_minimum_required(VERSION 3.14)
project(fmt_test)

add_subdirectory(benchmark)
add_subdirectory(fmt)

add_executable(fmt_test
    main.cpp
    test_functions.cpp
)
target_link_libraries(fmt_test PRIVATE fmt::fmt benchmark::benchmark)
