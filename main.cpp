#include <benchmark/benchmark.h>

#include <cstdio>

#include "fmt/compile.h"

static void JustWrite42(benchmark::State& state) {
  auto fp = std::fopen( "/tmp/file_jw.txt", "w" );
  std::fputc('a', fp);
  auto buffer = "42";
  auto buffer_size = std::strlen(buffer);
  for (auto _ : state) {
    benchmark::DoNotOptimize(std::fwrite(buffer, 1, buffer_size, fp));
  }
}
BENCHMARK(JustWrite42);

static void PrintTrivial(benchmark::State& state) {
  auto fp = std::fopen( "/tmp/file_pt.txt", "w" );
  std::fputc('a', fp);
  for (auto _ : state) {
    fmt::print(fp, "{}", 42);
  }
}
BENCHMARK(PrintTrivial);

static void PrintTrivialCompile(benchmark::State& state) {
  auto fp = std::fopen( "/tmp/file_ptc.txt", "w" );
  std::fputc('a', fp);
  for (auto _ : state) {
    fmt::print(fp, FMT_COMPILE("{}"), 42);
  }
}
BENCHMARK(PrintTrivialCompile);

static void PrintComplex(benchmark::State& state) {
  auto fp = std::fopen( "/tmp/file_pc.txt", "w" );
  std::fputc('a', fp);
  for (auto _ : state) {
    fmt::print(fp, "{:08x} {:0.2f} {:>7}", 42, 2.8, "text");
  }
}
BENCHMARK(PrintComplex);

static void PrintComplexCompile(benchmark::State& state) {
  auto fp = std::fopen( "/tmp/file_pcc.txt", "w" );
  std::fputc('a', fp);
  for (auto _ : state) {
    fmt::print(fp, FMT_COMPILE("{:08x} {:0.2f} {:>7}"), 42, 2.8, "text");
  }
}
BENCHMARK(PrintComplexCompile);


BENCHMARK_MAIN();
