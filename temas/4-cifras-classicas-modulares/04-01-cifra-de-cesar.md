# Tema 4 — Cifra de César

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Cifras clássicas modulares: primeira regra de substituição

## 1. O problema que queremos resolver

Imagine que duas pessoas combinem uma regra: cada letra será substituída pela letra que está três posições adiante no alfabeto.

```text
A -> D
B -> E
C -> F
...
X -> A
Y -> B
Z -> C
```

Esse deslocamento de três posições é o exemplo tradicional da **cifra de César**. Nas atividades, também usaremos outros deslocamentos; essa família é chamada de cifra de deslocamento ou César generalizada.

A transformação volta ao início quando chega ao final do alfabeto. É a ideia de ciclo estudada no Tema 3.

## 2. Vocabulário para acompanhar as contas

| Termo | Significado | Exemplo |
|---|---|---|
| Texto claro | Mensagem antes de cifrar | `CASA` |
| Texto cifrado | Resultado da transformação | `FDVD` |
| Algoritmo | Regra utilizada | Somar um deslocamento módulo 26 |
| Chave | Valor escolhido para a regra | `k = 3` |
| Cifragem | Aplicar a transformação | `CASA -> FDVD` |
| Decifragem | Recuperar a mensagem com a chave | `FDVD -> CASA` |
| Criptoanálise | Investigar a recuperação de informações sem conhecer a chave | Testar deslocamentos |

Conhecer o algoritmo não significa conhecer a chave. Podemos saber que a regra é somar um deslocamento e ainda precisar descobrir qual deslocamento foi usado.

## 3. Preparando uma mensagem

Usaremos somente as 26 letras de `A` a `Z`:

```text
A  B  C  D  E  F  G  H  I  J  K  L  M
0  1  2  3  4  5  6  7  8  9 10 11 12

N  O  P  Q  R  S  T  U  V  W  X  Y  Z
13 14 15 16 17 18 19 20 21 22 23 24 25
```

Exemplo de preparação:

```text
Texto recebido:   Olá, turma!
Texto preparado:  OLATURMA
```

Converter letras em números estabelece uma **representação**. A cifragem acontece quando aplicamos a transformação com a chave. Trocar `A` por `0`, por si só, não oferece sigilo.

## 4. A regra matemática

```text
C ≡ P + k (mod 26)
```

Lendo cada parte:

```text
P: número da letra original
k: chave de deslocamento
C: número da letra cifrada, escolhido entre 0 e 25
```

O símbolo `≡` expressa congruência. Para calcular o representante da tabela, fazemos:

```text
C = resto de (P + k) na divisão por 26
```

## 5. Exemplo resolvido: CASA com k = 3

Convertemos a mensagem, somamos a chave e reduzimos módulo `26`.

| Letra original | P | P + 3 | Resto por 26 | Letra cifrada |
|---|---:|---:|---:|---|
| C | 2 | 5 | 5 | F |
| A | 0 | 3 | 3 | D |
| S | 18 | 21 | 21 | V |
| A | 0 | 3 | 3 | D |

```text
CASA -> FDVD
```

Observe os dois `A`: ambos viraram `D`. Com uma chave fixa, a mesma letra sempre produz a mesma letra cifrada. Esse padrão terá importância na análise de segurança.

## 6. Exemplo resolvido: ZEBRA com k = 3

O primeiro cálculo ultrapassa o fim do alfabeto:

```text
Z = 25
25 + 3 = 28
28 = 26 * 1 + 2
2 = C
```

Completando a palavra:

| Letra | P | P + 3 | C | Resultado |
|---|---:|---:|---:|---|
| Z | 25 | 28 | 2 | C |
| E | 4 | 7 | 7 | H |
| B | 1 | 4 | 4 | E |
| R | 17 | 20 | 20 | U |
| A | 0 | 3 | 3 | D |

```text
ZEBRA -> CHEUD
```

O módulo mantém os resultados no mesmo alfabeto. Não precisamos inventar uma letra de número `28`.

## 7. Primeiro contato com a decifragem

Se cifrar significa somar `3`, decifrar significa subtrair `3`:

```text
P ≡ C - 3 (mod 26)
```

Para recuperar o `Z` a partir de `C`:

```text
C = 2
2 - 3 = -1
-1 + 26 = 25
25 = Z
```

O número negativo não é um erro. Ele precisa ser reduzido ao representante entre `0` e `25`.

## 8. Exercícios

### 8.1

Na transformação `CASA -> FDVD`, identifique texto claro, texto cifrado, algoritmo e chave.

### 8.2

Cifre `ROMA` com `k = 3`, mostrando a conversão numérica.

### 8.3

Cifre `XYZ` com `k = 4`. Explique como tratou os valores maiores que `25`.

### 8.4

Prepare `Olá, turma!` e cifre o resultado com `k = 3`.

### 8.5

Uma pessoa diz que trocar letras pelos números da tabela já protege a mensagem. Você concorda? Justifique.

## Gabarito comentado

### 8.1

Texto claro: `CASA`. Texto cifrado: `FDVD`. Algoritmo: deslocamento aditivo módulo `26`. Chave: `3`.

### 8.2

```text
R = 17 -> 17 + 3 = 20 -> U
O = 14 -> 14 + 3 = 17 -> R
M = 12 -> 12 + 3 = 15 -> P
A =  0 ->  0 + 3 =  3 -> D

ROMA -> URPD
```

### 8.3

```text
X = 23 -> 27 ≡ 1 (mod 26) -> B
Y = 24 -> 28 ≡ 2 (mod 26) -> C
Z = 25 -> 29 ≡ 3 (mod 26) -> D

XYZ -> BCD
```

### 8.4

```text
OLATURMA -> RODWXUPD
```

Por exemplo, `U = 20` vira `23 = X`. A cifragem é aplicada ao texto já preparado.

### 8.5

Não. Quem conhece a tabela pode fazer a conversão de volta imediatamente. A tabela representa os símbolos; não introduz uma chave secreta.

**Próxima aula:** [Deslocamento modular e decifragem](04-02-deslocamento-modular.md).
