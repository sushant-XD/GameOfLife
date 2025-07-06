#pragma once
#include "utils/print_utils.h"
#include <iostream>
#include <vector>
class Grids {
public:
  int rows;
  int columns;
  std::vector<std::vector<int>> grid;
  std::vector<std::vector<int>> nextgrid;
  Grids(int rows, int columns);
  ~Grids(){
      // empty
  };
  void print_grids();
  void create_grids();
  void update_grid();
  void set_grid(std::vector<std::pair<int, int>> coordinates);
};
