// questao 5 
#include <iostream>
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void encontrarCaminhos(TreeNode* raiz, std::string caminhoAtual, std::vector<std::string>& caminhos) {
    if (raiz != NULL) {
        caminhoAtual += std::to_string(raiz->val);

        if (raiz->left == NULL && raiz->right == NULL) {
            caminhos.push_back(caminhoAtual);
        } else {
            caminhoAtual += "->";
            encontrarCaminhos(raiz->left, caminhoAtual, caminhos);
            encontrarCaminhos(raiz->right, caminhoAtual, caminhos);
        }
    }
}

std::vector<std::string> caminhosDaRaizAteFolhas(TreeNode* raiz) {
    std::vector<std::string> caminhos;
    if (raiz != NULL) {
        encontrarCaminhos(raiz, "", caminhos);
    }
    return caminhos;
}

int main() {
    TreeNode* raiz1 = new TreeNode(1);
    raiz1->left = new TreeNode(2);
    raiz1->right = new TreeNode(3);
    raiz1->left->right = new TreeNode(5);

    std::vector<std::string> caminhos1 = caminhosDaRaizAteFolhas(raiz1);

    std::cout << "Exemplo 1: ";
    for (size_t i = 0; i < caminhos1.size(); ++i) {
        std::cout << (i > 0 ? "," : "") << "'" << caminhos1[i] << "'";
    }
    std::cout << std::endl;

    TreeNode* raiz2 = new TreeNode(1);

    std::vector<std::string> caminhos2 = caminhosDaRaizAteFolhas(raiz2);

    std::cout << "Exemplo 2: ";
    for (size_t i = 0; i < caminhos2.size(); ++i) {
        std::cout << (i > 0 ? "," : "") << "'" << caminhos2[i] << "'";
    }
    std::cout << std::endl;

    delete raiz1->left->right;
    delete raiz1->left;
    delete raiz1->right;
    delete raiz1;

    delete raiz2;

    return 0;
}

