#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int height;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(int height) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->height = height;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int height) {
    if (root == NULL) {
        return createNode(height);
    }

    if (height < root->height) {
        root->left = insertNode(root->left, height);
    } else {
        root->right = insertNode(root->right, height);
    }
    return root;
}

void findMinHeightsByLevel(TreeNode* root) {
    if (root == NULL) return;
    
    int level = 0;
    int levelSize = 1;
    int nextLevelSize = 0;
    TreeNode* queue[250];
    int front = 0, rear = 0;
    int minHeight = INT_MAX;
    
    queue[rear++] = root;
    
    while (front < rear) {
        TreeNode* node = queue[front++];
        if (node->height < minHeight) {
            minHeight = node->height;
        }
        
        if (node->left != NULL) {
            queue[rear++] = node->left;
            nextLevelSize++;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
            nextLevelSize++;
        }
        
        if (--levelSize == 0) {
            printf("%d %d\n", level, minHeight);
            level++;
            levelSize = nextLevelSize;
            nextLevelSize = 0;
            minHeight = INT_MAX;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertNode(root, heights[i]);
    }

    findMinHeightsByLevel(root);

    return 0;
}
