#ifndef BARKENGINE_HPP
#define BARKENGINE_HPP

#include "cell.hpp"
#include "dependencies.hpp"
#include "protagonist.hpp"

class Village : public Cell {
  public:
    explicit Village(size_t n = 25, size_t m = 50);

    ~Village();

    size_t const& get_n() { return n; }
    size_t const& get_m() { return m; }
    char& get_data_elem(int x, int y) { return cell[x][y].get_symb(); }
    int& get_barrier_elem(int x, int y) { return cell[x][y].get_status(); }
    Cell**& get_data() { return cell; }

    void print_village();

  private:
    size_t const n; // строки
    size_t const m; // столбцы
    Cell** cell;
};

void movement(int& c, int& x, int& y, int const& x_max, int const& y_max,
              Village& obj, Protagonist& mag);

void allot_cell(Cell **& arr, size_t const& n, size_t const& m);

#endif // BARKENGINE_HPP
