//questao
#include <iostream>
#include <vector>

// Definição básica de um nó de árvore
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

// Função auxiliar para encontrar todos os caminhos da raiz até as folhas
void encontrarCaminhos(TreeNode* raiz, std::vector<int>& caminhoAtual, std::vector<std::vector<int> >& caminhos) {
    if (raiz != 0) {
        caminhoAtual.push_back(raiz->val);

        if (raiz->left == 0 && raiz->right == 0) {
            caminhos.push_back(caminhoAtual);
        } else {
            encontrarCaminhos(raiz->left, caminhoAtual, caminhos);
            encontrarCaminhos(raiz->right, caminhoAtual, caminhos);
        }

        caminhoAtual.pop_back();
    }
}

// Função principal para encontrar todos os caminhos da raiz até as folhas
std::vector<std::vector<int> > caminhosDaRaizAteFolhas(TreeNode* raiz) {
    std::vector<std::vector<int> > caminhos;
    std::vector<int> caminhoAtual;
    encontrarCaminhos(raiz, caminhoAtual, caminhos);
    return caminhos;
}

int main() {
    // Construir a árvore de exemplo: [1, 2, 3, null, 5]
    TreeNode* raiz1 = new TreeNode(1);
    raiz1->left = new TreeNode(2);
    raiz1->right = new TreeNode(3);
    raiz1->left->right = new TreeNode(5);

    std::vector<std::vector<int> > caminhos1 = caminhosDaRaizAteFolhas(raiz1);

    std::cout << "Exemplo 1: [";
    for (size_t i = 0; i < caminhos1.size(); ++i) {
        std::cout << (i > 0 ? ", " : "") << "[";
        for (size_t j = 0; j < caminhos1[i].size(); ++j) {
            std::cout << (j > 0 ? ", " : "") << caminhos1[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]" << std::endl;

    // Limpar a memória alocada para os nós da árvore
    delete raiz1->left->right;
    delete raiz1->left;
    delete raiz1->right;
    delete raiz1;

    // Construir a árvore de exemplo: [1]
    TreeNode* raiz2 = new TreeNode(1);

    std::vector<std::vector<int> > caminhos2 = caminhosDaRaizAteFolhas(raiz2);

    std::cout << "Exemplo 2: [";
    for (size_t i = 0; i < caminhos2.size(); ++i) {
        std::cout << (i > 0 ? ", " : "") << "[";
        for (size_t j = 0; j < caminhos2[i].size(); ++j) {
            std::cout << (j > 0 ? ", " : "") << caminhos2[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]" << std::endl;

    // Limpar a memória alocada para os nós da árvore
    delete raiz2;

    return 0;
}

