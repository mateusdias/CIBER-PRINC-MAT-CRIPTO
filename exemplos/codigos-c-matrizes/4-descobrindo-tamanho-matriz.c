/*
 * Autor: Prof. Mateus Dias
 *
 * Este exemplo mostra como descobrir o tamanho de uma matriz em linguagem C.
 *
 * Quando declaramos uma matriz estatica, como int matriz[3][4], o tamanho dela
 * ja fica definido no codigo.
 *
 * Podemos usar o operador sizeof para descobrir:
 * - o tamanho total da matriz em bytes;
 * - o tamanho de uma linha em bytes;
 * - o tamanho de um elemento em bytes.
 *
 * O sizeof nao responde diretamente "quantas linhas" ou "quantas colunas"
 * existem. Ele responde quanto espaco algo ocupa na memoria, medido em bytes.
 *
 * Por isso, fazemos algumas divisoes:
 * - tamanho total da matriz / tamanho de uma linha = quantidade de linhas;
 * - tamanho de uma linha / tamanho de um elemento = quantidade de colunas.
 *
 * Assim, usamos os tamanhos em bytes para descobrir a organizacao da matriz.
 */

// Inclui a biblioteca padrao de entrada e saida.
#include <stdio.h>

// Define a funcao principal do programa.
int main(void) {
    // Cria uma matriz estatica de inteiros com 3 linhas e 4 colunas.
    int matriz[3][4] = {
        // Define os valores da primeira linha.
        {1, 2, 3, 4},

        // Define os valores da segunda linha.
        {5, 6, 7, 8},

        // Define os valores da terceira linha.
        {9, 10, 11, 12}
    };

    // Calcula o tamanho total da matriz em bytes.
    int tamanho_total = sizeof(matriz);

    // Calcula o tamanho de uma linha da matriz em bytes.
    int tamanho_linha = sizeof(matriz[0]);

    // Calcula o tamanho de um elemento da matriz em bytes.
    int tamanho_elemento = sizeof(matriz[0][0]);

    // Calcula a quantidade de linhas da matriz.
    int quantidade_linhas = tamanho_total / tamanho_linha;

    // Calcula a quantidade de colunas da matriz.
    int quantidade_colunas = tamanho_linha / tamanho_elemento;

    // Mostra o tamanho total da matriz em bytes.
    printf("Tamanho total da matriz: %d bytes\n", tamanho_total);

    // Mostra o tamanho de uma linha da matriz em bytes.
    printf("Tamanho de uma linha: %d bytes\n", tamanho_linha);

    // Mostra o tamanho de um elemento da matriz em bytes.
    printf("Tamanho de um elemento: %d bytes\n", tamanho_elemento);

    // Mostra a quantidade de linhas da matriz.
    printf("Quantidade de linhas: %d\n", quantidade_linhas);

    // Mostra a quantidade de colunas da matriz.
    printf("Quantidade de colunas: %d\n", quantidade_colunas);

    // Encerra o programa indicando que tudo ocorreu corretamente.
    return 0;
}
