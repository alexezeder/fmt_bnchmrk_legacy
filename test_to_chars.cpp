#include <charconv>

#include "test_functions.hpp"

namespace test_functions {
char* test_to_chars(char* buffer, unsigned value) {
  auto [ptr, ec] = std::to_chars(
      buffer, buffer + max_buffer_size /*no need to check*/, value, 16);
  return ptr;
}
}  // namespace test_functions
