#pragma once

#include <cstddef>
#include <string>
#include <string_view>

constexpr size_t max_buffer_size = 100;

constexpr auto print_text = std::string_view( "foo\n" );
constexpr auto format_text = std::string_view( "foobar" );

namespace test_functions {
void fmt_print();
char* fmt_format_to(char* buffer);
char* fmt_format_to_runtime(char* buffer, const std::string& text);
}  // namespace test_functions
