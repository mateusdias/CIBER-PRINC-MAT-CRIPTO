# Tema 5 — Multiplicação de Matriz por Vetor Módulo 26

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Matrizes modulares: transformação de um bloco

## 1. Retomando a chave do Tema 2

Na aula de matrizes, usamos:

```text
K = [ 3   2 ]
    [ 1   1 ]
```

Agora vamos explicar a transformação modular de cada bloco:

```text
C ≡ K*P (mod 26)
```

Aqui, `P` e `C` são vetores com dois números. No Tema 4, essas letras representavam números individuais; agora representam blocos.

## 2. Conferindo as dimensões

```text
K: 2 x 2
P: 2 x 1

(2 x 2) * (2 x 1) = (2 x 1)
```

As dimensões internas são iguais: a matriz tem duas colunas e o vetor tem duas linhas. O resultado tem duas linhas e uma coluna.

Isso significa que um par de letras de entrada produz outro par de letras.

## 3. A regra de linha por coluna

Se:

```text
K = [ a   b ]       P = [ p_1 ]
    [ c   d ]           [ p_2 ]
```

então:

```text
K*P = [ a*p_1 + b*p_2 ]
      [ c*p_1 + d*p_2 ]
```

Reduzimos **cada coordenada** módulo `26`:

```text
c_1 ≡ a*p_1 + b*p_2 (mod 26)
c_2 ≡ c*p_1 + d*p_2 (mod 26)
```

Não multiplicamos apenas os elementos que estão na mesma posição. Cada saída é uma soma de dois produtos.

## 4. Exemplo resolvido: EU

Convertendo o bloco:

```text
E = 4
U = 20

P = [  4 ]
    [ 20 ]
```

Aplicando a chave:

```text
K*P = [ 3   2 ] [  4 ]
      [ 1   1 ] [ 20 ]

    = [ 3*4 + 2*20 ]
      [ 1*4 + 1*20 ]

    = [ 52 ]
      [ 24 ]
```

Agora reduzimos:

```text
52 = 26 * 2 + 0
24 = 26 * 0 + 24

C = [  0 ]
    [ 24 ]
```

Convertendo para letras:

```text
0 = A
24 = Y

EU -> AY
```

## 5. Exemplo resolvido: RX

```text
R = 17
X = 23

K*P = [ 3*17 + 2*23 ] = [ 51 + 46 ] = [ 97 ]
      [ 1*17 + 1*23 ]   [ 17 + 23 ]   [ 40 ]
```

Reduzindo separadamente:

```text
97 = 26 * 3 + 19
40 = 26 * 1 + 14

C = [19] -> T
    [14] -> O

RX -> TO
```

O módulo não é aplicado ao vetor como se ele fosse um único número: cada posição recebe seu próprio resto.

## 6. A mistura entre as letras

Compare `EU` e `EV`, mudando apenas a segunda letra:

```text
EU: [4, 20] -> [52, 24] -> [0, 24] -> AY
EV: [4, 21] -> [54, 25] -> [2, 25] -> CZ
```

Nesta chave, alterar a segunda entrada modificou as duas saídas. Isso acontece porque o valor da segunda letra participa das duas somas.

Essa mistura é diferente da substituição individual de César e afim. Ela não é uma garantia de segurança: a transformação ainda é linear e pode ser estudada por meio de equações.

## 7. A convenção de coluna importa

Se representássemos `EU` como vetor linha e multiplicássemos à direita, obteríamos:

```text
[4  20] * [3  2] = [4*3 + 20*1    4*2 + 20*1]
          [1  1]

                  = [32  28]
                  ≡ [6   2] (mod 26)
```

Isso produziria `GC`, diferente de `AY`. Não há contradição: usamos outra convenção de multiplicação. Neste material, mantemos sempre **vetores coluna e chave à esquerda**.

## 8. Exercícios

Use `K = [[3, 2], [1, 1]]` e vetores coluna.

### 8.1

Cifre o bloco `AM` mostrando as duas somas.

### 8.2

Cifre o bloco `OB`.

### 8.3

Cifre o bloco `ZZ`. Reduza as duas coordenadas.

### 8.4

Um estudante calculou `EU -> [12, 20]`, multiplicando `3*4` e `1*20`. Explique o que falta no cálculo.

### 8.5

Se `P` tem dimensão `2 x 6`, qual é a dimensão de `K*P`? O que representa cada coluna do resultado?

## Gabarito comentado

### 8.1

```text
AM = [0, 12]
Primeira saída: 3*0 + 2*12 = 24
Segunda saída:  1*0 + 1*12 = 12

[24, 12] -> YM
```

### 8.2

```text
OB = [14, 1]
3*14 + 2*1 = 44 ≡ 18
1*14 + 1*1 = 15

[18, 15] -> SP
```

### 8.3

```text
ZZ = [25, 25]
3*25 + 2*25 = 125 ≡ 21
1*25 + 1*25 = 50  ≡ 24

[21, 24] -> VY
```

### 8.4

Cada saída precisa combinar a linha inteira com a coluna inteira. Faltam `2*20` na primeira soma e `1*4` na segunda. O vetor correto antes da redução é `[52, 24]`.

### 8.5

O resultado tem dimensão `2 x 6`. Cada coluna é um bloco cifrado de duas letras, na mesma posição do bloco original correspondente.

**Próxima aula:** [Cifra de Hill com matriz 2 x 2](05-03-cifra-de-hill-2x2.md).
