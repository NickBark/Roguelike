#include "barkengine.hpp"

Village::Village(size_t n, size_t m) : n(n), m(m), cell(NULL) { allot_cell(cell, n, m); }

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

void Village::print_village() {
    for (size_t i = 0; i < this->get_n(); i++) {
        for (size_t j = 0; j < this->get_m(); j++) {
            mvprintw(j, i, "%c", this->get_data_elem(i, j));
        }
        printw("\n");
    }
}

void Village::room(size_t& rx, size_t& ry, size_t& rx_max, size_t& ry_max) {
    rx = rand() % (this->get_n() - 3) + 1;
    ry = rand() % (this->get_m() - 3) + 1;
    rx_max = rand() % 5 + 4;
    ry_max = rand() % 10 + 8;

    for (size_t i = rx; i < rx + rx_max; i++) {
        for (size_t j = ry; j < ry + ry_max; j++) {
            if (i > this->get_n() - 2 || j > this->get_m() - 2)
                continue;
            this->get_data_elem(i, j) = ' ';
            this->get_barrier_elem(i, j) = 0;
        }
    }
}