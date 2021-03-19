#include <sstream>
#include <iomanip>

#include "test_functions.hpp"

namespace test_functions {
std::string test_stringstream(unsigned value) {
  std::stringstream sstream;
  sstream << std::setfill('0') << std::setw(8) << std::hex << value;
  return sstream.str();
}
}  // namespace test_functions
