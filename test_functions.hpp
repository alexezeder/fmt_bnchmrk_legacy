#pragma once

#include <string>

namespace test_functions {
std::string test_custom_code(unsigned value);
std::string test_fmt_compile_master(unsigned value);
std::string test_fmt_compile_master_noinline_removed_from_fill(unsigned value);
std::string test_fmt_compile_separate_formatter(unsigned value);
std::string test_fmt_compile_separate_formatter_noinline_removed_from_fill(
    unsigned value);
std::string test_stringstream(unsigned value);
}  // namespace test_functions
