#include "main.h"
int main(int argc, char *argv[]) {
  if (argc < 3) {
    print_usage(argv[0]);
    return 0;
  }
  int rows = 0, cols = 0, steps = 0;
  try {
    for (int i = 1; i < argc; i++) {
      std::string arg = argv[i];
      if ((arg == "-r") || (arg == "--rows")) {
        rows = std::stoi(argv[++i]);
      } else if ((arg == "-c") || (arg == "--columns")) {
        cols = std::stoi(argv[++i]);
      } else if ((arg == "-s") || (arg == "--steps")) {
        steps = std::stoi(argv[++i]);
      }
    }
  } catch (...) {
    print("Exception Occured. Couldn't parse input arguments");
    return 0;
  }
  print("Number of Rows", rows);
  print("Number of Columns", cols);
  print("Number of Steps", steps);
  if (rows == 0 || cols == 0) {
    print("Invalid rows or columns");
    return 0;
  }
  Grids grid(rows, cols);
  grid.print_grids();
  print("Enter the number of grid boxes you want to set to 1");
  int num;
  std::vector<std::pair<int, int>> inputCoordinates;
  std::cin >> num;
  for (int i = 0; i < num; i++) {
    std::pair<int, int> pairs;
    print("Enter x-coordinate");
    std::cin >> pairs.first;
    print("Enter y-coordinate");
    std::cin >> pairs.second;
    inputCoordinates.push_back(pairs);
  }
  grid.set_grid(inputCoordinates);
  print("Grid after adding life elements");
  grid.print_grids();
  int i = 0;
  while (i == 0 || i < steps) {
    grid.update_grid();
    grid.print_grids();
    i++;
  }
}
