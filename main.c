//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>

#include "juegodelavida.h"

int main() {
	struct jdlv juegodelavida;
	int i = 0;
	gol_init(&juegodelavida);
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(&juegodelavida);
		gol_step(&juegodelavida);
	} while (getchar() != 'q');
	return EXIT_SUCCESS;
}