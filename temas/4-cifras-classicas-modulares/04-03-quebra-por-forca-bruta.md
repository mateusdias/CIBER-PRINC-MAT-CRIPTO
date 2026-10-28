# Tema 4 — Quebra por Força Bruta

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Cifras clássicas modulares: busca de chaves e análise de resultados

## 1. E se a chave não for conhecida?

Quem recebe legitimamente a mensagem usa a chave combinada. Um adversário pode tentar recuperá-la explorando o algoritmo e os padrões do texto.

Na cifra de deslocamento, há apenas `26` chaves distintas, incluindo a identidade. Isso permite testar todas elas.

Essa estratégia é chamada de **força bruta**. Aqui, assumimos que o adversário conhece a família da cifra, o alfabeto e a convenção `A = 0`, mas não conhece `k`.

## 2. Roteiro do ataque

```text
Entrada: texto cifrado

Para cada k de 0 até 25:
    subtrair k de cada número do texto cifrado
    reduzir módulo 26
    converter os números para letras
    guardar o par (k, texto candidato)

Examinar os candidatos usando o contexto disponível
```

Testar uma chave significa aplicá-la à mensagem inteira. Uma palavra com `L` letras exige `L` transformações por tentativa; a busca completa exige `26 * L` transformações de letras.

## 3. Exemplo resolvido: FDVD

Vamos começar com algumas tentativas:

| Chave testada | Contas dos dois primeiros símbolos | Texto candidato |
|---:|---|---|
| 0 | `5 - 0 = 5`; `3 - 0 = 3` | `FDVD` |
| 1 | `5 - 1 = 4`; `3 - 1 = 2` | `ECUC` |
| 2 | `5 - 2 = 3`; `3 - 2 = 1` | `DBTB` |
| 3 | `5 - 3 = 2`; `3 - 3 = 0` | `CASA` |
| 4 | `5 - 4 = 1`; `3 - 4 ≡ 25` | `BZRZ` |

Com `k = 3`, aparece uma palavra plausível em português:

```text
FDVD -> CASA
```

A força bruta enumera possibilidades; a avaliação do contexto ajuda a selecionar uma delas. Em uma busca completa, continuaríamos até `k = 25`.

## 4. Resultado plausível não é prova isolada

Considere o texto cifrado `D`:

```text
k = 0 -> D
k = 1 -> C
k = 2 -> B
k = 3 -> A
...
```

Uma única letra admite muitas mensagens possíveis. Mesmo uma sequência curta pode ter interpretações diferentes, como siglas e nomes próprios.

Por isso, distinguir os candidatos pode depender de:

- tamanho e idioma da mensagem;
- palavras esperadas pelo contexto;
- trechos conhecidos do texto original;
- formato esperado, como um cabeçalho combinado.

O primeiro resultado legível não necessariamente revela a chave original.

## 5. Quando uma letra original é conhecida

Se soubermos que uma determinada posição tinha `P` e virou `C`, podemos calcular:

```text
C ≡ P + k (mod 26)
k ≡ C - P (mod 26)
```

Exemplo: sabemos que `A` virou `H` naquela posição.

```text
P = 0
C = 7
k ≡ 7 - 0 ≡ 7 (mod 26)
```

O par sugere `k = 7`. Aplicamos a chave ao restante do texto para conferir a consistência. Esse cenário usa **texto claro conhecido**, uma informação adicional em relação à busca feita apenas com o texto cifrado.

## 6. Padrões que continuam visíveis

Com uma chave fixa, César substitui sempre a mesma letra pelo mesmo resultado:

```text
CASA -> FDVD
```

O padrão de repetição permanece:

```text
posição 2 = posição 4 no texto original
posição 2 = posição 4 no texto cifrado
```

As quantidades de ocorrências também são preservadas, embora associadas a outras letras. Em textos maiores, analisar frequências pode ajudar a escolher candidatos. Em textos curtos, as frequências podem ser pouco representativas.

## 7. Experimento em Python

O trecho abaixo trabalha com um texto já preparado, contendo somente `A` a `Z`:

```python
alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
texto_cifrado = "FDVD"

for chave in range(26):
    candidato = ""
    for letra in texto_cifrado:
        c = alfabeto.index(letra)
        p = (c - chave) % 26
        candidato += alfabeto[p]
    print(f"k={chave:2}: {candidato}")
```

Em Python, `% 26` devolve um resultado entre `0` e `25`, inclusive quando o valor à esquerda é negativo.

## 8. Exercícios

### 8.1

Teste as chaves `0`, `1`, `2` e `3` no texto `URPD`. Qual produz uma palavra comum em português?

### 8.2

Quantas chaves distintas existem se permitirmos qualquer chave inteira? E se excluirmos a identidade?

### 8.3

Sabemos que `M` foi transformado em `R`. Encontre a chave e confira a transformação de `Z`.

### 8.4

Uma busca encontrou um candidato legível com duas letras. Isso garante que a chave original foi descoberta? Explique.

### 8.5

Adapte o código para atacar `VHJXUDQFD`. Registre a chave do candidato `SEGURANCA` e explique por que a busca é rápida.

## Gabarito comentado

### 8.1

```text
k = 0 -> URPD
k = 1 -> TQOC
k = 2 -> SPNB
k = 3 -> ROMA
```

`ROMA` é o candidato esperado, com `k = 3`.

### 8.2

São `26` transformações distintas, pois chaves congruentes módulo `26` são equivalentes. Excluindo a identidade, são `25`.

### 8.3

```text
M = 12
R = 17
k ≡ 17 - 12 ≡ 5 (mod 26)

Z = 25 -> 25 + 5 = 30 ≡ 4 -> E
```

### 8.4

Não. Uma sequência curta pode ter diversas interpretações. É preciso usar mais contexto ou informação conhecida para distinguir os candidatos.

### 8.5

A chave é `3`. São somente `26` deslocamentos para nove letras: `26 * 9 = 234` transformações de letras.

**Próxima aula:** [Cifra afim](04-04-cifra-afim.md).
