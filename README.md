# benchmarks for simplified `print` and `format_to`

these benchmarks check performance gain for use cases like:
```
fmt::print("foo\n");
// and
fmt::format_to(buffer, "foobar");
// and
fmt::format_to(buffer, fmt::runtime("foobar"));
```
in other words, with single string argument

### to run tests, execute `run.sh` script

## tests:

* `fmt_vanilla_test` - current `master` version of {fmt} in form of static library used
* `fmt_vanilla_header_only_test` - same as previous, but header-only version used
* `fmt_modified_test` - slightly modified version of {fmt} in form of static library
* `fmt_modified_header_only_test` - same as previous, but header-only version used

## benchmarks:

* Print - `fmt::print("foo\n")` called from the separate translation unit
* PrintDirect - `fmt::print("foo\n")` called inside the test body directly
* Format - `fmt::format_to("foobar")` called from the separate translation unit
* FormatDirect - `fmt::format_to("foobar")` called inside the test body directly
* FormatRuntime - `fmt::format_to(fmt::runtime(text))` called from the separate translation unit
* FormatRuntimeDirect - `fmt::format_to(fmt::runtime(text))` called inside the test body directly

## here are results on my PC:

### GCC 11 + libstdc++

```
fmt_vanilla_test
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
Print                      103 ns          103 ns      6721554
PrintDirect                103 ns          103 ns      6775457
Format                    10.6 ns         10.6 ns     64897024
FormatDirect              9.54 ns         9.54 ns     70402968
FormatRuntime             10.6 ns         10.6 ns     64920895
FormatRuntimeDirect       9.55 ns         9.54 ns     73340279

fmt_vanilla_header_only_test
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
Print                      107 ns          107 ns      6481817
PrintDirect                104 ns          104 ns      6679333
Format                    8.77 ns         8.77 ns     79701948
FormatDirect              7.94 ns         7.94 ns     85519139
FormatRuntime             9.02 ns         9.02 ns     74940549
FormatRuntimeDirect       7.72 ns         7.72 ns     89175381

fmt_modified_test
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
Print                     95.1 ns         95.1 ns      7379102
PrintDirect               95.0 ns         95.0 ns      7309307
Format                    1.24 ns         1.24 ns    561070145
FormatDirect             0.418 ns        0.416 ns   1000000000
FormatRuntime             3.33 ns         3.32 ns    211087746
FormatRuntimeDirect       2.70 ns         2.69 ns    260065788

fmt_modified_header_only_test
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
Print                     94.0 ns         93.7 ns      7506010
PrintDirect               94.1 ns         93.8 ns      7387256
Format                    1.04 ns         1.04 ns    668328264
FormatDirect             0.216 ns        0.216 ns   1000000000
FormatRuntime             3.32 ns         3.32 ns    210866334
FormatRuntimeDirect       2.50 ns         2.49 ns    280461947
```

### Clang 13 + libc++

```
fmt_vanilla_test
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
Print                      109 ns          109 ns      6355610
PrintDirect                108 ns          108 ns      6435999
Format                    9.82 ns         9.82 ns     66784736
FormatDirect              8.68 ns         8.68 ns     80637029
FormatRuntime             9.80 ns         9.80 ns     70645362
FormatRuntimeDirect       9.13 ns         9.12 ns     76735913

fmt_vanilla_header_only_test
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
Print                      108 ns          108 ns      6439798
PrintDirect                107 ns          107 ns      6487665
Format                    9.70 ns         9.70 ns     70959906
FormatDirect              8.79 ns         8.79 ns     79853477
FormatRuntime             9.66 ns         9.66 ns     71953253
FormatRuntimeDirect       8.77 ns         8.77 ns     79723996

fmt_modified_test
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
Print                     94.3 ns         94.2 ns      7437532
PrintDirect               95.0 ns         95.0 ns      6972868
Format                    1.04 ns         1.04 ns    657830320
FormatDirect              1.03 ns         1.03 ns    664825808
FormatRuntime             3.56 ns         3.56 ns    197351533
FormatRuntimeDirect       2.71 ns         2.71 ns    258042822

fmt_modified_header_only_test
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
Print                     93.7 ns         93.7 ns      7463731
PrintDirect               93.0 ns         92.9 ns      7418454
Format                    1.04 ns         1.04 ns    671818246
FormatDirect              1.02 ns         1.02 ns    676679866
FormatRuntime             3.52 ns         3.52 ns    199072433
FormatRuntimeDirect       2.69 ns         2.69 ns    260513853
```
