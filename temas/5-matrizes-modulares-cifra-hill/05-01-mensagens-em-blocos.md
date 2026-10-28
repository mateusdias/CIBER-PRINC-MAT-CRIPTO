# Tema 5 — Mensagens em Blocos Numéricos

## Identificação

**Componente curricular:** Princípios Matemáticos de Criptografia  
**Semestre:** 2º semestre de 2026  
**Tema:** Matrizes modulares: representação de pares de letras

## 1. De uma letra para um bloco

No Tema 4, cada letra era transformada separadamente. Na Cifra de Hill que estudaremos, a transformação recebe duas letras de uma vez.

```text
César e afim: uma letra -> uma letra
Hill 2 x 2:   duas letras -> duas letras
```

O tamanho do bloco precisa ser compatível com a dimensão da matriz-chave. Com uma chave `2 x 2`, usaremos blocos de duas letras.

## 2. Mantendo a convenção do alfabeto

```text
A  B  C  D  E  F  G  H  I  J  K  L  M
0  1  2  3  4  5  6  7  8  9 10 11 12

N  O  P  Q  R  S  T  U  V  W  X  Y  Z
13 14 15 16 17 18 19 20 21 22 23 24 25
```

A preparação também continua a mesma:

```text
Frase:            Eu amo BR!
Texto preparado:  EUAMOBR
Quantidade:       7 letras
```

Essa preparação elimina informações de formatação. A recuperação matemática da mensagem não recupera automaticamente espaços, acentos e pontuação.

## 3. Separando os blocos

Lemos da esquerda para a direita, sem sobrepor blocos:

```text
EUAMOBR -> EU | AM | OB | R
```

O último bloco tem apenas uma letra. Para completar, adotaremos a convenção de adicionar um único `X` quando o comprimento for ímpar:

```text
EUAMOBR -> EUAMOBRX
EU | AM | OB | RX
```

O nome desse procedimento é **preenchimento**, também conhecido como *padding*.

Se a quantidade de letras já for par, não acrescentamos nada:

```text
CASA -> CA | SA
```

## 4. Cada bloco vira um vetor coluna

Um vetor coluna é uma matriz com uma única coluna. O bloco `EU` é representado por:

```text
E = 4
U = 20

P_1 = [  4 ]
      [ 20 ]
```

A primeira letra fica em cima; a segunda, embaixo. Para a mensagem inteira:

```text
EU           AM           OB           RX

P_1 = [ 4]   P_2 = [ 0]   P_3 = [14]   P_4 = [17]
      [20]         [12]         [ 1]         [23]
```

O índice de `P_1`, `P_2` etc. indica o número do bloco. Ele não é o valor de uma letra.

## 5. Uma matriz com todos os blocos

Podemos organizar os vetores como colunas de uma única matriz:

```text
P = [  4    0   14   17 ]
    [ 20   12    1   23 ]
       EU   AM   OB   RX
```

A matriz tem dimensão `2 x 4`: duas letras por bloco e quatro blocos.

Para ler a mensagem, percorremos cada coluna de cima para baixo e passamos à próxima coluna. Ler a primeira linha inteira e depois a segunda mudaria a ordem das letras.

Para evitar confusão com as letras originais, a linha `EU AM OB RX` acima serve apenas como identificação das colunas.

## 6. Por que registrar o tamanho original?

Compare:

```text
Mensagem original 1: SOL  -> preparada e preenchida: SOLX
Mensagem original 2: SOLX -> preparada e preenchida: SOLX
```

As sequências preenchidas são iguais. O texto recuperado, sozinho, não permite saber se o último `X` é original ou adicional.

Nas atividades, registre a quantidade de letras do texto preparado antes do preenchimento. Por exemplo:

```text
Comprimento original: 3
Texto decifrado: SOLX
Remover exatamente a quarta letra, que foi acrescentada.
```

Não apague todos os `X` finais indiscriminadamente. A regra de preenchimento precisa ser conhecida pelo destinatário, e o comprimento original resolve a ambiguidade neste modelo didático.

## 7. Exercícios

### 7.1

Prepare `Matemática!`, separe em pares e escreva o comprimento original. É necessário preencher?

### 7.2

Escreva os vetores coluna da mensagem `CHAVE`, incluindo o preenchimento se necessário.

### 7.3

Recupere a sequência representada pela matriz abaixo, lendo por colunas:

```text
P = [ 2   3    6 ]
    [14   8   14 ]
```

### 7.4

Depois da decifragem, obtivemos `TAXI`. O comprimento original informado é `4`. Devemos remover o `X`? Justifique.

### 7.5

Uma matriz `P` contém oito blocos de duas letras, um por coluna. Qual é sua dimensão?

## Gabarito comentado

### 7.1

```text
MATEMATICA
Comprimento: 10
Blocos: MA | TE | MA | TI | CA
```

Não há preenchimento, pois `10` é par.

### 7.2

```text
CHAVE -> CHAVEX
Comprimento original: 5

CH = [2]    AV = [ 0]    EX = [ 4]
     [7]         [21]         [23]
```

### 7.3

As colunas são `[2, 14]`, `[3, 8]` e `[6, 14]`, correspondendo a `CO`, `DI` e `GO`. Resultado: `CODIGO`.

### 7.4

Não. A mensagem já tem quatro letras e o `X` está dentro dela. O preenchimento seria um `X` adicional ao final, apenas no caso de comprimento ímpar.

### 7.5

Dimensão `2 x 8`: duas linhas por bloco e oito colunas.

**Próxima aula:** [Multiplicação de matriz por vetor módulo 26](05-02-matriz-vetor-modulo-26.md).
