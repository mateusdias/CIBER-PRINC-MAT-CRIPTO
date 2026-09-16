# Tema 3 — Alfabeto Circular e Módulo 26

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Aritmética modular: alfabeto circular

## 1. Ideia central

O alfabeto pode ser visto como um ciclo.

Depois do `Z`, voltamos para o `A`.

Usando `A = 0`, temos:

```text
A = 0
B = 1
C = 2
...
Z = 25
```

Se uma operação passar de `25`, usamos módulo `26` para voltar ao intervalo correto.

## 2. Visualizando o ciclo

```text
0  -> A
1  -> B
2  -> C
...
24 -> Y
25 -> Z
26 -> A
27 -> B
28 -> C
```

Assim:

```text
26 ≡ 0 (mod 26)
27 ≡ 1 (mod 26)
28 ≡ 2 (mod 26)
```

## 3. Deslocamento de letras

Podemos deslocar uma letra somando um número.

Exemplo: deslocar `D` em `5` posições.

```text
D = 3
3 + 5 = 8
8 = I
```

Logo:

```text
D -> I
```

## 4. Quando passa do Z

Exemplo: deslocar `X` em `5` posições.

```text
X = 23
23 + 5 = 28
28 ≡ 2 (mod 26)
2 = C
```

Logo:

```text
X -> C
```

A letra passou por `Y`, `Z` e voltou ao começo do alfabeto.

## 5. Voltando no alfabeto

Também podemos deslocar para trás usando subtração.

Exemplo: voltar `5` posições a partir de `C`.

```text
C = 2
2 - 5 = -3
```

Como queremos um número entre `0` e `25`, somamos `26`:

```text
-3 + 26 = 23
23 = X
```

Logo:

```text
C -> X
```

## 6. Primeira ideia de cifragem

Uma regra de cifragem pode ser:

```text
C = P + k (mod 26)
```

em que:

```text
P é a letra original convertida para número
C é a letra cifrada convertida para número
k é o deslocamento
```

Exemplo com `k = 3`:

```text
A -> D
B -> E
C -> F
```

Essa é a estrutura matemática da cifra de César.

## 7. Exemplo guiado

Cifrar a palavra `CASA` com deslocamento `k = 3`.

Primeiro, convertemos:

```text
C = 2
A = 0
S = 18
A = 0
```

Agora somamos `3` módulo `26`:

```text
2  + 3 = 5  -> F
0  + 3 = 3  -> D
18 + 3 = 21 -> V
0  + 3 = 3  -> D
```

Logo:

```text
CASA -> FDVD
```

## 8. Decifrando por deslocamento inverso

Para desfazer um deslocamento de `3`, subtraímos `3`.

Exemplo:

```text
F = 5
5 - 3 = 2
2 = C
```

Assim:

```text
F -> C
```

## 9. Exercícios

Use `A = 0`.

### 9.1

Desloque `M` em `4` posições para frente.

### 9.2

Desloque `Y` em `5` posições para frente.

### 9.3

Desloque `B` em `4` posições para trás.

### 9.4

Cifre a palavra abaixo com deslocamento `k = 2`.

```text
ROMA
```

### 9.5

Decifre a palavra abaixo sabendo que ela foi cifrada com deslocamento `k = 2`.

```text
TQOC
```

## Gabarito

### 9.1

```text
M = 12
12 + 4 = 16
16 = Q
```

Resposta: `Q`.

### 9.2

```text
Y = 24
24 + 5 = 29
29 ≡ 3 (mod 26)
3 = D
```

Resposta: `D`.

### 9.3

```text
B = 1
1 - 4 = -3
-3 + 26 = 23
23 = X
```

Resposta: `X`.

### 9.4

```text
R = 17 -> 19 = T
O = 14 -> 16 = Q
M = 12 -> 14 = O
A = 0  -> 2  = C
```

Resposta:

```text
ROMA -> TQOC
```

### 9.5

Subtraindo `2`:

```text
T = 19 -> 17 = R
Q = 16 -> 14 = O
O = 14 -> 12 = M
C = 2  -> 0  = A
```

Resposta:

```text
TQOC -> ROMA
```
