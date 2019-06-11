#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 20

struct gol {
	bool **mundos[2];
};

void gol_init(struct gol *gol, const int x, const int y);
void gol_print(const struct gol *g, const int x, const int y);
void gol_step(struct gol *gol, const int x, const int y);
void gol_alloc(struct gol *gol, const int x, const int y);
void gol_free(struct gol *gol, const int y);

#endif
