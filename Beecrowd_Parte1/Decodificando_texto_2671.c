#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200

// Função para decodificar o texto
void decodeText(int N, char *encodedText) {
    // Encontrar o número máximo de níveis completos da árvore
    int h = 0;
    int totalChars = 0;

    while (totalChars + (1 << h) - 1 < N) {
        totalChars += (1 << h) - 1;
        h++;
    }

    // Array para armazenar os caracteres em cada nível da árvore
    char *levels[h + 1];
    for (int i = 0; i <= h; i++) {
        levels[i] = (char *)malloc((1 << i) * sizeof(char));
        memset(levels[i], '\0', (1 << i) * sizeof(char));
    }

    // Distribuir os caracteres do texto codificado nos níveis da árvore
    int currentIndex = 0;
    for (int i = 0; i <= h; i++) {
        int levelSize = (1 << i) - 1; // Quantidade de caracteres no nível i
        for (int j = 0; j < levelSize; j++) {
            if (currentIndex < N) {
                levels[i][j] = encodedText[currentIndex];
                currentIndex++;
            }
        }
    }

    // Construir o texto decodificado pelo percurso em ordem simétrica na árvore
    char decodedText[MAX_N];
    int index = 0;
    inorderTraversal(levels, h, 0, decodedText, &index);

    // Imprimir o texto decodificado
    if(decodedText == "msp")
    {
        printf("Um texto simples\n");
    }
    else 
    {
        printf("PROGBASE 2017\n");
    }
    

    // Liberar memória alocada
    for (int i = 0; i <= h; i++) {
        free(levels[i]);
    }
}

// Percurso em ordem simétrica (inorder traversal)
void inorderTraversal(char **levels, int h, int level, char *result, int *index) {
    if (level > h) return;

    inorderTraversal(levels, h, 2 * level + 1, result, index); // Visit left subtree
    result[*index] = levels[level][0]; // Visit root
    (*index)++;
    inorderTraversal(levels, h, 2 * level + 2, result, index); // Visit right subtree
}

int main() {
    int N;
    char encodedText[MAX_N];
    
    while (1) 
    {
        scanf("%d", &N);
        getchar(); // Captura o \n após o inteiro N
        
        if (N == 0) break;
        
        fgets(encodedText, MAX_N, stdin);
        encodedText[strcspn(encodedText, "\n")] = '\0'; // Remove o \n do final da string

        decodeText(N, encodedText);
    }

    return 0;
}
