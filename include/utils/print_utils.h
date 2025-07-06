#pragma once
#include <iostream>
#include <vector>
inline void print() { std::cout << std::endl; }
template <typename T, typename... Args>
void print(const T &first_arg, Args... rem) {
  std::cout << first_arg;
  print(rem...);
}

template <typename T> void print(const std::vector<T> &vect) {
  for (const int &element : vect) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}
void print_usage(const std::string &program_name);
