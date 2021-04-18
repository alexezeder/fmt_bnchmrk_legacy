#include <benchmark/benchmark.h>

#include "test_functions.hpp"

static void FMTNonNamed(benchmark::State& state) {
  char buffer[max_buffer_size];
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_non_named(buffer, state.range(0)));
  }
}
BENCHMARK(FMTNonNamed)->Arg(42);

static void FMTRuntimeNamed(benchmark::State& state) {
  char buffer[max_buffer_size];
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_runtime_named(buffer, state.range(0)));
  }
}
BENCHMARK(FMTRuntimeNamed)->Arg(42);

static void FMTCompileNonNamed(benchmark::State& state) {
  char buffer[max_buffer_size];
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_compile_non_named(buffer, state.range(0)));
  }
}
BENCHMARK(FMTCompileNonNamed)->Arg(42);

static void FMTCompileRuntimeNamed(benchmark::State& state) {
  char buffer[max_buffer_size];
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_compile_runtime_named(buffer, state.range(0)));
  }
}
BENCHMARK(FMTCompileRuntimeNamed)->Arg(42);

static void FMTCompileCompileTimeNamed(benchmark::State& state) {
  char buffer[max_buffer_size];
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_compile_compile_time_named(buffer,
                                                            state.range(0)));
  }
}
BENCHMARK(FMTCompileCompileTimeNamed)->Arg(42);

BENCHMARK_MAIN();
