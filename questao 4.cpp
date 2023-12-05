//questao 4 
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void posOrdem(TreeNode* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->left);
        posOrdem(raiz->right);
        std::cout << raiz->val << " ";
    }
}

int main() {
    TreeNode* raiz = new TreeNode(1);
    raiz->right = new TreeNode(2);
    raiz->right->left = new TreeNode(3);

    posOrdem(raiz);

    delete raiz->right->left;
    delete raiz->right;
    delete raiz;

    return 0;
}

