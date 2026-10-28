"""Hill 2 x 2: vetores coluna, chave à esquerda e módulo 26.

Execute na raiz: python3 exemplos/05-cifra-hill.py
O exemplo é independente de pacotes externos e dos demais scripts.
"""

from math import gcd
import unicodedata


ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MODULO = len(ALFABETO)


def preparar_texto(texto):
    """Remove acentos e mantém somente A a Z; não acrescenta preenchimento."""
    sem_acentos = unicodedata.normalize("NFD", texto.upper())
    return "".join(letra for letra in sem_acentos if letra in ALFABETO)


def validar_texto(texto):
    if any(letra not in ALFABETO for letra in texto):
        raise ValueError("Use texto preparado: somente letras de A a Z.")


def validar_matriz(matriz):
    if len(matriz) != 2 or any(len(linha) != 2 for linha in matriz):
        raise ValueError("A matriz deve ter dimensão 2 x 2.")
    if any(not isinstance(valor, int) for linha in matriz for valor in linha):
        raise ValueError("As entradas da matriz devem ser inteiras.")


def determinante(matriz):
    validar_matriz(matriz)
    a, b = matriz[0]
    c, d = matriz[1]
    return a * d - b * c


def inverso_modular(a):
    for candidato in range(MODULO):
        if (a * candidato) % MODULO == 1:
            return candidato
    raise ValueError(f"{a} não tem inverso módulo {MODULO}.")


def validar_chave(chave):
    det = determinante(chave)
    if gcd(det, MODULO) != 1:
        raise ValueError(
            f"Chave não invertível: det={det}, mdc(det, {MODULO})={gcd(det, MODULO)}."
        )


def inversa_modular(chave):
    validar_chave(chave)
    a, b = chave[0]
    c, d = chave[1]
    inverso_det = inverso_modular(determinante(chave))
    return [
        [(inverso_det * d) % MODULO, (-inverso_det * b) % MODULO],
        [(-inverso_det * c) % MODULO, (inverso_det * a) % MODULO],
    ]


def multiplicar_bloco(matriz, bloco):
    """Multiplica uma matriz 2 x 2 pelo vetor coluna [p_1, p_2]."""
    validar_matriz(matriz)
    p_1, p_2 = bloco
    a, b = matriz[0]
    c, d = matriz[1]
    return [
        (a * p_1 + b * p_2) % MODULO,
        (c * p_1 + d * p_2) % MODULO,
    ]


def transformar_blocos(texto, matriz):
    """Transformação matemática de blocos completos, sem tratar preenchimento."""
    validar_texto(texto)
    validar_matriz(matriz)
    if len(texto) % 2 != 0:
        raise ValueError("São necessários blocos completos de duas letras.")

    resultado = []
    for inicio in range(0, len(texto), 2):
        bloco = [ALFABETO.index(texto[inicio]), ALFABETO.index(texto[inicio + 1])]
        transformado = multiplicar_bloco(matriz, bloco)
        resultado.extend(ALFABETO[valor] for valor in transformado)
    return "".join(resultado)


def cifrar_hill(texto, chave):
    """Retorna (texto cifrado, comprimento original antes do preenchimento)."""
    validar_texto(texto)
    validar_chave(chave)
    comprimento_original = len(texto)
    if comprimento_original % 2 != 0:
        texto += "X"
    return transformar_blocos(texto, chave), comprimento_original


def decifrar_hill(texto_cifrado, chave, comprimento_original=None):
    """Sem comprimento, preserva o texto com eventual preenchimento.

    O comprimento fornecido deve corresponder à convenção de acrescentar
    um X somente quando o texto preparado tem tamanho ímpar.
    """
    inversa = inversa_modular(chave)
    recuperado = transformar_blocos(texto_cifrado, inversa)
    if comprimento_original is None:
        return recuperado

    if not isinstance(comprimento_original, int) or comprimento_original < 0:
        raise ValueError("O comprimento original deve ser um inteiro não negativo.")
    esperado = comprimento_original + comprimento_original % 2
    if esperado != len(recuperado):
        raise ValueError("Comprimento original incompatível com o texto cifrado.")
    if comprimento_original % 2 != 0 and not recuperado.endswith("X"):
        raise ValueError("O preenchimento esperado é um X no final da mensagem.")
    return recuperado[:comprimento_original]


def main():
    # Retoma o exemplo da aula de matrizes do Tema 2.
    chave = [[3, 2], [1, 1]]
    mensagem = preparar_texto("Eu amo BR!")
    cifrado, tamanho = cifrar_hill(mensagem, chave)

    print(f"Chave: {chave}")
    print(f"Determinante: {determinante(chave)}")
    print(f"Inversa módulo 26: {inversa_modular(chave)}")
    print(f"Texto preparado: {mensagem}")
    print(f"Comprimento original: {tamanho}")
    print(f"Texto cifrado: {cifrado}")
    print(f"Decifrado com preenchimento: {decifrar_hill(cifrado, chave)}")
    print(f"Decifrado sem preenchimento: {decifrar_hill(cifrado, chave, tamanho)}")

    # Esta segunda chave exige o inverso de 9 para montar a matriz inversa.
    outra_chave = [[3, 3], [2, 5]]
    cifrado, tamanho = cifrar_hill("HI", outra_chave)
    recuperado = decifrar_hill(cifrado, outra_chave, tamanho)
    print(f"\nOutra chave: HI -> {cifrado} -> {recuperado}")


if __name__ == "__main__":
    main()
