# Tema 4 — Deslocamento Modular e Decifragem

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Cifras clássicas modulares: chaves, ciclos e operação inversa

## 1. O que muda quando trocamos a chave?

A regra de César generalizada continua a mesma:

```text
C ≡ P + k (mod 26)
```

Com a letra `A`, vemos diretamente o efeito da chave:

```text
k = 1:  A -> B
k = 5:  A -> F
k = 25: A -> Z
k = 26: A -> A
```

Uma volta completa não altera a posição. Chaves que diferem por um múltiplo de `26` produzem a mesma transformação.

## 2. Chaves equivalentes

Compare `k = 3` e `k = 29`:

```text
29 ≡ 3 (mod 26)

Para P = 23:
23 + 3  = 26 -> resto 0 -> A
23 + 29 = 52 -> resto 0 -> A
```

Isso vale para qualquer letra, pois `P + 29 = P + 3 + 26`.

Escolhemos, então, uma lista de representantes das chaves:

```text
0, 1, 2, ..., 25
```

São `26` transformações distintas. A chave `0` é a identidade: deixa todas as letras como estavam. Excluindo essa opção, restam `25` deslocamentos que alteram a mensagem.

## 3. Como desfazer um deslocamento

Começamos com:

```text
C ≡ P + k (mod 26)
```

Subtraímos `k` dos dois lados:

```text
C - k ≡ P + k - k (mod 26)
C - k ≡ P (mod 26)
```

Portanto:

```text
P ≡ C - k (mod 26)
```

A subtração pode ser feita para qualquer chave inteira. Não precisamos de inverso multiplicativo para desfazer uma soma.

## 4. Exemplo completo: cifrar e decifrar CHAVE

Vamos usar `k = 7`.

| Letra | P | P + 7 | C | Letra cifrada |
|---|---:|---:|---:|---|
| C | 2 | 9 | 9 | J |
| H | 7 | 14 | 14 | O |
| A | 0 | 7 | 7 | H |
| V | 21 | 28 | 2 | C |
| E | 4 | 11 | 11 | L |

```text
CHAVE -> JOHCL
```

Agora desfazemos usando a mesma chave:

| Letra cifrada | C | C - 7 | P entre 0 e 25 | Letra original |
|---|---:|---:|---:|---|
| J | 9 | 2 | 2 | C |
| O | 14 | 7 | 7 | H |
| H | 7 | 0 | 0 | A |
| C | 2 | -5 | 21 | V |
| L | 11 | 4 | 4 | E |

No quarto caso, `-5 + 26 = 21`. Recuperamos `CHAVE`. O teste de ida e volta ajuda a conferir uma implementação.

## 5. Subtrair ou somar uma chave equivalente

Voltar `7` posições equivale a avançar `19`, porque:

```text
-7 ≡ 19 (mod 26)
7 + 19 = 26 ≡ 0 (mod 26)
```

Podemos usar uma destas formas equivalentes:

```text
P ≡ C - 7 (mod 26)
P ≡ C + 19 (mod 26)
```

O `19` é o **inverso aditivo** de `7` módulo `26`. Não é seu inverso multiplicativo: `7 * 19` não deixa resto `1`. As duas ideias desfazem operações diferentes.

## 6. Dois deslocamentos consecutivos

Se somarmos `5` e depois `8`, temos:

```text
P -> P + 5 -> P + 5 + 8
C ≡ P + 13 (mod 26)
```

Aplicar dois deslocamentos consecutivos produz outro deslocamento.

Exemplo em que a soma completa uma volta:

```text
k_1 = 19
k_2 = 7
k_total = 26 ≡ 0 (mod 26)
```

Nesse caso, a segunda transformação desfaz a primeira.

## 7. Exercícios

### 7.1

Reduza as chaves `31`, `-3` e `52` para representantes entre `0` e `25`.

### 7.2

Decifre `JHZH` sabendo que `k = 7`. Indique se algum cálculo produz um número negativo.

### 7.3

Cifre `ZOO` com `k = 5` e depois confira a decifragem.

### 7.4

Uma mensagem foi cifrada com deslocamento `18` e depois com deslocamento `11`. Qual é a chave equivalente?

### 7.5

Por que `k = 2` funciona em César mesmo que `2` não tenha inverso multiplicativo módulo `26`?

## Gabarito comentado

### 7.1

```text
31 ≡ 5 (mod 26)
-3 ≡ 23 (mod 26)
52 ≡ 0 (mod 26)
```

### 7.2

```text
J =  9 ->  9 - 7 =  2 ->  2 -> C
H =  7 ->  7 - 7 =  0 ->  0 -> A
Z = 25 -> 25 - 7 = 18 -> 18 -> S
H =  7 ->  7 - 7 =  0 ->  0 -> A

JHZH -> CASA
```

Neste exemplo não surgem negativos. Eles aparecem no exercício seguinte; a necessidade de somar `26` depende dos valores, não apenas da chave.

### 7.3

```text
Z = 25 -> 30 ≡ 4 -> E
O = 14 -> 19     -> T
O = 14 -> 19     -> T

ZOO -> ETT
```

Na volta, `4 - 5 = -1 ≡ 25` e `19 - 5 = 14`, recuperando `ZOO`.

### 7.4

```text
18 + 11 = 29 ≡ 3 (mod 26)
```

A chave equivalente é `3`.

### 7.5

A regra soma `2`; para desfazê-la, subtraímos `2`. A existência de inverso multiplicativo é necessária quando precisamos desfazer uma multiplicação.

**Próxima aula:** [Quebra por força bruta](04-03-quebra-por-forca-bruta.md).
