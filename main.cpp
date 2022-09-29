#include "barkengine.hpp"
#include "dependencies.hpp"
#include "protagonist.hpp"

int main(void) {
    setlocale(LC_ALL, "");

    Protagonist mag;

    initscr(); // инициализируем "курсы"
    noecho(); // отключаем экранизацию при нажатии кнопок
    curs_set(0); // выключаем отображение курсора
    keypad(stdscr, TRUE); // разрещаем стрелки

    mvaddstr(mag.get_y(), mag.get_x(), mag.get_avatar());

    while (1) {
        int c = getch();
        mvaddstr(mag.get_y(), mag.get_x(), " ");
        move(c, mag.get_x(), mag.get_y());
        mvaddstr(mag.get_y(), mag.get_x(), mag.get_avatar());
    }
    endwin();

    return 0;
}
