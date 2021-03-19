#include "test_functions.hpp"

namespace test_functions {
constexpr char hexchar[] = "0123456789abcdef";

std::string test_custom_code(unsigned value) {
  constexpr size_t sz = sizeof(value) * 2;
  std::string buffer(sz, L'\0');
  for (int i = 0; i < 2 * sizeof(value); i++)
    buffer[i] = hexchar[(value >> 4 * (sz - 1 - i)) & 0xf];
  return buffer;
}
}  // namespace test_functions
