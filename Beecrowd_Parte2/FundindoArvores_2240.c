#include <stdio.h>
#include <stdlib.h>

#define MAXN 10005

// Estrutura de um vértice de uma árvore ternária
typedef struct TreeNode {
    int left, center, right; // Identificadores dos filhos esquerdo, central e direito
} TreeNode;

// Estrutura da árvore
typedef struct Tree {
    TreeNode nodes[MAXN]; // Nós da árvore
    int size;             // Número de vértices na árvore
} Tree;

// Função para realizar a DFS e calcular os vértices necessários
void dfs(Tree *tree, int node, int *depthArray, int depth, int *minVertices) {
    depthArray[node] = depth;
    minVertices[depth]++;
    
    // Para cada filho, se existir, chama recursivamente a DFS
    if (tree->nodes[node].left != 0) {
        dfs(tree, tree->nodes[node].left, depthArray, depth + 1, minVertices);
    }
    if (tree->nodes[node].center != 0) {
        dfs(tree, tree->nodes[node].center, depthArray, depth + 1, minVertices);
    }
    if (tree->nodes[node].right != 0) {
        dfs(tree, tree->nodes[node].right, depthArray, depth + 1, minVertices);
    }
}

int main() {
    int N, M;
    int i, I, L, K;
    int P, Q, R;
    
    // Leitura do número de vértices da árvore canhota
    scanf("%d", &N);
    
    // Inicialização da árvore canhota
    Tree leftTree;
    leftTree.size = N;
    
    // Leitura dos vértices da árvore canhota
    for (i = 1; i <= N; i++) {
        scanf("%d %d %d", &I, &L, &K);
        leftTree.nodes[I].left = L;
        leftTree.nodes[I].center = K;
        leftTree.nodes[I].right = 0;
    }
    
    // Leitura do número de vértices da árvore destra
    scanf("%d", &M);
    
    // Inicialização da árvore destra
    Tree rightTree;
    rightTree.size = M;
    
    // Leitura dos vértices da árvore destra
    for (i = 1; i <= M; i++) {
        scanf("%d %d %d", &P, &Q, &R);
        rightTree.nodes[P].left = 0;
        rightTree.nodes[P].center = Q;
        rightTree.nodes[P].right = R;
    }
    
    // Arrays para controlar a profundidade dos vértices e a contagem mínima de vértices necessários
    int leftDepth[MAXN] = {0};
    int rightDepth[MAXN] = {0};
    int minVertices[MAXN] = {0};
    
    // Realiza a DFS para a árvore canhota partindo do vértice 1
    dfs(&leftTree, 1, leftDepth, 1, minVertices);
    
    // Realiza a DFS para a árvore destra partindo do vértice 1
    dfs(&rightTree, 1, rightDepth, 1, minVertices);
    
    // Encontra o máximo depth para calcular o total mínimo de vértices necessários
    int maxDepth = 0;
    for (i = 1; i <= N; i++) {
        if (leftDepth[i] > maxDepth) maxDepth = leftDepth[i];
    }
    for (i = 1; i <= M; i++) {
        if (rightDepth[i] > maxDepth) maxDepth = rightDepth[i];
    }
    
    // Calcula o número mínimo de vértices necessários
    int result = 0;
    for (i = 1; i <= maxDepth; i++) {
        result += minVertices[i];
    }
    
    // Imprime o resultado
    printf("%d\n", result);
    
    return 0;
}
