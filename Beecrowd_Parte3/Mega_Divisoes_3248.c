#include <stdio.h>
#include <stdlib.h>

// Define a Fenwick Tree structure
typedef struct {
    int* tree;
    int size;
} FenwickTree;

// Function to create a Fenwick Tree
FenwickTree* createFenwickTree(int size) {
    FenwickTree* fenwickTree = (FenwickTree*) malloc(sizeof(FenwickTree));
    fenwickTree->tree = (int*) calloc(size + 1, sizeof(int));
    fenwickTree->size = size;
    return fenwickTree;
}

// Function to update the Fenwick Tree
void update(FenwickTree* fenwickTree, int index, int delta) {
    while (index <= fenwickTree->size) {
        fenwickTree->tree[index] += delta;
        index += index & -index;
    }
}

// Function to query the Fenwick Tree
int query(FenwickTree* fenwickTree, int index) {
    int sum = 0;
    while (index > 0) {
        sum += fenwickTree->tree[index];
        index -= index & -index;
    }
    return sum;
}

// Function to free the Fenwick Tree
void freeFenwickTree(FenwickTree* fenwickTree) {
    free(fenwickTree->tree);
    free(fenwickTree);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* sequence = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }
    
    long long* rightSmaller = (long long*) calloc(n, sizeof(long long));
    long long* leftGreater = (long long*) calloc(n, sizeof(long long));
    
    FenwickTree* fenwickTree = createFenwickTree(n);
    
    // Calculate rightSmaller
    for (int i = n - 1; i >= 0; i--) {
        rightSmaller[i] = query(fenwickTree, sequence[i] - 1);
        update(fenwickTree, sequence[i], 1);
    }
    
    // Reset the Fenwick Tree
    freeFenwickTree(fenwickTree);
    fenwickTree = createFenwickTree(n);
    
    // Calculate leftGreater
    for (int i = 0; i < n; i++) {
        leftGreater[i] = i - query(fenwickTree, sequence[i]);
        update(fenwickTree, sequence[i], 1);
    }
    
    // Count the number of triples
    long long count = 0;
    for (int j = 0; j < n; j++) {
        count += leftGreater[j] * rightSmaller[j];
    }
    
    printf("%lld\n", count);
    
    // Free allocated memory
    free(sequence);
    free(rightSmaller);
    free(leftGreater);
    freeFenwickTree(fenwickTree);
    
    return 0;
}
