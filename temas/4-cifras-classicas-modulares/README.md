# Tema 4 — Cifras Clássicas Modulares

Este tema aplica a aritmética modular em cifras clássicas simples.

## Objetivo do tema

Mostrar como operações matemáticas elementares podem transformar letras em novas letras, produzindo cifras de substituição com regras algébricas explícitas.

## Ordem de estudo

1. [Cifra de César](04-01-cifra-de-cesar.md)
2. [Deslocamento modular e decifragem](04-02-deslocamento-modular.md)
3. [Quebra por força bruta](04-03-quebra-por-forca-bruta.md)
4. [Cifra afim](04-04-cifra-afim.md)
5. [Condição de reversibilidade](04-05-condicao-de-reversibilidade.md)
6. [Inverso modular aplicado à decifragem](04-06-inverso-modular-na-decifragem.md)

Cada aula contém exemplos resolvidos, exercícios e gabarito comentado. A última inclui um roteiro de experimentação com [Python](../../exemplos/04-cifras-classicas.py), sem bibliotecas externas.

## Pré-requisitos e convenções

Retome os materiais sobre [letras como números](../3-aritmetica-modular/03-04-letras-como-numeros.md), [alfabeto circular](../3-aritmetica-modular/03-05-alfabeto-circular-mod-26.md) e [inverso modular](../3-aritmetica-modular/03-06-introducao-ao-inverso-modular.md).

```text
A = 0, B = 1, ..., Z = 25
Módulo = 26
Texto preparado = maiúsculas, sem acentos, espaços ou pontuação
P = número da letra original
C = número da letra cifrada
```

A decifragem recupera o texto preparado. Os acentos, espaços e sinais removidos não são reconstruídos automaticamente.

## Caminho didático

```text
somar uma chave -> desfazer a soma -> testar chaves
-> multiplicar e somar -> verificar a reversibilidade
-> desfazer a soma e a multiplicação
```

## Relação com criptografia

As cifras clássicas modulares ajudam a conectar a matemática com a ideia de chave, cifragem, decifragem e ataque. Elas também preparam o caminho para cifras que usam matrizes como chaves.

César e afim são cifras de substituição: cada letra é transformada individualmente. No [Tema 5](../5-matrizes-modulares-cifra-hill/README.md), trabalharemos com pares de letras e matrizes.

Estas cifras servem para estudar matemática e ataques. Os espaços de chaves pequenos e os padrões de substituição permitem ataques simples; elas não são adequadas para proteger dados reais.
