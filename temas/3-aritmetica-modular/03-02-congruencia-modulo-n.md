# Tema 3 — Congruência Módulo n

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Aritmética modular: congruência módulo `n`

## 1. Ideia central

Dizemos que dois números são **congruentes módulo `n`** quando deixam o mesmo resto ao serem divididos por `n`.

Exemplo:

```text
17 e 5 deixam o mesmo resto quando divididos por 12.
```

De fato:

```text
17 = 12 * 1 + 5
5  = 12 * 0 + 5
```

Então escrevemos:

```text
17 ≡ 5 (mod 12)
```

Lê-se: `17` é congruente a `5` módulo `12`.

## 2. O que significa o símbolo de congruência ≡

O símbolo `≡` indica uma igualdade dentro de um sistema modular.

Quando escrevemos:

```text
a ≡ b (mod n)
```

estamos dizendo que `a` e `b` têm o mesmo resto na divisão por `n`.

Exemplo:

```text
29 ≡ 1 (mod 7)
```

porque:

```text
29 = 7 * 4 + 1
```

## 3. Exemplos

### Exemplo 1

```text
14 ≡ 2 (mod 12)
```

porque:

```text
14 = 12 * 1 + 2
```

### Exemplo 2

```text
38 ≡ 3 (mod 5)
```

porque:

```text
38 = 5 * 7 + 3
```

### Exemplo 3

```text
26 ≡ 0 (mod 26)
```

porque:

```text
26 = 26 * 1 + 0
```

### Exemplo 4

```text
27 ≡ 1 (mod 26)
```

porque:

```text
27 = 26 * 1 + 1
```

## 4. Números diferentes podem representar a mesma posição

No módulo `26`, os números abaixo são todos congruentes a `3`:

```text
3, 29, 55, 81, ...
```

Isso acontece porque:

```text
29 = 26 * 1 + 3
55 = 26 * 2 + 3
81 = 26 * 3 + 3
```

Então:

```text
3 ≡ 29 ≡ 55 ≡ 81 (mod 26)
```

Em criptografia, isso permite fazer contas grandes e depois reduzir o resultado para uma posição válida do alfabeto.

## 5. Uma forma alternativa de verificar

Também podemos dizer que:

```text
a ≡ b (mod n)
```

quando `a - b` é divisível por `n`.

Exemplo:

```text
29 ≡ 1 (mod 7)
```

porque:

```text
29 - 1 = 28
```

e `28` é divisível por `7`.

## 6. Congruência e ciclos

Congruência aparece sempre que temos ciclos.

Um relógio de 12 horas é um sistema módulo `12`.

O alfabeto com 26 letras pode ser visto como um sistema módulo `26`.

Se uma letra anda além do `Z`, ela volta para o começo do alfabeto.

## 7. Exercícios

### 7.1

Complete:

```text
19 ≡ ___ (mod 12)
```

### 7.2

Complete:

```text
45 ≡ ___ (mod 10)
```

### 7.3

Verifique se a afirmação é verdadeira:

```text
34 ≡ 4 (mod 10)
```

### 7.4

Verifique se a afirmação é verdadeira:

```text
41 ≡ 6 (mod 7)
```

### 7.5

Escreva três números positivos diferentes que sejam congruentes a `2` módulo `5`.

## Gabarito

### 7.1

```text
19 = 12 * 1 + 7
```

Logo:

```text
19 ≡ 7 (mod 12)
```

### 7.2

```text
45 = 10 * 4 + 5
```

Logo:

```text
45 ≡ 5 (mod 10)
```

### 7.3

Verdadeira, pois `34` deixa resto `4` na divisão por `10`.

### 7.4

Verdadeira, pois:

```text
41 = 7 * 5 + 6
```

### 7.5

Exemplo:

```text
2, 7, 12
```

Todos deixam resto `2` na divisão por `5`.
