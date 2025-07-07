#include "grids.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

PYBIND11_MODULE(py_game_of_life, m) {
  py::class_<Grids>(m, "Grids")
      .def(py::init<int, int>())
      .def("set_grid", &Grids::set_grid)
      .def("get_grid", &Grids::get_grid)
      .def("update_grid", &Grids::update_grid)
      .def("reset_grid", &Grids::reset_grid);
}
