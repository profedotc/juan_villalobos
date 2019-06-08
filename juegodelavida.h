#ifndef _JUEGODELAVIDA_H_
#define _JUEGODELAVIDA_H_

#include <stdbool.h>

#define TAM_X 5
#define TAM_Y 5

struct jdlv {
	bool mundos[2][TAM_X][TAM_Y];
	unsigned int mundo;
};

void gol_init(struct jdlv *jdlv);
void gol_print(const struct jdlv *jdlv);
void gol_step(struct jdlv *jdlv);
int gol_count_neighbors(const struct jdlv *jdlv, int x, int y);
bool gol_get_cell(const struct jdlv *jdlv, int x, int y);

#endif