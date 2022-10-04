#include "barkengine.hpp"
#include "dependencies.hpp"
#include "protagonist.hpp"

// сделать barrier обычной функцией, посмотреть исправит ли это ошибку
// сегментации

int main(void) {
    setlocale(LC_ALL, "");

    int const rows = 25;
    int const cols = 50;

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
    for (size_t i = 0; i != brin.get_n(); i++) {
        for (size_t j = 0; j < brin.get_m(); j++) {
            addch(brin.get_data_elem(i, j));
        }
        addch('\n');
    }
    mvaddch(mag.get_y(), mag.get_x(), mag.get_avatar());

    while ((c = getch()) && c != 27) { // 27 - ESC
        clear();
        for (size_t i = 0; i != brin.get_n(); i++) {
            for (size_t j = 0; j < brin.get_m(); j++) {
                addch(brin.get_data_elem(i, j));
            }
            addch('\n');
        }
        move(c, mag.get_x(), mag.get_y(), brin.get_m(), brin.get_n(), brin);
        mvaddch(mag.get_y(), mag.get_x(), mag.get_avatar());
    }
    endwin();

    return 0;
}
