#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//#include "doctest.h"

#include "general.h"
#include "interfaz.h"
#include "ficha.h"

#define MAX_STR 8



#ifndef NDBG
#define DEBUG(x...)                     \
    fprintf(stderr, "\x1B[33m");        \
    fprintf(stderr, "DEBUG: " x);       \
    fprintf(stderr, "\x1B[0m");         \
    fprintf(stderr, "\n\n");
#else
#define DEBUG(x...)
#endif

bool
no_haya_ganado(enum EJugador victoria) {
    // victoria marca si ha ganado el jugador j0 o j1
    // Mientras no haya ganado ninguno vale JUGADORES.
    return victoria == JUGADORES;
}


enum EJugador
alternar(enum EJugador turno) {
    return (enum EJugador) (( (int) turno + 1 ) % 2);
}

void
gestor_partida() {
    enum EJugador turno,                    // Num jugador que le toca
                  victoria;                 // Num jugador que ha ganado

    // 6 fichas que pueden estar en casa o en el tablero.
    int fichas[JUGADORES][FICHAS][DIMENS];
    char nombre[JUGADORES][MAX_STR];


    /* Inicialización */
    turno = j0;
    victoria = JUGADORES;
    bzero(fichas, sizeof(fichas));    // Mover fichas a casa

    for (int j=j0; j<JUGADORES; j++)
        pedir_nombre((enum EJugador) j, &nombre[j][0]);

    do { // GAME LOOP
        // Elegir qué ficha hay que mover.
        int (*ficha_mover)[DIMENS] = elegir_mv(fichas, turno);
    
        DEBUG("Fichas  [%p]", fichas);
        DEBUG("Elegida [%p]", ficha_mover);
        bool valido;
        do {
            int fila, col;

            donde_mover (turno, &fila, &col);
            valido = mov_valido (fichas, fila, col);

            if (valido){
                (*ficha_mover)[FILA] = fila;
                (*ficha_mover)[COL]  = col ;
            } else {
                printf ("Movimiento inválido.\n");
            }

        }while (!valido);
        
        
        pintar_mesa(fichas);
        turno = alternar(turno);
    } while ( no_haya_ganado (victoria)); // Ganado?


}


int
main (int argc, char *argv[]) {

    enum EJugador jugador;

    splash();
    gestor_partida ();

    return EXIT_SUCCESS;
}

