#include <stdio.h>

int main() {

    int tabuleiro[10][10] = {0};
    int visivel[10][10] = {0};

    // NAVIOS
    tabuleiro[0][0] = 1;
    tabuleiro[0][1] = 1;
    tabuleiro[0][2] = 1;

    tabuleiro[1][1] = 1;
    tabuleiro[2][1] = 1;
    tabuleiro[3][1] = 1;

    tabuleiro[5][2] = 1;
    tabuleiro[5][3] = 1;
    tabuleiro[5][4] = 1;

    tabuleiro[6][7] = 1;
    tabuleiro[7][8] = 1;
    tabuleiro[8][9] = 1;

    int cruz[5][5] = {0};
    int cone[5][5] = {0};
    int octaedro[5][5] = {0};

    int centro = 2;

    // CRUZ
    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            if(i == centro || j == centro) {

                cruz[i][j] = 1;

            }
        }
    }

    // CONE
    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            if(i <= centro &&
               j >= centro - i &&
               j <= centro + i) {

                cone[i][j] = 1;

            }
        }
    }

    // OCTAEDRO
    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            int distancia =
            (i > centro ? i - centro : centro - i) +
            (j > centro ? j - centro : centro - j);

            if(distancia <= 1) {

                octaedro[i][j] = 1;

            }
        }
    }

    int habilidade;
    int linha;
    int coluna;

    printf("ESCOLHA UMA HABILIDADE:\n");
    printf("1 - Cruz\n");
    printf("2 - Cone\n");
    printf("3 - Octaedro\n");
    scanf("%d", &habilidade);

    printf("Digite a linha: ");
    scanf("%d", &linha);

    printf("Digite a coluna: ");
    scanf("%d", &coluna);

    // CRUZ
    if(habilidade == 1) {

        for(int i = 0; i < 5; i++) {

            for(int j = 0; j < 5; j++) {

                int linhaReal = linha + (i - centro);
                int colunaReal = coluna + (j - centro);

                if(linhaReal >= 0 && linhaReal < 10 &&
                   colunaReal >= 0 && colunaReal < 10) {

                    if(cruz[i][j] == 1) {

                        if(tabuleiro[linhaReal][colunaReal] == 1) {

                            visivel[linhaReal][colunaReal] = 1;

                            printf("Navio encontrado em [%d][%d]!\n",
                                   linhaReal,
                                   colunaReal);

                        }

                        else {

                            visivel[linhaReal][colunaReal] = 3;

                        }
                    }
                }
            }
        }
    }

    // CONE
    else if(habilidade == 2) {

        for(int i = 0; i < 5; i++) {

            for(int j = 0; j < 5; j++) {

                int linhaReal = linha + (i - centro);
                int colunaReal = coluna + (j - centro);

                if(linhaReal >= 0 && linhaReal < 10 &&
                   colunaReal >= 0 && colunaReal < 10) {

                    if(cone[i][j] == 1) {

                        if(tabuleiro[linhaReal][colunaReal] == 1) {

                            visivel[linhaReal][colunaReal] = 1;

                            printf("Navio encontrado em [%d][%d]!\n",
                                   linhaReal,
                                   colunaReal);

                        }

                        else {

                            visivel[linhaReal][colunaReal] = 3;

                        }
                    }
                }
            }
        }
    }

    // OCTAEDRO
    else if(habilidade == 3) {

        for(int i = 0; i < 5; i++) {

            for(int j = 0; j < 5; j++) {

                int linhaReal = linha + (i - centro);
                int colunaReal = coluna + (j - centro);

                if(linhaReal >= 0 && linhaReal < 10 &&
                   colunaReal >= 0 && colunaReal < 10) {

                    if(octaedro[i][j] == 1) {

                        if(tabuleiro[linhaReal][colunaReal] == 1) {

                            visivel[linhaReal][colunaReal] = 1;

                            printf("Navio encontrado em [%d][%d]!\n",
                                   linhaReal,
                                   colunaReal);

                        }

                        else {

                            visivel[linhaReal][colunaReal] = 3;

                        }
                    }
                }
            }
        }
    }

    else {

        printf("Habilidade invalida!\n");
        return 0;

    }

    printf("\nTABULEIRO FINAL:\n\n");

    for(int i = 0; i < 10; i++) {

        for(int j = 0; j < 10; j++) {

            printf("%d ", visivel[i][j]);

        }

        printf("\n");
    }

    return 0;
}