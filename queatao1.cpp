#include <iostream>

// Definição básica de um nó de árvore binária
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void percorrerEmOrdem(TreeNode* raiz) {
    if (raiz != NULL) {
        // Percorrer o nó da esquerda
        percorrerEmOrdem(raiz->left);
        
        // Processar o nó atual
        std::cout << raiz->val << " ";
        
        // Percorrer o nó da direita
        percorrerEmOrdem(raiz->right);
    }
}

int main() {
    // Construir a árvore de exemplo: [1, null, 2, 3]
    TreeNode* raiz = new TreeNode(1);
    raiz->right = new TreeNode(2);
    raiz->right->left = new TreeNode(3);

    // Chamar a função de percurso em ordem
    percorrerEmOrdem(raiz);

    // Limpar a memória alocada para os nós da árvore
    // (Normalmente você faria isso de maneira mais robusta,
    // usando uma função de desalocação recursiva.)
    delete raiz->right->left;
    delete raiz->right;
    delete raiz;

    return 0;
}

