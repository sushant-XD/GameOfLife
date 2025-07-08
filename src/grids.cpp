#include "grids.h"
Grids::Grids(int rows, int columns) {
  this->rows = rows;
  this->columns = columns;
  // basically a 2d matrix of n rows and m columns stored in a vector in
  // which 1 means there is life and 0 means there is no life firstly, when we
  // create grids with x rows and y columns, create and assign an empty 2d
  // vector with all 0
  for (int i = 0; i < rows; i++) {
    std::vector<int> singleCol;
    for (int j = 0; j < columns; j++) {
      singleCol.push_back(0);
    }
    this->grid.push_back(singleCol);
  }
}

void Grids::print_grids() {
  for (int i = 0; i < rows; i++) {
    print(grid[i]);
  }
}

std::vector<std::vector<int>> Grids::get_grid() const { return grid; }

void Grids::reset_grid() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      grid[i][j] = 0;
    }
  }
}

void Grids::set_grid(std::vector<std::pair<int, int>> coordinates) {
  // so here we get the vector of pair of co-ordinates that we need to set thee
  // life to 1
  reset_grid();

  for (const auto &coordinate : coordinates) {
    int x = coordinate.first;
    int y = coordinate.second;
    if (x >= rows || y >= columns || x < 0 || y < 0) {
      std::cout << "X and Y indices out of bound. Not responding" << std::endl;
      continue;
    } else {
      grid[x][y] = 1;
    }
  }
}

std::vector<std::vector<int>> Grids::update_grid() {
  // here, in every element in the grid, we need to check: elements on the
  // adjacent 8 sides
  nextgrid = grid;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {

      int top = (i - 1 + rows) % rows;
      int bottom = (i + 1) % rows;
      int left = (j - 1 + columns) % columns;
      int right = (j + 1) % columns;
      int aliveneighbors = grid[top][left] + grid[top][j] + grid[top][right] +
                           grid[i][left] + grid[i][right] + grid[bottom][left] +
                           grid[bottom][j] + grid[bottom][right];
      if (grid[i][j] == 1) {
        // if the element is alive
        if (aliveneighbors < 2) {
          // if neighbors are less than 3
          nextgrid[i][j] = 0;
        } else if (aliveneighbors <= 3) {
          // if neighbors are 2 or three
          nextgrid[i][j] = 1;
        } else {
          // if there are mroe than three neighbors
          nextgrid[i][j] = 0;
        }
      } else {
        // if the element is dead
        if (aliveneighbors == 3) {
          nextgrid[i][j] = 1;
        }
      }
    }
  }
  grid = nextgrid;
  return grid;
}
