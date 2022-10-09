#include "barkengine.hpp"

Village::Village(size_t n, size_t m) : n(n), m(m) { allot_cell(cell, n, m); }

Village::~Village() {
    for (size_t i = 0; i < n; i++) {
        delete[] cell[i];
    }
    delete[] cell;
}

void movement(int& c, int& x, int& y, int const& x_max, int const& y_max,
              Village& obj, Protagonist& mag) {
    if ((c == 'w' || c == KEY_UP) && y != 0 &&
        !obj.get_barrier_elem(x, y - 1)) {
        mag.get_old_x() = x;
        mag.get_old_y() = y;
        mag.get_old_symb() = obj.get_data_elem(x, y);
        y--;
    } else if ((c == 's' || c == KEY_DOWN) && y != y_max - 1 &&
               !obj.get_barrier_elem(x, y + 1)) {
        mag.get_old_x() = x;
        mag.get_old_y() = y;
        mag.get_old_symb() = obj.get_data_elem(x, y);
        y++;
    } else if ((c == 'a' || c == KEY_LEFT) && x != 0 &&
               !obj.get_barrier_elem(x - 1, y)) {
        mag.get_old_x() = x;
        mag.get_old_y() = y;
        mag.get_old_symb() = obj.get_data_elem(x, y);
        x--;
    } else if ((c == 'd' || c == KEY_RIGHT) && x != x_max - 1 &&
               !obj.get_barrier_elem(x + 1, y)) {
        mag.get_old_x() = x;
        mag.get_old_y() = y;
        mag.get_old_symb() = obj.get_data_elem(x, y);
        x++;
    }
    mvaddch(mag.get_old_y(), mag.get_old_x(), mag.get_old_symb());
    mvaddch(mag.get_y(), mag.get_x(), mag.get_avatar());
    // mvprintw(mag.get_y(), mag.get_x(), "🧙");
}

void allot_cell(Cell**& arr, size_t const& n, size_t const& m) {
    arr = new Cell*[n];
    for (size_t i = 0; i < n; i++) {
        arr[i] = new Cell[m];
    }
}

// void allot_map_paint(char**& arr, size_t const& n, size_t const& m) {
//     arr = new char*[n];
//     for (size_t i = 0; i < n; i++) {
//         arr[i] = new char[m];
//     }
// }

// void allot_map_barrier(int**& arr, size_t const& n, size_t const& m) {
//     arr = new int*[n];
//     for (size_t i = 0; i < n; i++) {
//         arr[i] = new int[m];
//     }
// }
