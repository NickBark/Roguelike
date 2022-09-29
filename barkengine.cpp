#include "barkengine.hpp"

void move(int& c, int& x, int& y) {
    if ((c == 'w' || c == KEY_UP) && y != 0) {
        y--;
    } else if (c == 's' || c == KEY_DOWN) {
        y++;
    } else if ((c == 'a' || c == KEY_LEFT) && x != 0) {
        x--;
    } else if (c == 'd' || c == KEY_RIGHT) {
        x++;
    }
}
