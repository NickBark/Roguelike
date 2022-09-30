#ifndef BARKENGINE_HPP
#define BARKENGINE_HPP

#include "dependencies.hpp"

void move(int& c, int& x, int& y, int const& x_max, int const& y_max);
void allot(char**& arr, size_t const& n, size_t const& m);

class Village {
  public:
    explicit Village(size_t n = 100, size_t m = 100);

    ~Village() {
        for (size_t i = 0; i < n; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    size_t const& get_n() { return n; }
    size_t const& get_m() { return m; }
    char& get_data_elem(int n, int m) { return data[n][m]; }

  private:
    size_t const n; // строки
    size_t const m; // столбцы
    char** data;
};

#endif // BARKENGINE_HPP
