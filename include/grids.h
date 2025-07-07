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
  std::vector<std::vector<int>> get_grid() const;
  void print_grids();
  void create_grids();
  void reset_grid();
  std::vector<std::vector<int>> update_grid();
  void set_grid(std::vector<std::pair<int, int>> coordinates);
};
