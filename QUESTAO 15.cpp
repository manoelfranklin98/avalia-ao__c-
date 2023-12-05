//QUESTAO 15 
#include <iostream>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(NULL), direita(NULL) {}
};

int somar_nos_folhas(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return raiz->valor;
    }

    int soma_esquerda = somar_nos_folhas(raiz->esquerda);
    int soma_direita = somar_nos_folhas(raiz->direita);

    return soma_esquerda + soma_direita;
}

int main() {
    No* raiz = new No(10);
    raiz->esquerda = new No(5);
    raiz->direita = new No(15);
    raiz->esquerda->esquerda = new No(3);
    raiz->esquerda->direita = new No(7);
    raiz->direita->esquerda = new No(12);
    raiz->direita->direita = new No(18);

    int soma_folhas = somar_nos_folhas(raiz);

    std::cout << "Soma dos nos folhas: " << soma_folhas << std::endl;

    delete raiz->esquerda->esquerda;
    delete raiz->esquerda->direita;
    delete raiz->esquerda;
    delete raiz->direita->esquerda;
    delete raiz->direita->direita;
    delete raiz->direita;
    delete raiz;

    return 0;
}


