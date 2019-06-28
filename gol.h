#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 20


struct gol {
	bool mundos[2][TAM_X][TAM_Y];
	unsigned int mundo;
};

void gol_init(struct gol *gol);
void gol_print(const struct gol *gol);
void gol_step(struct gol *gol);

#endif