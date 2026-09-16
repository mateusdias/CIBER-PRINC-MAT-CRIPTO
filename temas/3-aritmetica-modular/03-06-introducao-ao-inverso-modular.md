# Tema 3 — Introdução ao Inverso Modular

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Aritmética modular: introdução ao inverso modular

## 1. Ideia central

Em muitas cifras, cifrar uma mensagem significa aplicar uma operação matemática.

Para decifrar, precisamos desfazer essa operação.

Na soma, desfazer é simples:

```text
C = P + 3 (mod 26)
```

Para voltar:

```text
P = C - 3 (mod 26)
```

Mas na multiplicação modular, desfazer exige mais cuidado.

## 2. O que é inverso modular?

O inverso modular de um número `a` módulo `n` é um número `b` tal que:

```text
a * b ≡ 1 (mod n)
```

Nesse caso, dizemos que:

```text
b é o inverso de a módulo n
```

ou:

```text
a^(-1) ≡ b (mod n)
```

## 3. Exemplo em módulo 26

Queremos encontrar o inverso de `3` módulo `26`.

Procuramos um número `b` tal que:

```text
3 * b ≡ 1 (mod 26)
```

Testando alguns valores:

```text
3 * 1 = 3
3 * 2 = 6
3 * 3 = 9
...
3 * 9 = 27
```

Como:

```text
27 ≡ 1 (mod 26)
```

temos:

```text
3 * 9 ≡ 1 (mod 26)
```

Logo, o inverso de `3` módulo `26` é `9`.

## 4. Por que o inverso modular é importante?

Suponha uma regra de cifragem:

```text
C = 3P (mod 26)
```

Para recuperar `P`, precisamos desfazer a multiplicação por `3`.

Como o inverso de `3` módulo `26` é `9`, multiplicamos por `9`:

```text
9C ≡ 9 * 3P (mod 26)
9C ≡ 27P (mod 26)
```

Como:

```text
27 ≡ 1 (mod 26)
```

então:

```text
9C ≡ P (mod 26)
```

Assim, multiplicar por `9` desfaz a multiplicação por `3`.

## 5. Nem todo número tem inverso modular

Nem todo número possui inverso em um determinado módulo.

Exemplo: `2` não tem inverso módulo `26`.

Se tentarmos:

```text
2 * b ≡ 1 (mod 26)
```

teríamos que encontrar um múltiplo de `2` que deixasse resto `1` na divisão por `26`.

Mas múltiplos de `2` são pares, e números congruentes a `1` módulo `26` são ímpares:

```text
1, 27, 53, 79, ...
```

Então não existe esse `b`.

## 6. Condição para existir inverso

Um número `a` tem inverso módulo `n` quando `a` e `n` são primos entre si.

Ou seja:

```text
mdc(a, n) = 1
```

Exemplos em módulo `26`:

```text
3 tem inverso módulo 26, pois mdc(3, 26) = 1.
5 tem inverso módulo 26, pois mdc(5, 26) = 1.
13 não tem inverso módulo 26, pois mdc(13, 26) = 13.
2 não tem inverso módulo 26, pois mdc(2, 26) = 2.
```

## 7. Lista de números com inverso módulo 26

Os números entre `0` e `25` que têm inverso módulo `26` são:

```text
1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25
```

Esses números são justamente os que não compartilham fator comum com `26`.

Como:

```text
26 = 2 * 13
```

os números que têm inverso módulo `26` não podem ser divisíveis por `2` nem por `13`.

## 8. Relação com a cifra afim

A cifra afim usa uma regra do tipo:

```text
C = aP + b (mod 26)
```

Para essa cifra poder ser decifrada, o número `a` precisa ter inverso módulo `26`.

Se `a` não tiver inverso, letras diferentes podem acabar produzindo a mesma letra cifrada, e a mensagem original pode não ser recuperável de forma única.

## 9. Relação com a Cifra de Hill

Na Cifra de Hill, a chave é uma matriz.

Para decifrar, precisamos da matriz inversa módulo `26`.

Assim como alguns números não têm inverso modular, algumas matrizes também não têm inversa modular.

Por isso, estudar inverso modular agora prepara o caminho para as matrizes modulares.

## 10. Exercícios

### 10.1

Verifique se `5` é inversível módulo `26`.

### 10.2

Encontre o inverso de `5` módulo `26`.

### 10.3

Verifique se `13` é inversível módulo `26`.

### 10.4

Verifique se `7` é inversível módulo `26`.

### 10.5

Encontre o inverso de `7` módulo `26`.

## Gabarito

### 10.1

Sim. Como `mdc(5, 26) = 1`, o número `5` tem inverso módulo `26`.

### 10.2

Procuramos `b` tal que:

```text
5b ≡ 1 (mod 26)
```

Testando:

```text
5 * 21 = 105
105 = 26 * 4 + 1
```

Logo:

```text
5^(-1) ≡ 21 (mod 26)
```

### 10.3

Não. Como `mdc(13, 26) = 13`, o número `13` não tem inverso módulo `26`.

### 10.4

Sim. Como `mdc(7, 26) = 1`, o número `7` tem inverso módulo `26`.

### 10.5

Procuramos `b` tal que:

```text
7b ≡ 1 (mod 26)
```

Testando:

```text
7 * 15 = 105
105 = 26 * 4 + 1
```

Logo:

```text
7^(-1) ≡ 15 (mod 26)
```
