#include "asteroid.h"
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

Asteroid::Asteroid(int _x, int _y) : x(_x), y(_y) {}

// Esta funcion nos dibuja el bello diseño del asteroide utilizando el sistema ASCII.
void Asteroid::draw() {
    gotoxy(x, y);
        printf("%c%c%c", 174, 147, 175);
}

// Con esta funcion marcamos donde iran cayendo los asteroides de manera aletoria utilizando el ancho de la pantalla que habiamos fijado antes.
void Asteroid::move() {
    gotoxy(x, y);
        printf("   ");
    y++;
    if (y > 32) {
        x = rand() % 71 + 4;
        y = 4;
    }
    draw();
}

void Asteroid::crash(SHIP& P) {
    if (x < P.getX() + 5 && x + 2 > P.getX() && y < P.getY() + 4 && y + 2 > P.getY()) {
        // Con esto borramos la nave y el asteroide de la pantalla una vez hayan hecho colision.
        gotoxy(x, y);
            printf("   ");
        gotoxy(x, y + 1);
            printf("   ");
        gotoxy(x, y + 2);
            printf("   ");
        gotoxy(x, y + 3);
            printf("   ");

        // Actualiza las caracteristicas de la nave y la vuelve a renderizar.
        P.damage();
        P.erase();
        P.draw();
        P.paint_hearts();
        x = rand() % 71 + 4; // Aqui es vuelto a generar el asteroide que habia sido destruido.
        y = 4;
    }
}
