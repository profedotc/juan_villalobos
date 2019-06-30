#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

#define IT 1000
#define TAM_X 10
#define TAM_Y 20
// MAIN
int main ()
{
    struct gol gol;
    gol_alloc(&gol, TAM_X, TAM_Y);
    gol_init(&gol);
    for (int i = 0; i < IT; i++) {
            gol_step(&gol);
    }
        gol_free(&gol);
        
        return EXIT_SUCCESS;
}