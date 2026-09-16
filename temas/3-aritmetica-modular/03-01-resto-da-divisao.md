# Tema 3 — Resto da Divisão

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Aritmética modular: resto da divisão

## 1. Ideia central

Quando dividimos um número inteiro por outro, nem sempre a divisão é exata.

O que sobra dessa divisão é chamado de **resto**.

Exemplo:

```text
17 dividido por 5 dá quociente 3 e resto 2.
```

Isso acontece porque:

```text
17 = 5 * 3 + 2
```

Nesse caso:

```text
dividendo = 17
divisor = 5
quociente = 3
resto = 2
```

## 2. Forma geral da divisão euclidiana

Essa forma de escrever a divisão é chamada de **divisão euclidiana** por causa de Euclides, matemático grego associado à obra *Os Elementos*. Euclides não batizou a conta com esse nome; o nome foi dado posteriormente em referência à tradição matemática ligada a ele, especialmente ao estudo da divisibilidade e ao algoritmo de Euclides para calcular o máximo divisor comum.

A ideia da divisão com resto é sempre a mesma:

```text
número dividido = divisor * quantidade de vezes que coube + resto
```

Por exemplo:

```text
17 dividido por 5
```

O `5` cabe `3` vezes dentro do `17`, porque:

```text
5 * 3 = 15
```

Depois disso, sobram `2`, porque:

```text
17 - 15 = 2
```

Então escrevemos:

```text
17 = 5 * 3 + 2
```

Lendo essa conta:

```text
17 é o número que queremos dividir
5 é o divisor
3 é a quantidade de vezes que o 5 coube
2 é o resto
```

Agora podemos escrever a mesma ideia usando letras:

```text
a = n * q + r
```

em que:

```text
a é o número que queremos dividir
n é o divisor
q é o quociente, isto é, a quantidade de vezes que n coube em a
r é o resto, isto é, o que sobrou
```

O resto sempre precisa ser menor que o divisor.

Por isso:

```text
0 <= r < n
```

Ou seja, se estamos dividindo por `n`, o resto pode ser `0`, pode ser `1`, pode ir aumentando, mas nunca pode chegar em `n`.

Exemplo:

```text
29 = 7 * 4 + 1
```

Lendo:

```text
29 é o número que queremos dividir
7 é o divisor
4 é o quociente
1 é o resto
```

Logo, o resto da divisão de `29` por `7` é `1`.

## 3. Restos possíveis

Ao dividir por `5`, os restos possíveis são:

```text
0, 1, 2, 3, 4
```

Nunca aparece resto `5`, porque se sobrasse `5`, ainda daria para dividir mais uma vez por `5`.

Ao dividir por `12`, os restos possíveis são:

```text
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
```

Ao dividir por `26`, os restos possíveis são:

```text
0, 1, 2, ..., 25
```

Essa última lista será muito importante quando trabalharmos com letras do alfabeto.

## 4. Exemplo com relógio

Um relógio comum trabalha com ciclos.

Se agora são `10h` e passam `5` horas, temos:

```text
10 + 5 = 15
```

Mas no relógio de 12 horas, `15h` corresponde a `3h`.

Isso acontece porque:

```text
15 = 12 * 1 + 3
```

O resto da divisão de `15` por `12` é `3`.

Em outras palavras, no relógio, contamos sempre dentro de um ciclo de tamanho `12`.

## 5. Resto e criptografia

Em criptografia, muitas vezes trabalhamos com conjuntos finitos.

Por exemplo, se usamos o alfabeto com 26 letras, queremos que qualquer transformação de uma letra resulte em outra letra do mesmo alfabeto.

Se `A = 0`, `B = 1`, ..., `Z = 25`, então o resultado de uma conta precisa voltar para o intervalo:

```text
0 até 25
```

O resto da divisão por `26` faz exatamente isso.

Exemplo:

```text
28 dividido por 26 dá resto 2.
```

Então, em um alfabeto numérico de 26 posições:

```text
28 volta para 2
```

E `2` representa a letra `C`, se usarmos `A = 0`.

## 6. Exercícios

### 6.1

Determine o resto da divisão de `34` por `6`.

### 6.2

Determine o resto da divisão de `52` por `10`.

### 6.3

Determine o resto da divisão de `100` por `26`.

### 6.4

Em um relógio de 12 horas, são `9h`. Que hora será indicada após `8` horas?

### 6.5

Explique por que, ao dividir um número por `26`, o resto nunca pode ser `26`.

## Gabarito

### 6.1

```text
34 = 6 * 5 + 4
```

Resto: `4`.

### 6.2

```text
52 = 10 * 5 + 2
```

Resto: `2`.

### 6.3

```text
100 = 26 * 3 + 22
```

Resto: `22`.

### 6.4

```text
9 + 8 = 17
17 = 12 * 1 + 5
```

O relógio indicará `5h`.

### 6.5

Porque se sobrassem `26`, ainda seria possível dividir mais uma vez por `26`. Por isso, ao dividir por `26`, os restos possíveis vão de `0` até `25`.
