#ifndef PROTAGONIST_HPP
#define PROTAGONIST_HPP

#include "dependencies.hpp"

class Protagonist {
  public:
    explicit Protagonist(int x = 0, int y = 0) : avatar('@'), x(x), y(y) {}
    int& get_x() { return x; }
    int& get_y() { return y; }

    int& get_old_x() { return old_x; }
    int& get_old_y() { return old_y; }
    char& get_old_symb() { return old_symb; }

    char get_avatar() const { return avatar; }

  private:
    char avatar;
    int x;
    int y;

    int old_x;
    int old_y;
    char old_symb;
};

#endif // PROTAGONIST_HPP
