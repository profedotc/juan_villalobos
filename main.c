//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 20

void gol_init(bool mundo[TAM_X][TAM_Y]);
void gol_print(bool mundo[TAM_X][TAM_Y]);
void gol_step(bool mundoa[TAM_X][TAM_Y], bool mundob[TAM_X][TAM_Y]);
int gol_count_neighbors(bool mundo[TAM_X][TAM_Y], int x, int y);
bool gol_get_cell(bool mundo[TAM_X][TAM_Y], int x, int y);
void gol_copy(bool dst[TAM_X][TAM_Y], bool src[TAM_X][TAM_Y]);

int main()
{
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

void gol_init(bool mundo[TAM_X][TAM_Y])
{
	for (int i = 0; i < TAM_X; i++)
		for (int j = 0; j < TAM_Y; j++)
			mundo[i][j] = false;

	// Glider
	mundo[0][1] = true;
	mundo[1][2] = true;
	mundo[2][0] = true;
	mundo[2][1] = true;
	mundo[2][2] = true;
}

void gol_print(bool mundo[TAM_X][TAM_Y])
{
	for (int i = 0; i < TAM_X; i++) {
		for (int j = 0; j < TAM_Y; j++) {
			printf("%s", mundo[i][j] ? " #" : " .");
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(bool mundoa[TAM_X][TAM_Y], bool mundob[TAM_X][TAM_Y])
{
	for (int i = 0; i < TAM_X; i++) {
		for (int j = 0; j < TAM_Y; j++) {
			int n = gol_count_neighbors(mundoa, i, j);
			mundob[i][j] = (mundoa[i][j] && n == 2) || n == 3;
		}
	}
}

int gol_count_neighbors(bool mundo[TAM_X][TAM_Y], int x, int y)
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

bool gol_get_cell(bool mundo[TAM_X][TAM_Y], int x, int y)
{
	// Fix coords
	if (x >= TAM_X)
		x = 0;
	else if (x < 0)
		x = TAM_X - 1;

	if (y >= TAM_Y)
		y = 0;
	else if (y < 0)
		y = TAM_Y - 1;

	return mundo[x][y];

}