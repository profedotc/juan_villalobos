#include "gol.h"

#include <stdio.h>

static bool get_cell(const struct gol *gol, int x, int y);
static int count_neighbors(const struct gol *gol, int x, int y);

enum mundo {
  ACTUAL = 0,
  SIGUIENTE = 1,
};

void gol_init(struct gol *gol, const int x, const int y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      gol->mundos[0][i][j] = false;
    }
  }
  gol->mundos[ACTUAL][1][0] = true;
  gol->mundos[ACTUAL][1][1] = true;
  gol->mundos[ACTUAL][1][2] = true;
}

void gol_print(const struct gol *gol, const int x, const int y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      printf("%c", gOL->mundos[ACTUAL][i][j] ? '#' : '.');
    }
    printf("\n");
  }
}

void gol_step(struct gol *gol, const int x, const int y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      int alives_neighbors = count_neighbors(g, i, j, x, y);
      if (gol->mundos[ACTUAL][i][j] && (alives_neighbors < 2 || alives_neighbors > 3))
      {
        gol->mundos[SIGUIENTE][i][j] = 0;
      }
      else if (gol->mundos[ACTUAL][i][j] && (alives_neighbors == 2 || alives_neighbors == 3))
      {
        gol->mundos[SIGUIENTE][i][j] = 1;
      }
      else if (!(gol->mundos[ACTUAL][i][j]) && alives_neighbors == 3)
      {
        gol->mundos[SIGUIENTE][i][j] = 1;
      }
      else if (!(gol->mundos[ACTUAL][i][j]) && alives_neighbors != 3)
      {
        gol->mundos[SIGUIENTE][i][j] = 0;
      }
    }
  }
  bool **aux_array = gol->mundos[ACTUAL];
  gol->mundos[ACTUAL] = gol->mundos[SIGUIENTE];
  gol->mundos[SIGUIENTE] = aux_array;
}

static int count_neighbors(const struct gol *gol, const int i, const int j, const int f, const int c) {
  int count_neighbors = -get_cell(gol, i, j, f, c);
  for (int x = i - 1; x < i + 2; x++) {
    for (int y = j - 1; y < j + 2; y++) {
      if (get_cell(gol, x, y, f, c))
        count_neighbors++;
    }
  }
  return count_neighbors;
}

static bool get_cell(const struct gol *gol, int x, int y)
{
	if (x >= TAM_X)
		x = 0;
	else if (x < 0)
		x = TAM_X - 1;

	if (y >= TAM_Y)
		y = 0;
	else if (y < 0)
		y = TAM_Y - 1;

	return gol->mundos[ACTUAL][x][y];
}

void gol_alloc(struct gol *gol, const int x, const int y) {
  gol->mundos[ACTUAL] = (bool **) malloc(x * sizeof(bool *));
  gol->mundos[SIGUIENTE] = (bool **) malloc(x * sizeof(bool *));
  for (int i = 0; i < cols; i++)
  {
    gol->worlds[ACTUAL][i] = (bool *) malloc(y * sizeof(bool));
    gol->worlds[SIGUIENTE][i] = (bool *) malloc(y * sizeof(bool));
  }
}

void gol_free(struct gol *gol, const int y) {
  for (int i = 0; i < y; i++) {
    free(gol->worlds[SIGUIENTE][i]);
    free(gol->worlds[ACTUAL][i]);
  }
  free(gol->worlds[SIGUIENTE]);
  free(gol->worlds[ACTUAL]);
}
