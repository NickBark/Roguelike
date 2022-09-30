#include "barkengine.hpp"

Village::Village(size_t n, size_t m) : n(n), m(m) { allot(data, n, m); }

void move(int& c, int& x, int& y, int const& x_max, int const& y_max) {
    if ((c == 'w' || c == KEY_UP) && y != 0) {
        y--;
    } else if ((c == 's' || c == KEY_DOWN) && y != y_max - 1) {
        y++;
    } else if ((c == 'a' || c == KEY_LEFT) && x != 0) {
        x--;
    } else if ((c == 'd' || c == KEY_RIGHT) && x != x_max - 1) {
        x++;
    }
}

void allot(char**& arr, size_t const& n, size_t const& m) {
    arr = new char*[n];
    for (size_t i = 0; i < n; i++) {
        arr[i] = new char[m];
    }
}
