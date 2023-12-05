//QUESTAO13
#include <iostream>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(NULL), direita(NULL) {}
};

bool verificar_soma_filhos(No* raiz) {
    if (raiz == NULL) {
        return false;
    }

    int soma_filhos = 0;

    if (raiz->esquerda != NULL) {
        soma_filhos += raiz->esquerda->valor;
    }

    if (raiz->direita != NULL) {
        soma_filhos += raiz->direita->valor;
    }

    return soma_filhos == raiz->valor;
}

int main() {
    No* raiz = new No(10);
    raiz->esquerda = new No(4);
    raiz->direita = new No(6);

    std::cout << "Arvore (in-order): " << raiz->valor << ", " << raiz->esquerda->valor << ", " << raiz->direita->valor << std::endl;

    bool resultado = verificar_soma_filhos(raiz);

    std::cout << "Resultado: " << (resultado ? "TRUE" : "FALSE") << std::endl;

    delete raiz->esquerda;
    delete raiz->direita;
    delete raiz;

    return 0;
}

