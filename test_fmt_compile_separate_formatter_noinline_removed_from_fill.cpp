#include "fmt_separate_formatter_noinlined_removed_from_fill/compile.h"
#include "test_functions.hpp"

namespace test_functions {
char* test_fmt_compile_separate_formatter_noinline_removed_from_fill(
    char* buffer, unsigned value) {
  return fmt::format_to(buffer, FMT_COMPILE("{:0>8x}"), value);
}
}  // namespace test_functions
