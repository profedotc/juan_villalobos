//
// Created by Juan Villalobos Quiros on 07/05/2019.
//


#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

int main()
{
	int iteration = 0;
	struct gol gol;
	gol_alloc(&gol, TAM_X, TAM_Y);
	gol_init(&gol, TAM_X, TAM_Y);
	do {
		printf("\033cIteration %d\n", it);
		gol_print(&gol, TAM_X, TAM_Y);

		gol_step(&gol, TAM_X, TAM_Y);
		++iteration;
	} while (getchar() != 'q');

	gol_free(&gol, TAM_Y);
	return EXIT_SUCCESS;
}
