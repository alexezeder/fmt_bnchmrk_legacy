# fmt_bnchmrk

## benchmarks:

* CustomCode - simplified code from {fmt}, almost perfect in terms of
  performance
* FMTCompileMaster - header only, commit `eef4ba9c02de46e5cce031db57268cc199c101fe` to be
  precise
* FMTCompileMasterNOINLINERemovedFromFill - same as previous with FMT_NOINLINE
  removed from
  ```cpp
  template <typename OutputIt, typename Char>
  FMT_NOINLINE FMT_CONSTEXPR OutputIt fill(OutputIt it, size_t n,
                                           const fill_t<Char>& fill) {
    auto fill_size = fill.size();
    if (fill_size == 1) return detail::fill_n(it, n, fill[0]);
    auto data = fill.data();
    for (size_t i = 0; i < n; ++i)
      it = copy_str<Char>(data, data + fill_size, it);
    return it;
  }
  ```
* FMTCompileSeparateFormatter - header only, a separate formatter
  class `int_formatter`, which takes `basic_format_specs` as template argument,
  thus it's able to prepare `format()` method at compile-time, requires C++20
* FMTCompileSeparateFormatterNOINLINERemovedFromFill - same as previous with
  FMT_NOINLINE removed from the same `fill` function as in
  FMTCompileMasterNOINLINERemovedFromFill
* ToChars - `to_chars` from C++17 `<charconv>` header used

## here are results on my PC:

### GCC 10 C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 1.76 ns |
| FMTCompileMaster                                   | 1.51 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 1.50 ns |
| FMTCompileSeparateFormatter                        | 2.00 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 2.26 ns |
| ToChars                                            | 1.00 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 2.51 ns |
| FMTCompileMaster                                   | 1.99 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 2.00 ns |
| FMTCompileSeparateFormatter                        | 2.75 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 2.76 ns |
| ToChars                                            | 2.10 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 5.82 ns |
| FMTCompileMaster                                   | 3.32 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 3.78 ns |
| FMTCompileSeparateFormatter                        | 4.27 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 4.04 ns |
| ToChars                                            | 3.95 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.92 ns |
| FMTCompileMaster                                   | 4.84 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 4.79 ns |
| FMTCompileSeparateFormatter                        | 5.77 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.61 ns |
| ToChars                                            | 4.52 ns |


### Clang (main, 961e4384f4e938b901490912813ff0e8347cc3c0) C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 1.60 ns |
| FMTCompileMaster                                   | 6.84 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 6.52 ns |
| FMTCompileSeparateFormatter                        | 1.63 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 1.65 ns |
| ToChars                                            | 1.25 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 2.27 ns |
| FMTCompileMaster                                   | 7.41 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 7.17 ns |
| FMTCompileSeparateFormatter                        | 2.09 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 2.08 ns |
| ToChars                                            | 2.27 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 5.10 ns |
| FMTCompileMaster                                   | 8.99 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 8.90 ns |
| FMTCompileSeparateFormatter                        | 4.18 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 3.64 ns |
| ToChars                                            | 3.52 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.65 ns |
| FMTCompileMaster                                   | 10.5 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 10.6 ns |
| FMTCompileSeparateFormatter                        | 4.80 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 4.84 ns |
| ToChars                                            | 5.03 ns |


### MSVC 19.28.29913 C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 3.08 ns |
| FMTCompileMaster                                   | 38.1 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 38.2 ns |
| FMTCompileSeparateFormatter                        | 7.60 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 7.64 ns |
| ToChars                                            | 7.11 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 4.14 ns |
| FMTCompileMaster                                   | 38.5 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 38.5 ns |
| FMTCompileSeparateFormatter                        | 7.87 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 7.89 ns |
| ToChars                                            | 8.07 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 7.27 ns |
| FMTCompileMaster                                   | 40.2 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 40.2 ns |
| FMTCompileSeparateFormatter                        | 9.01 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 9.02 ns |
| ToChars                                            | 10.2 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 10.7 ns |
| FMTCompileMaster                                   | 42.1 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 41.8 ns |
| FMTCompileSeparateFormatter                        | 10.4 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 10.4 ns |
| ToChars                                            | 11.6 ns |
