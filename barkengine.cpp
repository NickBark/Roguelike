#include "barkengine.hpp"

void move(int& c, int& x, int& y) {
    if (c == 'w' && y != 0) {
        y--;
    } else if (c == 's') {
        y++;
    } else if (c == 'a' && x != 0) {
        x--;
    } else if (c == 'd') {
        x++;
    }
}
