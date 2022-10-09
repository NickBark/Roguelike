#ifndef CELL_HPP
#define CELL_HPP

using namespace std;

#include "dependencies.hpp"

class Cell {
  public:
    int& get_status() { return status_barrier; }
    char& get_symb() { return symb; }

  private:
    int status_barrier;
    char symb;
};

#endif // CELL_HPP