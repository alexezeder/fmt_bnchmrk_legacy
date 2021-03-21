#include "test_functions.hpp"

namespace test_functions {
constexpr char hexchar[] = "0123456789abcdef";

constexpr int count_digits(unsigned n) {
  int num_digits = 0;
  do {
    ++num_digits;
  } while ((n >>= 4) != 0);
  return num_digits;
}

constexpr char* format_uint(char* buffer, unsigned value, int num_digits) {
  buffer += num_digits;
  char* end = buffer;
  do {
    unsigned digit = (value & ((1 << 4) - 1));
    *--buffer = hexchar[digit];
  } while ((value >>= 4) != 0);
  return end;
}

char* test_custom_code(char* buffer, unsigned value) {
  int num_digits = count_digits(value);
  for (int i = 0; i < 8 - num_digits; ++i) {
    *buffer++ = '0';
  }
  return format_uint(buffer, value, num_digits);
}
}  // namespace test_functions
