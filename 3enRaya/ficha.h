#ifndef __FICHA_H__
#define __FICHA_H__

#include "general.h"

#ifdef __cplusplus
extern "C" {
#endif

	bool esta_en_casa(int ficha[DIMENS]);
	int (*elegir_mv(int fichas[JUGADORES][FICHAS][DIMENS], enum EJugador turno))[DIMENS];

    bool mov_valido (
        const int fichas[JUGADORES][FICHAS][DIMENS], 
        int fila,
        int col);


#ifdef __cplusplus	
}
#endif

#endif