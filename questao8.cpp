//questao 8
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
    if (no == NULL) {
        return 0;
    } else {
        std::vector<int> subarvore_alturas;
        for (std::vector<No*>::iterator it = no->filhos.begin(); it != no->filhos.end(); ++it) {
            subarvore_alturas.push_back(altura_arvore(*it));
        }
        return 1 + *std::max_element(subarvore_alturas.begin(), subarvore_alturas.end());
    }
}


bool arvore_balanceada(No* no) {
    if (no == NULL) {
        return true;
    }

    
    int altura_esquerda = altura_arvore(no->filhos.size() > 0 ? no->filhos[0] : NULL);
    int altura_direita = altura_arvore(no->filhos.size() > 1 ? no->filhos[1] : NULL);

   
    if (std::abs(altura_esquerda - altura_direita) <= 1 &&
        arvore_balanceada(no->filhos.size() > 0 ? no->filhos[0] : NULL) &&
        arvore_balanceada(no->filhos.size() > 1 ? no->filhos[1] : NULL)) {
        return true;
    }

    return false;
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

    
    bool balanceada = arvore_balanceada(raiz);

    
    if (balanceada) {
        std::cout << "A arvore esta balanceada." << std::endl;
    } else {
        std::cout << "A arvore nao esta balanceada." << std::endl;
    }

    
    delete raiz;
    delete no2;
    delete no3;
    delete no4;
    delete no5;
    delete no6;

    return 0;
}

