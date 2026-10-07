# Lista de Exercícios Pré-Avaliação 1

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Temas:** matrizes, congruência e aritmética modular

## Orientações

Use os conteúdos dos temas de matrizes e aritmética modular. Quando necessário, use a convenção `A = 0`, isto é:

```text
A = 0, B = 1, C = 2, ..., Z = 25
```

---

## Exercícios

### 1. Construção de matriz por regra

Construa a matriz `A = (a_ij)` do tipo `3 x 2`, sabendo que:

```text
a_ij = 2i + j
```

### 2. Construção de matriz com condições

Construa a matriz `B = (b_ij)` de ordem `3`, sabendo que:

```text
b_ij = 7, se i = j
b_ij = 1, se i < j
b_ij = 0, se i > j
```

### 3. Igualdade de matrizes

Determine `x`, `y` e `z` para que as matrizes sejam iguais.

```text
[ x + 2    3y ]   [  8    15 ]
[ z - 1    10 ] = [ -4    10 ]
```

### 4. Matriz transposta

Determine a matriz transposta de `A`.

```text
A = [ 2   -1    0 ]
    [ 5    4    7 ]
```

### 5. Soma de matrizes

Dadas as matrizes:

```text
A = [ 4   -2 ]
    [ 0    7 ]

B = [ -1    5 ]
    [  3   -4 ]
```

Calcule:

```text
A + B
```

### 6. Combinação linear de matrizes

Usando as matrizes do exercício anterior, calcule:

```text
2A - 3B
```

### 7. Multiplicação de matrizes

Dadas as matrizes:

```text
A = [  1    0    2 ]
    [ -1    3    1 ]

B = [ 2    1 ]
    [ 0   -2 ]
    [ 4    3 ]
```

Calcule:

```text
AB
```

### 8. Operações possíveis

Considere as dimensões:

```text
A: 2 x 3
B: 3 x 2
C: 2 x 2
D: 3 x 3
```

Indique quais operações são possíveis e, quando forem possíveis, informe a dimensão do resultado.

```text
A + B
AB
BA
AC
DA
CB
```

### 9. Matriz identidade

Dada a matriz:

```text
A = [  6   -2 ]
    [  1    5 ]
```

Calcule:

```text
I_2 A
```

### 10. Redução modular de uma matriz

Reduza todos os elementos da matriz abaixo módulo `26`, deixando cada resultado entre `0` e `25`.

```text
M = [ 28   -3 ]
    [ 52   31 ]
```

### 11. Resto da divisão

Determine o resto da divisão de `137` por `12`.

### 12. Resto módulo 26

Determine o resto da divisão de `250` por `26`.

### 13. Congruência

Complete:

```text
89 ≡ ___ (mod 7)
```

### 14. Verificação de congruência

Verifique se a afirmação abaixo é verdadeira ou falsa.

```text
74 ≡ 2 (mod 9)
```

### 15. Verificação de congruência

Verifique se a afirmação abaixo é verdadeira ou falsa.

```text
59 ≡ 6 (mod 13)
```

### 16. Números congruentes

Escreva três números positivos diferentes que sejam congruentes a `4` módulo `11`.

### 17. Soma modular

Calcule:

```text
17 + 29 (mod 12)
```

### 18. Subtração modular

Calcule:

```text
5 - 14 (mod 12)
```

### 19. Multiplicação modular

Calcule:

```text
9 * 17 (mod 26)
```

### 20. Redução antes ou depois

Calcule:

```text
123 + 88 (mod 10)
```

### 21. Equação modular simples

Encontre um número `x`, entre `0` e `11`, que satisfaça:

```text
x + 7 ≡ 3 (mod 12)
```

### 22. Inverso modular

Encontre o inverso de `11` módulo `26`, isto é, encontre `b` tal que:

```text
11b ≡ 1 (mod 26)
```

### 23. Inverso modular

Verifique se `9` tem inverso módulo `26`. Se tiver, encontre esse inverso.

### 24. Existência de inverso modular

Verifique se `12` tem inverso módulo `26`. Justifique.

### 25. Letras como números

Usando `A = 0`, converta a palavra abaixo para números.

```text
CHAVE
```

### 26. Números como letras

Usando `A = 0`, converta os números abaixo para letras.

```text
12, 14, 3, 20, 11, 14
```

### 27. Alfabeto circular

Usando `A = 0`, desloque a letra `Y` em `8` posições para frente.

### 28. Alfabeto circular

Usando `A = 0`, desloque a letra `C` em `5` posições para trás.

### 29. Cifra por deslocamento

Cifre a palavra abaixo usando deslocamento `k = 4`.

```text
CIBER
```

### 30. Decifragem por deslocamento

A palavra abaixo foi cifrada com deslocamento `k = 2`. Decifre.

```text
OCVTKB
```

---

## Gabarito

### 1

```text
A = [ 3   4 ]
    [ 5   6 ]
    [ 7   8 ]
```

### 2

```text
B = [ 7   1   1 ]
    [ 0   7   1 ]
    [ 0   0   7 ]
```

### 3

```text
x = 6
y = 5
z = -3
```

### 4

```text
A^T = [  2    5 ]
      [ -1    4 ]
      [  0    7 ]
```

### 5

```text
A + B = [ 3   3 ]
        [ 3   3 ]
```

### 6

```text
2A - 3B = [ 11   -19 ]
          [ -9    26 ]
```

### 7

```text
AB = [ 10    7 ]
     [  2   -4 ]
```

### 8

```text
A + B: não é possível
AB: possível, resultado 2 x 2
BA: possível, resultado 3 x 3
AC: não é possível
DA: não é possível
CB: não é possível
```

### 9

```text
I_2 A = A = [ 6   -2 ]
            [ 1    5 ]
```

### 10

```text
M ≡ [ 2   23 ]
    [ 0    5 ] (mod 26)
```

### 11

```text
137 = 12 * 11 + 5
```

Resposta: `5`.

### 12

```text
250 = 26 * 9 + 16
```

Resposta: `16`.

### 13

```text
89 = 7 * 12 + 5
```

Logo:

```text
89 ≡ 5 (mod 7)
```

### 14

Verdadeira, pois:

```text
74 = 9 * 8 + 2
```

### 15

Falsa, pois:

```text
59 = 13 * 4 + 7
```

Logo:

```text
59 ≡ 7 (mod 13)
```

### 16

Uma resposta possível:

```text
4, 15, 26
```

### 17

```text
17 + 29 = 46
46 = 12 * 3 + 10
```

Resposta: `10`.

### 18

```text
5 - 14 = -9
-9 + 12 = 3
```

Resposta: `3`.

### 19

```text
9 * 17 = 153
153 = 26 * 5 + 23
```

Resposta: `23`.

### 20

```text
123 + 88 = 211
211 = 10 * 21 + 1
```

Resposta: `1`.

### 21

```text
x + 7 ≡ 3 (mod 12)
x ≡ 3 - 7 (mod 12)
x ≡ -4 (mod 12)
x ≡ 8 (mod 12)
```

Resposta: `x = 8`.

### 22

```text
11 * 19 = 209
209 = 26 * 8 + 1
```

Logo:

```text
11^(-1) ≡ 19 (mod 26)
```

### 23

Sim. Como `mdc(9, 26) = 1`, `9` tem inverso módulo `26`.

```text
9 * 3 = 27
27 ≡ 1 (mod 26)
```

Logo:

```text
9^(-1) ≡ 3 (mod 26)
```

### 24

`12` não tem inverso módulo `26`, pois:

```text
mdc(12, 26) = 2
```

Como o mdc não é `1`, não existe inverso modular.

### 25

```text
CHAVE -> 2, 7, 0, 21, 4
```

### 26

```text
12, 14, 3, 20, 11, 14 -> MODULO
```

### 27

```text
Y = 24
24 + 8 = 32
32 ≡ 6 (mod 26)
6 = G
```

Resposta: `G`.

### 28

```text
C = 2
2 - 5 = -3
-3 + 26 = 23
23 = X
```

Resposta: `X`.

### 29

```text
C = 2  ->  6 = G
I = 8  -> 12 = M
B = 1  ->  5 = F
E = 4  ->  8 = I
R = 17 -> 21 = V
```

Resposta:

```text
CIBER -> GMFIV
```

### 30

Como o deslocamento foi `k = 2`, subtraímos `2` de cada letra.

```text
O = 14 -> 12 = M
C = 2  ->  0 = A
V = 21 -> 19 = T
T = 19 -> 17 = R
K = 10 ->  8 = I
B = 1  -> -1 ≡ 25 = Z
```

Resposta:

```text
OCVTKB -> MATRIZ
```
