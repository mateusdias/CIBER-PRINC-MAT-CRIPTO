# Tema 5 — Cifra de Hill com Matriz 2 x 2

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Cifra de Hill: cifragem de mensagens completas

## 1. Organizando o procedimento inteiro

A Cifra de Hill usa uma matriz como chave para transformar blocos de letras. Neste tema, trabalhamos com blocos de tamanho `2` e módulo `26`.

```text
Mensagem -> preparação -> preenchimento, se necessário
-> pares de letras -> vetores coluna
-> multiplicação pela chave -> redução módulo 26
-> conversão para letras -> texto cifrado
```

A mesma chave é aplicada a todos os blocos. As aulas seguintes ensinam a verificar se essa chave permite decifrar. Por enquanto, usamos uma matriz que já sabemos ser válida:

```text
K = [ 3   2 ]
    [ 1   1 ]
```

## 2. Exemplo completo: EUAMOBR

Retomamos a mensagem da aula de matrizes:

```text
Texto preparado:       EUAMOBR
Comprimento original:  7
Texto com preenchimento: EUAMOBRX
Blocos: EU | AM | OB | RX
```

Todos os produtos abaixo seguem a regra de linha por coluna:

| Bloco | Vetor de entrada | Primeira conta | Segunda conta | Vetor reduzido | Saída |
|---|---|---|---|---|---|
| EU | `[4, 20]` | `3*4 + 2*20 = 52` | `4 + 20 = 24` | `[0, 24]` | AY |
| AM | `[0, 12]` | `3*0 + 2*12 = 24` | `0 + 12 = 12` | `[24, 12]` | YM |
| OB | `[14, 1]` | `3*14 + 2*1 = 44` | `14 + 1 = 15` | `[18, 15]` | SP |
| RX | `[17, 23]` | `3*17 + 2*23 = 97` | `17 + 23 = 40` | `[19, 14]` | TO |

As listas entre colchetes na tabela abreviam vetores coluna, sem alterar a convenção.

Concatenando os blocos na ordem:

```text
EU | AM | OB | RX
AY | YM | SP | TO

EUAMOBR -> AYYMSPTO
```

O texto cifrado tem oito letras porque houve uma letra de preenchimento antes da cifragem. O `X` não aparece diretamente no final do texto cifrado: ele participou da transformação do bloco `RX`.

## 3. O mesmo cálculo em uma matriz de blocos

Podemos fazer todos os blocos de uma vez:

```text
P = [  4    0   14   17 ]
    [ 20   12    1   23 ]

K*P = [ 3   2 ] [  4    0   14   17 ]
      [ 1   1 ] [ 20   12    1   23 ]

    = [ 52   24   44   97 ]
      [ 24   12   15   40 ]

C   = [  0   24   18   19 ]  (mod 26)
      [ 24   12   15   14 ]
```

Lendo por colunas, obtemos `AY`, `YM`, `SP`, `TO`. Fazer um produto matricial maior equivale a aplicar a chave a cada coluna separadamente.

## 4. Exemplo completo: MATEMATICA

O desafio proposto no Tema 2 pode agora ser resolvido sistematicamente:

```text
MATEMATICA -> MA | TE | MA | TI | CA
Comprimento: 10, sem preenchimento
```

| Bloco | Números | Produto antes do módulo | Restos | Saída |
|---|---|---|---|---|
| MA | `[12, 0]` | `[36, 12]` | `[10, 12]` | KM |
| TE | `[19, 4]` | `[65, 23]` | `[13, 23]` | NX |
| MA | `[12, 0]` | `[36, 12]` | `[10, 12]` | KM |
| TI | `[19, 8]` | `[73, 27]` | `[21, 1]` | VB |
| CA | `[2, 0]` | `[6, 2]` | `[6, 2]` | GC |

Resultado:

```text
MATEMATICA -> KMNXKMVBGC
```

O bloco `MA` aparece duas vezes e vira `KM` nas duas posições. Hill, nessa forma básica, transforma blocos iguais em blocos iguais.

## 5. Mesma letra em blocos diferentes

Compare:

```text
CA = [2, 0] -> [6, 2] -> GC
CO = [2, 14] -> [34, 16] -> [8, 16] -> IQ
```

O `C` inicial participou de saídas diferentes porque seu parceiro mudou. Hill transforma pares completos; não há uma tabela fixa de substituição de letras individuais como na cifra afim.

Isso não elimina todos os padrões: os pares completos continuam sujeitos a uma regra fixa.

## 6. O que significa ser uma cifra simétrica?

As partes autorizadas compartilham a matriz-chave `K` e as convenções. Para decifrar, calculam `K^(-1)` a partir de `K`, quando essa inversa existe.

Embora as matrizes de cifragem e decifragem possam ser diferentes, uma é calculada facilmente a partir da outra. O sistema depende de um segredo compartilhado, e não de um par de chave pública e chave privada.

## 7. Exercícios

Use a chave `[[3, 2], [1, 1]]`.

### 7.1

Cifre `CASA`, apresentando os dois blocos e as contas.

### 7.2

Cifre `SOL`. Registre o comprimento original, o preenchimento e a saída.

### 7.3

Cifre `MAMA`. O que você observa nos blocos de saída?

### 7.4

Em `MATEMATICA`, por que `MA` e `TI` exigem cálculos separados, enquanto a segunda ocorrência de `MA` pode ser conferida pelo primeiro resultado?

### 7.5

Uma mensagem preparada tem `13` letras. Quantas letras e quantos blocos terá o texto cifrado nesta convenção?

## Gabarito comentado

### 7.1

```text
CA = [2, 0]  -> [3*2 + 2*0, 2 + 0]   = [6, 2]   -> GC
SA = [18, 0] -> [3*18 + 2*0, 18 + 0] = [54, 18] -> [2, 18] -> CS

CASA -> GCCS
```

### 7.2

```text
SOL -> SOLX
Comprimento original: 3
Blocos: SO | LX

SO = [18, 14] -> [82, 32] -> [4, 6] -> EG
LX = [11, 23] -> [79, 34] -> [1, 8] -> BI

SOL -> EGBI
```

### 7.3

```text
MA -> KM
MA -> KM

MAMA -> KMKM
```

Blocos iguais produzem blocos iguais com a mesma chave e o mesmo alinhamento.

### 7.4

`MA` e `TI` correspondem a vetores diferentes. As duas ocorrências de `MA` são o mesmo vetor e recebem a mesma transformação; portanto, precisam produzir a mesma saída.

### 7.5

Será acrescentado um `X`, totalizando `14` letras e `7` blocos. Cada bloco de duas letras produz exatamente duas letras cifradas.

**Próxima aula:** [Determinante de matriz 2 x 2](05-04-determinante-2x2.md).
