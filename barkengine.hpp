#ifndef BARKENGINE_HPP
#define BARKENGINE_HPP

#include "dependencies.hpp"

class Village {
  public:
    explicit Village(size_t n = 25, size_t m = 50);

    ~Village() {
        for (size_t i = 0; i < n; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    size_t const& get_n() { return n; }
    size_t const& get_m() { return m; }
    char& get_data_elem(int x_, int y_) { return data[x_][y_]; }
    char**& get_data() { return data; }

  private:
    size_t const n; // строки
    size_t const m; // столбцы
    char** data;
};

void move(int& c, int& x, int& y, int const& x_max, int const& y_max,
          Village& obj);
void allot(char**& arr, size_t const& n, size_t const& m);
bool barrier(char c);

#endif // BARKENGINE_HPP
