#include <benchmark/benchmark.h>
#include <fmt/core.h>

#include "test_functions.hpp"

static void Print(benchmark::State& state) {
  for (auto _ : state) {
    test_functions::fmt_print();
  }
}
BENCHMARK(Print);

static void PrintDirect(benchmark::State& state) {
  for (auto _ : state) {
    fmt::print(stderr, print_text);
  }
}
BENCHMARK(PrintDirect);

static void Format(benchmark::State& state) {
  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(test_functions::fmt_format_to(buffer));
  }
}
BENCHMARK(Format);

static void FormatDirect(benchmark::State& state) {
  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(fmt::format_to(buffer, format_text));
  }
}
BENCHMARK(FormatDirect);

auto runtime_text = std::string(format_text);
static void FormatRuntime(benchmark::State& state) {
  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::fmt_format_to_runtime(buffer, runtime_text));
  }
}
BENCHMARK(FormatRuntime);

static void FormatRuntimeDirect(benchmark::State& state) {
  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        fmt::format_to(buffer, fmt::runtime(runtime_text)));
  }
}
BENCHMARK(FormatRuntimeDirect);

BENCHMARK_MAIN();
