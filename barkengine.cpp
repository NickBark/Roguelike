#include "barkengine.hpp"

Village::Village(size_t n, size_t m) : n(n), m(m) {
    allot_map_paint(data, n, m);
    allot_map_barrier(barrier, n, m);
}

Village::~Village() {
    for (size_t i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;

    for (size_t i = 0; i < n; i++) {
        delete[] barrier[i];
    }
    delete[] barrier;
}

void move(int& c, int& x, int& y, int const& x_max, int const& y_max,
          Village& obj) {
    if ((c == 'w' || c == KEY_UP) && y != 0 &&
        !obj.get_barrier_elem(x, y - 1)) {
        y--;
    } else if ((c == 's' || c == KEY_DOWN) && y != y_max - 1 &&
               !obj.get_barrier_elem(x, y + 1)) {
        y++;
    } else if ((c == 'a' || c == KEY_LEFT) && x != 0 &&
               !obj.get_barrier_elem(x - 1, y)) {
        x--;
    } else if ((c == 'd' || c == KEY_RIGHT) && x != x_max - 1 &&
               !obj.get_barrier_elem(x + 1, y)) {
        x++;
    }
}

void allot_map_paint(char**& arr, size_t const& n, size_t const& m) {
    arr = new char*[n];
    for (size_t i = 0; i < n; i++) {
        arr[i] = new char[m];
    }
}

void allot_map_barrier(int**& arr, size_t const& n, size_t const& m) {
    arr = new int*[n];
    for (size_t i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
}
