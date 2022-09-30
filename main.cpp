#include "barkengine.hpp"
#include "dependencies.hpp"
#include "protagonist.hpp"

int main(void) {
    setlocale(LC_ALL, "");

    Protagonist mag;
    Village brin(25, 50);

    for (size_t i = 0; i != brin.get_n(); i++) {
        for (size_t j = 0; j < brin.get_m(); j++) {
            brin.get_data_elem(i, j) = '_';
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
    mvaddstr(mag.get_y(), mag.get_x(), mag.get_avatar());
    while ((c = getch()) && c != 27) { // 27 - ESC
        // clear();
        mvaddch(mag.get_y(), mag.get_x(), brin.get_data_elem(0, 0));
        move(c, mag.get_x(), mag.get_y(), brin.get_m(), brin.get_n());
        mvaddstr(mag.get_y(), mag.get_x(), mag.get_avatar());
    }
    endwin();

    return 0;
}
