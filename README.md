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
| FMTCompileMaster                                   | 11.5 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 11.3 ns |
| FMTCompileSeparateFormatter                        | 10.8 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 2.52 ns |
| ToChars                                            | 1.25 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 2.79 ns |
| FMTCompileMaster                                   | 12.0 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 12.0 ns |
| FMTCompileSeparateFormatter                        | 11.5 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 3.53 ns |
| ToChars                                            | 2.49 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.15 ns |
| FMTCompileMaster                                   | 13.3 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 13.2 ns |
| FMTCompileSeparateFormatter                        | 14.2 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 7.49 ns |
| ToChars                                            | 3.76 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.82 ns |
| FMTCompileMaster                                   | 14.5 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 14.4 ns |
| FMTCompileSeparateFormatter                        | 16.6 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 10.5 ns |
| ToChars                                            | 5.45 ns |
