//questao6s

#include <iostream>
#include <vector>
#include <algorithm>

class No {
public:
    int valor;
    std::vector<No*> filhos;

    No(int v) : valor(v) {}
};

int profundidade_arvore(No* no) {
    if (no->filhos.empty()) {
        return 1;
    } else {
        std::vector<int> subarvore_profundidades;
        for (std::vector<No*>::iterator it = no->filhos.begin(); it != no->filhos.end(); ++it) {
            subarvore_profundidades.push_back(profundidade_arvore(*it));
        }
        return 1 + *std::max_element(subarvore_profundidades.begin(), subarvore_profundidades.end());
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

    int profundidade = profundidade_arvore(raiz);
    std::cout << profundidade << std::endl;

    // Lembre-se de liberar a mem�ria alocada para os n�s
    delete raiz;
    delete no2;
    delete no3;
    delete no4;
    delete no5;
    delete no6;

    return 0;
}

