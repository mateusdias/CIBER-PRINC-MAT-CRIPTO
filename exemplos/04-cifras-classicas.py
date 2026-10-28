"""César e cifra afim: exemplos didáticos com A=0 e módulo 26.

Execute na raiz: python3 exemplos/04-cifras-classicas.py
As funções de cifragem recebem texto já preparado; preparar_texto faz a
normalização separadamente para deixar visível a informação removida.
"""

from math import gcd
import unicodedata


ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MODULO = len(ALFABETO)


def preparar_texto(texto):
    """Remove acentos e mantém somente as letras de A a Z, em maiúsculas."""
    sem_acentos = unicodedata.normalize("NFD", texto.upper())
    return "".join(letra for letra in sem_acentos if letra in ALFABETO)


def validar_texto(texto):
    if any(letra not in ALFABETO for letra in texto):
        raise ValueError("Use texto preparado: somente letras de A a Z.")


def inverso_modular(a, modulo=MODULO):
    """Busca diretamente o inteiro u tal que a*u deixe resto 1."""
    if modulo < 2:
        raise ValueError("O módulo deve ser pelo menos 2.")
    a %= modulo
    for candidato in range(modulo):
        if (a * candidato) % modulo == 1:
            return candidato
    raise ValueError(f"{a} não tem inverso módulo {modulo}.")


def cifrar_cesar(texto, chave):
    validar_texto(texto)
    return "".join(
        ALFABETO[(ALFABETO.index(letra) + chave) % MODULO]
        for letra in texto
    )


def decifrar_cesar(texto, chave):
    return cifrar_cesar(texto, -chave)


def forca_bruta_cesar(texto):
    """Enumera candidatos; não escolhe automaticamente a mensagem original."""
    return [(chave, decifrar_cesar(texto, chave)) for chave in range(MODULO)]


def validar_multiplicador(a):
    if gcd(a, MODULO) != 1:
        raise ValueError(f"Chave inválida: mdc({a}, {MODULO}) deve ser 1.")


def cifrar_afim(texto, a, b):
    validar_texto(texto)
    validar_multiplicador(a)
    return "".join(
        ALFABETO[(a * ALFABETO.index(letra) + b) % MODULO]
        for letra in texto
    )


def decifrar_afim(texto, a, b):
    validar_texto(texto)
    validar_multiplicador(a)
    inverso = inverso_modular(a)
    return "".join(
        ALFABETO[(inverso * (ALFABETO.index(letra) - b)) % MODULO]
        for letra in texto
    )


def forca_bruta_afim(texto):
    """Retorna os 312 candidatos, incluindo a transformação identidade."""
    validar_texto(texto)
    candidatos = []
    for a in range(MODULO):
        if gcd(a, MODULO) == 1:
            for b in range(MODULO):
                candidatos.append(((a, b), decifrar_afim(texto, a, b)))
    return candidatos


def main():
    # Troque a mensagem e as chaves para fazer os experimentos das aulas.
    mensagem = preparar_texto("Casa!")
    chave_cesar = 3
    a, b = 5, 8

    cifrado = cifrar_cesar(mensagem, chave_cesar)
    recuperado = decifrar_cesar(cifrado, chave_cesar)
    print(f"César (k={chave_cesar}): {mensagem} -> {cifrado} -> {recuperado}")

    cifrado = cifrar_afim(mensagem, a, b)
    recuperado = decifrar_afim(cifrado, a, b)
    print(f"Afim (a={a}, b={b}): {mensagem} -> {cifrado} -> {recuperado}")
    print(f"Inverso de {a} módulo 26: {inverso_modular(a)}")

    print("\nTodos os candidatos de César para FDVD:")
    for chave, candidato in forca_bruta_cesar("FDVD"):
        print(f"k={chave:2}: {candidato}")

    candidatos_afins = forca_bruta_afim("SIUI")
    print(f"\nQuantidade de candidatos afins para SIUI: {len(candidatos_afins)}")
    print("Para listar cada um, percorra forca_bruta_afim('SIUI').")


if __name__ == "__main__":
    main()
