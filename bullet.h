#pragma once

class BULLET {
    int x, y;
public:
    BULLET(int _x, int _y);
    int X();
    int Y();
    void move();
    bool out();
};