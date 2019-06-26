#ifndef _gol_H_
#define _gol_H_

#include <stdbool.h>

struct gol
{
    bool **mundos[2];
    int x;
    int y;
};

void gol_alloc(struct gol *gol, int sx, int sy);
void gol_free(struct gol *gol);
void gol_init(struct gol *gol);
void gol_print(struct gol *gol);
void gol_step(struct gol *gol);

#endif
