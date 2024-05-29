#include "tablero.h"
#include "terminal.h"

#include <stdio.h>
#include <stdlib.h>






void
pintar_cols(unsigned spcsh, const char *blank_char, const char *intersecc) {
    for (int cell=0; cell<3; cell++){
        for (int col=0; col<spcsh; col++)
            printf("%s", blank_char);

        if (cell != 2)
            printf ("%s", intersecc); 
    }

    printf("\n");
}


void
pintar_tablero (unsigned f0, unsigned c0, unsigned spcsv, unsigned spcsh){
    
    printf ("\x1B[96m");

    for (int fila=0; fila<3; fila++){
        
        // Pintar el hueco
        for (int j=0; j<spcsv; j++) {
            poner_cursor(f0 + (spcsv + 1) * fila + j, c0);
            pintar_cols(spcsh, " ", "│");
        }

        // Pintar la línea de separación
        if (fila != 2) {
            poner_cursor(f0 + (spcsv + 1) * fila + spcsv, c0);
            pintar_cols(spcsh, "─", "┼");
        }
    }


    printf ("\x1B[0m\n");
}


void
pintar_fichas(
                int fichas[JUGADORES][FICHAS][DIMENS],
                unsigned f0,
                unsigned c0,
                unsigned spcsv,
                unsigned spcsh
            ) {
    

    // Pintar fichas
    const char *TFICHA[] = { 
        "\x1B[36mO\x1B[0m", 
        "\x1B[39mX\x1B[0m"
    };

    for (int jug=j0; jug<JUGADORES; jug++)
        for (int ficha=0; ficha<NFICHAS; ficha++)
            if (!esta_en_casa(fichas[j][i])){
                poner_cursor(
                    f0 + spcsv / 2 + (spcsv + 1) * (fichas[jug][ficha][FILA] - 1), 
                    c0 + spcsh / 2 + (spcsh + 1) * (fichas[jug][ficha][COL]  - 1) );
                printf("%s", TFICHA[jug]);
            }
    
}



void
tablero_debug(int fichas[JUGADORES][FICHAS][DIMENS]){
    printf ("TABLERO\n");
    printf ("=======\n\n\n");

    for (int j=0; j<JUGADORES; j++){
        printf("Jugador %i\n", j + 1);
        for (int i=0; i<FICHAS; i++)
            if (!esta_en_casa(fichas[j][i]))
                printf("F%i: [%i, %i]\n", i+1, fichas[j][i][FILA], fichas[j][i][COL]);

        printf("\n");
    }
}