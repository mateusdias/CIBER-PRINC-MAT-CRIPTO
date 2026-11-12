# Cifra de Hill em C

Exemplo didático de cifra e decifra com matriz **2 × 2**, alfabeto de 26 letras e funções separadas. O programa usa somente a biblioteca padrão de C.

## Compilar e executar

Dentro desta pasta, execute:

```sh
cc -std=c11 -Wall -Wextra -Wpedantic hill.c -o hill
./hill
```

Escolha `1` para cifrar ou `2` para decifrar e digite o texto. Cada execução realiza uma operação.

Exemplo para cifrar:

```text
Escolha: 1
Digite o texto (ate 1000 caracteres, sem acentos): HELP
Texto preparado: HELP
Texto cifrado: HIAT
```

Para recuperar a mensagem, execute novamente, escolha `2` e informe `HIAT`. O resultado será `HELP`.

## Como funciona

Cada letra vira um número: `A = 0`, `B = 1`, ..., `Z = 25`. A mensagem é dividida em pares, representados como vetores coluna.

A chave está definida em `main`:

```text
K = [ 3  3 ]
    [ 2  5 ]
```

Para cifrar o par `HE`, por exemplo:

```text
H = 7; E = 4

primeira letra = (3 * 7 + 3 * 4) mod 26 = 7 -> H
segunda letra  = (2 * 7 + 5 * 4) mod 26 = 8 -> I
```

Logo, `HE` vira `HI`. O mesmo cálculo transforma `LP` em `AT`.

Para decifrar, o programa calcula a inversa da chave no módulo 26:

```text
det(K) = 3 * 5 - 3 * 2 = 9
inverso de 9 modulo 26 = 3, pois 9 * 3 mod 26 = 1

K_inversa = 3 * [  5  -3 ] mod 26 = [ 15  17 ]
                [ -2   3 ]          [ 20   9 ]
```

A multiplicação por essa inversa recupera os pares originais. Uma chave só funciona para decifrar se seu determinante tiver inverso módulo 26, isto é, se o determinante e 26 forem coprimos. Para experimentar outra chave, altere os quatro valores em `main`, usando números de 0 a 25, e atualize a mensagem que mostra a chave. O programa rejeita uma chave sem inversa.

## Funções

| Função | Responsabilidade |
| --- | --- |
| `modulo26` | Manter o resultado entre 0 e 25, inclusive para números negativos. |
| `inverso_modular` | Buscar um inverso multiplicativo módulo 26. |
| `calcular_matriz_inversa` | Calcular a inversa da chave ou informar que ela não existe. |
| `ler_linha` | Ler a entrada e verificar o limite de tamanho. |
| `preparar_texto` | Selecionar letras e convertê-las para maiúsculas. |
| `transformar_blocos` | Multiplicar cada par de letras por uma matriz. |
| `cifrar` | Transformar os pares usando a chave. |
| `decifrar` | Transformar os pares usando a chave inversa. |
| `main` | Organizar a leitura, as validações e a exibição do resultado. |

`cifrar`, `decifrar` e `transformar_blocos` recebem textos já preparados, com apenas letras `A-Z` e tamanho par. Os vetores de saída precisam ter espaço para o texto e o terminador `\0`. Essas condições são garantidas por `main`.

## Regras do exemplo

- A entrada aceita até 1000 caracteres ASCII por linha. Letras minúsculas viram maiúsculas; espaços, números e pontuação são descartados tanto na cifra quanto na decifra.
- Acentos, cedilha, emojis e outros caracteres fora de ASCII são rejeitados. Escreva `ACAO` em vez de `AÇÃO`.
- Se a mensagem tiver um número ímpar de letras, a cifra acrescenta `X`. Por exemplo, `ABC` é preparado como `ABCX` e cifrado como `DFXP`.
- A decifra exige um número par de letras e preserva o `X` final. Não é possível distinguir automaticamente um preenchimento de um `X` que já fazia parte da mensagem.
- Espaços, pontuação e a capitalização original não são recuperados.
- Esta é uma cifra histórica para estudo de matrizes e aritmética modular. Não deve ser usada para proteger dados reais.
