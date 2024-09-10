#include "bullet.h"
#include "BULLET.h"
#include <stdio.h>
#include "utility.h"
// Constructor
BULLET::BULLET(int _x, int _y) : x(_x), y(_y) {}
// Con estas declaraciones podemos accesar a los valores de la poscion de la bala, estas caracteristicas son privadas.
int BULLET::X() { return x; }
int BULLET::Y() { return y; }

// Con esta funcion vamos a la posicion de la nave y colocamos el lugar del cual saldra la bala y la imprimimos.
void BULLET::move() {
    gotoxy(x, y);
        printf(" ");
    y--;
    gotoxy(x, y);
        printf("%c", 221);
}
// Con este bool fijamos que la bala no salga del marco del juego.
bool BULLET::out() {
    return y == 3;
}
