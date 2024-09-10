#pragma once

class SHIP {
private:
    int x, y;
    int hearts;
    int lifes;

public:
    SHIP(int _x, int _y, int _hearts, int _lifes);
    int getX();
    int getY();
    void damage();
    int life();
    void draw();
    void erase();
    void move(char direction);
    void paint_hearts();
    void death();

    SHIP() = default;
};
