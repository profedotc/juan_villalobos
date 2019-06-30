#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

enum world_type {
        ACTUAL,
        SIGUIENTE,
};

static bool get_cell(const struct gol *gol, int x, int y);
static int count_neighbors(const struct gol *gol, int x, int y);

void gol_alloc(struct gol *gol, int x, int y)
{
    gol->mundos[ACTUAL] = (bool **)malloc(x * sizeof(bool*));
    gol->mundos[SIGUIENTE] = (bool **)malloc(x * sizeof(bool*));
    for (int k = 0; k < x; k++) {
        gol->mundos[ACTUAL][k] = (bool *)malloc(y * sizeof(bool));
        gol->mundos[SIGUIENTE][k] = (bool *)malloc(y * sizeof(bool));
    }
    gol->x = x;
    gol->y = y;
}

void gol_free(struct gol *gol)
{
    for (int k = 0; k < gol->x; k++) {
        free(gol->mundos[SIGUIENTE][k]);
        free(gol->mundos[ACTUAL][k]); 
    }
    free(gol->mundos[SIGUIENTE]);
    free(gol->mundos[ACTUAL]);
}

void gol_init(struct gol *gol)
{
    for (int x = 0; x < gol->x; x++) {
        for (int y = 0; y < gol->y; y++) { 
            gol->mundos[ACTUAL][x][y] = 0;
        }
    }

            gol->mundos[ACTUAL][0][1] = 1;
            gol->mundos[ACTUAL][1][2] = 1;
            gol->mundos[ACTUAL][2][0] = 1;
            gol->mundos[ACTUAL][2][1] = 1;
            gol->mundos[ACTUAL][2][2] = 1;
}

void gol_print(struct gol *gol)
{
    for (int x = 0; x < gol->x; x++) {
        for (int y = 0; y < gol->y; y++) {
            printf("%c ", gol->mundos[ACTUAL][x][y]? '#' : '.');
        }
        printf("\n");
    }
}

void gol_step(struct gol *gol)
{
    for (int x = 0; x < gol->x; x++) {
        for (int y = 0; y < gol->y; y++) {
            int an = count_neighbors(gol, x, y);
            if (gol->mundos[ACTUAL][x][y]) {
                    gol->mundos[SIGUIENTE][x][y] = (an == 2) || (an == 3);
            }   else {      
                    gol->mundos[SIGUIENTE][x][y] = (an == 3);
                }
        }      
    }
    bool **swap = gol->mundos[ACTUAL];
    gol->mundos[ACTUAL] = gol->mundos[SIGUIENTE];
    gol->mundos[SIGUIENTE] = swap;
}

static int count_neighbors(const struct gol *gol, int x, int y)
{
    int anc = 0;
    
    anc += get_cell(gol, x - 1, y + 1);
    anc += get_cell(gol, x, y + 1);
    anc += get_cell(gol, x + 1, y + 1);
    
    anc += get_cell(gol, x - 1, y);
    anc += get_cell(gol, x + 1, y);
    
    anc += get_cell(gol, x - 1, y - 1);
    anc += get_cell(gol, x, y - 1);
    anc += get_cell(gol, x + 1, y - 1);
    
    return anc;         
}

static bool get_cell(const struct gol *gol, int x, int y)
{
     if(x >= gol->x)
        x = 0;
    else if (x < 0)
        x = gol->x - 1;
    if(y >= gol->y)
        y = 0;
    else if (y <0)
        y = gol->y - 1;
    return gol->mundos[ACTUAL][x][y];
}