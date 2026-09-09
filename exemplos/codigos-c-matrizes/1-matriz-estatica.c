/*
 * Autor: Prof. Mateus Dias
 *
 * Este exemplo mostra como criar uma matriz estatica em linguagem C.
 *
 * Em C, podemos representar uma matriz como uma tabela:
 * ela possui linhas e colunas, como as matrizes estudadas em matematica.
 *
 * Na pratica, o C guarda essa tabela usando dois indices:
 * um indice para indicar a linha e outro indice para indicar a coluna.
 *
 * A declaracao int matriz[2][2] cria uma matriz com:
 * - 2 linhas
 * - 2 colunas
 * - valores do tipo inteiro
 *
 * Diferente da notacao matematica usada em sala, os indices em C comecam em zero.
 *
 * Portanto, em uma matriz 2x2, as posicoes sao:
 * matriz[0][0] -> linha 0, coluna 0
 * matriz[0][1] -> linha 0, coluna 1
 * matriz[1][0] -> linha 1, coluna 0
 * matriz[1][1] -> linha 1, coluna 1
 *
 * A forma geral de acessar um elemento e:
 * matriz[linha][coluna]
 *
 * Neste programa, os valores da matriz ja estao definidos no proprio codigo.
 * Por isso, chamamos este exemplo de matriz com dados fixos.
 */

// Inclui a biblioteca padrao de entrada e saida.
#include <stdio.h>

// Define a funcao principal do programa.
int main(void) {
    // Cria uma matriz estatica de inteiros com 2 linhas e 2 colunas.
    int matriz[2][2] = {
        // Define os valores da primeira linha da matriz.
        {1, 2},

        // Define os valores da segunda linha da matriz.
        {3, 4}
    };

    // Mostra um titulo antes de imprimir a matriz.
    printf("Matriz 2x2:\n");

    // Imprime os elementos da primeira linha.
    printf("%d %d\n", matriz[0][0], matriz[0][1]);

    // Imprime os elementos da segunda linha.
    printf("%d %d\n", matriz[1][0], matriz[1][1]);

    // Encerra o programa indicando que tudo ocorreu corretamente.
    return 0;
}
