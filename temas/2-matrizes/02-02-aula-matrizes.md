# Tema 2 — Aula de Matrizes

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Matrizes: conceito, propriedades, nomenclatura e operações

## 1. Matrizes

Uma **matriz** é um conjunto retangular de números, símbolos ou expressões, organizados em linhas e colunas.

Cada informação contida em uma matriz é chamada de **elemento**.

## 2. Notação de matriz

Uma matriz pode ser representada da seguinte forma:

```text
A = [ a_11   ...   a_1n ]
    [  ...   ...    ... ]
    [ a_m1   ...   a_mn ]
```

Também podemos escrever:

```text
A_(m x n) = (a_ij)
```

Lê-se: matriz `A` de dimensão `m x n`, significando que `A` possui `m` linhas e `n` colunas.

O elemento `a_ij` é um elemento de `A` que está localizado na linha `i` e na coluna `j` de `A`.

Por exemplo, em uma matriz `A_(2 x 3)`, temos 2 linhas e 3 colunas:

```text
A = [ a_11   a_12   a_13 ]
    [ a_21   a_22   a_23 ]
```

O primeiro índice indica a linha. O segundo índice indica a coluna.

```text
a_12 fica na linha 1, coluna 2.
a_21 fica na linha 2, coluna 1.
a_23 fica na linha 2, coluna 3.
```

## 3. Como construir uma matriz usando uma regra

Muitos exercícios definem uma matriz por meio de uma regra para `a_ij`.

Exemplo:

```text
A_(2 x 3), com a_ij = i + j
```

Antes de fazer contas mais complicadas, é recomendável montar a matriz com as posições:

```text
A = [ a_11   a_12   a_13 ]
    [ a_21   a_22   a_23 ]
```

Agora substituímos `i` e `j` em cada posição:

```text
a_11 = 1 + 1 = 2
a_12 = 1 + 2 = 3
a_13 = 1 + 3 = 4

a_21 = 2 + 1 = 3
a_22 = 2 + 2 = 4
a_23 = 2 + 3 = 5
```

Portanto:

```text
A = [ 2   3   4 ]
    [ 3   4   5 ]
```

Quando a regra possui condições, como `i > j`, `i < j` ou `i = j`, analisamos uma posição por vez.

Exemplo:

```text
B_(3 x 3), com:

b_ij = 1, se i = j
b_ij = 0, se i != j
```

Primeiro montamos as posições:

```text
B = [ b_11   b_12   b_13 ]
    [ b_21   b_22   b_23 ]
    [ b_31   b_32   b_33 ]
```

Depois avaliamos cada uma:

```text
b_11 = 1, pois 1 = 1
b_12 = 0, pois 1 != 2
b_13 = 0, pois 1 != 3

b_21 = 0, pois 2 != 1
b_22 = 1, pois 2 = 2
b_23 = 0, pois 2 != 3

b_31 = 0, pois 3 != 1
b_32 = 0, pois 3 != 2
b_33 = 1, pois 3 = 3
```

Logo:

```text
B = [ 1   0   0 ]
    [ 0   1   0 ]
    [ 0   0   1 ]
```

Essa matriz é chamada de **matriz identidade de ordem 3**, ou simplesmente `I_3`.

## 4. Igualdade de matrizes

Duas matrizes `A` e `B` são iguais se possuem a mesma dimensão e se os elementos que ocupam as mesmas posições são iguais.

Em notação:

```text
A_(m x n) = B_(m x n)  <=>  a_ij = b_ij
```

Exemplo:

```text
[ x + 1   2y ]   [ 5    8 ]
[ z       3  ] = [ -1   3 ]
```

Como as matrizes são iguais, comparamos posição por posição:

```text
x + 1 = 5
2y = 8
z = -1
3 = 3
```

Resolvendo:

```text
x = 4
y = 4
z = -1
```

## 5. Matriz transposta

Dada uma matriz `A_(m x n)`, a sua matriz transposta é a matriz:

```text
A^T_(n x m)
```

As linhas da matriz transposta são as colunas da matriz original.

Exemplo:

```text
A = [ 1   2   3 ]
    [ 4   5   6 ]
```

Então:

```text
A^T = [ 1   4 ]
      [ 2   5 ]
      [ 3   6 ]
```

Também podemos visualizar assim:

```text
A tem dimensão 2 x 3.
A^T tem dimensão 3 x 2.
```

O elemento que estava na linha 1, coluna 2 de `A` passa para a linha 2, coluna 1 de `A^T`.

## 6. Soma e subtração de matrizes

Para somar ou subtrair duas matrizes, elas precisam ter a **mesma dimensão**.

Se `A` e `B` são matrizes do tipo `m x n`, então:

```text
A + B = (a_ij + b_ij)
A - B = (a_ij - b_ij)
```

Ou seja, somamos ou subtraímos os elementos que ocupam a mesma posição.

Exemplo:

```text
A = [  5    2 ]
    [  0   -7 ]

B = [  3    6 ]
    [ -4    1 ]
```

Então:

```text
A + B = [  5 + 3      2 + 6  ]
        [  0 + (-4)  -7 + 1  ]

A + B = [  8    8 ]
        [ -4   -6 ]
```

E:

```text
A - B = [  5 - 3      2 - 6  ]
        [  0 - (-4)  -7 - 1  ]

A - B = [  2   -4 ]
        [  4   -8 ]
```

Se as dimensões forem diferentes, a soma ou subtração não é possível.

Exemplo:

```text
A_(2 x 3) + B_(3 x 2)
```

não é possível, pois as matrizes não possuem a mesma quantidade de linhas e colunas.

## 7. Multiplicação de matriz por número real

Para multiplicar uma matriz por um número real, multiplicamos **todos os elementos** da matriz por esse número.

Se:

```text
A = [  5    2 ]
    [  0   -7 ]
```

Então:

```text
3A = [ 3 * 5    3 * 2  ]
     [ 3 * 0    3 * -7 ]

3A = [ 15    6 ]
     [  0  -21 ]
```

## 8. Multiplicação de matrizes

A multiplicação de matrizes tem uma regra diferente da soma e da subtração.

Para calcular o produto:

```text
A_(m x n) * B_(n x p)
```

o número de **colunas de A** precisa ser igual ao número de **linhas de B**.

Quando a multiplicação é possível, o resultado tem dimensão:

```text
(m x p)
```

De forma resumida:

```text
A_(m x n) * B_(n x p) = C_(m x p)
```

Observe que os números do meio precisam ser iguais:

```text
A_(2 x 3) * B_(3 x 2)
        3 = 3
```

Logo, o produto é possível e o resultado será uma matriz `2 x 2`.

Já o produto:

```text
A_(3 x 2) * B_(3 x 2)
```

não é possível, pois o número de colunas da primeira matriz é `2`, mas o número de linhas da segunda matriz é `3`.

## 9. Como calcular cada elemento do produto

Para calcular cada elemento da matriz produto, usamos:

```text
linha da primeira matriz * coluna da segunda matriz
```

Mais precisamente, se:

```text
C = AB
```

então o elemento `c_ij` é obtido multiplicando os elementos da linha `i` de `A` pelos elementos da coluna `j` de `B` e somando os resultados.

Exemplo:

```text
A = [ 1   2   3 ]
    [ 4   5   6 ]

B = [  7    8 ]
    [  9   10 ]
    [ 11   12 ]
```

A matriz `A` é do tipo `2 x 3` e a matriz `B` é do tipo `3 x 2`.

Assim:

```text
AB é possível e terá dimensão 2 x 2.
```

Antes de calcular, desenhamos a matriz resultado:

```text
AB = [ c_11   c_12 ]
     [ c_21   c_22 ]
```

Cada posição de `AB` será preenchida por uma conta:

```text
c_11: linha 1 de A com coluna 1 de B
c_12: linha 1 de A com coluna 2 de B
c_21: linha 2 de A com coluna 1 de B
c_22: linha 2 de A com coluna 2 de B
```

Calculando:

```text
c_11 = 1*7 + 2*9 + 3*11 = 7 + 18 + 33 = 58
c_12 = 1*8 + 2*10 + 3*12 = 8 + 20 + 36 = 64

c_21 = 4*7 + 5*9 + 6*11 = 28 + 45 + 66 = 139
c_22 = 4*8 + 5*10 + 6*12 = 32 + 50 + 72 = 154
```

Portanto:

```text
AB = [  58    64 ]
     [ 139   154 ]
```

## 10. Atenção: a ordem importa

Em geral:

```text
AB != BA
```

Além disso, pode acontecer de `AB` ser possível e `BA` não ser possível.

Exemplo:

```text
A_(2 x 3) * B_(3 x 2)
```

é possível e gera uma matriz `2 x 2`.

Mas:

```text
B_(3 x 2) * A_(2 x 3)
```

também é possível, porém gera uma matriz `3 x 3`.

Ou seja, mesmo quando os dois produtos existem, eles podem ter dimensões diferentes e resultados diferentes.

## 11. Quadro-resumo das operações

```text
Operação        Condição para existir                  Dimensão do resultado

A + B           A e B têm a mesma dimensão              mesma dimensão de A e B
A - B           A e B têm a mesma dimensão              mesma dimensão de A e B
kA              k é número real                         mesma dimensão de A
A^T             sempre existe                           se A é m x n, A^T é n x m
AB              colunas de A = linhas de B              linhas de A x colunas de B
```

## 12. Por que matrizes aparecem em criptografia?

Matrizes são úteis em criptografia porque permitem transformar blocos de números de forma organizada.

Uma mensagem pode ser convertida em números, agrupada em vetores ou matrizes, e depois transformada por operações matriciais.

Por exemplo, em uma cifra matricial simples, poderíamos representar um bloco da mensagem como um vetor coluna:

```text
P = [ p_1 ]
    [ p_2 ]
```

e aplicar uma matriz-chave `K`:

```text
C = K P
```

Nesse caso, `P` representa o bloco original e `C` representa o bloco cifrado.

A regra de multiplicação de matrizes é importante aqui porque a matriz-chave precisa ter dimensão compatível com os blocos da mensagem.

## 13. Exercício 1

Calcule o produto dos elementos da 2ª linha da matriz `A_(4 x 3)` dada por:

```text
a_ij = i, se i > j
a_ij = j, se i <= j
```

### Resolução organizada

Como a matriz é do tipo `4 x 3`, temos 4 linhas e 3 colunas.

Antes de calcular o produto pedido, vamos montar a matriz inteira.

Como são 4 linhas e 3 colunas, as posições são:

```text
A = [ a_11   a_12   a_13 ]
    [ a_21   a_22   a_23 ]
    [ a_31   a_32   a_33 ]
    [ a_41   a_42   a_43 ]
```

A regra é:

```text
se i > j, usamos a_ij = i
se i <= j, usamos a_ij = j
```

Agora calculamos linha por linha.

Na 1ª linha, `i = 1`:

```text
a_11 = 1, pois 1 <= 1, então a_11 = j = 1
a_12 = 2, pois 1 <= 2, então a_12 = j = 2
a_13 = 3, pois 1 <= 3, então a_13 = j = 3
```

Na 2ª linha, `i = 2`:

```text
a_21 = 2, pois 2 > 1, então a_21 = i = 2
a_22 = 2, pois 2 <= 2, então a_22 = j = 2
a_23 = 3, pois 2 <= 3, então a_23 = j = 3
```

Na 3ª linha, `i = 3`:

```text
a_31 = 3, pois 3 > 1, então a_31 = i = 3
a_32 = 3, pois 3 > 2, então a_32 = i = 3
a_33 = 3, pois 3 <= 3, então a_33 = j = 3
```

Na 4ª linha, `i = 4`:

```text
a_41 = 4, pois 4 > 1, então a_41 = i = 4
a_42 = 4, pois 4 > 2, então a_42 = i = 4
a_43 = 4, pois 4 > 3, então a_43 = i = 4
```

Assim, a matriz é:

```text
A = [ 1   2   3 ]
    [ 2   2   3 ]
    [ 3   3   3 ]
    [ 4   4   4 ]
```

A 2ª linha é:

```text
[ 2   2   3 ]
```

Produto dos elementos:

```text
2 * 2 * 3 = 12
```

Resposta:

```text
12
```

## 14. Exercício 2

Calcule o produto dos elementos da 2ª coluna da matriz `A_(3 x 5)` dada por:

```text
a_ij = i + j, se i > j
a_ij = -2j, se i <= j
```

### Resolução organizada

Como a matriz é do tipo `3 x 5`, temos 3 linhas e 5 colunas.

As posições da matriz são:

```text
A = [ a_11   a_12   a_13   a_14   a_15 ]
    [ a_21   a_22   a_23   a_24   a_25 ]
    [ a_31   a_32   a_33   a_34   a_35 ]
```

A regra é:

```text
se i > j, usamos a_ij = i + j
se i <= j, usamos a_ij = -2j
```

Como o exercício pede o produto dos elementos da 2ª coluna, precisamos apenas dos elementos em que `j = 2`:

```text
a_12
a_22
a_32
```

Calculando cada elemento da 2ª coluna:

```text
a_12 = -2 * 2 = -4, pois 1 <= 2
a_22 = -2 * 2 = -4, pois 2 <= 2
a_32 = 3 + 2 = 5, pois 3 > 2
```

A 2ª coluna é:

```text
[ -4 ]
[ -4 ]
[  5 ]
```

Produto dos elementos:

```text
(-4) * (-4) * 5 = 80
```

Resposta:

```text
80
```

Se quisermos montar a matriz inteira para visualizar melhor, ficamos com:

```text
A = [ -2   -4   -6   -8  -10 ]
    [  3   -4   -6   -8  -10 ]
    [  4    5   -6   -8  -10 ]
```

Observe que, mesmo quando o exercício pede apenas uma linha ou coluna, montar a matriz inteira pode ajudar a evitar confusão com os índices.

## 15. Exercício 3

Dada a matriz `A_(2 x 2)` tal que:

```text
a_ij = i + j^2 - 1
```

calcule o valor da expressão:

```text
a_11 * a_22 - a_12 * a_21
```

### Resolução organizada

Antes de calcular a expressão, vamos montar a matriz `A`.

Como `A` é do tipo `2 x 2`, ela possui 2 linhas e 2 colunas:

```text
A = [ a_11   a_12 ]
    [ a_21   a_22 ]
```

Agora usamos a regra:

```text
a_ij = i + j^2 - 1
```

Calculando cada posição:

```text
a_11 = 1 + 1^2 - 1 = 1
a_12 = 1 + 2^2 - 1 = 4
a_21 = 2 + 1^2 - 1 = 2
a_22 = 2 + 2^2 - 1 = 5
```

Substituindo os valores nas posições correspondentes:

```text
A = [ a_11   a_12 ]   [ 1   4 ]
    [ a_21   a_22 ] = [ 2   5 ]
```

Agora podemos calcular a expressão:

```text
a_11 * a_22 - a_12 * a_21 = 1 * 5 - 4 * 2
```

Logo:

```text
5 - 8 = -3
```

Resposta:

```text
-3
```

Esse cálculo é o mesmo padrão que aparece no determinante de uma matriz `2 x 2`:

```text
det(A) = a_11 * a_22 - a_12 * a_21
```

Esse assunto será importante mais adiante, especialmente quando estudarmos matrizes inversas.

## 16. Exercício 4

Determine os valores de `a`, `b`, `c`, `d` e `e` para que a igualdade seja válida:

```text
[ 3a       b + 1 ]   [  6    5 ]
[ a - b+c  c + d ] = [  0   -1 ]
[ 0        b - e ]   [  0   -4 ]
```

### Resolução organizada

Como as matrizes são iguais, os elementos que ocupam as mesmas posições também devem ser iguais.

Vamos identificar as posições:

```text
[ linha 1, coluna 1    linha 1, coluna 2 ]
[ linha 2, coluna 1    linha 2, coluna 2 ]
[ linha 3, coluna 1    linha 3, coluna 2 ]
```

Assim:

```text
3a        está na posição (1,1), assim como 6
b + 1     está na posição (1,2), assim como 5
a - b + c está na posição (2,1), assim como 0
c + d     está na posição (2,2), assim como -1
0         está na posição (3,1), assim como 0
b - e     está na posição (3,2), assim como -4
```

Comparando posição por posição:

```text
3a = 6
b + 1 = 5
a - b + c = 0
c + d = -1
0 = 0
b - e = -4
```

Resolvendo:

```text
a = 2
b = 4
2 - 4 + c = 0  =>  c = 2
2 + d = -1     =>  d = -3
4 - e = -4     =>  e = 8
```

Resposta:

```text
a = 2, b = 4, c = 2, d = -3, e = 8
```

## 17. Exercício 5

Dadas as matrizes:

```text
A = [  1    2 ]
    [ -1    0 ]
    [  3   -2 ]

C = [  1    1 ]
    [ -1    4 ]
```

calcule `AC`, se possível.

### Resolução organizada

A matriz `A` é do tipo `3 x 2`.

A matriz `C` é do tipo `2 x 2`.

Como o número de colunas de `A` é igual ao número de linhas de `C`, o produto `AC` é possível:

```text
A_(3 x 2) * C_(2 x 2) = AC_(3 x 2)
```

Como o resultado será do tipo `3 x 2`, primeiro podemos desenhar a matriz produto:

```text
AC = [ c_11   c_12 ]
     [ c_21   c_22 ]
     [ c_31   c_32 ]
```

Cada elemento será calculado usando uma linha de `A` e uma coluna de `C`.

```text
c_11: linha 1 de A com coluna 1 de C
c_12: linha 1 de A com coluna 2 de C

c_21: linha 2 de A com coluna 1 de C
c_22: linha 2 de A com coluna 2 de C

c_31: linha 3 de A com coluna 1 de C
c_32: linha 3 de A com coluna 2 de C
```

Calculando:

```text
c_11 = 1*1 + 2*(-1) = 1 - 2 = -1
c_12 = 1*1 + 2*4 = 1 + 8 = 9

c_21 = -1*1 + 0*(-1) = -1 + 0 = -1
c_22 = -1*1 + 0*4 = -1 + 0 = -1

c_31 = 3*1 + (-2)*(-1) = 3 + 2 = 5
c_32 = 3*1 + (-2)*4 = 3 - 8 = -5
```

Logo:

```text
AC = [ -1    9 ]
     [ -1   -1 ]
     [  5   -5 ]
```

## 18. Roteiro para resolver exercícios de matrizes

Ao resolver um exercício de matrizes, siga este roteiro:

```text
1. Identifique a dimensão da matriz.
2. Desenhe a matriz com as posições a_ij.
3. Substitua i e j em cada posição.
4. Se houver condições, verifique uma posição por vez.
5. Monte a matriz numérica.
6. Só depois faça a operação pedida.
```

Esse roteiro é especialmente útil quando o exercício usa fórmulas como:

```text
a_ij = i + j
a_ij = i + j^2 - 1
a_ij = 0, se i != j
a_ij = i, se i > j
```

## 19. Final da aula: brincadeira de cifragem com matriz

Agora vamos fazer uma brincadeira prática: cifrar uma frase sem espaços usando uma matriz.

A ideia é transformar letras em números:

```text
A = 0
B = 1
C = 2
D = 3
...
Z = 25
```

Vamos cifrar a frase:

```text
EUAMOBR
```

Como a matriz-chave que vamos usar é `2 x 2`, vamos trabalhar com blocos de 2 letras.

```text
EUAMOBR -> EU AM OB R
```

O último bloco ficou com apenas uma letra. Para completar, colocamos `X` no final:

```text
EUAMOBR -> EU AM OB RX
```

Vamos usar a seguinte matriz-chave:

```text
K = [ 3   2 ]
    [ 1   1 ]
```

Para cifrar, calculamos:

```text
C = K P
```

em que `P` é o bloco original e `C` é o bloco cifrado.

Antes de calcular, conferimos as dimensões:

```text
K é 2 x 2
P é 2 x 1
```

Logo:

```text
K_(2 x 2) * P_(2 x 1) = C_(2 x 1)
```

O produto é possível, e o resultado será um vetor coluna com 2 linhas.

### Primeiro bloco: EU

Convertendo as letras:

```text
E = 4
U = 20
```

Agora representamos esse bloco como um vetor coluna:

```text
P = [  4 ]
    [ 20 ]
```

Calculando:

```text
C = [ 3   2 ] [  4 ]
    [ 1   1 ] [ 20 ]

C = [ 3*4 + 2*20 ]
    [ 1*4 + 1*20 ]

C = [ 12 + 40 ]
    [  4 + 20 ]

C = [ 52 ]
    [ 24 ]
```

Como estamos trabalhando com letras de `0` a `25`, reduzimos os resultados usando o resto da divisão por `26`.

```text
52 dividido por 26 deixa resto 0.
24 dividido por 26 deixa resto 24.
```

Então:

```text
C = [  0 ]
    [ 24 ]
```

Voltando para letras:

```text
0  = A
24 = Y
```

Portanto:

```text
EU vira AY
```

### Cifrando a frase inteira

Agora repetimos o processo para todos os blocos:

```text
EU AM OB RX
```

Tabela de conversão:

```text
Bloco original    Números       Produto K*P              Resto por 26       Bloco cifrado

EU                [ 4, 20 ]     [ 52, 24 ]               [  0, 24 ]         AY
AM                [ 0, 12 ]     [ 24, 12 ]               [ 24, 12 ]         YM
OB                [14,  1 ]     [ 44, 15 ]               [ 18, 15 ]         SP
RX                [17, 23 ]     [ 97, 40 ]               [ 19, 14 ]         TO
```

Juntando tudo:

```text
EUAMOBR vira AYYMSPTO
```

### Estudante querido(a), teste!

Cifre a frase abaixo usando a mesma matriz-chave:

```text
MATEMATICA
```

Agrupe em blocos de 2 letras:

```text
MA TE MA TI CA
```

Lembrete:

```text
1. Transforme cada letra em número.
2. Monte cada bloco como vetor coluna.
3. Multiplique pela matriz-chave.
4. Calcule o resto da divisão por 26.
5. Transforme os números finais em letras.
```

### Observação importante

Para decifrar a mensagem, precisaríamos usar a matriz inversa da matriz-chave.

Esse é um dos motivos pelos quais matrizes inversas são importantes em criptografia: elas permitem desfazer a transformação feita durante a cifragem.

## 20. Para praticar

Os exercícios de prática estão organizados no arquivo:

```text
02-03-lista-1-matrizes.md
```
