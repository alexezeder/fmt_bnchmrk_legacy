#include "fmt_separate_formatter/compile.h"
#include "test_functions.hpp"

namespace test_functions {
std::string test_fmt_compile_separate_formatter(unsigned value) {
  return fmt::format(FMT_COMPILE("{:0>8x}"), value);
}
}  // namespace test_functions
