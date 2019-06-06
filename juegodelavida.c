#include "juegodelavida.h"
#include <stdio.h>

void gol_init(struct jdlv *jdlv) {
	jdlv->mundo = 0;
	for (int i = 0; i < TAM_X; i++){
		for (int j = 0; j < TAM_Y; j++){
			jdlv->mundos[jdlv->mundo][i][j] = false;
		}
	}
	jdlv->mundos[jdlv->mundo][0][1] = true;
	jdlv->mundos[jdlv->mundo][1][2] = true;
	jdlv->mundos[jdlv->mundo][2][0] = true;
	jdlv->mundos[jdlv->mundo][2][1] = true;
	jdlv->mundos[jdlv->mundo][2][2] = true;      
}

void gol_print(const struct jdlv *jdlv) {
	for (int i = 0; i < TAM_X; i++) {
		for (int j = 0; j < TAM_Y; j++) {
			printf("%s", jdlv->mundos[jdlv->mundo][i][j] ? " #" : " .");
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(struct jdlv *jdlv) {
	for (int i = 0; i < TAM_X; i++) {
		for (int j = 0; j < TAM_Y; j++) {
			int n = gol_count_neighbors(mundoa, i, j);
			jdlv->mundos[!jdlv->mundo][i][j] =
				(jdlv->mundos[jdlv->mundo][i][j] && n == 2) || n == 3;
		}
	}
	jdlv->mundo = !jdlv->mundo;
}

int gol_count_neighbors(const struct jdlv *jdlv, int x, int y) {
	int count = 0;
	count += gol_get_cell(jdlv, x - 1, y + 1);
	count += gol_get_cell(jdlv, x - 0, y + 1);
	count += gol_get_cell(jdlv, x + 1, y + 1);
	count += gol_get_cell(jdlv, x - 1, y + 0);
	count += gol_get_cell(jdlv, x + 1, y + 0);
	count += gol_get_cell(jdlv, x - 1, y - 1);
	count += gol_get_cell(jdlv, x - 0, y - 1);
	count += gol_get_cell(jdlv, x + 1, y - 1);
	return count;
}

bool gol_get_cell(const struct jdlv *jdlv, int x, int y) {
	if (x >= GOL_SIZE_X) {
        x = 0;
    } else if (x < 0) {
            x = GOL_SIZE_X - 1;
    } 
    if (y >= GOL_SIZE_Y) {
            y = 0;
    } else if (y < 0) {
            y = GOL_SIZE_Y - 1;
    }
	return jdlv->mundos[jdlv->mundo][x][y];
}