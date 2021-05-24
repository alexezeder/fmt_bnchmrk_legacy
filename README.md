# fmt_bnchmrk

## benchmarks:

* JustWrite42 - just write `"42"` to file using `std::fwrite()`
* PrintTrivial - use `fmt::print("{}", 42)` to write `42`
* PrintTrivialCompile - same as PrintTrivial, but using compile-time API
* PrintComplex - same as trivial, but with `"{:08x} {:0.2f} {:>7}"` as format string
* PrintComplexCompile - same as PrintComplex, but using compile-time API

## here are results on my PC:

### GCC 10 C++20

#### using static library

| Benchmark             |      Time    |
| ----------------------|--------------|
| JustWrite42           |   12.2 ns    |
| PrintTrivial          |   25.2 ns    |
| PrintTrivialCompile   |   20.3 ns    |
| PrintComplex          |    216 ns    |
| PrintComplexCompile   |    135 ns    |

#### using header-only library

| Benchmark             |      Time    |
| ----------------------|--------------|
| JustWrite42           |   12.1 ns    |
| PrintTrivial          |   25.2 ns    |
| PrintTrivialCompile   |   16.6 ns    |
| PrintComplex          |    216 ns    |
| PrintComplexCompile   |    141 ns    |
