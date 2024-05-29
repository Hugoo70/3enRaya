#include "ficha.h"

#include <stddef.h>



/****************/
/*   PRIVATE    */
/****************/



int ( *primera_de_casa(int fichas[FICHAS][DIMENS]) )[DIMENS] {
	int (*elegida)[DIMENS] = NULL;

	for (int f=0; f<FICHAS; f++)
		if (esta_en_casa(fichas[f])) {
			elegida = &fichas[f];
			break;					// Es mejor hacer el return aquí
									// pero, por poneros un break una
									// vez en la vida.
		}

	return elegida;
}



int ( *cual_mover(int fichas[FICHAS][DIMENS]) ) [DIMENS] {
	int (*elegida)[DIMENS] = NULL;

	// Preguntar fila y columna

	// Si alguna de las fichas coincide con la fila y la columna elegidas...
	// es decir, es de este jugador...

	// retornar la que coincide.

	return elegida;
}


/**************/
/*   PUBLIC   */
/**************/

/**
 * elegir_mv
 * 
 * Elige una ficha de las que estan en casa o, si no, de las del tablero.
 **/
int (*elegir_mv(int fichas[JUGADORES][FICHAS][DIMENS], enum EJugador turno)) [DIMENS] {
	 int (*elegida)[DIMENS] = NULL;

     if ( ! (elegida = primera_de_casa(fichas[turno])) )
   	     elegida = cual_mover(fichas[turno]);


	 return elegida;
}

bool esta_en_casa(int ficha[DIMENS]) {
	return ficha[FILA] == 0 || ficha[COL] == 0;
}


bool
is_inbound (int dato) {
    return dato>0 && dato<4;
}

bool
esta_vacia(
        const int fichas[JUGADORES][FICHAS][DIMENS], 
        int fila,
        int col
    )
{
    for (int j=j0; j<JUGADORES; j++)
        for (int f=0; f<NFICHAS; f++)
            if (fichas[j][f][FILA] == fila && 
            	fichas[j][f][COL]  == col)
                return false;

    return true;
}
// Comprobar que la fila y la col:
// - están dentro de límites.
// - la posición no está ocupada.
bool
mov_valido (
        const int fichas[JUGADORES][FICHAS][DIMENS], 
        int fila,
        int col) {

    if (is_inbound (fila) && is_inbound (col))
        if ( esta_vacia(fichas, fila, col ) )
            return true;

    return false;
}