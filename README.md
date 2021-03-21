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
| FMTCompileMaster                                   | 1.50 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 1.50 ns |
| FMTCompileSeparateFormatter                        | 10.8 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 2.54 ns |
| ToChars                                            | 1.24 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 2.55 ns |
| FMTCompileMaster                                   | 2.00 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 2.00 ns |
| FMTCompileSeparateFormatter                        | 11.5 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 3.80 ns |
| ToChars                                            | 2.90 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 5.81 ns |
| FMTCompileMaster                                   | 3.34 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 3.41 ns |
| FMTCompileSeparateFormatter                        | 14.5 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 8.26 ns |
| ToChars                                            | 4.50 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.95 ns |
| FMTCompileMaster                                   | 4.86 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 4.82 ns |
| FMTCompileSeparateFormatter                        | 16.5 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 11.3 ns |
| ToChars                                            | 5.63 ns |


### Clang (main, 961e4384f4e938b901490912813ff0e8347cc3c0) C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 1.59 ns |
| FMTCompileMaster                                   | 6.82 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 6.58 ns |
| FMTCompileSeparateFormatter                        | 9.97 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 1.59 ns |
| ToChars                                            | 1.25 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 2.26 ns |
| FMTCompileMaster                                   | 7.49 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 7.23 ns |
| FMTCompileSeparateFormatter                        | 10.5 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 2.26 ns |
| ToChars                                            | 2.25 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 5.19 ns |
| FMTCompileMaster                                   | 8.95 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 8.99 ns |
| FMTCompileSeparateFormatter                        | 13.7 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.51 ns |
| ToChars                                            | 3.50 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.72 ns |
| FMTCompileMaster                                   | 10.6 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 10.7 ns |
| FMTCompileSeparateFormatter                        | 15.7 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 6.67 ns |
| ToChars                                            | 5.02 ns |


