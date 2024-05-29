#include "terminal.h"

#include <stdio.h>

void guardar_cursor() {
    printf("\x1B[s"); // Guardar Cursor
}

void poner_cursor(int fila, int col) {
    printf("\x1B[%i;%iH", fila, col);   // Mover cursor
}

void restablecer_cursor(){
    printf("\x1B[u");
}