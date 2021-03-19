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
| CustomCode                                         | 3.49 ns |
| FMTCompileMaster                                   | 36.7 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 36.7 ns |
| FMTCompileSeparateFormatter                        | 20.1 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 15.6 ns |
| StringStream                                       |  310 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 3.51 ns |
| FMTCompileMaster                                   | 36.4 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 36.5 ns |
| FMTCompileSeparateFormatter                        | 19.8 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 14.9 ns |
| StringStream                                       |  311 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 3.51 ns |
| FMTCompileMaster                                   | 35.7 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 35.8 ns |
| FMTCompileSeparateFormatter                        | 19.0 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 15.6 ns |
| StringStream                                       |  316 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 3.49 ns |
| FMTCompileMaster                                   | 32.7 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 32.8 ns |
| FMTCompileSeparateFormatter                        | 19.3 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 15.3 ns |
| StringStream                                       |  304 ns |


### Clang (main, 961e4384f4e938b901490912813ff0e8347cc3c0) C++20

#### `value == 0`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 3.24 ns |
| FMTCompileMaster                                   | 28.1 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 27.9 ns |
| FMTCompileSeparateFormatter                        | 19.4 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 19.0 ns |
| StringStream                                       |  321 ns |

#### `value == 42`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 3.24 ns |
| FMTCompileMaster                                   | 28.1 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 27.9 ns |
| FMTCompileSeparateFormatter                        | 18.5 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 18.8 ns |
| StringStream                                       |  322 ns |

#### `value == 273123`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 3.24 ns |
| FMTCompileMaster                                   | 26.8 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 26.7 ns |
| FMTCompileSeparateFormatter                        | 18.1 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 18.9 ns |
| StringStream                                       |  326 ns |

#### `value == 9223372036854775807`

| Benchmark                                          |    Time |
| ---------------------------------------------------|---------|
| CustomCode                                         | 3.25 ns |
| FMTCompileMaster                                   | 24.5 ns |
| FMTCompileMasterNOINLINERemovedFromFill            | 24.4 ns |
| FMTCompileSeparateFormatter                        | 17.6 ns |
| FMTCompileSeparateFormatterNOINLINERemovedFromFill | 19.6 ns |
| StringStream                                       |  317 ns |

### GCC 10 C++20 with LTO 

|Benchmark                            |    Time |     CPU | Iterations|
|-------------------------------------|---------|---------|-----------|
|CustomCode/0                         | 3.32 ns | 3.32 ns |  209049795|
|CustomCode/42                        | 3.32 ns | 3.32 ns |  209769711|
|CustomCode/273123                    | 3.34 ns | 3.34 ns |  209340833|
|CustomCode/9223372036854775807       | 3.33 ns | 3.33 ns |  210997224|
|FMTCompileMaster/0                   | 30.5 ns | 30.5 ns |   22915793|
|FMTCompileMaster/42                  | 30.2 ns | 30.2 ns |   23112169|
|FMTCompileMaster/273123              | 29.6 ns | 29.6 ns |   23590029|
|FMTCompileMaster/9223372036854775807 | 26.7 ns | 26.7 ns |   26143214|
|StringStream/0                       |  311 ns |  311 ns |    2239268|
|StringStream/42                      |  313 ns |  313 ns |    2230706|
|StringStream/273123                  |  314 ns |  314 ns |    2195529|
|StringStream/9223372036854775807     |  303 ns |  303 ns |    2292915|

|Benchmark                                                              |    Time |     CPU | Iterations|
|-----------------------------------------------------------------------|---------|---------|-----------|
|CustomCode/0                                                           | 3.33 ns | 3.33 ns |  209342634|
|CustomCode/42                                                          | 3.33 ns | 3.33 ns |  208700972|
|CustomCode/273123                                                      | 3.33 ns | 3.33 ns |  208585764|
|CustomCode/9223372036854775807                                         | 3.33 ns | 3.33 ns |  209115577|
|FMTCompileSeparateFormatterNOINLINERemovedFromFill/0                   | 16.8 ns | 16.8 ns |   41139956|
|FMTCompileSeparateFormatterNOINLINERemovedFromFill/42                  | 16.3 ns | 16.3 ns |   42287737|
|FMTCompileSeparateFormatterNOINLINERemovedFromFill/273123              | 16.7 ns | 16.7 ns |   42106678|
|FMTCompileSeparateFormatterNOINLINERemovedFromFill/9223372036854775807 | 15.4 ns | 15.4 ns |   45993127|
|StringStream/0                                                         |  316 ns |  316 ns |    2218069|
|StringStream/42                                                        |  316 ns |  316 ns |    2218073|
|StringStream/273123                                                    |  320 ns |  320 ns |    2181946|
|StringStream/9223372036854775807                                       |  309 ns |  309 ns |    2264052|
