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
| FMTCompileMaster                                   | 21.8 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 4.08 ns |
| FMTCompileSeparateFormatter                        | 8.64 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.72 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 4.27 ns |
| FMTCompileMaster                                   | 22.3 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 4.82 ns |
| FMTCompileSeparateFormatter                        | 8.72 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.95 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 7.18 ns |
| FMTCompileMaster                                   | 23.6 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 5.78 ns |
| FMTCompileSeparateFormatter                        | 10.1 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 6.95 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 7.53 ns |
| FMTCompileMaster                                   | 20.8 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 5.06 ns |
| FMTCompileSeparateFormatter                        | 7.97 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 6.04 ns |


### Clang (main, 961e4384f4e938b901490912813ff0e8347cc3c0) C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 5.29 ns |
| FMTCompileMaster                                   | 14.4 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 14.2 ns |
| FMTCompileSeparateFormatter                        | 6.41 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 4.76 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 6.19 ns |
| FMTCompileMaster                                   | 14.8 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 15.0 ns |
| FMTCompileSeparateFormatter                        | 6.85 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 5.32 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 8.58 ns |
| FMTCompileMaster                                   | 16.2 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 16.2 ns |
| FMTCompileSeparateFormatter                        | 8.69 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 7.05 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 8.45 ns |
| FMTCompileMaster                                   | 13.9 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 13.9 ns |
| FMTCompileSeparateFormatter                        | 6.79 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 6.17 ns |


