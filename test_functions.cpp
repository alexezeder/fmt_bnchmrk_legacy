#include <benchmark/benchmark.h>

#include "fmt/compile.h"

namespace test_functions {
char* test_fmt_non_named(char* buffer, unsigned value) {
  return fmt::format_to(buffer, "{}", value);
}
char* test_fmt_runtime_named(char* buffer, unsigned value) {
  return fmt::format_to(buffer, "{arg}", fmt::arg("arg", value));
}
char* test_fmt_compile_non_named(char* buffer, unsigned value) {
  return fmt::format_to(buffer, FMT_COMPILE("{}"), value);
}
char* test_fmt_compile_runtime_named(char* buffer, unsigned value) {
  return fmt::format_to(buffer, FMT_COMPILE("{arg}"), fmt::arg("arg", value));
}
char* test_fmt_compile_compile_time_named(char* buffer, unsigned value) {
  using namespace fmt::literals;
  return fmt::format_to(buffer, FMT_COMPILE("{arg}"), "arg"_a = value);
}

}  // namespace test_functions
