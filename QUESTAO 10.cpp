//questao 10
#include <iostream>
#include <climits>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(NULL), direita(NULL) {}
};

bool verificar_BST_util(No* no, int& valor_minimo, int& valor_maximo) {
    if (no == NULL) {
        return true;
    }

    if (!verificar_BST_util(no->esquerda, valor_minimo, no->valor)) {
        return false;
    }

    if (no->valor <= valor_minimo || no->valor >= valor_maximo) {
        return false;
    }

    valor_minimo = no->valor;

    return verificar_BST_util(no->direita, no->valor, valor_maximo);
}

bool verificar_BST(No* raiz) {
    int valor_minimo = INT_MIN;
    int valor_maximo = INT_MAX;

    return verificar_BST_util(raiz, valor_minimo, valor_maximo);
}

int main() {
    No* raiz_bst = new No(2);
    raiz_bst->esquerda = new No(1);
    raiz_bst->direita = new No(3);

    No* raiz_nao_bst = new No(2);
    raiz_nao_bst->esquerda = new No(3);
    raiz_nao_bst->direita = new No(1);

    std::cout << "A arvore raiz_bst e um BST? " << (verificar_BST(raiz_bst) ? "Sim" : "Nao") << std::endl;
    std::cout << "A arvore raiz_nao_bst e um BST? " << (verificar_BST(raiz_nao_bst) ? "Sim" : "Nao") << std::endl;

    delete raiz_bst->esquerda;
    delete raiz_bst->direita;
    delete raiz_bst;

    delete raiz_nao_bst->esquerda;
    delete raiz_nao_bst->direita;
    delete raiz_nao_bst;

    return 0;
}

