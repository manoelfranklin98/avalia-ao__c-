//questao 9
#include <iostream>
#include <vector>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(NULL), direita(NULL) {}
};

void percorrer_arvore(No* no, std::vector<int>& valores) {
    if (no == NULL) {
        return;
    }

    percorrer_arvore(no->esquerda, valores);
    valores.push_back(no->valor);
    percorrer_arvore(no->direita, valores);
}

No* construir_arvore_balanceada(std::vector<int>& valores, int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }

    int meio = (inicio + fim) / 2;
    No* no = new No(valores[meio]);

    no->esquerda = construir_arvore_balanceada(valores, inicio, meio - 1);
    no->direita = construir_arvore_balanceada(valores, meio + 1, fim);

    return no;
}

No* balancear_arvore(No* raiz) {
    std::vector<int> valores;
    percorrer_arvore(raiz, valores);

    return construir_arvore_balanceada(valores, 0, valores.size() - 1);
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
    No* raiz = new No(3);
    raiz->esquerda = new No(1);
    raiz->direita = new No(5);
    raiz->esquerda->direita = new No(2);
    raiz->direita->esquerda = new No(4);
    raiz->direita->direita = new No(6);

    std::cout << "Árvore original (in-order): ";
    imprimir_arvore(raiz);
    std::cout << std::endl;

    No* raiz_balanceada = balancear_arvore(raiz);

    std::cout << "Árvore balanceada (in-order): ";
    imprimir_arvore(raiz_balanceada);
    std::cout << std::endl;

    delete raiz;
    delete raiz_balanceada;

    return 0;
}

