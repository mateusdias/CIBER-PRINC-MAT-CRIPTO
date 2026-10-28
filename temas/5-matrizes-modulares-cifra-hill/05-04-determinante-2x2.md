# Tema 5 — Determinante de Matriz 2 x 2

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Matrizes modulares: o número que orienta o teste de invertibilidade

## 1. Por que precisamos de uma ferramenta nova?

Já sabemos multiplicar uma matriz pelos blocos da mensagem. Falta responder: como saber se essa transformação pode ser desfeita?

Para a cifra afim, verificamos se o multiplicador tem inverso modular. Para Hill, precisaremos verificar uma propriedade da matriz-chave inteira. O **determinante** é o número que permitirá fazer isso.

Nesta aula, aprendemos a calculá-lo. Na próxima, veremos por que o teste modular exige mais do que um determinante diferente de zero.

## 2. A fórmula para duas linhas e duas colunas

Para:

```text
K = [ a   b ]
    [ c   d ]
```

definimos:

```text
det(K) = a*d - b*c
```

O procedimento é:

```text
1. Multiplicar os elementos da diagonal principal: a*d.
2. Multiplicar os elementos da outra diagonal: b*c.
3. Subtrair o segundo produto do primeiro.
```

Não é a soma dos quatro elementos, nem o produto de todos eles.

## 3. Exemplo resolvido: a chave das aulas anteriores

```text
K = [ 3   2 ]
    [ 1   1 ]

a = 3, b = 2, c = 1, d = 1

det(K) = 3*1 - 2*1
det(K) = 3 - 2
det(K) = 1
```

O resultado `1` tem inverso módulo `26`: ele mesmo. Essa é uma boa indicação, que será formalizada no teste da próxima aula.

## 4. Exemplo resolvido: outra chave

```text
H = [ 3   3 ]
    [ 2   5 ]

det(H) = 3*5 - 3*2
det(H) = 15 - 6
det(H) = 9
```

Como `mdc(9, 26) = 1`, o determinante tem inverso modular. Mais adiante, usaremos essa chave para praticar uma inversa matricial que exige o inverso de `9`.

## 5. Exemplo com determinante negativo

```text
M = [ 1   2 ]
    [ 3   4 ]

det(M) = 1*4 - 2*3
det(M) = 4 - 6
det(M) = -2
```

O determinante inteiro é `-2`. No contexto modular, também podemos trabalhar com seu representante:

```text
-2 ≡ 24 (mod 26)
```

Os dois números têm o mesmo comportamento módulo `26`. Como `mdc(-2, 26) = mdc(24, 26) = 2`, nenhum deles tem inverso nesse módulo.

Não transforme um determinante negativo em positivo tomando o valor absoluto. O representante de `-2` módulo `26` é `24`, não `2`.

## 6. Determinante zero e perda de informação

Considere:

```text
S = [ 1   2 ]
    [ 2   4 ]

det(S) = 1*4 - 2*2 = 0
```

A segunda linha é o dobro da primeira. Na transformação:

```text
c_1 ≡ p_1 + 2p_2 (mod 26)
c_2 ≡ 2p_1 + 4p_2 ≡ 2c_1 (mod 26)
```

A segunda saída não fornece uma combinação independente. Podemos mostrar uma colisão concreta:

```text
AA = [0, 0]:
S*[0, 0] = [0, 0] -> AA

YB = [24, 1]:
S*[24, 1] = [26, 52] ≡ [0, 0] -> AA
```

Logo, `AA` e `YB` são dois blocos distintos com a mesma saída. A transformação não permite recuperar o bloco original de forma única.

## 7. O cuidado com matrizes em módulo 26

Em matrizes reais `2 x 2`, determinante diferente de zero garante uma inversa real. Em módulo `26`, precisamos que o determinante tenha inverso **modular**.

Exemplo:

```text
T = [ 2   0 ]
    [ 0   1 ]

det(T) = 2
```

Embora `2` seja diferente de zero, ele não tem inverso módulo `26`. A matriz será rejeitada como chave reversível de Hill nesse módulo.

O teste completo será:

```text
mdc(det(K), 26) = 1
```

## 8. Exercícios

### 8.1

Calcule o determinante de `A = [[5, 1], [2, 1]]`.

### 8.2

Calcule o determinante de `B = [[2, 4], [1, 2]]`.

### 8.3

Calcule o determinante de `D = [[1, 3], [4, 5]]` e encontre seu representante módulo `26`.

### 8.4

Uma matriz tem determinante `27`. Qual é seu determinante módulo `26`? Esse número tem inverso?

### 8.5

Um colega afirma que qualquer matriz com determinante `13` serve para Hill módulo `26`, pois `13` é diferente de zero. Explique o erro.

## Gabarito comentado

### 8.1

```text
det(A) = 5*1 - 1*2 = 5 - 2 = 3
```

### 8.2

```text
det(B) = 2*2 - 4*1 = 4 - 4 = 0
```

### 8.3

```text
det(D) = 1*5 - 3*4 = 5 - 12 = -7
-7 + 26 = 19
```

O determinante inteiro é `-7`; seu representante módulo `26` é `19`.

### 8.4

`27 ≡ 1 (mod 26)`. O número `1` tem inverso modular igual a `1`.

### 8.5

Ser diferente de zero não basta. Como `mdc(13, 26) = 13`, o determinante não tem inverso modular. Assim, a matriz não possui a inversa necessária para decifrar todos os blocos de forma única.

**Próxima aula:** [Invertibilidade módulo 26](05-05-invertibilidade-modulo-26.md).
