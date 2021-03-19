#include <benchmark/benchmark.h>

#include <cstdio>

#include "test_functions.hpp"

static void CustomCode(benchmark::State& state) {
  // check
  {
    std::string expected_result =
        test_functions::test_stringstream(state.range(0));
    std::string actual_result =
        test_functions::test_custom_code(state.range(0));
    if (expected_result != actual_result) {
      fprintf(stderr, "1 expected: '%s', actual: '%s'\n", expected_result.data(),
              actual_result.data());
    }
  }

  for (auto _ : state) {
    benchmark::DoNotOptimize(test_functions::test_custom_code(state.range(0)));
  }
}
BENCHMARK(CustomCode)
    ->Arg(0)
    ->Arg(42)
    ->Arg(273123)
    ->Arg(std::numeric_limits<int64_t>::max());

static void FMTCompileMaster(benchmark::State& state) {
  // check
  {
    std::string expected_result =
        test_functions::test_stringstream(state.range(0));
    std::string actual_result =
        test_functions::test_fmt_compile_master(state.range(0));
    if (expected_result != actual_result) {
      fprintf(stderr, "2 expected: '%s', actual: '%s'\n", expected_result.data(),
              actual_result.data());
    }
  }

  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_compile_master(state.range(0)));
  }
}
BENCHMARK(FMTCompileMaster)
    ->Arg(0)
    ->Arg(42)
    ->Arg(273123)
    ->Arg(std::numeric_limits<int64_t>::max());

static void FMTCompileMasterNOINLINERemovedFromFill(benchmark::State& state) {
  // check
  {
    std::string expected_result =
        test_functions::test_stringstream(state.range(0));
    std::string actual_result =
        test_functions::test_fmt_compile_master_noinline_removed_from_fill(
            state.range(0));
    if (expected_result != actual_result) {
      fprintf(stderr, "3 expected: '%s', actual: '%s'\n", expected_result.data(),
              actual_result.data());
    }
  }

  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_compile_master_noinline_removed_from_fill(
            state.range(0)));
  }
}
BENCHMARK(FMTCompileMasterNOINLINERemovedFromFill)
    ->Arg(0)
    ->Arg(42)
    ->Arg(273123)
    ->Arg(std::numeric_limits<int64_t>::max());

static void FMTCompileSeparateFormatter(benchmark::State& state) {
  // check
  {
    std::string expected_result =
        test_functions::test_stringstream(state.range(0));
    std::string actual_result =
        test_functions::test_fmt_compile_separate_formatter(state.range(0));
    if (expected_result != actual_result) {
      fprintf(stderr, "4 expected: '%s', actual: '%s'\n", expected_result.data(),
              actual_result.data());
    }
  }

  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_compile_separate_formatter(state.range(0)));
  }
}
BENCHMARK(FMTCompileSeparateFormatter)
    ->Arg(0)
    ->Arg(42)
    ->Arg(273123)
    ->Arg(std::numeric_limits<int64_t>::max());

static void FMTCompileSeparateFormatterNOINLINERemovedFromFill(
    benchmark::State& state) {
  // check
  {
    std::string expected_result =
        test_functions::test_stringstream(state.range(0));
    std::string actual_result = test_functions::
        test_fmt_compile_separate_formatter_noinline_removed_from_fill(
            state.range(0));
    if (expected_result != actual_result) {
      fprintf(stderr, "5 expected: '%s', actual: '%s'\n", expected_result.data(),
              actual_result.data());
    }
  }

  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::
            test_fmt_compile_separate_formatter_noinline_removed_from_fill(
                state.range(0)));
  }
}
BENCHMARK(FMTCompileSeparateFormatterNOINLINERemovedFromFill)
    ->Arg(0)
    ->Arg(42)
    ->Arg(273123)
    ->Arg(std::numeric_limits<int64_t>::max());

static void StringStream(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(test_functions::test_stringstream(state.range(0)));
  }
}
BENCHMARK(StringStream)
    ->Arg(0)
    ->Arg(42)
    ->Arg(273123)
    ->Arg(std::numeric_limits<int64_t>::max());

BENCHMARK_MAIN();
