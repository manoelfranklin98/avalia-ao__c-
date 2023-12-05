//QUESTAO 11
#include <iostream>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(NULL), direita(NULL) {}
};

No* inverter_arvore(No* raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    // Trocar os filhos esquerdo e direito recursivamente
    No* temp = raiz->esquerda;
    raiz->esquerda = inverter_arvore(raiz->direita);
    raiz->direita = inverter_arvore(temp);

    return raiz;
}

void imprimir_arvore(No* no) {
    if (no == NULL) {
        return;
    }

    imprimir_arvore(no->esquerda);
    std::cout << no->valor << " ";
    imprimir_arvore(no->direita);
}

int main() {
    // Criar uma árvore de exemplo
    No* raiz = new No(4);
    raiz->esquerda = new No(2);
    raiz->direita = new No(7);
    raiz->esquerda->esquerda = new No(1);
    raiz->esquerda->direita = new No(3);
    raiz->direita->esquerda = new No(6);
    raiz->direita->direita = new No(9);

    std::cout << "Árvore original (in-order): ";
    imprimir_arvore(raiz);
    std::cout << std::endl;

    // Inverter a árvore
    No* raiz_invertida = inverter_arvore(raiz);

    std::cout << "Árvore invertida (in-order): ";
    imprimir_arvore(raiz_invertida);
    std::cout << std::endl;

    // Lembre-se de liberar a memória alocada para os nós
    delete raiz->esquerda;
    delete raiz->direita;
    delete raiz;

    delete raiz_invertida->esquerda;
    delete raiz_invertida->direita;
    delete raiz_invertida;

    return 0;
}

