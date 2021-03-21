#include "fmt_eef4ba9c02de46e5cce031db57268cc199c101fe/compile.h"
#include "test_functions.hpp"

namespace test_functions {
char* test_fmt_compile_master(char* buffer, unsigned value) {
  return fmt::format_to(buffer, FMT_COMPILE("{:0>8x}"), value);
}
}  // namespace test_functions
