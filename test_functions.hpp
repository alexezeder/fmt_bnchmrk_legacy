#pragma once

namespace test_functions {
char* test_custom_code(char* buffer, unsigned value);
char* test_fmt_compile_master(char* buffer, unsigned value);
char* test_fmt_compile_master_noinline_removed_from_fill(char* buffer,
                                                         unsigned value);
char* test_fmt_compile_separate_formatter(char* buffer, unsigned value);
char* test_fmt_compile_separate_formatter_noinline_removed_from_fill(
    char* buffer, unsigned value);
}  // namespace test_functions
