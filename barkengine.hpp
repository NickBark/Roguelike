#ifndef BARKENGINE_HPP
#define BARKENGINE_HPP

#include "dependencies.hpp"
#include "protagonist.hpp"

class Village {
  public:
    explicit Village(size_t n = 25, size_t m = 50);

    ~Village();

    size_t const& get_n() { return n; }
    size_t const& get_m() { return m; }
    char& get_data_elem(int x, int y) { return data[x][y]; }
    int& get_barrier_elem(int x, int y) { return barrier[x][y]; }
    char**& get_data() { return data; }

  private:
    size_t const n; // строки
    size_t const m; // столбцы
    int** barrier;
    char** data;
};

void movement(int& c, int& x, int& y, int const& x_max, int const& y_max,
              Village& obj, Protagonist& mag);
void allot_map_paint(char**& arr, size_t const& n, size_t const& m);
void allot_map_barrier(int**& arr, size_t const& n, size_t const& m);

#endif // BARKENGINE_HPP
