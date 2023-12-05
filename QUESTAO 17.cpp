// QUESATO 17
#include <iostream>
#include <climits>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(NULL), direita(NULL) {}
};

int maiorSomaSubarvore(No* raiz, int& maiorSoma) {
    if (raiz == NULL) {
        return 0;
    }

    int somaAtual = raiz->valor +
                    maiorSomaSubarvore(raiz->esquerda, maiorSoma) +
                    maiorSomaSubarvore(raiz->direita, maiorSoma);

    maiorSoma = std::max(maiorSoma, somaAtual);

    return somaAtual;
}

int maiorSomaSubarvore(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int maiorSoma = INT_MIN;
    maiorSomaSubarvore(raiz, maiorSoma);

    return maiorSoma;
}

int main() {
    No* raiz = new No(1);
    raiz->esquerda = new No(4);
    raiz->direita = new No(3);
    raiz->esquerda->esquerda = new No(2);
    raiz->esquerda->direita = new No(4);
    raiz->direita->esquerda = new No(2);
    raiz->direita->direita = new No(5);
    raiz->direita->direita->esquerda = new No(4);
    raiz->direita->direita->direita = new No(6);

    int result = maiorSomaSubarvore(raiz);

    std::cout << "Maior soma de subArvore: " << result << std::endl;

    delete raiz->direita->direita->direita;
    delete raiz->direita->direita->esquerda;
    delete raiz->direita->direita;
    delete raiz->direita->esquerda;
    delete raiz->direita;
    delete raiz->esquerda->direita;
    delete raiz->esquerda->esquerda;
    delete raiz->esquerda;
    delete raiz;

    return 0;
}

