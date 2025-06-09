#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
  // Nível Novato - Posicionamento dos Navios
  // inicialização do tabuleiro
    int tabuleiro[10][10];// matriz do tabuleiro

    for(int i = 0; i <= 9; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // criação dos navios.
    int navioHorizontal [3] = {3, 3, 3};
    int navioVertical [3] = {3, 3, 3};
    int navioDiagonal1 [3] = {3, 3, 3};
    int navioDiagonal2 [3] = {3, 3, 3};

    // Posições iniciais
    int posiHorizontalL = 2;// largura inicial
    int posiHorizontalC = 3;// comprimento inicial

    int posiVerticalL = 3;// largura inicial
    int posiVerticalC = 8;// comprimento inicial

    //posições iniciais dos navios na diagonal
     int posiDiagonalL1 = 6;
     int posiDiagonalC1 = 6;

     if(posiDiagonalL1 + 2 < 10 && posiDiagonalC1 < 10){// verifica se há espaço suficiente para colocar 333
        for(int i = 0; i < 3; i++){
            tabuleiro[posiDiagonalL1 + i][posiDiagonalC1 + i] = navioDiagonal1[i]; // coluna aumenta e liha aumenta
        }
     }

     // segundo navio da diagonal
    int posiDiagonalL2 = 4;
    int posiDiagonalC2 = 4;

     if(posiDiagonalL2 + 2 < 10 && posiDiagonalC2 < 10){ 
        for(int i = 0; i < 3; i++){
            tabuleiro[posiDiagonalL2 + i][posiDiagonalC2 - i] = navioDiagonal2[i]; // linha aumenta e coluna diminui
        }
     }

    // posiciona o navio horizontal na tabela (se couber)
    if (posiHorizontalC + 2 < 10 && posiHorizontalL < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[posiHorizontalL][posiHorizontalC + i] = navioHorizontal[i];
        }
    }

    // posiciona o navio vertical na tabela (se couber)
    if (posiVerticalL + 2 < 10 && posiVerticalC < 10) { // explique essa condição
        for (int i = 0; i < 3; i++) {
            tabuleiro[posiVerticalL + i][posiVerticalC] = navioVertical[i];
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
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0