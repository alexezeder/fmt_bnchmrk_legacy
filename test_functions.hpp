#pragma once

#include <cstddef>

constexpr size_t max_buffer_size = 100;

namespace test_functions {
char* test_fmt_non_named(char* buffer, unsigned value);
char* test_fmt_runtime_named(char* buffer, unsigned value);
char* test_fmt_compile_non_named(char* buffer, unsigned value);
char* test_fmt_compile_runtime_named(char* buffer, unsigned value);
char* test_fmt_compile_compile_time_named(char* buffer, unsigned value);
}  // namespace test_functions
