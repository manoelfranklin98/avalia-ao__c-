//QUESTAO 18
#include <iostream>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(0), direita(0) {}
};

No* arrayParaBST(const int nums[], int inicio, int fim) {
    if (inicio > fim) {
        return 0;
    }

    int meio = (inicio + fim) / 2;
    No* raiz = new No(nums[meio]);

    raiz->esquerda = arrayParaBST(nums, inicio, meio - 1);
    raiz->direita = arrayParaBST(nums, meio + 1, fim);

    return raiz;
}

No* arrayParaBST(const int nums[], int tamanho) {
    if (tamanho <= 0) {
        return 0;
    }

    return arrayParaBST(nums, 0, tamanho - 1);
}

void percorrerEmOrdem(No* raiz) {
    if (raiz != 0) {
        percorrerEmOrdem(raiz->esquerda);
        std::cout << raiz->valor << " ";
        percorrerEmOrdem(raiz->direita);
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int tamanho = sizeof(nums) / sizeof(nums[0]);

    No* raiz = arrayParaBST(nums, tamanho);

    std::cout << "Árvore Binária de Busca (BST) resultante (percurso em ordem): ";
    percorrerEmOrdem(raiz);
    std::cout << std::endl;

    // Libera a memória alocada para a árvore
    // (aqui você pode implementar uma função de liberação de memória recursiva)
    delete raiz;

    return 0;
}

