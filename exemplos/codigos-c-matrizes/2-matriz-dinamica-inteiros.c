/*
 * Autor: Prof. Mateus Dias
 *
 * Este exemplo mostra como preencher uma matriz em linguagem C.
 *
 * A matriz criada neste programa possui 2 linhas e 2 colunas.
 *
 * Diferente do primeiro exemplo, os valores nao estao fixos no codigo.
 * O usuario digita cada valor pelo teclado, e o programa guarda esses
 * valores nas posicoes da matriz.
 *
 * A forma geral de acesso continua sendo:
 * matriz[linha][coluna]
 */

// Inclui a biblioteca padrao de entrada e saida.
#include <stdio.h>

// Define a funcao principal do programa.
int main(void) {
    // Cria uma matriz estatica de inteiros com 2 linhas e 2 colunas.
    int matriz[2][2];

    // Mostra uma mensagem inicial para o usuario.
    printf("Digite os valores da matriz 2x2:\n");

    // A leitura dos dados tambem poderia ser feita usando iteracao.
    // Para deixar este primeiro exemplo mais simples, vamos ler os valores um a um.

    // Solicita e armazena o valor da linha 0, coluna 0.
    printf("Valor para a posicao [0][0]: ");
    scanf("%d", &matriz[0][0]);

    // Solicita e armazena o valor da linha 0, coluna 1.
    printf("Valor para a posicao [0][1]: ");
    scanf("%d", &matriz[0][1]);

    // Solicita e armazena o valor da linha 1, coluna 0.
    printf("Valor para a posicao [1][0]: ");
    scanf("%d", &matriz[1][0]);

    // Solicita e armazena o valor da linha 1, coluna 1.
    printf("Valor para a posicao [1][1]: ");
    scanf("%d", &matriz[1][1]);

    // Mostra um titulo antes de imprimir a matriz.
    printf("\nMatriz digitada:\n");

    // Imprime os elementos da primeira linha.
    printf("%d %d\n", matriz[0][0], matriz[0][1]);

    // Imprime os elementos da segunda linha.
    printf("%d %d\n", matriz[1][0], matriz[1][1]);

    // Encerra o programa indicando que tudo ocorreu corretamente.
    return 0;
}
