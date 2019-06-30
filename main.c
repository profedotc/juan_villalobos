//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

#define TAM_X 10
#define TAM_Y 20

int main () {
        int i = 0;
        struct gol gol;
        gol_alloc(&gol, TAM_X, TAM_Y);
        gol_init(&gol);
        do {
                printf("\033cIteration %d\n", i++);
                gol_print(&gol);
                gol_step(&gol);
        }   while (getchar() != 'q');
            gol_free(&gol);
        return EXIT_SUCCESS;
}