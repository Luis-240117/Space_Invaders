#include "ship.h"
#include "utility.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <list>
#include <iterator>
#include <Windows.h>


using namespace std;

SHIP::SHIP(int _x, int _y, int _hearts, int _lifes) : x(_x), y(_y), hearts(_hearts), lifes(_lifes) {}

int SHIP::getX() { return x; }
int SHIP::getY() { return y; }
void SHIP::damage() { hearts--; }
int SHIP::life() { return lifes; }

// Aqui utilice ciertos caracteres para pintar mi nave.
void SHIP::draw() {
    gotoxy(x, y);
        printf("  %c", 221);
    gotoxy(x, y + 1);
        printf(" %c%c%c", 201, 206, 187);
    gotoxy(x, y + 2);
        printf("%c%c%c%c%c", 201, 202, 206, 202, 187);
    gotoxy(x, y + 3);
        printf("%c %c %c", 94, 94, 94);
}

// Con esta funcion manejamos el borrado de la nave.
void SHIP::erase() {
    gotoxy(x, y);
        printf("     ");
    gotoxy(x, y + 1);
        printf("     ");
    gotoxy(x, y + 2);
        printf("     ");
    gotoxy(x, y + 3);
        printf("     ");
}

// Con esta funcion manejamos el movimiento de la nave utilizando las teclas de WASD con ayuda de un switch.
void SHIP::move(char direction) {
    erase();

    switch (direction) {
    case 'a':
        if (x > 2) x--;
        break;
    case 'd':
        if (x < 72) x++;
        break;
    case 'w':
        if (y > 3) y--;
        break;
    case 's':
        if (y < 29) y++;
        break;
    }

    draw();
    paint_hearts();
}

// Con esta funcion colocamos los mensajes que estan colocados en la parte superior de la pantalla donde vemos la vida y las vidas.
void SHIP::paint_hearts() {
    gotoxy(40, 1);
        printf("Lifes: %d", lifes);
    gotoxy(4, 1);
        printf("Health:");
    gotoxy(12, 1);
        printf("         ");
    for (int i = 0; i < hearts; i++) {
        gotoxy(12 + i, 1);
            printf("%c", 219);
    }
}

// Con esta funcion podemos ver una pequeña animacion de como la nave es destruida.
void SHIP::death() {
    if (hearts == 0) {
        erase();
        gotoxy(x, y);
            printf("     ");
        gotoxy(x, y + 1);
            printf("  *  ");
        gotoxy(x, y + 2);
            printf("     ");
        Sleep(200);
        erase();
        gotoxy(x, y);
            printf(" * * ");
        gotoxy(x, y + 1);
            printf("*   *");
        gotoxy(x, y + 2);
            printf(" * * ");
        Sleep(200);
        erase();
        gotoxy(x, y);
            printf("* * *");
        gotoxy(x, y + 1);
            printf(" *** ");
        gotoxy(x, y + 2);
            printf("* * *");
        Sleep(200);
        erase();
        lifes--;
        hearts = 3;
        paint_hearts();
        draw();
    }
}
