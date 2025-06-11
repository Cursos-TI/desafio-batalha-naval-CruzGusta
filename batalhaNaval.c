#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    // Nível Novato - Posicionamento dos Navios
    // inicialização do tabuleiro
    int tabuleiro[10][10]; // matriz do tabuleiro

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // criação do navio na horizontal :
    int navioHorizontal[3] = {3, 3, 3}; // navio da horizontal

    int posiHorizontalL = 2; // largura inicial
    int posiHorizontalC = 3; // comprimento inicial

    // posiciona o navio horizontal na tabela (se couber)
    if (posiHorizontalC + 2 < 10 && posiHorizontalL < 10) { // se for o inicio + 2 pro lado menor que 10.
        for (int i = 0; i < 3; i++) {
            tabuleiro[posiHorizontalL][posiHorizontalC + i] = navioHorizontal[i];
        }
    }

    // criação do navio na vertical :
    int navioVertical[3] = {3, 3, 3}; // navio da vertical

    int posiVerticalL = 3; // largura inicial
    int posiVerticalC = 8; // comprimento inicial

    // posiciona o navio vertical na tabela (se couber)
    if (posiVerticalL + 2 < 10 && posiVerticalC < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[posiVerticalL + i][posiVerticalC] = navioVertical[i];
        }
    }

    // criação do navio 1 na diagonal
    int navioDiagonal1[3] = {3, 3, 3}; // primeiro navio na diagonal

    int posiDiagonalL1 = 6;
    int posiDiagonalC1 = 6;

    if (posiDiagonalL1 + 2 < 10 && posiDiagonalC1 < 10) { // verifica se há espaço suficiente para colocar 333
        for (int i = 0; i < 3; i++) {
            tabuleiro[posiDiagonalL1 + i][posiDiagonalC1 + i] = navioDiagonal1[i]; // coluna aumenta e linha aumenta
        }
    }

    // segundo navio na diagonal
    int navioDiagonal2[3] = {3, 3, 3};

    int posiDiagonalL2 = 4;
    int posiDiagonalC2 = 4;

    if (posiDiagonalL2 + 2 < 10 && posiDiagonalC2 < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[posiDiagonalL2 + i][posiDiagonalC2 - i] = navioDiagonal2[i]; // linha aumenta e coluna diminui
        }
    }

    // adicionando recursos do nivel mestre :
    // ataque cone
    int ataqueCONE[3][5];
    int origemLinhaCone = 2;
    int origemColunaCone = 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) { // se a coluna for maior que 2 casa pra esquerda ou direita
                ataqueCONE[i][j] = 1;
            } else {
                ataqueCONE[i][j] = 0;
            }
        }
    }
    // adicionando cone no tabuleiro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaCone = origemLinhaCone + i - 2;
            int colunaCone = origemColunaCone + j - 2;

            if (linhaCone >= 0 && linhaCone < 10 && colunaCone >= 0 && colunaCone < 10) {
                if (ataqueCONE[i][j] == 1) {
                    if (tabuleiro[linhaCone][colunaCone] == 3) {
                        tabuleiro[linhaCone][colunaCone] = 1; // caso sobreponha o navio ele printa 1 no lugar de 3
                    } else {
                        tabuleiro[linhaCone][colunaCone] = 5;
                    }
                }
            }
        }
    }
    // colocando a cruz :
    int ataqueCRUZ[3][5];
    int origemLinhaCruz = 2;
    int origemColunaCruz = 6;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 1 || j == 2) {
                ataqueCRUZ[i][j] = 1;
            } else {
                ataqueCRUZ[i][j] = 0;
            }
        }
    }
    // adição do ataque de cruz no tabuleiro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaCruz = origemLinhaCruz + i - 1;
            int colunaCruz = origemColunaCruz + j - 1;

            if (linhaCruz >= 0 && linhaCruz < 10 && colunaCruz >= 0 && colunaCruz < 10) {
                if (ataqueCRUZ[i][j] == 1) {
                    if (tabuleiro[linhaCruz][colunaCruz] == 3) { // corrigido == para comparação
                        tabuleiro[linhaCruz][colunaCruz] = 1;   // corrigido = para atribuição
                    } else {
                        tabuleiro[linhaCruz][colunaCruz] = 5;
                    }
                }
            }
        }
    }
    // adição do ataque em octaedro
    int ataqueOCTAEDRO[3][5];
    int origemLinhaOCTA = 7;
    int origemColunaOCTA = 4;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 0 && j == 2) ||
                (i == 1 && (j == 1 || j == 2 || j == 3)) ||
                (i == 2 && j == 2)) {
                ataqueOCTAEDRO[i][j] = 1;
            } else {
                ataqueOCTAEDRO[i][j] = 0;
            }
        }
    }
    // exibição do ataque octaedro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaOCTAEDRO = origemLinhaOCTA + i - 1;
            int colunaOCTAEDRO = origemColunaOCTA + j - 2;

            if (linhaOCTAEDRO >= 0 && linhaOCTAEDRO < 10 && colunaOCTAEDRO >= 0 && colunaOCTAEDRO < 10) {
                if (ataqueOCTAEDRO[i][j] == 1) {
                    if (tabuleiro[linhaOCTAEDRO][colunaOCTAEDRO] == 3) { // corrigido == para comparação
                        tabuleiro[linhaOCTAEDRO][colunaOCTAEDRO] = 1;  // corrigido = para atribuição
                    } else {
                        tabuleiro[linhaOCTAEDRO][colunaOCTAEDRO] = 5;
                    }
                }
            }
        }
    }
    // Exibe o tabuleiro
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}