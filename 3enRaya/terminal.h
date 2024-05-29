#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#ifdef __cplusplus
extern "C" {
#endif
	

	void guardar_cursor();
	void restablecer_cursor();
	void poner_cursor(int fila, int col);


#ifdef __cplusplus
}
#endif

#endif