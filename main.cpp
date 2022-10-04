#include "barkengine.hpp"
#include "dependencies.hpp"
#include "protagonist.hpp"

// Существует ли универсальный тип, как сделать одну функцию выделения памяти
// для разных типов (может быть через указатели на функции ?)

int main(void) {
    setlocale(LC_ALL, "");

    int const rows = 50;
    int const cols = 25;

    Protagonist mag;
    Village brin(rows, cols);

    for (size_t i = 0; i < brin.get_n(); i++) {
        for (size_t j = 0; j < brin.get_m(); j++) {
            if (i >= 5 && i <= 10 && j >= 4 && j <= 9) {
                brin.get_data_elem(i, j) = '^';
            } else {
                brin.get_data_elem(i, j) = '_';
            }
        }
    }

    initscr(); // инициализируем "курсы"
    noecho(); // отключаем экранизацию при нажатии кнопок
    curs_set(0); // выключаем отображение курсора
    keypad(stdscr, TRUE); // разрешаем стрелки

    int c = 0;
    // int old_x = 0;
    // int old_y = 0;
    // char old_symb = 0;

    for (size_t i = 0; i < brin.get_n(); i++) {
        for (size_t j = 0; j < brin.get_m(); j++) {
            mvaddch(j, i, brin.get_data_elem(i, j));
        }
        addch('\n');
    }
    // mvaddch(mag.get_y(), mag.get_x(), mag.get_avatar());

    mvprintw(mag.get_y(), mag.get_x(), "🧙");

    // old_x = mag.get_x();
    // old_y = mag.get_y();
    // old_symb = brin.get_data_elem(old_x, old_y);

    while ((c = getch()) && c != 27) { // 27 - ESC
        clear();
        for (size_t i = 0; i < brin.get_n(); i++) {
            for (size_t j = 0; j < brin.get_m(); j++) {
                mvaddch(j, i, brin.get_data_elem(i, j));
            }
            addch('\n');
        }
    
        move(c, mag.get_x(), mag.get_y(), brin.get_n(), brin.get_m(), brin);

        // mvaddch(mag.get_y(), mag.get_x(), mag.get_avatar());
        mvprintw(mag.get_y(), mag.get_x(), "🧙");
        // mvaddch(old_y, old_x, old_symb);

        // old_x = mag.get_x();
        // old_y = mag.get_y();
        // old_symb = brin.get_data_elem(old_x, old_y);
    }
    endwin();

    return 0;
}
