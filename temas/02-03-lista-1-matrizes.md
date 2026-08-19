# Tema 2 — Lista 1: Matrizes

## Identificação

**Pontifícia Universidade Católica de Campinas**  
**Escola Politécnica**  
**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  

## Lista 1

## 1. Construção de matrizes

Escrever a matriz `A = (a_ij)` nos seguintes casos.

### 1.1

`A` é do tipo `3 x 2`, com:

```text
a_ij = 5, para i != j
a_ij = 3, para i = j
```

### 1.2

`A` é de 3ª ordem, com:

```text
a_ij = 1, para i = j
a_ij = 0, para i != j
```

### 1.3

`A` é uma matriz do tipo `2 x 3`, com:

```text
a_ij = 4, para i > j
a_ij = 5, para i < j
a_ij = 8, para i = j
```

## 2. Igualdade de matrizes

Determinar os valores de `x`, `y`, `z` e `v` para que as matrizes sejam iguais.

```text
[ 2x       8       ]   [ 10      y - 2z ]
[ 3        expressão ] = [  3          23 ]
```

Observação: no arquivo original, a segunda linha da igualdade contém uma expressão algébrica envolvendo `v`. O gabarito extraído do documento indica:

```text
x = 5
y = 10
z = ±6
v_1 = 4
v_2 = -1
```

## 3. Operações com matrizes

Dadas as matrizes:

```text
A = [ 5    2 ]
    [ 0   -7 ]

B = [ 3    6 ]
    [ -4   1 ]
```

Calcular:

### 3.1

```text
A + B
```

### 3.2

```text
A - B
```

### 3.3

```text
3A
```

## 4. Combinação linear de matrizes

Dadas as matrizes:

```text
A = [  3    5 ]
    [ -2    4 ]

B = [ -1   -3 ]
    [  6    7 ]
```

Determinar `X` tal que:

```text
X = 2A - 4B
```

## 5. Operações possíveis

Dadas as matrizes:

```text
A = [  1    2 ]
    [ -1    0 ]
    [  3   -2 ]

B = [  0   -2 ]
    [  4    5 ]
    [ -2   -3 ]

C = [  1    1 ]
    [ -1    4 ]

D = [  2   -1    0 ]
    [  5    6    1 ]
```

Calcule, se possível, as matrizes abaixo.

### 5.1

```text
A + B
```

### 5.2

```text
B - 2A
```

### 5.3

```text
AB
```

### 5.4

```text
BC
```

### 5.5

```text
DB + 3C
```

### 5.6

```text
CD
```

### 5.7

```text
AD
```

## Gabarito

### 1.1

```text
A = [ 3   5 ]
    [ 5   3 ]
    [ 5   5 ]
```

### 1.2

```text
I_3 = [ 1   0   0 ]
      [ 0   1   0 ]
      [ 0   0   1 ]
```

### 1.3

```text
A = [ 8   5   5 ]
    [ 4   8   5 ]
```

### 2

```text
x = 5
y = 10
z = ±6
v_1 = 4
v_2 = -1
```

### 3.1

```text
A + B = [  8    8 ]
        [ -4   -6 ]
```

### 3.2

```text
A - B = [  2   -4 ]
        [  4   -8 ]
```

### 3.3

```text
3A = [ 15    6 ]
     [  0  -21 ]
```

### 4

```text
X = [ 10   22 ]
    [ -28 -20 ]
```

### 5.1

```text
A + B = [  1    0 ]
        [  3    5 ]
        [  1   -5 ]
```

### 5.2

```text
B - 2A = [ -2   -6 ]
         [  6    5 ]
         [ -8    1 ]
```

### 5.3

```text
AB não é possível.
```

A matriz `A` é `3 x 2` e a matriz `B` é `3 x 2`. Para calcular `AB`, o número de colunas de `A` deveria ser igual ao número de linhas de `B`.

### 5.4

```text
BC = [  2   -8 ]
     [ -1   24 ]
     [  1  -14 ]
```

A matriz `B` é `3 x 2` e a matriz `C` é `2 x 2`. O produto `BC` é possível e tem dimensão `3 x 2`.

### 5.5

```text
DB + 3C = [ -1   -6 ]
          [ 19   29 ]
```

### 5.6

```text
CD = [  7    5    1 ]
     [ 18   25    4 ]
```

### 5.7

```text
AD = [ 12   11    2 ]
     [ -2    1    0 ]
     [ -4  -15   -2 ]
```

## Observação sobre o gabarito

A transcrição do arquivo `.docx` foi convertida para Markdown a partir do conteúdo interno do documento. Algumas expressões matemáticas do arquivo original foram armazenadas em formato de equação do Word e exigiram reconstituição textual para ficarem legíveis em Markdown.
