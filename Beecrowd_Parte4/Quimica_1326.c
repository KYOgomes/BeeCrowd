#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//saida errada
#define MAX_R 1000
#define MAX_S 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int inDegree;
    int level;
    int numNeighbors;
    char neighbors[MAX_S][MAX_NAME];
} Substance;

Substance substances[MAX_S];
int numSubstances;

Substance* findSubstance(char* name) {
    for (int i = 0; i < numSubstances; ++i) {
        if (strcmp(substances[i].name, name) == 0) {
            return &substances[i];
        }
    }
    strcpy(substances[numSubstances].name, name);
    return &substances[numSubstances++];
}

void addEdge(Substance* from, Substance* to) {
    strcpy(from->neighbors[from->numNeighbors++], to->name);
    ++to->inDegree;
}

int main() {
    while (1) {
        int R;
        scanf("%d", &R);
        if (R == 0) break;
        getchar();  // Consumir a linha restante

        numSubstances = 0;
        memset(substances, 0, sizeof(substances));

        char finalProduct[MAX_NAME];
        for (int i = 0; i < R; ++i) {
            char S1[MAX_NAME], S2[MAX_NAME], S3[MAX_NAME];
            scanf("%s + %s -> %s", S1, S2, S3);
            getchar();  // Consumir a linha restante

            Substance* substance1 = findSubstance(S1);
            Substance* substance2 = findSubstance(S2);
            Substance* substance3 = findSubstance(S3);

            addEdge(substance1, substance3);
            addEdge(substance2, substance3);

            if (i == R - 1) {
                strcpy(finalProduct, S3);
            }
        }

        // Realizar a ordenação topológica
        Substance* queue[MAX_S];
        int front = 0, back = 0;

        for (int i = 0; i < numSubstances; ++i) {
            if (substances[i].inDegree == 0) {
                queue[back++] = &substances[i];
                substances[i].level = 1;
            }
        }

        while (front != back) {
            Substance* current = queue[front++];
            int currentLevel = current->level;

            for (int i = 0; i < current->numNeighbors; ++i) {
                Substance* neighbor = findSubstance(current->neighbors[i]);
                --neighbor->inDegree;
                if (neighbor->inDegree == 0) {
                    queue[back++] = neighbor;
                    neighbor->level = currentLevel + 1;
                }
            }
        }

        // O número de recipientes necessários é a profundidade máxima da DAG
        int containersNeeded = findSubstance(finalProduct)->level;
        printf("%s requires %d containers\n", finalProduct, containersNeeded);
    }

    return 0;
}