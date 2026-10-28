# Tema 5 — Matrizes Modulares e Cifra de Hill

Este tema retoma matrizes dentro da aritmética modular.

## Objetivo do tema

Usar matrizes como chaves de transformação para cifrar blocos de letras, chegando a uma primeira cifra simétrica baseada em álgebra linear modular.

## Ordem de estudo

1. [Mensagens em blocos numéricos](05-01-mensagens-em-blocos.md)
2. [Multiplicação de matriz por vetor módulo 26](05-02-matriz-vetor-modulo-26.md)
3. [Cifra de Hill com matriz 2 x 2](05-03-cifra-de-hill-2x2.md)
4. [Determinante de matriz 2 x 2](05-04-determinante-2x2.md)
5. [Invertibilidade módulo 26](05-05-invertibilidade-modulo-26.md)
6. [Decifragem com matriz inversa modular](05-06-decifragem-com-matriz-inversa.md)

Cada aula tem exemplos resolvidos, exercícios e gabarito comentado. O tema termina com um laboratório apoiado por [código Python](../../exemplos/05-cifra-hill.py), sem bibliotecas externas.

## Pré-requisitos

Retome a [multiplicação de matrizes do Tema 2](../2-matrizes/02-02-aula-matrizes.md), as [operações modulares](../3-aritmetica-modular/03-03-operacoes-modulares.md) e o [inverso na decifragem afim](../4-cifras-classicas-modulares/04-06-inverso-modular-na-decifragem.md).

## Convenções deste tema

```text
A = 0, B = 1, ..., Z = 25
Texto preparado = maiúsculas, sem acentos, espaços ou pontuação
Blocos = pares de letras, representados por vetores coluna
K = matriz-chave 2 x 2, multiplicada à esquerda
C ≡ K*P (mod 26)
Preenchimento = um X ao final, somente se o tamanho for ímpar
```

A orientação dos vetores faz parte da convenção. Usar vetores linha com a mesma matriz pode produzir outro resultado.

O tamanho original do texto preparado deve ser registrado quando houver preenchimento. A decifragem recupera o texto preparado com o eventual `X` adicional; o tamanho permite remover apenas esse preenchimento, preservando letras `X` legítimas.

## Caminho didático

Retomamos a chave `[[3, 2], [1, 1]]` e a mensagem `EUAMOBR`, usadas na aula de matrizes. Primeiro fazemos a cifragem; depois construímos as ferramentas para justificar a escolha da chave e recuperar a mensagem.

Também estudamos `[[3, 3], [2, 5]]`, cujo determinante é `9`, para praticar um caso em que é necessário calcular um inverso escalar diferente de `1`.

## Relação com criptografia

A Cifra de Hill mostra como uma transformação matricial pode misturar letras de uma mensagem. Para que a mensagem possa ser recuperada, a matriz usada como chave precisa ser invertível no módulo escolhido.

A mistura de letras não garante segurança. A estrutura linear de Hill permite recuperar a chave a partir de blocos originais e cifrados adequados; a última aula apresenta esse ataque em um exemplo. O uso aqui é didático.
