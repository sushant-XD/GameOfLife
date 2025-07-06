#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(py_game_of_life, m) {
  m.doc() = "Temporary pybind11 module for testing";
  m.def("hello", []() { return "Hello from C++!"; });
}
