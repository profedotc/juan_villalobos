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
        struct gol g;
        gol_alloc(&g, TAM_X, TAM_Y);
        gol_init(&g);
        do 
        {
                printf("\033cIteration %d\n", i++);
                gol_print(&g);
                gol_step(&g);
        }   while (getchar() != 'q');
            gol_free(&g);
            return EXIT_SUCCESS;
}
