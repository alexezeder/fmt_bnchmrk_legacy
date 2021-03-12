#include <benchmark/benchmark.h>

#include <cstdio>

#include "test_functions.hpp"

static void CustomCode(benchmark::State& state) {
  // check
  {
    std::string expected_result;
    std::string actual_result;
    {
      char buffer[max_buffer_size]{};
      auto end = test_functions::test_to_chars(buffer, state.range(0));
      expected_result = std::string_view(buffer, end);
    }
    {
      char buffer[max_buffer_size]{};
      auto end = test_functions::test_custom_code(buffer, state.range(0));
      actual_result = std::string_view(buffer, end);
    }
    if (expected_result != actual_result) {
      fprintf(stderr, "expected: '%s', actual: '%s'", expected_result.data(),
              actual_result.data());
    }
  }

  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_custom_code(buffer, state.range(0)));
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
    std::string expected_result;
    std::string actual_result;
    {
      char buffer[max_buffer_size]{};
      auto end = test_functions::test_to_chars(buffer, state.range(0));
      expected_result = std::string_view(buffer, end);
    }
    {
      char buffer[max_buffer_size]{};
      auto end =
          test_functions::test_fmt_compile_master(buffer, state.range(0));
      actual_result = std::string_view(buffer, end);
    }
    if (expected_result != actual_result) {
      fprintf(stderr, "expected: '%s', actual: '%s'", expected_result.data(),
              actual_result.data());
    }
  }

  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_compile_master(buffer, state.range(0)));
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
    std::string expected_result;
    std::string actual_result;
    {
      char buffer[max_buffer_size]{};
      auto end = test_functions::test_to_chars(buffer, state.range(0));
      expected_result = std::string_view(buffer, end);
    }
    {
      char buffer[max_buffer_size]{};
      auto end =
          test_functions::test_fmt_compile_master_noinline_removed_from_fill(
              buffer, state.range(0));
      actual_result = std::string_view(buffer, end);
    }
    if (expected_result != actual_result) {
      fprintf(stderr, "expected: '%s', actual: '%s'", expected_result.data(),
              actual_result.data());
    }
  }

  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_compile_master_noinline_removed_from_fill(
            buffer, state.range(0)));
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
    std::string expected_result;
    std::string actual_result;
    {
      char buffer[max_buffer_size]{};
      auto end = test_functions::test_to_chars(buffer, state.range(0));
      expected_result = std::string_view(buffer, end);
    }
    {
      char buffer[max_buffer_size]{};
      auto end = test_functions::test_fmt_compile_separate_formatter(
          buffer, state.range(0));
      actual_result = std::string_view(buffer, end);
    }
    if (expected_result != actual_result) {
      fprintf(stderr, "expected: '%s', actual: '%s'", expected_result.data(),
              actual_result.data());
    }
  }

  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_fmt_compile_separate_formatter(buffer,
                                                            state.range(0)));
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
    std::string expected_result;
    std::string actual_result;
    {
      char buffer[max_buffer_size]{};
      auto end = test_functions::test_to_chars(buffer, state.range(0));
      expected_result = std::string_view(buffer, end);
    }
    {
      char buffer[max_buffer_size]{};
      auto end = test_functions::
          test_fmt_compile_separate_formatter_noinline_removed_from_fill(
              buffer, state.range(0));
      actual_result = std::string_view(buffer, end);
    }
    if (expected_result != actual_result) {
      fprintf(stderr, "expected: '%s', actual: '%s'", expected_result.data(),
              actual_result.data());
    }
  }

  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::
            test_fmt_compile_separate_formatter_noinline_removed_from_fill(
                buffer, state.range(0)));
  }
}
BENCHMARK(FMTCompileSeparateFormatterNOINLINERemovedFromFill)
    ->Arg(0)
    ->Arg(42)
    ->Arg(273123)
    ->Arg(std::numeric_limits<int64_t>::max());

static void ToChars(benchmark::State& state) {
  char buffer[max_buffer_size]{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(
        test_functions::test_to_chars(buffer, state.range(0)));
  }
}
BENCHMARK(ToChars)->Arg(0)->Arg(42)->Arg(273123)->Arg(
    std::numeric_limits<int64_t>::max());

BENCHMARK_MAIN();
