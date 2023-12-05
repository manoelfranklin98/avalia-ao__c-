//QUESTAO 7
#include <iostream>
#include <vector>
#include <algorithm>

class No {
public:
    int valor;
    std::vector<No*> filhos;

    No(int v) : valor(v) {}
};

int altura_arvore(No* no) {
    if (no->filhos.empty()) {
        return 0;
    } else {
        std::vector<int> subarvore_alturas;
        for (std::vector<No*>::iterator it = no->filhos.begin(); it != no->filhos.end(); ++it) {
            subarvore_alturas.push_back(altura_arvore(*it));
        }
        return 1 + *std::max_element(subarvore_alturas.begin(), subarvore_alturas.end());
    }
}

int main() {
    No* raiz = new No(1);
    No* no2 = new No(2);
    No* no3 = new No(3);
    No* no4 = new No(4);
    No* no5 = new No(5);
    No* no6 = new No(6);

    raiz->filhos.push_back(no2);
    raiz->filhos.push_back(no3);
    no2->filhos.push_back(no4);
    no2->filhos.push_back(no5);
    no5->filhos.push_back(no6);

    int altura = altura_arvore(raiz);
    std::cout << "A altura da árvore é: " << altura << std::endl;

    // Lembre-se de liberar a memória alocada para os nós
    delete raiz;
    delete no2;
    delete no3;
    delete no4;
    delete no5;
    delete no6;

    return 0;
}

