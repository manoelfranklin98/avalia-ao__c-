#include <iostream>

// Defini��o b�sica de um n� de �rvore bin�ria
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void percorrerEmOrdem(TreeNode* raiz) {
    if (raiz != NULL) {
        // Percorrer o n� da esquerda
        percorrerEmOrdem(raiz->left);
        
        // Processar o n� atual
        std::cout << raiz->val << " ";
        
        // Percorrer o n� da direita
        percorrerEmOrdem(raiz->right);
    }
}

int main() {
    // Construir a �rvore de exemplo: [1, null, 2, 3]
    TreeNode* raiz = new TreeNode(1);
    raiz->right = new TreeNode(2);
    raiz->right->left = new TreeNode(3);

    // Chamar a fun��o de percurso em ordem
    percorrerEmOrdem(raiz);

    // Limpar a mem�ria alocada para os n�s da �rvore
    // (Normalmente voc� faria isso de maneira mais robusta,
    // usando uma fun��o de desaloca��o recursiva.)
    delete raiz->right->left;
    delete raiz->right;
    delete raiz;

    return 0;
}

