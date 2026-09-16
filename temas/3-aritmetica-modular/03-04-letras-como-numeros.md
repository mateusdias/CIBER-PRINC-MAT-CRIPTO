# Tema 3 — Representação de Letras como Números

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Aritmética modular: letras como números

## 1. Ideia central

Para aplicar matemática em mensagens, precisamos transformar letras em números.

Essa conversão permite que operações como soma, subtração e multiplicação sejam usadas para cifrar e decifrar mensagens.

## 2. Duas formas comuns de numerar o alfabeto

Existem duas convenções bastante comuns.

### Convenção 1: A = 1

```text
A = 1
B = 2
C = 3
...
Z = 26
```

Essa convenção é intuitiva para leitura humana.

Ela aparece bastante em atividades introdutórias.

### Convenção 2: A = 0

```text
A = 0
B = 1
C = 2
...
Z = 25
```

Essa convenção é mais natural para aritmética modular, porque o conjunto de restos módulo `26` é:

```text
0, 1, 2, ..., 25
```

Por isso, em cifras modulares, geralmente usamos `A = 0`.

## 3. Tabela com A = 0

```text
A  B  C  D  E  F  G  H  I  J  K  L  M
0  1  2  3  4  5  6  7  8  9 10 11 12

N  O  P  Q  R  S  T  U  V  W  X  Y  Z
13 14 15 16 17 18 19 20 21 22 23 24 25
```

## 4. Convertendo uma palavra para números

Exemplo: converter `CRIPTO`.

Usando `A = 0`:

```text
C = 2
R = 17
I = 8
P = 15
T = 19
O = 14
```

Logo:

```text
CRIPTO -> 2, 17, 8, 15, 19, 14
```

## 5. Convertendo números para letras

Agora fazemos o caminho contrário.

Exemplo:

```text
12, 0, 19, 17, 8, 25
```

Usando a tabela:

```text
12 = M
0  = A
19 = T
17 = R
8  = I
25 = Z
```

Logo:

```text
12, 0, 19, 17, 8, 25 -> MATRIZ
```

## 6. Tratamento de espaços e acentos

Para atividades iniciais, é recomendável simplificar a mensagem:

1. Usar apenas letras maiúsculas.
2. Remover acentos.
3. Remover pontuação.
4. Tratar espaços separadamente ou remover os espaços.

Exemplo:

```text
É SEGURA?
```

pode ser preparada como:

```text
ESEGURA
```

Essa simplificação permite concentrar a atenção na matemática.

## 7. Relação com criptografia

Depois que uma mensagem vira uma sequência de números, podemos aplicar uma regra matemática.

Exemplo simples:

```text
C = P + 3 (mod 26)
```

Nessa regra:

```text
P é o número da letra original
C é o número da letra cifrada
3 é a chave de deslocamento
```

Essa é a base da cifra de César.

## 8. Exercícios

Use a convenção `A = 0`.

### 8.1

Converta a palavra abaixo para números:

```text
CHAVE
```

### 8.2

Converta a palavra abaixo para números:

```text
SEGREDO
```

### 8.3

Converta os números abaixo para letras:

```text
2, 14, 3, 8, 6, 14
```

### 8.4

Converta os números abaixo para letras:

```text
0, 17, 8, 19, 12, 4, 19, 8, 2, 0
```

### 8.5

Prepare a frase abaixo para uso em uma cifra modular:

```text
Matemática é poder!
```

## Gabarito

### 8.1

```text
CHAVE -> 2, 7, 0, 21, 4
```

### 8.2

```text
SEGREDO -> 18, 4, 6, 17, 4, 3, 14
```

### 8.3

```text
2, 14, 3, 8, 6, 14 -> CODIGO
```

### 8.4

```text
0, 17, 8, 19, 12, 4, 19, 8, 2, 0 -> ARITMETICA
```

### 8.5

Uma preparação possível:

```text
MATEMATICAEPODER
```
