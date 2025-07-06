#include "grids.h"
Grids::Grids(int rows, int columns) {
  this->rows = rows;
  this->columns = columns;
  // basically I need a 2d matrix of n rows and m columns stored in a vector in
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

void Grids::set_grid(std::vector<std::pair<int, int>> coordinates) {
  // so here we get the vector of pair of co-ordinates that we need to set thee
  // life to 1
  for (size_t i = 0; i < coordinates.size(); i++) {
    std::pair<int, int> coordinate = coordinates[i];
    grid[coordinate.first][coordinate.second] = 1;
  }
}

void Grids::update_grid() {
  // here, in every element in the grid, we need to check: elements on the
  // adjacent 8 sides
  nextgrid = grid;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if ((i == 0) || (i == rows - 1) || (j == 0) || (j == columns - 1)) {
        // edges
        // not implemented right now, meaning if it is at the edge, kill the
        // grid
        nextgrid[i][j] = 0;
      } else {
        int aliveneighbors = grid[i - 1][j - 1] + grid[i - 1][j] +
                             grid[i - 1][j + 1] + grid[i][j - 1] +
                             grid[i][j + 1] + grid[i + 1][j - 1] +
                             grid[i + 1][j] + grid[i + 1][j + 1];
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
  }
  grid = nextgrid;
}
