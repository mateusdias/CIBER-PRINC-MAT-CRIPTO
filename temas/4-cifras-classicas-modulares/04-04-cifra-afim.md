# Tema 4 — Cifra Afim

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Cifras clássicas modulares: multiplicação seguida de soma

## 1. Da soma para uma regra com duas etapas

Na cifra de César, somamos uma chave ao número de cada letra. Agora vamos combinar duas operações:

```text
1. Multiplicar o número original por a.
2. Somar b ao resultado.
3. Reduzir módulo 26.
```

A regra resultante é a **cifra afim**:

```text
C ≡ aP + b (mod 26)
```

A chave passa a ser o par ordenado `(a, b)`. O primeiro valor controla a multiplicação; o segundo, o deslocamento. A ordem das operações importa.

## 2. Uma chave válida para começar

Usaremos:

```text
a = 5
b = 8
C ≡ 5P + 8 (mod 26)
```

O valor `5` tem inverso módulo `26`, pois `mdc(5, 26) = 1`. Essa propriedade permitirá desfazer a multiplicação. A aula seguinte explica o critério e o que acontece com escolhas inadequadas.

Para `b`, podemos escolher qualquer representante entre `0` e `25`: somar um deslocamento sempre pode ser desfeito por subtração.

## 3. Exemplo resolvido: uma letra

Vamos cifrar `C`:

```text
C como letra original corresponde a P = 2.

Multiplicação: 5 * 2 = 10
Soma:         10 + 8 = 18
Redução:      18 mod 26 = 18
Letra final:  18 = S
```

Portanto, a letra `C` vira `S`.

Na fórmula, a variável `C` designa o número da letra cifrada; ela não significa necessariamente a letra do alfabeto chamada `C`. Use o contexto para distinguir as duas coisas.

## 4. Exemplo resolvido: CASA

| Letra original | P | 5P | 5P + 8 | Resto por 26 | Letra cifrada |
|---|---:|---:|---:|---:|---|
| C | 2 | 10 | 18 | 18 | S |
| A | 0 | 0 | 8 | 8 | I |
| S | 18 | 90 | 98 | 20 | U |
| A | 0 | 0 | 8 | 8 | I |

Detalhando a maior conta:

```text
5 * 18 + 8 = 98
98 = 26 * 3 + 20
20 = U
```

Resultado:

```text
CASA -> SIUI
```

Os dois `A` continuam produzindo a mesma letra cifrada. A cifra afim ainda é uma substituição fixa de letras.

## 5. Exemplo resolvido: ZEBRA

Com a mesma chave `(5, 8)`:

| Letra | P | 5P + 8 | Redução | Resultado |
|---|---:|---:|---|---|
| Z | 25 | 133 | `133 = 26 * 5 + 3` | D |
| E | 4 | 28 | `28 = 26 * 1 + 2` | C |
| B | 1 | 13 | `13 = 26 * 0 + 13` | N |
| R | 17 | 93 | `93 = 26 * 3 + 15` | P |
| A | 0 | 8 | `8 = 26 * 0 + 8` | I |

```text
ZEBRA -> DCNPI
```

Podemos reduzir após cada etapa ou só ao final. Para o `Z`:

```text
5 * 25 = 125 ≡ 21 (mod 26)
21 + 8 = 29 ≡ 3 (mod 26)
```

Chegamos novamente ao `3`, que representa `D`.

## 6. Por que a ordem importa?

Compare estas regras com `P = 2`, `a = 5` e `b = 8`:

```text
Multiplicar e depois somar:
5 * 2 + 8 = 18 -> S

Somar e depois multiplicar:
5 * (2 + 8) = 50 ≡ 24 -> Y
```

São transformações diferentes. A expressão da cifra afim deste tema é `aP + b`, com a multiplicação antes da soma.

## 7. Casos particulares

| Escolha | Regra | Interpretação |
|---|---|---|
| `a = 1` | `C ≡ P + b (mod 26)` | Cifra de deslocamento |
| `b = 0` | `C ≡ aP (mod 26)` | Cifra multiplicativa |
| `a = 1`, `b = 0` | `C ≡ P (mod 26)` | Identidade |

A cifra de César está contida na família afim. O critério sobre `a` continua necessário nos casos multiplicativos.

## 8. Exercícios

### 8.1

Cifre `ROMA` com a chave `(5, 8)`. Apresente as quatro contas.

### 8.2

Cifre `ABC` com a chave `(3, 4)`.

### 8.3

Com `(5, 8)`, qual letra original produz o número cifrado `8`? Confira substituindo o valor na fórmula.

### 8.4

Explique por que `(a, b) = (1, 3)` reproduz César com deslocamento `3`.

### 8.5

Um estudante calculou `5 * (P + 8)` para implementar a chave `(5, 8)`. Mostre o erro usando `P = 0`.

## Gabarito comentado

### 8.1

```text
R = 17 -> 5*17 + 8 = 93 ≡ 15 -> P
O = 14 -> 5*14 + 8 = 78 ≡  0 -> A
M = 12 -> 5*12 + 8 = 68 ≡ 16 -> Q
A =  0 -> 5*0  + 8 =  8 ≡  8 -> I

ROMA -> PAQI
```

### 8.2

```text
A = 0 -> 3*0 + 4 =  4 -> E
B = 1 -> 3*1 + 4 =  7 -> H
C = 2 -> 3*2 + 4 = 10 -> K

ABC -> EHK
```

### 8.3

`A`, pois `P = 0` e `5 * 0 + 8 = 8`. Como `5` é inversível módulo `26`, essa saída corresponde a uma única letra original.

### 8.4

Substituindo, `C ≡ 1P + 3 ≡ P + 3 (mod 26)`. Multiplicar por `1` não altera o número original.

### 8.5

Pela regra correta, `5 * 0 + 8 = 8`, dando `I`. Pela regra usada pelo estudante, `5 * (0 + 8) = 40 ≡ 14`, dando `O`. Os resultados são diferentes.

**Próxima aula:** [Condição de reversibilidade](04-05-condicao-de-reversibilidade.md).
