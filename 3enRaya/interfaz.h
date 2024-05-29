#ifndef __INTERFAZ_H__
#define __INTERFAZ_H__

#include "general.h"

#ifdef __cplusplus
extern "C" {
#endif

    void splash();
    void titulo();
    
    void pedir_nombre(enum EJugador jugador, char *pos_nombre);

    void pintar_mesa(int fichas[JUGADORES][FICHAS][DIMENS]);

    void donde_mover (enum EJugador turno, int *pfila, int *pcol);


#ifdef __cplusplus	
}
#endif

#endif
