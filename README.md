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

## here are results on my PC:

### GCC 10 C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 4.48 ns |
| FMTCompileMaster                                   | 27.8 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 27.7 ns |
| FMTCompileSeparateFormatter                        | 11.0 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.97 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 5.61 ns |
| FMTCompileMaster                                   | 28.8 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 28.6 ns |
| FMTCompileSeparateFormatter                        | 11.8 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 6.21 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 8.07 ns |
| FMTCompileMaster                                   | 29.7 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 29.9 ns |
| FMTCompileSeparateFormatter                        | 15.1 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 8.06 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 9.28 ns |
| FMTCompileMaster                                   | 27.2 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 27.5 ns |
| FMTCompileSeparateFormatter                        | 16.7 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 9.33 ns |


### Clang (main, 961e4384f4e938b901490912813ff0e8347cc3c0) C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 5.23 ns |
| FMTCompileMaster                                   | 19.2 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 19.2 ns |
| FMTCompileSeparateFormatter                        | 9.97 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.48 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.08 ns |
| FMTCompileMaster                                   | 19.6 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 19.6 ns |
| FMTCompileSeparateFormatter                        | 10.7 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.99 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 8.44 ns |
| FMTCompileMaster                                   | 20.9 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 21.0 ns |
| FMTCompileSeparateFormatter                        | 13.5 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 8.30 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 8.28 ns |
| FMTCompileMaster                                   | 19.3 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 19.0 ns |
| FMTCompileSeparateFormatter                        | 15.7 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 10.6 ns |


