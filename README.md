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
| CustomCode                                         | 4.07 ns |
| FMTCompileMaster                                   | 21.5 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 4.12 ns |
| FMTCompileSeparateFormatter                        | 11.6 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.60 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 4.32 ns |
| FMTCompileMaster                                   | 21.9 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 4.84 ns |
| FMTCompileSeparateFormatter                        | 11.8 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.96 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.91 ns |
| FMTCompileMaster                                   | 23.2 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 5.72 ns |
| FMTCompileSeparateFormatter                        | 14.7 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 7.98 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 7.53 ns |
| FMTCompileMaster                                   | 20.5 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 5.07 ns |
| FMTCompileSeparateFormatter                        | 16.9 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 9.38 ns |


### Clang (main, 961e4384f4e938b901490912813ff0e8347cc3c0) C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 5.27 ns |
| FMTCompileMaster                                   | 14.2 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 14.2 ns |
| FMTCompileSeparateFormatter                        | 9.72 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 4.95 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.15 ns |
| FMTCompileMaster                                   | 14.8 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 15.0 ns |
| FMTCompileSeparateFormatter                        | 10.7 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 6.29 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 8.51 ns |
| FMTCompileMaster                                   | 16.3 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 16.2 ns |
| FMTCompileSeparateFormatter                        | 12.6 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 9.37 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 8.38 ns |
| FMTCompileMaster                                   | 14.0 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 13.9 ns |
| FMTCompileSeparateFormatter                        | 14.9 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 11.7 ns |


