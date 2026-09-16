# Tema 3 — Aritmética Modular

Este tema introduz a ideia de cálculo com restos, congruências e operações em conjuntos finitos.

## Objetivo do tema

Preparar a base matemática para cifras que trabalham com alfabetos finitos, como a cifra de César, a cifra afim e, mais adiante, a Cifra de Hill.

## Tópicos previstos

1. [Resto da divisão](03-01-resto-da-divisao.md)
2. [Congruência módulo `n`](03-02-congruencia-modulo-n.md)
3. [Soma, subtração e multiplicação modular](03-03-operacoes-modulares.md)
4. [Representação de letras como números](03-04-letras-como-numeros.md)
5. [Alfabeto circular e operações módulo 26](03-05-alfabeto-circular-mod-26.md)
6. [Introdução ao inverso modular](03-06-introducao-ao-inverso-modular.md)

## Relação com criptografia

A aritmética modular permite transformar mensagens sem sair do conjunto de símbolos permitido. Em vez de números crescerem indefinidamente, os resultados retornam para um intervalo fixo, como `0` a `25` no caso de um alfabeto com 26 letras.

## Caminho didático

O tema começa com restos de divisão, avança para congruências e operações modulares, depois conecta esses conceitos à representação numérica de letras.

Ao final, o estudante deve conseguir entender por que cifras simples como César e cifras um pouco mais estruturadas como a cifra afim dependem de contas módulo 26. Esse mesmo raciocínio será retomado depois nas matrizes modulares e na Cifra de Hill.
