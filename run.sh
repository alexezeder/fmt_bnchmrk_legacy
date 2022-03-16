#!/bin/bash -e

TEMP_DIR="$(mktemp -d)"
CPU_COUNT=$(nproc --all)
TESTS=("fmt_vanilla_test" "fmt_vanilla_header_only_test" "fmt_modified_test" "fmt_modified_header_only_test")

cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=20 -S . -B "${TEMP_DIR}"
cmake --build "${TEMP_DIR}" --target "${TESTS[@]}" --parallel "${CPU_COUNT}"

for test_name in "${TESTS[@]}"; do
  echo -e "\n${test_name}"
  "${TEMP_DIR}/${test_name}" 2>/dev/null
done

rm -rf "${TEMP_DIR}"
