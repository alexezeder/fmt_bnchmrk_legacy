cmake_minimum_required(VERSION 3.14)
project(fmt_test)

add_subdirectory(benchmark)

add_executable(fmt_test
    main.cpp
    test_custom_code.cpp
    test_fmt_compile_master.cpp
    test_fmt_compile_master_noinline_removed_from_fill.cpp
    test_fmt_compile_separate_formatter.cpp
    test_fmt_compile_separate_formatter_noinline_removed_from_fill.cpp
    test_stringstream.cpp
)
target_compile_definitions(fmt_test PRIVATE FMT_HEADER_ONLY=1)
target_include_directories(fmt_test PRIVATE include)
target_link_libraries(fmt_test PRIVATE benchmark::benchmark)
