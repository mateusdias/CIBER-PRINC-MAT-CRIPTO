# Tema 5 — Decifragem com Matriz Inversa Modular

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Cifra de Hill: recuperação da mensagem e limites da transformação linear

## 1. A fórmula de decifragem

Se a cifragem é:

```text
C ≡ K*P (mod 26)
```

multiplicamos à esquerda pela inversa:

```text
K^(-1)*C ≡ K^(-1)*K*P (mod 26)
K^(-1)*C ≡ I*P (mod 26)
K^(-1)*C ≡ P (mod 26)
```

Portanto:

```text
P ≡ K^(-1)*C (mod 26)
```

A ordem dos fatores precisa ser mantida. Não tentamos uma divisão comum de vetores ou matrizes.

## 2. Exemplo completo: AYYMSPTO

Usamos a chave das primeiras aulas e a inversa calculada na aula anterior:

```text
K = [3  2]        K^(-1) = [ 1  24]
    [1  1]                 [25   3]
```

Separamos o texto cifrado em pares, mantendo o alinhamento:

```text
AY | YM | SP | TO
```

### Primeiro bloco: AY

```text
A = 0
Y = 24

K^(-1)*C = [ 1   24 ] [  0 ]
            [25    3 ] [ 24 ]

          = [ 1*0 + 24*24 ] = [576]
            [25*0 +  3*24 ]   [ 72]

576 = 26 * 22 + 4
72  = 26 * 2 + 20

P = [ 4] -> E
    [20] -> U
```

### Todos os blocos

| Bloco cifrado | Vetor | Produto pela inversa | Restos por 26 | Bloco recuperado |
|---|---|---|---|---|
| AY | `[0, 24]` | `[576, 72]` | `[4, 20]` | EU |
| YM | `[24, 12]` | `[312, 636]` | `[0, 12]` | AM |
| SP | `[18, 15]` | `[378, 495]` | `[14, 1]` | OB |
| TO | `[19, 14]` | `[355, 517]` | `[17, 23]` | RX |

Juntando:

```text
AYYMSPTO -> EUAMOBRX
```

O comprimento original informado era `7`. Portanto, removemos exatamente o último caractere, acrescentado no preenchimento:

```text
Texto preparado recuperado: EUAMOBR
```

Os espaços e a pontuação originais não fazem parte dessa recuperação.

## 3. Outro exemplo: chave com determinante 9

Agora usamos:

```text
H = [3  3]        H^(-1) = [15  17]
    [2  5]                 [20   9]
```

Vamos cifrar `HI`:

```text
H como letra = 7
I como letra = 8

H*[7, 8] = [3*7 + 3*8, 2*7 + 5*8]
         = [45, 54]
         ≡ [19, 2] -> TC
```

Na volta:

```text
H^(-1)*[19, 2] = [15*19 + 17*2, 20*19 + 9*2]
                = [319, 398]

319 = 26 * 12 + 7
398 = 26 * 15 + 8

TC -> HI
```

O inverso de `9` já foi incorporado à matriz de decifragem. Não precisamos repeti-lo a cada bloco.

## 4. Quando o preenchimento é ambíguo

Se recuperarmos `SOLX`, há pelo menos duas possibilidades antes do preenchimento:

```text
SOL, com X acrescentado
SOLX, sem preenchimento
```

Sem a informação de comprimento, não podemos decidir apenas olhando as letras. Nosso procedimento recebe o comprimento do texto preparado antes de completar o último bloco.

Se a mensagem original terminava em `X`, esse `X` precisa ser preservado. Apagar todos os `X` finais corromperia mensagens legítimas.

## 5. Reversibilidade não garante segurança

Hill mistura letras, mas a transformação é linear. Se um adversário conhecer blocos originais e seus blocos cifrados correspondentes, pode montar equações para descobrir a chave.

Vamos mostrar isso com dois pares conhecidos, usando a chave das primeiras aulas:

```text
BA = [1, 0] -> [3, 1] -> DB
BB = [1, 1] -> [5, 2] -> FC
```

Organizando os blocos originais e cifrados como colunas:

```text
P = [1  1]       C = [3  5]
    [0  1]           [1  2]
```

Sabemos que `C ≡ K*P`. Como `det(P) = 1`, `P` tem inversa modular:

```text
P^(-1) = [1  25]
         [0   1]
```

Multiplicamos **à direita** por essa inversa para isolar a chave:

```text
K ≡ C*P^(-1) (mod 26)

K ≡ [3  5] [1  25] = [3   80] ≡ [3  2] (mod 26)
    [1  2] [0   1]   [1   27]   [1  1]
```

Recuperamos a matriz-chave. O exemplo mostra um ataque com texto claro conhecido: o adversário não precisou receber a chave diretamente.

Não basta escolher quaisquer dois blocos conhecidos para usar essa fórmula. As colunas originais precisam formar uma matriz `P` invertível módulo `26`. Se não formarem, esse cálculo direto não se aplica; pode ser necessário obter outros blocos ou resolver as restrições por outro método.

## 6. Laboratório em Python

O arquivo [05-cifra-hill.py](../../exemplos/05-cifra-hill.py) implementa a multiplicação modular, o determinante, a inversa `2 x 2`, a cifragem e a decifragem. O programa usa apenas a biblioteca padrão.

Na raiz do repositório:

```bash
python3 exemplos/05-cifra-hill.py
```

Entre os resultados esperados:

```text
Texto preparado: EUAMOBR
Comprimento original: 7
Texto cifrado: AYYMSPTO
Decifrado com preenchimento: EUAMOBRX
Decifrado sem preenchimento: EUAMOBR
```

Roteiro de investigação:

1. Cifre `MATEMATICA` e compare com `KMNXKMVBGC`.
2. Cifre e decifre mensagens com comprimentos pares e ímpares.
3. Teste `SOLX` e confira que o `X` original é preservado quando o comprimento é informado.
4. Troque a chave para `[[3, 3], [2, 5]]` e confira `HI -> TC -> HI`.
5. Tente usar `[[2, 0], [0, 1]]`. Explique por que o programa rejeita a chave.

O código deixa o texto decifrado com preenchimento quando o comprimento original não é fornecido. Essa escolha evita apagar letras sem informação suficiente.

## 7. Erros frequentes e como conferir

| Situação | Como conferir |
|---|---|
| Blocos recuperados não fazem sentido | Verifique `A = 0`, a chave e o alinhamento dos pares |
| Inversa calculada com frações reais | Use o inverso modular do determinante |
| Só alguns elementos da adjunta foram multiplicados | Aplique o fator a todos os quatro elementos |
| Resultado numérico fora de 0 a 25 | Reduza cada coordenada módulo 26 |
| Letras trocadas na reconstrução | Leia por colunas, de cima para baixo |
| Última letra legítima desapareceu | Remova preenchimento apenas com o comprimento original |

O primeiro teste da chave inversa é multiplicá-la pela chave original e obter a identidade módulo `26`. Depois, confira uma mensagem de ida e volta.

## 8. Exercícios

### 8.1

Decifre `GCCS` com `K = [[3, 2], [1, 1]]`.

### 8.2

Decifre `EGBI` com a mesma chave. O comprimento original informado é `3`. Mostre a saída antes e depois de remover o preenchimento.

### 8.3

Decifre `GECK` com `H = [[3, 3], [2, 5]]`.

### 8.4

Um adversário sabe que os blocos `BA` e `AB` foram cifrados como `DB` e `CB`, respectivamente. Usando a estrutura dos vetores, descubra a chave `2 x 2`.

### 8.5

Por que conhecer os pares `AA -> AA` e `AB -> CB` não determina diretamente as quatro entradas da chave?

### 8.6

Compare o papel do inverso modular na cifra afim com o papel da inversa matricial na Cifra de Hill.

## Gabarito comentado

### 8.1

Com `K^(-1) = [[1, 24], [25, 3]]`:

```text
GC = [6, 2]  -> [54, 156] -> [2, 0]  -> CA
CS = [2, 18] -> [434, 104] -> [18, 0] -> SA

GCCS -> CASA
```

### 8.2

```text
EG = [4, 6] -> [148, 118] -> [18, 14] -> SO
BI = [1, 8] -> [193, 49]  -> [11, 23] -> LX
```

Obtemos `SOLX`. O comprimento original é `3`, então removemos apenas o último `X` e recuperamos `SOL`.

### 8.3

Com `H^(-1) = [[15, 17], [20, 9]]`:

```text
GE = [6, 4]  -> [158, 156] -> [2, 0]  -> CA
CK = [2, 10] -> [200, 130] -> [18, 0] -> SA

GECK -> CASA
```

### 8.4

O vetor de `BA` é `[1, 0]`. Multiplicar a chave por esse vetor seleciona sua primeira coluna, portanto essa coluna é `[3, 1]`, correspondente a `DB`.

O vetor de `AB` é `[0, 1]` e seleciona a segunda coluna. Como a saída é `CB`, essa coluna é `[2, 1]`.

Logo, a chave é `[[3, 2], [1, 1]]` módulo `26`.

### 8.5

`AA` é o vetor zero, que vira zero com qualquer matriz linear. Esse par não traz restrições sobre a chave. `AB` revela apenas a segunda coluna; a primeira continua desconhecida. A matriz de blocos originais teria determinante zero e não poderia ser invertida.

### 8.6

Na afim, o inverso escalar de `a` desfaz a multiplicação de um número, depois de subtrair `b`. Em Hill, a inversa de `K` desfaz a transformação de um vetor inteiro. Para construir essa matriz inversa, precisamos do inverso escalar de seu determinante.

**Retomar a sequência:** [Visão geral do Tema 5](README.md).
