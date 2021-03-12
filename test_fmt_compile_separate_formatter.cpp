#include "fmt_separate_formatter/compile.h"
#include "test_functions.hpp"

namespace test_functions {
char* test_fmt_compile_separate_formatter(char* buffer, unsigned value) {
  return fmt::format_to(buffer, FMT_COMPILE("{:x}"), value);
}
}  // namespace test_functions
