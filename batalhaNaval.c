#include <stdio.h>

    int main() {

        int agua [10][10] = {0}; // 0 representa água, 1 representa navio

        int navios = 3; // número de navios a serem colocados

        // Colocar os navios no tabuleiro
        agua [0][0] = 1; // navio 1
        agua [0][1] = 1; // navio 1
        agua [0][2] = 1; // navio 1
        agua [1][1] = 1; // navio 2
        agua [2][1] = 1; // navio 2
        agua [3][1] = 1; // navio 2
        agua [5][2] = 1; // navio 3
        agua [5][3] = 1; // navio 3
        agua [5][4] = 1; // navio 3
        

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf ("%d ", agua [i][j]);
            }
            printf ("\n");
        }



    }