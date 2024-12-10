#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_Q 100000
#define MAX_VALUE 100000

typedef struct {
    int tree[MAX_VALUE + 1];
    int maxVal;
} FenwickTree;

void initFenwickTree(FenwickTree *ft, int maxSize) {
    ft->maxVal = maxSize;
    for (int i = 0; i <= maxSize; ++i) {
        ft->tree[i] = 0;
    }
}

void add(FenwickTree *ft, int idx, int value) {
    while (idx <= ft->maxVal) {
        ft->tree[idx] += value;
        idx += idx & (-idx);
    }
}

int sum(FenwickTree *ft, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += ft->tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int rangeSum(FenwickTree *ft, int left, int right) {
    return sum(ft, right) - sum(ft, left - 1);
}

int main() {
    int N, Q;
    int array[MAX_N + 1];
    FenwickTree ft;
    
    while (1) {
        scanf("%d %d", &N, &Q);
        if (N == 0 && Q == 0) break;
        
        // Read array elements
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &array[i]);
        }
        
        // Initialize Fenwick Tree
        initFenwickTree(&ft, MAX_VALUE);
        
        // Build initial Fenwick Tree and count array
        for (int i = 1; i <= N; ++i) {
            add(&ft, array[i], 1);
        }
        
        // Process queries
        for (int q = 0; q < Q; ++q) {
            int type;
            scanf("%d", &type);
            
            if (type == 1) {
                // Operation 1: Update element at position A to Y
                int A, Y;
                scanf("%d %d", &A, &Y);
                
                int currentVal = array[A];
                if (currentVal != Y) {
                    add(&ft, currentVal, -1);
                    add(&ft, Y, 1);
                    array[A] = Y;
                }
                
            } else if (type == 2) {
                // Operation 2: Query how many numbers greater than X in range [A, B]
                int X, A, B;
                scanf("%d %d %d", &X, &A, &B);
                
                int greaterCount = rangeSum(&ft, X + 1, MAX_VALUE);
                printf("%d\n", greaterCount);
            }
        }
        
        // Print a blank line between test cases
        printf("\n");
    }
    
    return 0;
}
