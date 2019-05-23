//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 5
#define TAM_Y 5

void gol_init(bool[ *][ *]);

void gol_print(bool[ *][ *]);

void gol_step(bool[ *][ *], bool[ *][ *]);

int gol_count_neighbors(bool[ *][ *], int, int);

bool gol_get_cell(bool[ *][ *], int, int);

void gol_copy(bool[ *][ *], bool[ *][ *]);

int main() {
    int i = 0;
    // Declara dos mundos
    bool mundo_a[TAM_X][TAM_Y];
    bool mundo_b[TAM_X][TAM_Y];
    
    // inicializa el mundo
    for(int i = 0; i < TAM_X; i++){
        for(int j = 0; j < TAM_Y; j++){
            if((i==2&&j==1) ||
               (i==2 && j==2) || (i==2 && j==3)){
                mundo_a[i][j] = 1;
            }else{
                mundo_a[i][j] = 0;
            }
        }
    }
    
    // gol_init(mundo_a);
    gol_print(mundo_a);
    
    
    /*
     printf("%d\n", gol_get_cell(mundo_a, 2, 1));
     printf("%d\n", gol_get_cell(mundo_a, 2, 2));
     printf("%d\n", gol_get_cell(mundo_a, 2, 3));
     */
    
    /*
     do {
     printf("\033cIteration %d\n", i++);
     // TODO: Imprime el mundo
     // TODO: Itera
     for (i = 0; i < TAM_X; i++) {
     for (int j = 0; j < TAM_Y; j++) {
     printf("%c ", mundo_a[i][j] ? '#' : '.');
     }
     printf("\n");
     }
     } while (getchar() != 'q');
     */
    
    return EXIT_SUCCESS;
}

void gol_init(bool mundo_a[TAM_X][TAM_Y]) {
    // Poner el mundo a false
    for (int i = 0; i < TAM_X; i++) {
        for (int j = 0; j < TAM_Y; j++) {
            mundo_a[i][j] = 0;
        }
    }
    
    /* TODO: Inicializar con el patrón del glider:
     *           . # .
     *           . . #
     *           # # #
     */
}

void gol_print(bool mundo_a[TAM_X][TAM_Y]) {
    // Imprimir el mundo por consola. Sugerencia:
    for (int i = 0; i < TAM_X; i++) {
        for (int j = 0; j < TAM_Y; j++) {
            printf("%c ", mundo_a[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

void gol_step(bool mundo_a[TAM_X][TAM_Y], bool mundo_b[TAM_X][TAM_Y]) {
    /*
     * TODO:
     * - Recorrer el mundo célula por célula comprobando si nace, sobrevive
     *   o muere.
     *
     * - No se puede cambiar el estado del mundo a la vez que se recorre:
     *   Usar un mundo auxiliar para guardar el siguiente estado.
     *
     * - Copiar el mundo auxiliar sobre el mundo principal
     */
    
    //
    
    for(int i = 0; i < TAM_X; i++){
        for(int j = 0; j < TAM_Y; j++){
            int neighbours = gol_count_neighbors(mundo_a, i, j);
            
        }
    }
    
    if(){
        
    }
}

int gol_count_neighbors(bool mundo[TAM_X][TAM_Y], int x, int y) {
    // Devuelve el número de vecinos
    int i = 0;
    if (mundo[x - 1][y + 1] == 1) {
        i++;
    }
    if (mundo[x][y + 1] == 1) {
        i++;
    }
    if (mundo[x + 1][y + 1] == 1) {
        i++;
    }
    if (mundo[x - 1][y] == 1) {
        i++;
    }
    if (mundo[x + 1][y] == 1) {
        i++;
    }
    if (mundo[x - 1][y - 1] == 1) {
        i++;
    }
    if (mundo[x][y - 1] == 1) {
        i++;
    }
    if (mundo[x + 1][y - 1] == 1) {
        i++;
    }
    return i;
}

bool gol_get_cell(bool mundo[TAM_X][TAM_Y], int x, int y) {
    // Devuelve el estado de la célula de posición indicada
    if (x > TAM_X || y > TAM_Y) {
        printf("No se puede obtener el estado de la célula de la posición indicada.");
        return 0;
    } else {
        return mundo[x][y];
    }
}

void gol_copy(bool mundo_a[TAM_X][TAM_Y], bool mundo_b[TAM_X][TAM_Y]) {
    // Copia el mundo segundo mundo sobre el primero
    for (int i = 0; i < TAM_X; i++) {
        for (int j = 0; i < TAM_Y; j++) {
            mundo_a[i][j] = mundo_b[i][j];
        }
    }
}
