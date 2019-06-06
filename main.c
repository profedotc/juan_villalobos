//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "juegodelavida.c"

#define TAM_X 5
#define TAM_Y 5

void gol_init(bool[TAM_X][TAM_Y]);
void gol_print(bool[TAM_X][TAM_Y]);
void gol_step(bool[TAM_X][TAM_Y], bool[TAM_X][TAM_Y]);
int gol_count_neighbors(bool[TAM_X][TAM_Y], int, int);
bool gol_get_cell(bool[TAM_X][TAM_Y], int, int);

int main() {
	int i = 0;
	bool mundos[2][TAM_X][TAM_Y];
	unsigned int mundo = 0;

	gol_init(mundos[mundo]);
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(mundos[mundo]);
		gol_step(mundos[mundo], mundos[!mundo]);
		mundo = !mundo;
	} while (getchar() != 'q');
	return EXIT_SUCCESS;
}
