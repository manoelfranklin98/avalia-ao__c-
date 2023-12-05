//questao 19
#include <iostream>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(0), direita(0) {}
};

No* maiorNoBST(No* raiz) {
    if (raiz == 0) {
        return 0;
    }

    while (raiz->direita != 0) {
        raiz = raiz->direita;
    }

    return raiz;
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

    No* maior = maiorNoBST(raiz);

    if (maior != 0) {
        std::cout << "Maior no da arvore: " << maior->valor << std::endl;
    } else {
        std::cout << "arvore vazia." << std::endl;
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

