# Tema 4 — Inverso Modular Aplicado à Decifragem

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Cifras clássicas modulares: desfazendo a transformação afim

## 1. Desfazer as operações na ordem inversa

A cifragem afim multiplica por `a` e depois soma `b`. Para voltar, precisamos:

```text
1. Subtrair b.
2. Multiplicar pelo inverso modular de a.
3. Reduzir módulo 26.
```

Partindo da fórmula:

```text
C ≡ aP + b (mod 26)
C - b ≡ aP (mod 26)
a^(-1) * (C - b) ≡ P (mod 26)
```

Logo:

```text
P ≡ a^(-1) * (C - b) (mod 26)
```

Não usamos a divisão comum por `a`. O símbolo `a^(-1)` representa um inteiro cujo produto por `a` deixa resto `1`, e não a fração real `1/a`.

## 2. Encontrando o inverso de 5 por tentativa

Para a chave `(5, 8)`, precisamos resolver:

```text
5u ≡ 1 (mod 26)
```

Podemos testar `u` de `0` a `25`. Quando chegamos a `21`:

```text
5 * 21 = 105
105 = 26 * 4 + 1
```

Portanto:

```text
5^(-1) ≡ 21 (mod 26)
P ≡ 21 * (C - 8) (mod 26)
```

Encontramos o inverso uma vez por chave, não uma vez por letra.

## 3. O mesmo inverso pelo algoritmo de Euclides

Para números maiores, testar todos os candidatos pode ser trabalhoso. Podemos usar divisões sucessivas e depois reorganizar as igualdades.

Primeiro, calculamos o MDC:

```text
26 = 5 * 5 + 1
5  = 1 * 5 + 0
```

O último resto não nulo é `1`. Agora isolamos esse `1`:

```text
1 = 26 - 5 * 5
```

Módulo `26`, o termo `26` desaparece:

```text
1 ≡ -5 * 5 (mod 26)
```

O coeficiente `-5` é um inverso de `5`. Como `-5 ≡ 21 (mod 26)`, recuperamos o mesmo resultado.

Reorganizar as divisões para escrever o MDC como combinação dos números é a ideia do **algoritmo de Euclides estendido**.

### Um exemplo com mais de uma substituição: inverso de 7

```text
26 = 7 * 3 + 5
7  = 5 * 1 + 2
5  = 2 * 2 + 1
2  = 1 * 2 + 0
```

Voltando nas igualdades:

```text
1 = 5 - 2 * 2
2 = 7 - 5

1 = 5 - 2 * (7 - 5)
1 = 3 * 5 - 2 * 7

5 = 26 - 3 * 7

1 = 3 * (26 - 3 * 7) - 2 * 7
1 = 3 * 26 - 11 * 7
```

Assim, o inverso de `7` é `-11 ≡ 15 (mod 26)`. Conferindo: `7 * 15 = 105 ≡ 1`.

## 4. Exemplo completo: SIUI volta a CASA

Sabemos que a chave é `(5, 8)` e que o inverso de `5` é `21`:

| Letra cifrada | C | C - 8 | 21(C - 8) | Resto por 26 | Letra original |
|---|---:|---:|---:|---:|---|
| S | 18 | 10 | 210 | 2 | C |
| I | 8 | 0 | 0 | 0 | A |
| U | 20 | 12 | 252 | 18 | S |
| I | 8 | 0 | 0 | 0 | A |

As reduções são:

```text
210 = 26 * 8 + 2
252 = 26 * 9 + 18
```

Recuperamos:

```text
SIUI -> CASA
```

## 5. Exemplo com diferença negativa: a letra D

A palavra `ZEBRA` foi cifrada como `DCNPI`. Para decifrar o primeiro símbolo:

```text
D = 3
3 - 8 = -5
21 * (-5) = -105
```

Uma forma de reduzir é somar múltiplos de `26`:

```text
-105 + 26 * 5 = 25
25 = Z
```

Outra forma é reduzir antes da multiplicação:

```text
-5 ≡ 21 (mod 26)
21 * 21 = 441
441 = 26 * 16 + 25
```

Os dois caminhos chegam à mesma letra. Não use valor absoluto: trocar `-5` por `5` altera a congruência.

## 6. Tabela de apoio: inversos módulo 26

| a | Inverso | Produto | Conferência |
|---:|---:|---:|---|
| 1 | 1 | 1 | `1 ≡ 1` |
| 3 | 9 | 27 | `27 = 26 * 1 + 1` |
| 5 | 21 | 105 | `105 = 26 * 4 + 1` |
| 7 | 15 | 105 | `105 = 26 * 4 + 1` |
| 9 | 3 | 27 | `27 = 26 * 1 + 1` |
| 11 | 19 | 209 | `209 = 26 * 8 + 1` |
| 15 | 7 | 105 | `105 = 26 * 4 + 1` |
| 17 | 23 | 391 | `391 = 26 * 15 + 1` |
| 19 | 11 | 209 | `209 = 26 * 8 + 1` |
| 21 | 5 | 105 | `105 = 26 * 4 + 1` |
| 23 | 17 | 391 | `391 = 26 * 15 + 1` |
| 25 | 25 | 625 | `625 = 26 * 24 + 1` |

Todas as congruências da tabela usam módulo `26`.

## 7. Laboratório em Python

O arquivo [04-cifras-classicas.py](../../exemplos/04-cifras-classicas.py) implementa preparação do texto, cifragem e decifragem de César e afim, busca de inversos e enumeração de chaves.

Na raiz do repositório, execute:

```bash
python3 exemplos/04-cifras-classicas.py
```

O programa apresenta, entre outros resultados:

```text
César (k=3): CASA -> FDVD -> CASA
Afim (a=5, b=8): CASA -> SIUI -> CASA
Inverso de 5 módulo 26: 21
```

Roteiro de investigação:

1. Troque a mensagem para `ZEBRA` e compare com as contas desta aula.
2. Use `(7, 2)` e procure o inverso necessário para decifrar.
3. Tente `(2, 3)` e observe a rejeição do multiplicador sem inverso.
4. Enumere as `312` chaves afins para um texto curto. Examine quantos candidatos parecem plausíveis.

O código usa busca direta do inverso para tornar a definição visível. Não exige instalar pacotes.

## 8. Exercícios

### 8.1

Decifre `PAQI` com a chave `(5, 8)`.

### 8.2

Decifre `EHK` com a chave `(3, 4)`. Mostre o inverso utilizado.

### 8.3

Cifre e depois decifre `SOL` com a chave `(7, 2)`.

### 8.4

Por que `a^(-1) * C - b` não é, em geral, a fórmula correta de decifragem? Use `C = 18` e a chave `(5, 8)`.

### 8.5

Encontre o inverso de `11` módulo `26` pelo algoritmo de Euclides e confira o produto.

## Gabarito comentado

### 8.1

```text
P = 15 -> 21*(15 - 8) = 147  ≡ 17 -> R
A =  0 -> 21*(0  - 8) = -168 ≡ 14 -> O
Q = 16 -> 21*(16 - 8) = 168  ≡ 12 -> M
I =  8 -> 21*(8  - 8) = 0    ≡  0 -> A

PAQI -> ROMA
```

### 8.2

O inverso de `3` é `9`, pois `3 * 9 = 27 ≡ 1`.

```text
E =  4 -> 9*(4  - 4) = 0  -> 0 -> A
H =  7 -> 9*(7  - 4) = 27 -> 1 -> B
K = 10 -> 9*(10 - 4) = 54 -> 2 -> C

EHK -> ABC
```

### 8.3

```text
S = 18 -> 7*18 + 2 = 128 ≡ 24 -> Y
O = 14 -> 7*14 + 2 = 100 ≡ 22 -> W
L = 11 -> 7*11 + 2 = 79  ≡  1 -> B

SOL -> YWB
```

Como `7^(-1) ≡ 15`:

```text
Y = 24 -> 15*(24 - 2) = 330 ≡ 18 -> S
W = 22 -> 15*(22 - 2) = 300 ≡ 14 -> O
B =  1 -> 15*(1  - 2) = -15 ≡ 11 -> L
```

### 8.4

A subtração precisa acontecer antes da multiplicação:

```text
Correto:   21*(18 - 8) = 210 ≡ 2  -> C
Incorreto: 21*18 - 8   = 370 ≡ 6  -> G
```

Distribuindo corretamente, teríamos `21C - 21b`, não `21C - b`.

### 8.5

```text
26 = 11 * 2 + 4
11 = 4 * 2 + 3
4  = 3 * 1 + 1

1 = 4 - 3
1 = 4 - (11 - 2*4) = 3*4 - 11
1 = 3*(26 - 2*11) - 11 = 3*26 - 7*11
```

O inverso é `-7 ≡ 19`. Conferindo: `11 * 19 = 209 = 26 * 8 + 1`.

**Próximo tema:** [Matrizes modulares e Cifra de Hill](../5-matrizes-modulares-cifra-hill/README.md).
