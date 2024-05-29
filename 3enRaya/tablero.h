#ifndef __TABLERO_H__
#define __TABLERO_H__

#include "general.h"
#include "interfaz.h"
#include "ficha.h"

#define X0T 50
#define Y0T 10
#define SPCSV 3
#define SPCSH 5


#ifdef __cplusplus
extern "C" {
#endif


void tablero_debug  (int fichas[JUGADORES][FICHAS][DIMENS]);

void pintar_tablero(unsigned f0, unsigned c0, unsigned spcsv, unsigned spcsh);
void pintar_fichas(
		int fichas[JUGADORES][FICHAS][DIMENS],
		unsigned f0,
		unsigned c0,
		unsigned spcsv,
		unsigned spcsh
	);

#ifdef __cplusplus	
}
#endif

#endif