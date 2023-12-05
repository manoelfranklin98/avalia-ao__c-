//questao 2
#include <iostream>

struct NoArvore {
    int valor;
    NoArvore* esquerda;
    NoArvore* direita;
    NoArvore(int x) : valor(x), esquerda(NULL), direita(NULL) {}
};

bool saoArvoresIguais(NoArvore* p, NoArvore* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    
    if (p == NULL || q == NULL) {
        return false;
    }
    
    if (p->valor != q->valor) {
        return false;
    }
    
    return saoArvoresIguais(p->esquerda, q->esquerda) && saoArvoresIguais(p->direita, q->direita);
}

int main() {
    NoArvore* p = new NoArvore(1);
    p->esquerda = new NoArvore(2);
    p->direita = new NoArvore(3);

    NoArvore* q = new NoArvore(1);
    q->esquerda = new NoArvore(2);
    q->direita = new NoArvore(3);

    bool resultado = saoArvoresIguais(p, q);

    std::cout << "As árvores são iguais? " << (resultado ? "Sim" : "Não") << std::endl;

    delete p->esquerda;
    delete p->direita;
    delete p;

    delete q->esquerda;
    delete q->direita;
    delete q;

    return 0;
}

