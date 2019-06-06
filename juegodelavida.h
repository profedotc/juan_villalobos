
#ifndef _JUEGODELAVIDA_H_
#define _JUEGODELAVIDA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 5
#define TAM_Y 5

void gol_init(bool[TAM_X][TAM_Y]);
void gol_print(bool[TAM_X][TAM_Y]);
void gol_step(bool[TAM_X][TAM_Y], bool[TAM_X][TAM_Y]);
int gol_count_neighbors(bool[TAM_X][TAM_Y], int, int);
bool gol_get_cell(bool[TAM_X][TAM_Y], int, int);

#endif