#include "test_functions.hpp"

#include <fmt/core.h>

namespace test_functions {
void fmt_print() {  //
  return fmt::print(stderr, print_text);
}

char* fmt_format_to(char* buffer) {  //
  return fmt::format_to(buffer, format_text);
}

char* fmt_format_to_runtime(char* buffer, const std::string& text) {  //
  return fmt::format_to(buffer, fmt::runtime(text));
}
}  // namespace test_functions
