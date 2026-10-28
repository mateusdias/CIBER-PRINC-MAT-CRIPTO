# Tema 5 — Invertibilidade Módulo 26

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Matrizes modulares: existência e construção da inversa

## 1. O que queremos de uma matriz inversa?

Na cifragem, fazemos:

```text
C ≡ K*P (mod 26)
```

Queremos uma matriz `K^(-1)` que desfaça essa transformação:

```text
K^(-1)*K ≡ I (mod 26)
```

A matriz identidade de ordem `2` é:

```text
I = [ 1   0 ]
    [ 0   1 ]
```

Ela preserva qualquer vetor, pois:

```text
I*[p_1, p_2] = [1*p_1 + 0*p_2, 0*p_1 + 1*p_2] = [p_1, p_2]
```

As listas acima abreviam vetores coluna. Dizer que duas matrizes são congruentes significa que os elementos correspondentes são congruentes no módulo indicado.

## 2. O critério de existência

Uma matriz quadrada com entradas inteiras é invertível módulo `26` exatamente quando:

```text
mdc(det(K), 26) = 1
```

Para `2 x 2`, calculamos `det(K) = ad - bc`. Não precisamos que o determinante seja `1` como inteiro; ele precisa ter inverso modular.

Como `26 = 2 * 13`, rejeitamos determinantes pares ou divisíveis por `13`.

## 3. Por que esse critério aparece?

Para uma matriz `2 x 2`, construímos a **adjunta** assim:

```text
K = [ a   b ]       adj(K) = [  d   -b ]
    [ c   d ]                [ -c    a ]
```

O procedimento é trocar `a` com `d` e mudar os sinais de `b` e `c`. Essa operação não é apenas transpor a matriz.

Multiplicando as matrizes:

```text
K*adj(K) = [ ad-bc    -ab+ba ]
           [ cd-dc    -cb+da ]

         = [ det(K)    0      ]
           [   0      det(K)  ]

         = det(K)*I
```

Se o determinante tem inverso modular, podemos multiplicar por esse inverso e obter a identidade. Por isso:

```text
K^(-1) ≡ det(K)^(-1) * adj(K) (mod 26)
```

O fator `det(K)^(-1)` é um número e multiplica **todos** os elementos da adjunta.

O critério também é necessário: se `K` tivesse uma inversa `L`, a propriedade `det(LK) = det(L)det(K)` daria:

```text
det(L) * det(K) ≡ det(I) ≡ 1 (mod 26)
```

Logo, o determinante de `K` teria um inverso modular. Sem esse inverso escalar, não pode existir uma inversa matricial.

## 4. Exemplo resolvido: a chave do Tema 2

```text
K = [ 3   2 ]
    [ 1   1 ]

det(K) = 3*1 - 2*1 = 1
Inverso do determinante: 1
```

Construímos a adjunta:

```text
adj(K) = [  1   -2 ]
         [ -1    3 ]
```

Multiplicamos pelo inverso do determinante e reduzimos:

```text
K^(-1) ≡ 1 * [  1   -2 ] ≡ [  1   24 ] (mod 26)
              [ -1    3 ]   [ 25    3 ]
```

### Conferência pelo produto

```text
K^(-1)*K = [  1   24 ] [ 3   2 ]
            [ 25    3 ] [ 1   1 ]

          = [ 1*3 + 24*1     1*2 + 24*1 ]
            [25*3 +  3*1    25*2 +  3*1 ]

          = [ 27   26 ]
            [ 78   53 ]

          ≡ [ 1   0 ] (mod 26)
            [ 0   1 ]
```

A inversa passou pela verificação: o produto deu a identidade módulo `26`.

## 5. Exemplo resolvido: determinante diferente de 1

```text
H = [ 3   3 ]
    [ 2   5 ]

det(H) = 15 - 6 = 9
```

Como `9 * 3 = 27 ≡ 1`, o inverso do determinante é `3`.

```text
adj(H) = [  5   -3 ]
         [ -2    3 ]

H^(-1) ≡ 3 * [  5   -3 ] = [ 15   -9 ]
              [ -2    3 ]   [ -6    9 ]

       ≡ [ 15   17 ] (mod 26)
         [ 20    9 ]
```

Conferindo:

```text
H^(-1)*H = [ 15*3 + 17*2    15*3 + 17*5 ] = [ 79   130 ]
            [ 20*3 +  9*2    20*3 +  9*5 ]   [ 78   105 ]

          ≡ [ 1   0 ] (mod 26)
            [ 0   1 ]
```

O determinante não precisou ser `1`. Precisamos apenas multiplicar a adjunta pelo inverso correto.

## 6. Exemplo de matriz rejeitada

```text
T = [ 2   0 ]
    [ 0   1 ]

det(T) = 2
mdc(2, 26) = 2
```

Não existe inversa módulo `26`. A colisão fica visível nos blocos:

```text
AA = [0, 0]  -> [0, 0]  -> AA
NA = [13, 0] -> [26, 0] ≡ [0, 0] -> AA
```

A matriz tem inversa real `[[1/2, 0], [0, 1]]`, mas `1/2` não substitui um inverso modular de `2`, que não existe nesse módulo.

## 7. Roteiro para escolher e conferir uma chave

```text
1. Calcule o determinante.
2. Verifique se o MDC com 26 é 1.
3. Se o MDC for maior que 1, rejeite a chave.
4. Encontre o inverso modular do determinante.
5. Monte a adjunta.
6. Multiplique todos os elementos pelo inverso do determinante.
7. Reduza cada elemento módulo 26.
8. Confira se o produto com a chave dá a identidade módulo 26.
```

Ter entradas não nulas ou muitas entradas ímpares não substitui esse teste. A condição depende do determinante.

## 8. Exercícios

### 8.1

Quais chaves são invertíveis módulo `26`?

```text
A = [5  1]    B = [2  0]    D = [1  3]    E = [1  0]
    [2  1]        [0  1]        [4  5]        [0 13]
```

### 8.2

Calcule a inversa modular de `A = [[5, 1], [2, 1]]` e confira o produto.

### 8.3

Mostre que `D = [[1, 3], [4, 5]]`, de determinante negativo, também possui inversa módulo `26`.

### 8.4

Uma pessoa construiu corretamente a adjunta de `H = [[3, 3], [2, 5]]`, mas esqueceu de multiplicar pelo inverso de `9`. Por que a matriz obtida não é a inversa?

## Gabarito comentado

### 8.1

```text
det(A) = 3:  MDC com 26 é 1  -> invertível
det(B) = 2:  MDC com 26 é 2  -> não invertível
det(D) = -7: MDC com 26 é 1  -> invertível
det(E) = 13: MDC com 26 é 13 -> não invertível
```

### 8.2

O inverso de `3` é `9`:

```text
A^(-1) ≡ 9 * [ 1  -1 ] = [  9   -9 ] ≡ [  9   17 ] (mod 26)
              [-2   5 ]   [-18   45 ]   [  8   19 ]

A^(-1)*A = [ 79   26 ] ≡ [1  0] (mod 26)
            [ 78   27 ]   [0  1]
```

### 8.3

`det(D) = -7 ≡ 19`. Como `19 * 11 = 209 ≡ 1`, o inverso do determinante é `11`.

```text
D^(-1) ≡ 11 * [ 5  -3 ] = [ 55  -33 ] ≡ [ 3   19 ] (mod 26)
               [-4   1 ]   [-44   11 ]   [ 8   11 ]
```

O produto `D^(-1)*D` é `[[79, 104], [52, 79]]`, que se reduz à identidade.

### 8.4

Porque `adj(H)*H = 9I`, não `I`. Multiplicar a adjunta por `3`, inverso de `9`, transforma esse produto em `27I ≡ I (mod 26)`.

**Próxima aula:** [Decifragem com matriz inversa modular](05-06-decifragem-com-matriz-inversa.md).
