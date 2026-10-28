# Tema 4 — Condição de Reversibilidade

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Cifras clássicas modulares: colisões, MDC e escolha da chave

## 1. Conseguir cifrar não basta

Podemos calcular `aP + b` com qualquer par de inteiros. Mas uma cifra precisa permitir que o destinatário recupere o original de forma única.

Quando duas letras diferentes produzem a mesma saída, ocorre uma **colisão**. O resultado isolado já não permite saber qual das duas entrou.

Como há 26 entradas e 26 saídas possíveis, uma transformação sem colisões associa cada letra a exatamente uma saída diferente. Dizemos que ela é uma **bijeção**, ou uma permutação do alfabeto.

## 2. Exemplo de falha com a = 2

Considere:

```text
C ≡ 2P + 3 (mod 26)
```

Vamos cifrar `A` e `N`:

```text
A = 0:
2 * 0 + 3 = 3 -> D

N = 13:
2 * 13 + 3 = 29 ≡ 3 -> D
```

Temos:

```text
A -> D
N -> D
```

Se recebermos `D`, saber a chave `(2, 3)` ainda não basta para decidir entre `A` e `N`. A perda de informação ocorreu na própria transformação.

## 3. Somar b não elimina a colisão

Antes de somar `3`, os números `0` e `13` já se encontravam na mesma saída:

```text
2 * 0  ≡ 0 (mod 26)
2 * 13 ≡ 0 (mod 26)
```

Adicionar o mesmo `b` aos dois resultados mantém a igualdade modular. Portanto, escolher outro deslocamento não conserta um multiplicador inadequado.

## 4. A condição correta

A regra afim é reversível módulo `26` exatamente quando:

```text
mdc(a, 26) = 1
```

O **máximo divisor comum**, ou MDC, é o maior inteiro positivo que divide os dois números.

```text
Divisores positivos de 5:  1, 5
Divisores positivos de 26: 1, 2, 13, 26
Único divisor comum: 1
Logo, mdc(5, 26) = 1.
```

Serem **primos entre si** significa terem MDC igual a `1`. Isso não exige que cada número seja primo: `9` e `26` são primos entre si, embora `9` não seja primo.

## 5. Por que o inverso impede colisões?

Se `a` tem inverso e duas entradas produzem a mesma saída, então:

```text
aP_1 + b ≡ aP_2 + b (mod 26)
aP_1 ≡ aP_2 (mod 26)
```

Multiplicamos os dois lados pelo inverso de `a`:

```text
a^(-1) * aP_1 ≡ a^(-1) * aP_2 (mod 26)
P_1 ≡ P_2 (mod 26)
```

Como as entradas estão entre `0` e `25`, elas são o mesmo número. Assim, duas entradas diferentes não podem ter a mesma saída.

Para entender a outra direção, suponha que `d = mdc(a, 26) > 1`. As entradas `0` e `26/d` são distintas no alfabeto, mas:

```text
a * (26/d) = (a/d) * 26 ≡ 0 (mod 26)
```

Portanto, elas colidem antes da soma e continuam colidindo depois dela. Isso explica por que o critério é necessário, além de suficiente.

## 6. Quais multiplicadores podemos usar?

Como `26 = 2 * 13`, eliminamos os pares e os múltiplos de `13`. Restam:

```text
1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25
```

São `12` escolhas para `a`. Para cada uma, há `26` escolhas para `b`:

```text
12 * 26 = 312 chaves afins distintas
```

A contagem inclui a identidade `(1, 0)` e as `26` cifras de deslocamento, nas quais `a = 1`.

O espaço é maior que o de César, mas continua pequeno: um programa pode testar todas as `312` chaves. Além disso, as frequências e os padrões de repetição de letras continuam presentes.

## 7. Comparação de algumas escolhas

| a | mdc(a, 26) | Pode ser usado? | Motivo |
|---:|---:|---|---|
| 0 | 26 | Não | Todas as letras viram o mesmo `b` |
| 2 | 2 | Não | Entradas separadas por 13 colidem |
| 5 | 1 | Sim | Possui inverso modular |
| 9 | 1 | Sim | Não compartilha fatores com 26 |
| 13 | 13 | Não | Há somente duas saídas antes do deslocamento |
| 25 | 1 | Sim | `25 * 25 ≡ 1 (mod 26)` |

Com `a = 13`, uma entrada par produz `0` antes da soma e uma entrada ímpar produz `13`. Assim, 26 letras ficam comprimidas em apenas duas possibilidades.

## 8. Exercícios

### 8.1

Classifique as chaves `(7, 2)`, `(6, 5)`, `(13, 1)` e `(25, 0)` como válidas ou inválidas para uma cifra reversível.

### 8.2

Na regra `C ≡ 2P + 3 (mod 26)`, mostre que `B` e `O` colidem.

### 8.3

Um estudante afirma: “Se `a` é ímpar, a chave sempre é válida módulo 26”. Encontre um contraexemplo.

### 8.4

Se mudássemos para um alfabeto de 10 símbolos, quais representantes de `a`, entre `0` e `9`, seriam válidos? Quantas chaves afins existiriam?

### 8.5

Por que uma transformação reversível pode continuar sendo fácil de atacar?

## Gabarito comentado

### 8.1

`(7, 2)` e `(25, 0)` são válidas porque os multiplicadores têm MDC `1` com `26`. `(6, 5)` é inválida, pois o MDC é `2`; `(13, 1)` é inválida, pois o MDC é `13`.

### 8.2

```text
B = 1:  2*1  + 3 = 5 -> F
O = 14: 2*14 + 3 = 31 ≡ 5 -> F
```

O mesmo símbolo cifrado pode ter vindo de duas letras diferentes.

### 8.3

`a = 13` é ímpar, mas `mdc(13, 26) = 13`. Precisamos excluir tanto os múltiplos de `2` quanto os de `13`.

### 8.4

Os multiplicadores são `1, 3, 7, 9`, pois têm MDC `1` com `10`. Com dez escolhas para `b`, são `4 * 10 = 40` chaves.

### 8.5

Reversibilidade garante a recuperação única com a chave. Ela não garante dificuldade de descobrir a chave. César e afim são reversíveis com chaves válidas, mas permitem enumeração rápida das chaves e preservam padrões do texto.

**Próxima aula:** [Inverso modular aplicado à decifragem](04-06-inverso-modular-na-decifragem.md).
