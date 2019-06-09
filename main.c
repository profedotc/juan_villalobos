//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "juegodelavida.h"

#define TAM_X 5
#define TAM_Y 5

int main() {
	struct jdlv *jdlv;
	int i = 0;

	gol_init(&jdlv);
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(&jdlv);
		gol_step(&jdlv);
	} while (getchar() != 'q');

return EXIT_SUCCESS;
}
