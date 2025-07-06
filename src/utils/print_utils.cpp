#include "utils/print_utils.h"

void print_usage(const std::string &program_name) {
  print("Print Usage: ", program_name, "[Arguments]");
  print("  -r, --rows          Number of rows in the grid");
  print("  -c, --columns       Number of columns in the grid");
  print("  -s, --steps         Number of steps(0 for infinite)");
}
