//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "juegodelavida.h"

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