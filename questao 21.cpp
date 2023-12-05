// questao 21
#include <iostream>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(0), direita(0) {}
};

No* buscaBinariaBST(No* raiz, int alvo) {
    if (raiz == 0 || raiz->valor == alvo) {
        return raiz;
    }

    if (alvo < raiz->valor) {
        return buscaBinariaBST(raiz->esquerda, alvo);
    } else {
        return buscaBinariaBST(raiz->direita, alvo);
    }
}

int main() {
    No* raiz = new No(8);
    raiz->esquerda = new No(3);
    raiz->direita = new No(10);
    raiz->esquerda->esquerda = new No(1);
    raiz->esquerda->direita = new No(6);
    raiz->esquerda->direita->esquerda = new No(4);
    raiz->esquerda->direita->direita = new No(7);
    raiz->direita->direita = new No(14);
    raiz->direita->direita->esquerda = new No(13);

    int alvo = 6;
    No* resultado = buscaBinariaBST(raiz, alvo);

    if (resultado != 0) {
        std::cout << "No com valor " << alvo << " encontrado." << std::endl;
    } else {
        std::cout << "No com valor " << alvo << " nao encontrado." << std::endl;
    }

    delete raiz->esquerda->direita->direita;
    delete raiz->esquerda->direita->esquerda;
    delete raiz->esquerda->direita;
    delete raiz->esquerda->esquerda;
    delete raiz->esquerda;
    delete raiz->direita->direita->esquerda;
    delete raiz->direita->direita;
    delete raiz->direita;
    delete raiz;

    return 0;
}

