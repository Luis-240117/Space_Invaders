#include <list>
#include <conio.h>
#include<Windows.h>
#include "SHIP.h"
#include "Asteroid.h"
#include "BULLET.h"
#include "utility.h"

int main() {
    hideCursor();
    paintLimits();
    countdown();

    // Construtor, nos crea una nave en las coordenadas 37, 29, con 4 de vida y 3 vidas.
    SHIP P(37, 29, 4, 3);
    P.draw();
    P.paint_hearts();

    // Aqui generamos una lista y un puntero a la lista en donde instanciamos varios asteroides para luego darles coordenadas al azar dentro de los rangos de nuestra pantalla.
    std::list<Asteroid*> A;
    for (int i = 0; i < 8; i++) {
        A.push_back(new Asteroid(rand() % 75 + 3, rand() % 5 + 4));
    }

    // Esta es una lista de objetos instanciados, en este casos son balas.
    std::list<BULLET*> B;

    // Este bool nos marca el gameloop inicial.
    bool game_over = false;
    // Aqui inicializamos la variable de puntos en cero.
    int points = 0;
    while (!game_over) {
        gotoxy(60, 1);
            printf("Points: %d", points);

        // Con esta funcion podemos leer las tacles que oprime el usuario, si el usuario oprime el space una nueva bala es generada y añadida a la lista de balas.
        if (_kbhit()) {
            char key = _getch();
            if (key == ' ') {
                B.push_back(new BULLET(P.getX() + 2, P.getY() - 1));  // Disparar.
            }
            else {
                P.move(key);  // Mover.
            }
        }

        /*A traves de este for podemos manejar el movimiento y borrado de las balas. 
        Inicialiamos la bala en el principio de la lista, despues mandamos llamara la funcion de movieminto de la bala lo cual actualiza la posicion de la bala. 
        El if con el out nos revisa si la bala ha salido de los limites de la pantalla.
        Si la bala ha salido de la pantalla se activa la siguiente parte del for la cual elimina la bala.
        Una vez eliminadad la bala el iterador procede a hacer el mimso analisis con la siguiente bala.*/
        for (auto iterB = B.begin(); iterB != B.end();) {
            (*iterB)->move();
            if ((*iterB)->out()) {
                gotoxy((*iterB)->X(), (*iterB)->Y());
                    printf(" ");
                delete* iterB;
                iterB = B.erase(iterB);
            }
            else {
                ++iterB;
            }
        }

        /*Aqui igualmente inicializamos la bala en el primer lugar de la lista , este bucle no terminara hasta que se llegue al final de la lista.
        El iterador manda a llamar la funcion de movimiento de los asteroides para actualizar la posicion de los asteroides.
        Por ultimo se manda a llamar a la funcion de crash la cual nos permite determinar si la nave y el asteroide han colisionado.*/
        for (auto itrA = A.begin(); itrA != A.end(); ++itrA) {
            (*itrA)->move();
            (*itrA)->crash(P);
        }

        // Handle asteroid-bullet collisions
        /*Aqui se pone demonicaco, el bucle mas externo itera a traves de la lista de los asteroides, el bucle interno revisa si la bala interseca
        con la posicion actual de uno de los asteroides.
        Si una colision es detectada la bala y el asteroide son removidos de la pantalla, el contador de los puntos es actualizado y un nuevo
        asteroide es generado.*/
        for (auto itrA = A.begin(); itrA != A.end();) {
            bool asteroid_destroyed = false;
            for (auto iterB = B.begin(); iterB != B.end();) {
                if ((*iterB)->X() >= (*itrA)->X() && (*iterB)->X() <= (*itrA)->X() + 2 &&
                    ((*iterB)->Y() == (*itrA)->Y() || (*iterB)->Y() == (*itrA)->Y() + 1)) {
                    gotoxy((*iterB)->X(), (*iterB)->Y());
                        printf(" ");
                    delete* iterB;
                    iterB = B.erase(iterB);

                    // Borramos el asteroide y actualizamos la lista.
                    gotoxy((*itrA)->X(), (*itrA)->Y());
                        printf("   ");
                    delete* itrA;
                    itrA = A.erase(itrA);
                    asteroid_destroyed = true;
                    points += 1;
                    break;  // Cerramos el bucle de las balas.
                }
                else {
                    ++iterB;
                }
            }

            if (!asteroid_destroyed) {
                ++itrA;
            }
            else {
                A.push_back(new Asteroid(rand() % 74 + 3, 4));  // Se agrega el nuevo asteroide.
            }
        }

        if (P.life() == 0) game_over = true;
        P.death();  // Aqui evaluamos la muerte de la nave.

        Sleep(30);  // Pause y volvemos.
    }
    // Mensaje final del juego.
    gotoxy(32, 15);
        printf("Game Over");
    gotoxy(26, 17);
        printf("Press any key to exit...");

    _getch();
    return 0;
}
