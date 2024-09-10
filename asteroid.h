#pragma once

#include "SHIP.h"

class Asteroid {
public:
    int x, y;
    Asteroid(int _x, int _y);
    void draw();
    void move();
    void crash(SHIP& P);
    int X() { return x; }
    int Y() { return y; }
};
