/*
 * Autor: Prof. Mateus Dias
 *
 * Este exemplo mostra como percorrer uma matriz em linguagem C.
 *
 * A matriz criada neste programa possui 5 linhas e 5 colunas.
 *
 * Para acessar todos os elementos da matriz, usamos dois lacos de repeticao:
 * - o primeiro laco percorre as linhas;
 * - o segundo laco percorre as colunas.
 *
 * Esse tipo de estrutura e chamado de laco aninhado, porque um laco fica dentro
 * do outro.
 *
 * A forma geral de acesso continua sendo:
 * matriz[linha][coluna]
 */

// Inclui a biblioteca padrao de entrada e saida.
#include <stdio.h>

// Define a funcao principal do programa.
int main(void) {
    // Cria uma matriz estatica de inteiros com 5 linhas e 5 colunas.
    int matriz[5][5] = {
        // Define os valores da primeira linha.
        {1, 2, 3, 4, 5},

        // Define os valores da segunda linha.
        {6, 7, 8, 9, 10},

        // Define os valores da terceira linha.
        {11, 12, 13, 14, 15},

        // Define os valores da quarta linha.
        {16, 17, 18, 19, 20},

        // Define os valores da quinta linha.
        {21, 22, 23, 24, 25}
    };

    // Mostra um titulo antes de imprimir a matriz.
    printf("Matriz 5x5:\n");

    // Percorre cada linha da matriz.
    for (int linha = 0; linha < 5; linha++) {
        // Percorre cada coluna da linha atual.
        for (int coluna = 0; coluna < 5; coluna++) {
            // Imprime o elemento que esta na linha e coluna atuais.
            printf("%2d ", matriz[linha][coluna]);
        }

        // Pula para a proxima linha depois de imprimir todas as colunas.
        printf("\n");
    }

    // Encerra o programa indicando que tudo ocorreu corretamente.
    return 0;
}
