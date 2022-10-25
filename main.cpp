#include "barkengine.hpp"
#include "dependencies.hpp"
#include "protagonist.hpp"

// Существует ли универсальный тип, как сделать одну функцию выделения памяти
// для разных типов (может быть через указатели на функции ?) !!! через ШАБЛОНЫ

void village_1_type(Village& brin) {
    for (size_t i = 0; i < brin.get_n(); i++) {
        for (size_t j = 0; j < brin.get_m(); j++) {
            if (rand() % 10 == 1) {
                if (rand() % 10 == 1) {
                    brin.get_data_elem(i, j) = '*';
                    brin.get_barrier_elem(i, j) = 1;

                } else {
                    brin.get_data_elem(i, j) = '|';
                    brin.get_barrier_elem(i, j) = 1;
                }
            } else {
                brin.get_data_elem(i, j) = '.';
                brin.get_barrier_elem(i, j) = 0;
            }
        }
    }
}

void place_goblin(Village& brin, Protagonist& goblin, int const& rows,
                  int const& cols) {
    do {
        goblin.get_x() = rand() % rows;
        goblin.get_y() = rand() % cols;
    } while (brin.get_barrier_elem(goblin.get_x(), goblin.get_y()));
    mvaddch(goblin.get_y(), goblin.get_x(), goblin.get_avatar());
}

int main(void) {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    int gold = 0;
    int rows = 25;
    int cols = 10;

    initscr(); // инициализируем "курсы"
    noecho(); // отключаем экранизацию при нажатии кнопок
    curs_set(0); // выключаем отображение курсора
    keypad(stdscr, TRUE); // разрешаем стрелки
    // getmaxyx(stdscr, cols, rows); // размер консоли

    // rows = rand() % rows;
    // cols = rand() % cols;

    Protagonist mag;
    Protagonist goblin;
    Village brin(rows, cols);
    goblin.get_avatar() = 't';

    village_1_type(brin);

    brin.print_village();

    place_goblin(brin, goblin, rows, cols);
    mvaddch(mag.get_y(), mag.get_x(), mag.get_avatar());
    mvprintw(cols, 0, "Gold: %d", gold);

    // mvprintw(mag.get_y(), mag.get_x(), "🧙");

    mag.get_old_x() = mag.get_x();
    mag.get_old_y() = mag.get_y();
    mag.get_old_symb() = brin.get_data_elem(mag.get_old_x(), mag.get_old_y());

    int c = 0;

    while ((c = getch()) && c != 27) { // 27 - ESC
        movement(c, mag.get_x(), mag.get_y(), brin.get_n(), brin.get_m(), brin,
                 mag);
        if (mag.get_x() == goblin.get_x() && mag.get_y() == goblin.get_y()) {
            gold += random() % 10 + 1;
            place_goblin(brin, goblin, rows, cols);
        }
        mvprintw(cols, 0, "Gold: %d", gold);
    }

    endwin();
    cout << "GAME OVER" << endl;
    return 0;
}
