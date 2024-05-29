#include "interfaz.h"
#include "caratula.h"
#include "tablero.h"
#include "terminal.h"

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <unistd.h>



/*************************/
/*    ENTRADA DE DATOS   */
/*************************/

void
pedir_nombre(
        enum EJugador jugador,
        char *pos_nombre        // Posición de memoria donde hay que escribir.
        ) {

    printf ("Nombre del Jugador %i: ", (int) jugador + 1);
    scanf (" %s", pos_nombre);
}



// El inconveniente de devolver pasando por referencia es que 
// no se pueden encadenar llamadas
// Encadenar llamadas mejora la legibilidad, pero complica
// la depuración.
// A los que encadenan llamadas por costumbre se les llama one-liners.
void
donde_mover(enum EJugador turno, int *fila, int *col) {
    printf ("Mueve Jugador %i.\n", turno + 1);
    printf ("=================\n\n");

    __fpurge(stdin);
    printf ("Fila: ");
    scanf (" %i", fila);

    printf ("Columna: ");
    scanf (" %i", col);
}






//struct TCoordenada
//donde_mover(enum EJugador turno)






/************************/
/*    SALIDA DE DATOS   */
/************************/


// ------------------
// One Call Functions
// ------------------

void
splash () {
    system ("clear");
    printf (
            "\x1B[93m"  /* Cambiar el color de la pluma a amarillo. */
            "\x1B[7B"
            SPLASH
            "\x1B[0m"
            "\n\n\n"
            );

    usleep (1000000);
}

void
titulo () {
    system ("clear");
    system ("toilet -f pagga '3 en Raya'");
    printf ("\n\n\n");
}




// -------------------
// Game Loop Functions
// -------------------

void pintar_casa(int fichas[JUGADORES][FICHAS][DIMENS]){

    printf ("CASA\n");
    printf ("====\n\n\n");
    
    printf ("\tJugador 1: ");
    for (int i=0; i<FICHAS; i++)
        if (esta_en_casa(fichas[j0][i]))
            printf (" %i", i+1);
    printf("\n");

    printf ("\tJugador 2: ");
    for (int i=0; i<FICHAS; i++)
        if (esta_en_casa(fichas[j1][i]))
            printf (" %i", i+1);
    printf("\n");

}




void pintar_mesa(int fichas[JUGADORES][FICHAS][DIMENS]) {
    
    system("clear");
    printf("\n\n");
    titulo();

    guardar_cursor();

    // pintar_casa(fichas);
    pintar_tablero(Y0T, X0T, SPCSV, SPCSH);
    pintar_fichas(fichas, Y0T, X0T, SPCSV, SPCSH);
    
    restablecer_cursor();
}
