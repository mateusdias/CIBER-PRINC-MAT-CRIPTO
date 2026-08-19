# Tema 2 — Aula de Matrizes

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Matrizes: conceito, propriedades e nomenclatura

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

## 3. Igualdade de matrizes

Duas matrizes `A` e `B` são iguais se possuem a mesma dimensão e se os elementos que ocupam as mesmas posições são iguais.

Em notação:

```text
A_(m x n) = B_(m x n)  <=>  a_ij = b_ij
```

## 4. Matriz transposta

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

## 5. Exercício 1

Calcule o produto dos elementos da 2ª linha da matriz `A_(4 x 3)` dada por:

```text
a_ij = i, se i > j
a_ij = j, se i <= j
```

### Resolução organizada

Como a matriz é do tipo `4 x 3`, temos 4 linhas e 3 colunas.

Construindo os elementos:

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

## 6. Exercício 2

Calcule o produto dos elementos da 2ª coluna da matriz `A_(3 x 5)` dada por:

```text
a_ij = i + j, se i > j
a_ij = -2j, se i <= j
```

### Resolução organizada

Como a matriz é do tipo `3 x 5`, temos 3 linhas e 5 colunas.

Para a 2ª coluna, temos `j = 2`.

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

## 7. Exercício 3

Dada a matriz `A_(2 x 2)` tal que:

```text
a_ij = i + j^2 - 1
```

calcule o valor da expressão:

```text
a_11 * a_22 - a_12 * a_21
```

### Resolução organizada

Calculando os elementos:

```text
a_11 = 1 + 1^2 - 1 = 1
a_12 = 1 + 2^2 - 1 = 4
a_21 = 2 + 1^2 - 1 = 2
a_22 = 2 + 2^2 - 1 = 5
```

Assim:

```text
A = [ 1   4 ]
    [ 2   5 ]
```

Agora:

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

## 8. Exercício 4

Determine os valores de `a`, `b`, `c`, `d` e `e` para que a igualdade seja válida:

```text
[ 3a       b + 1 ]   [  6    5 ]
[ a - b+c  c + d ] = [  0   -1 ]
[ 0        b - e ]   [  0   -4 ]
```

### Resolução organizada

Como as matrizes são iguais, os elementos que ocupam as mesmas posições também devem ser iguais.

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

## 9. Para praticar

Os exercícios de prática estão organizados no arquivo:

```text
02-03-lista-1-matrizes.md
```
