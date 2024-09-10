#include "utility.h"
#include "utility.h"
#include <Windows.h>
#include <stdio.h>

// Con esta funcion manejamos el movimiento a traves de la consola utilizando las variables de "x" y "y".
void gotoxy(int x, int y) {
    HANDLE hShip;
    hShip = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPosition;
    dwPosition.X = x;
    dwPosition.Y = y;
    SetConsoleCursorPosition(hShip, dwPosition);
}

// Con esta funcion escondemos el curso para que se vea bonita la pantalla.
void hideCursor() {
    HANDLE hShip;
    hShip = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = false;
    SetConsoleCursorInfo(hShip, &cci);
}

// Con esta funcion utilizamos dos for con los cuales recorremos los margenes de la pantalla donde previamente fijamos los limites y lo va marcando con caracteres.
void paintLimits() {
    for (int i = 1; i < 78; i++) {
        gotoxy(i, 2);
            printf("%c", 196);
        gotoxy(i, 33);
            printf("%c", 196);
    }
    for (int i = 3; i < 33; i++) {
        gotoxy(1, i);
            printf("%c", 179);
        gotoxy(77, i);
            printf("%c", 179);
    }
    gotoxy(1, 2);
        printf("%c", 218);
    gotoxy(1, 33);
        printf("%c", 192);
    gotoxy(77, 2);
        printf("%c", 191);
    gotoxy(77, 33);
        printf("%c", 217);
}

// Con esta funcion añadi un lindo contador cuando inicias el programa.
void countdown() {
    gotoxy(35, 15);
        printf("3");
    Sleep(1000); // Wait for 1 second

    gotoxy(35, 15);
        printf("2");
    Sleep(1000); // Wait for 1 second

    gotoxy(35, 15);
        printf("1");
    Sleep(1000); // Wait for 1 second

    gotoxy(35, 15);
        printf("Go!");
    Sleep(1000); // Wait for 1 second

    gotoxy(35, 15);
        printf("   "); // Clear the countdown message
}
