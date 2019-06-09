//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMX 10
#define TAMY 20

void gol_init(bool mundo[TAMX][TAMY]);
void gol_print(bool mundo[TAMX][TAMY]);
void gol_step(bool mundoa[TAMX][TAMY], bool mundob[TAMX][TAMY]);
int gol_count_neighbors(bool mundo[TAMX][TAMY], int x, int y);
bool gol_get_cell(bool mundo[TAMX][TAMY], int x, int y);
void gol_copy(bool dst[TAMX][TAMY], bool src[TAMX][TAMY]);

int main()
{
	int i = 0;
	bool mundos[2][TAMX][TAMY];
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

void gol_init(bool mundo[TAMX][TAMY])
{
	for (int i = 0; i < TAMX; i++)
		for (int j = 0; j < TAMY; j++)
			mundo[i][j] = false;

	// Glider
	mundo[0][1] = true;
	mundo[1][2] = true;
	mundo[2][0] = true;
	mundo[2][1] = true;
	mundo[2][2] = true;
}

void gol_print(bool mundo[TAMX][TAMY])
{
	for (int i = 0; i < TAMX; i++) {
		for (int j = 0; j < TAMY; j++) {
			printf("%s", mundo[i][j] ? " #" : " .");
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(bool mundoa[TAMX][TAMY], bool mundob[TAMX][TAMY])
{
	for (int i = 0; i < TAMX; i++) {
		for (int j = 0; j < TAMY; j++) {
			int n = gol_count_neighbors(mundoa, i, j);
			mundob[i][j] = (mundoa[i][j] && n == 2) || n == 3;
		}
	}
}

int gol_count_neighbors(bool mundo[TAMX][TAMY], int x, int y)
{
	int count = 0;

	count += gol_get_cell(mundo, x - 1, y + 1);
	count += gol_get_cell(mundo, x - 0, y + 1);
	count += gol_get_cell(mundo, x + 1, y + 1);
	count += gol_get_cell(mundo, x - 1, y + 0);
	count += gol_get_cell(mundo, x + 1, y + 0);
	count += gol_get_cell(mundo, x - 1, y - 1);
	count += gol_get_cell(mundo, x - 0, y - 1);
	count += gol_get_cell(mundo, x + 1, y - 1);

	return count;
}

bool gol_get_cell(bool mundo[TAMX][TAMY], int x, int y)
{
	// Fix coords
	if (x >= TAMX)
		x = 0;
	else if (x < 0)
		x = TAMX - 1;

	if (y >= TAMY)
		y = 0;
	else if (y < 0)
		y = TAMY - 1;

	return mundo[x][y];
}