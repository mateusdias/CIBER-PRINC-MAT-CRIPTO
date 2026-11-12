/*
 * Cifra de Hill com uma matriz 2 x 2.
 *
 * Usamos A = 0, B = 1, ..., Z = 25 e blocos de duas letras.
 * Cada bloco e um vetor coluna. Para cifrar: C = K * P (mod 26).
 * Para decifrar: P = K_inversa * C (mod 26).
 *
 * Exemplo didatico: esta cifra historica nao protege dados reais.
 */

#include <stdio.h>
#include <string.h>

#define ALFABETO 26
#define TAMANHO_BLOCO 2
#define MAX_TEXTO 1000

/* O resto de um numero negativo em C pode ser negativo.
 * Esta funcao sempre devolve um valor entre 0 e 25. */
int modulo26(int numero) {
    return (numero % ALFABETO + ALFABETO) % ALFABETO;
}

/* O inverso modular de um numero e um inteiro x que satisfaz:
 *
 *     (numero * x) mod 26 = 1
 *
 * Ou seja, o produto precisa deixar resto 1 quando dividido por 26.
 * Esse x faz o papel da divisao na aritmetica modular: multiplicar pelo
 * numero e depois por seu inverso recupera o valor original modulo 26.
 * Nao estamos calculando a fracao 1/numero nem usando numeros decimais.
 *
 * Exemplo: o inverso de 9 modulo 26 e 3, pois:
 *     9 * 3 = 27 = 1 * 26 + 1  ->  resto 1.
 *
 * Nem todo numero tem inverso. Ele so existe quando o numero e 26 sao
 * coprimos, isto e, seu maximo divisor comum (MDC) e 1.
 * Por exemplo, 2 nao tem inverso modulo 26: todo produto 2*x e par,
 * e seu resto na divisao por 26 tambem e par, portanto nunca sera 1.
 *
 * Como o modulo e pequeno, testamos todos os candidatos de 0 a 25.
 * Isso basta porque qualquer inteiro tem o mesmo resto de um desses
 * candidatos, e candidatos com o mesmo resto produzem o mesmo resultado.
 * Retornamos o inverso encontrado ou -1 para indicar que ele nao existe.
 * Na cifra de Hill, esta funcao e usada para inverter o determinante. */
int inverso_modular(int numero) {
    /* Reduz o numero ao intervalo de 0 a 25, inclusive se for negativo.
     * Por exemplo, 35 equivale a 9 modulo 26 e tem o mesmo inverso. */
    numero = modulo26(numero);

    /* Comeca em 0 e testa um candidato por vez, ate 25.
     * x++ aumenta o candidato em uma unidade a cada repeticao. */
    for (int x = 0; x < ALFABETO; x++) {
        /* Calcula o resto do produto. Se for 1, encontramos o inverso.
         * Para numero = 9: x = 0 da resto 0; x = 1 da resto 9;
         * x = 2 da resto 18; x = 3 da resto 1. */
        if (modulo26(numero * x) == 1) {
            /* return entrega o candidato encontrado e encerra a funcao,
             * sem precisar testar os candidatos restantes. */
            return x;
        }
    }

    /* Se chegamos aqui, nenhum candidato funcionou.
     * -1 sinaliza a falha e nao se confunde com os restos de 0 a 25.
     * Quem chamou a funcao deve verificar esse retorno antes de usa-lo. */
    return -1;
}

/* Para K = [a b; c d], o determinante e a*d - b*c.
 * A inversa modular e det_inverso * [d -b; -c a] (mod 26).
 * Retorna 1 em caso de sucesso e 0 se a chave nao for invertivel.
 * Os valores da chave devem estar entre 0 e 25. */
int calcular_matriz_inversa(const int chave[2][2], int inversa[2][2]) {
    int a = chave[0][0];
    int b = chave[0][1];
    int c = chave[1][0];
    int d = chave[1][1];
    int determinante = a * d - b * c;
    int inverso = inverso_modular(determinante);

    if (inverso == -1) {
        return 0;
    }

    inversa[0][0] = modulo26(inverso * d);
    inversa[0][1] = modulo26(inverso * (-b));
    inversa[1][0] = modulo26(inverso * (-c));
    inversa[1][1] = modulo26(inverso * a);

    return 1;
}

/* Le uma linha de ate MAX_TEXTO caracteres e remove a quebra de linha.
 * O vetor recebido deve ter MAX_TEXTO + 2 posicoes: texto, '\n' e '\0'.
 * Retorna 0 se houver erro ou se a linha ultrapassar o limite. */
int ler_linha(char texto[MAX_TEXTO + 2]) {
    /* fgets le uma linha da entrada e a guarda como uma string em texto.
     * Seus tres argumentos sao:
     * - texto: vetor que recebera os caracteres lidos.
     * - MAX_TEXTO + 2: capacidade do vetor, incluindo o terminador '\0'.
     * - stdin: entrada padrao, normalmente o teclado.
     *
     * A leitura para ao encontrar uma quebra de linha ('\n'), ao atingir
     * o limite de MAX_TEXTO + 1 caracteres ou ao chegar ao fim da entrada.
     * Se o '\n' for lido, ele tambem fica no vetor; vamos remove-lo abaixo.
     * Em uma leitura bem-sucedida, fgets acrescenta '\0' ao final da string
     * e retorna o endereco do vetor texto.
     * Se ocorrer erro, ou se a entrada terminar antes de ler qualquer
     * caractere, retorna NULL. Nesse caso, nossa funcao retorna 0. */
    if (fgets(texto, MAX_TEXTO + 2, stdin) == NULL) {
        return 0;
    }

    size_t tamanho = strcspn(texto, "\n");
    if (tamanho > MAX_TEXTO) {
        return 0;
    }

    texto[tamanho] = '\0';
    return 1;
}

/* Copia apenas letras ASCII, convertendo minusculas em maiusculas.
 * Espacos, numeros e pontuacao ASCII sao descartados.
 * Rejeita caracteres fora de ASCII (por exemplo, letras com acentos em UTF-8).
 * Retorna a quantidade de letras ou -1 em caso de caractere nao aceito.
 * A saida deve ter pelo menos strlen(entrada) + 1 posicoes. */
int preparar_texto(const char entrada[], char saida[]) {
    int quantidade = 0;

    for (int i = 0; entrada[i] != '\0'; i++) {
        unsigned char letra = (unsigned char) entrada[i];

        if (letra > 127) {
            return -1;
        }

        if (letra >= 'a' && letra <= 'z') {
            letra = (unsigned char) (letra - 'a' + 'A');
        }

        if (letra >= 'A' && letra <= 'Z') {
            saida[quantidade] = (char) letra;
            quantidade++;
        }
    }

    saida[quantidade] = '\0';
    return quantidade;
}

/* Multiplica cada par de letras pela matriz, sempre modulo 26.
 * Entrada: somente A-Z, com quantidade par de letras.
 * Saida: vetor com pelo menos strlen(entrada) + 1 posicoes.
 * Tanto a cifra quanto a decifra usam esta mesma operacao matematica. */
void transformar_blocos(const char entrada[], const int matriz[2][2], char saida[]) {
    int i;

    for (i = 0; entrada[i] != '\0'; i += TAMANHO_BLOCO) {
        int primeira = entrada[i] - 'A';
        int segunda = entrada[i + 1] - 'A';

        int resultado1 = modulo26(matriz[0][0] * primeira + matriz[0][1] * segunda);
        int resultado2 = modulo26(matriz[1][0] * primeira + matriz[1][1] * segunda);

        saida[i] = (char) ('A' + resultado1);
        saida[i + 1] = (char) ('A' + resultado2);
    }

    saida[i] = '\0';
}

/* Cifra um texto ja preparado e com tamanho par, usando a chave original. */
void cifrar(const char texto[], const int chave[2][2], char cifrado[]) {
    transformar_blocos(texto, chave, cifrado);
}

/* Decifra um texto ja preparado e com tamanho par, usando a chave inversa. */
void decifrar(const char cifrado[], const int inversa[2][2], char texto[]) {
    transformar_blocos(cifrado, inversa, texto);
}

int main(void) {
    /* Como calcular o determinante de uma matriz 2 x 2:
     *
     * Para uma matriz [a b; c d], usamos det = a*d - b*c.
     * Ou seja: produto da diagonal principal menos o produto da secundaria.
     *
     * Na chave abaixo: a = 3, b = 3, c = 2 e d = 5.
     * Diagonal principal: 3 * 5 = 15.
     * Diagonal secundaria: 3 * 2 = 6.
     * Determinante: 15 - 6 = 9.
     *
     * O inverso de 9 modulo 26 e 3, pois (9 * 3) % 26 = 1.
     * Sua matriz inversa e [15 17; 20 9]. */
    const int chave[2][2] = {
        {3, 3},
        {2, 5}
    };
    int inversa[2][2];

    /* Duas posicoes extras permitem guardar um X de preenchimento e '\0'. */
    char entrada[MAX_TEXTO + 2];
    char texto[MAX_TEXTO + 2];
    char resultado[MAX_TEXTO + 2];
    char opcao[MAX_TEXTO + 2];

    if (calcular_matriz_inversa(chave, inversa) == 0) {
        printf("Erro: a chave nao possui inversa modulo 26.\n");
        return 1;
    }

    printf("Cifra de Hill (matriz 2 x 2)\n");
    printf("Chave: [3 3; 2 5]\n");
    printf("1 - Cifrar\n2 - Decifrar\nEscolha: ");

    if (!ler_linha(opcao) || (strcmp(opcao, "1") != 0 && strcmp(opcao, "2") != 0)) {
        printf("Erro: escolha 1 ou 2.\n");
        return 1;
    }

    printf("Digite o texto (ate %d caracteres, sem acentos): ", MAX_TEXTO);
    if (!ler_linha(entrada)) {
        printf("Erro: leitura invalida ou texto acima do limite.\n");
        return 1;
    }

    int tamanho = preparar_texto(entrada, texto);
    if (tamanho <= 0) {
        printf("Erro: use pelo menos uma letra de A a Z e nao use acentos.\n");
        return 1;
    }

    if (strcmp(opcao, "1") == 0) {
        /* Um bloco incompleto precisa de mais uma letra para ser multiplicado. */
        if (tamanho % TAMANHO_BLOCO != 0) {
            texto[tamanho] = 'X';
            texto[tamanho + 1] = '\0';
            printf("Foi acrescentado um X para completar o ultimo bloco.\n");
        }

        cifrar(texto, chave, resultado);
        printf("Texto preparado: %s\nTexto cifrado: %s\n", texto, resultado);
    } else {
        if (tamanho % TAMANHO_BLOCO != 0) {
            printf("Erro: o texto cifrado precisa ter uma quantidade par de letras.\n");
            return 1;
        }

        decifrar(texto, inversa, resultado);
        printf("Texto decifrado: %s\n", resultado);
        printf("Um eventual X de preenchimento permanece no resultado.\n");
    }

    return 0;
}
