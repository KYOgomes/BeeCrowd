#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura da Árvore de Fenwick (BIT)
typedef struct {
    int *tree;
    int size;
} BIT;

// Inicializa a Árvore de Fenwick
BIT *createBIT(int size) {
    BIT *bit = (BIT *)malloc(sizeof(BIT));
    bit->size = size;
    bit->tree = (int *)calloc(size + 1, sizeof(int));
    return bit;
}

// Função para atualizar um elemento na BIT
void update(BIT *bit, int index, int delta) {
    while (index <= bit->size) {
        bit->tree[index] += delta;
        index += index & (-index);
    }
}

// Função para realizar uma consulta de soma até o índice 'index'
int query(BIT *bit, int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit->tree[index];
        index -= index & (-index);
    }
    return sum;
}

// Função para realizar uma consulta de soma no intervalo [left, right]
int queryRange(BIT *bit, int left, int right) {
    return query(bit, right) - query(bit, left - 1);
}

// Libera a memória da BIT
void freeBIT(BIT *bit) {
    free(bit->tree);
    free(bit);
}

int main() {
    int T;
    scanf("%d", &T); // Número de instâncias
    getchar(); // Consumir o newline após T
    
    while (T-- > 0) {
        int N;
        scanf("%d", &N); // Quantidade de pilhas
        int *pilhas = (int *)malloc((N + 1) * sizeof(int));
        
        // Inicialização das pilhas e da BIT
        BIT *bit = createBIT(N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &pilhas[i]);
            update(bit, i, pilhas[i]);
        }
        
        int Q;
        scanf("%d", &Q); // Quantidade de operações
        
        while (Q-- > 0) {
            int tipoOperacao;
            scanf("%d", &tipoOperacao);
            
            if (tipoOperacao == 1) {
                int X, Y, K;
                scanf("%d %d %d", &X, &Y, &K);
                
                // Consulta quantidade de elementos no intervalo [X, Y]
                int quantidadeXaY = queryRange(bit, X, Y);
                printf("%d\n", quantidadeXaY);
            } else if (tipoOperacao == 2) {
                int X, W;
                scanf("%d %d", &X, &W);
                
                // Atualiza a pilha na posição X com o valor W
                int valorAntigo = pilhas[X];
                int delta = W - valorAntigo;
                pilhas[X] = W;
                update(bit, X, delta);
            }
        }
        
        free(pilhas);
        freeBIT(bit);
    }
    
    return 0;
}
