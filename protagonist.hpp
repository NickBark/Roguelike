#ifndef PROTAGONIST_HPP
#define PROTAGONIST_HPP

#include "dependencies.hpp"

class Protagonist {
  public:
    explicit Protagonist(int x = 0, int y = 0) : avatar('@'), x(x), y(y) {}
    int& get_x() { return x; }
    int& get_y() { return y; }
    char get_avatar() const { return avatar; }

  private:
    char avatar;
    int x;
    int y;
};

#endif // PROTAGONIST_HPP
