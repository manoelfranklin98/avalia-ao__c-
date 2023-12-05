//QUESTAO 16
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) : valor(v), esquerda(NULL), direita(NULL) {}
};

std::vector<int> maiores_nos_por_nivel(No* raiz) {
    std::vector<int> maiores_nos;

    if (raiz == NULL) {
        return maiores_nos;
    }

    std::queue<No*> fila;
    fila.push(raiz);

    while (!fila.empty()) {
        int tamanho_nivel = fila.size();
        int maior_no_nivel = INT_MIN;

        for (int i = 0; i < tamanho_nivel; ++i) {
            No* no_atual = fila.front();
            fila.pop();

            if (no_atual->valor > maior_no_nivel) {
                maior_no_nivel = no_atual->valor;
            }

            if (no_atual->esquerda != NULL) {
                fila.push(no_atual->esquerda);
            }

            if (no_atual->direita != NULL) {
                fila.push(no_atual->direita);
            }
        }

        maiores_nos.push_back(maior_no_nivel);
    }

    return maiores_nos;
}

int main() {
    No* raiz = new No(1);
    raiz->esquerda = new No(3);
    raiz->direita = new No(2);
    raiz->esquerda->esquerda = new No(5);
    raiz->esquerda->direita = new No(3);
    raiz->direita->direita = new No(9);

    std::vector<int> maiores_nos = maiores_nos_por_nivel(raiz);

    std::cout << "Maior no de cada nivel: ";
    for (std::vector<int>::iterator it = maiores_nos.begin(); it != maiores_nos.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    delete raiz->esquerda->esquerda;
    delete raiz->esquerda->direita;
    delete raiz->esquerda;
    delete raiz->direita->direita;
    delete raiz->direita;
    delete raiz;

    return 0;
}

