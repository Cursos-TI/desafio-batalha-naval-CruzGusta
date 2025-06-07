#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
  // Nível Novato - Posicionamento dos Navios
  // inicialização do tabuleiro
    int tabuleiro[10][10];

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

    // Posições iniciais
    int posiHorizontalL = 2;
    int posiHorizontalC = 3;

    int posiVerticalL = 7;
    int posiVerticalC = 6;

    // Coloca o navio horizontal (se couber)
    if (posiHorizontalC + 2 < 10 && posiHorizontalL < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[posiHorizontalL][posiHorizontalC + i] = navioHorizontal[i];
        }
    }

    // Coloca o navio vertical (se couber)
    if (posiVerticalL + 2 < 10 && posiVerticalC < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[posiVerticalL + i][posiVerticalC] = navioVertical[i];
        }
    }

    // Exibe o tabuleiro
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            printf(" %d", tabuleiro[i][j]);
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