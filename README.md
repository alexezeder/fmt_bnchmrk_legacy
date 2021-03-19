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
| CustomCode                                         | 1.75 ns |
| FMTCompileMaster                                   | 11.3 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 11.3 ns |
| FMTCompileSeparateFormatter                        | 3.31 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 2.28 ns |
| ToChars                                            |1.000 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 2.79 ns |
| FMTCompileMaster                                   | 11.8 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 11.8 ns |
| FMTCompileSeparateFormatter                        | 4.83 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 3.31 ns |
| ToChars                                            | 2.01 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.15 ns |
| FMTCompileMaster                                   | 13.0 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 13.0 ns |
| FMTCompileSeparateFormatter                        | 8.57 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 6.66 ns |
| ToChars                                            | 3.90 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.85 ns |
| FMTCompileMaster                                   | 14.5 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 14.5 ns |
| FMTCompileSeparateFormatter                        | 11.6 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 9.80 ns |
| ToChars                                            | 4.54 ns |


### Clang (main, 961e4384f4e938b901490912813ff0e8347cc3c0) C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 1.57 ns |
| FMTCompileMaster                                   | 12.3 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 12.2 ns |
| FMTCompileSeparateFormatter                        | 9.71 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 1.57 ns |
| ToChars                                            | 1.90 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 2.24 ns |
| FMTCompileMaster                                   | 12.8 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 12.7 ns |
| FMTCompileSeparateFormatter                        | 10.6 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 2.26 ns |
| ToChars                                            | 2.23 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 5.13 ns |
| FMTCompileMaster                                   | 14.0 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 14.0 ns |
| FMTCompileSeparateFormatter                        | 13.5 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.16 ns |
| ToChars                                            | 3.48 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.58 ns |
| FMTCompileMaster                                   | 15.5 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 15.5 ns |
| FMTCompileSeparateFormatter                        | 15.6 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 6.55 ns |
| ToChars                                            | 5.00 ns |


