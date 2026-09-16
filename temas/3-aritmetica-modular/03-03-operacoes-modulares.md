# Tema 3 — Operações Modulares

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Aritmética modular: soma, subtração e multiplicação

## 1. Ideia central

Em aritmética modular, fazemos a conta normalmente e depois reduzimos o resultado pelo resto da divisão.

Exemplo:

```text
8 + 7 = 15
15 ≡ 3 (mod 12)
```

Então, em módulo `12`:

```text
8 + 7 ≡ 3 (mod 12)
```

## 2. Soma modular

Para somar módulo `n`:

1. Somamos normalmente.
2. Dividimos o resultado por `n`.
3. Ficamos com o resto.

Exemplo:

```text
20 + 15 = 35
35 = 26 * 1 + 9
```

Logo:

```text
20 + 15 ≡ 9 (mod 26)
```

## 3. Subtração modular

Na subtração, também podemos obter valores negativos.

Exemplo:

```text
3 - 8 = -5
```

Em módulo `26`, queremos um resultado entre `0` e `25`.

Para encontrar um representante positivo, somamos `26`:

```text
-5 + 26 = 21
```

Logo:

```text
3 - 8 ≡ 21 (mod 26)
```

Isso faz sentido porque:

```text
21 - (-5) = 26
```

Então `21` e `-5` são congruentes módulo `26`.

## 4. Multiplicação modular

Para multiplicar módulo `n`:

1. Multiplicamos normalmente.
2. Reduzimos o resultado pelo resto da divisão por `n`.

Exemplo:

```text
7 * 8 = 56
56 = 26 * 2 + 4
```

Logo:

```text
7 * 8 ≡ 4 (mod 26)
```

## 5. Podemos reduzir antes ou depois

Às vezes, é mais fácil reduzir os números antes de fazer a conta.

Exemplo:

```text
31 + 48 (mod 10)
```

Como:

```text
31 ≡ 1 (mod 10)
48 ≡ 8 (mod 10)
```

podemos fazer:

```text
1 + 8 = 9
```

Então:

```text
31 + 48 ≡ 9 (mod 10)
```

Se fizermos direto:

```text
31 + 48 = 79
79 ≡ 9 (mod 10)
```

O resultado é o mesmo.

## 6. Por que isso importa para criptografia?

Em uma cifra que trabalha com letras, usamos um conjunto finito.

Se representarmos as letras por números de `0` a `25`, qualquer conta precisa terminar dentro desse intervalo.

A aritmética modular permite que isso aconteça.

Exemplo:

```text
X = 23
deslocamento = 5
23 + 5 = 28
28 ≡ 2 (mod 26)
```

O número `2` representa `C`.

Então, ao deslocar `X` em 5 posições, voltamos para o começo do alfabeto e chegamos em `C`.

## 7. Exercícios

### 7.1

Calcule:

```text
9 + 8 (mod 12)
```

### 7.2

Calcule:

```text
4 - 9 (mod 12)
```

### 7.3

Calcule:

```text
6 * 7 (mod 10)
```

### 7.4

Calcule:

```text
23 + 11 (mod 26)
```

### 7.5

Calcule:

```text
5 - 12 (mod 26)
```

### 7.6

Calcule:

```text
15 * 4 (mod 26)
```

## Gabarito

### 7.1

```text
9 + 8 = 17
17 ≡ 5 (mod 12)
```

Resposta: `5`.

### 7.2

```text
4 - 9 = -5
-5 + 12 = 7
```

Resposta: `7`.

### 7.3

```text
6 * 7 = 42
42 ≡ 2 (mod 10)
```

Resposta: `2`.

### 7.4

```text
23 + 11 = 34
34 ≡ 8 (mod 26)
```

Resposta: `8`.

### 7.5

```text
5 - 12 = -7
-7 + 26 = 19
```

Resposta: `19`.

### 7.6

```text
15 * 4 = 60
60 = 26 * 2 + 8
```

Resposta: `8`.
