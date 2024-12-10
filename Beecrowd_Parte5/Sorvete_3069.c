#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um intervalo [start, end]
typedef struct {
    int start;
    int end;
} Interval;

// Função para comparar dois intervalos pelo início (start)
int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return intervalA->start - intervalB->start;
}

int main() {
    int testNumber = 1;
    int P, S;

    while (1) {
        scanf("%d %d", &P, &S);

        if (P == 0 && S == 0) break;

        // Leitura dos intervalos de trabalho de cada sorveteiro
        Interval *intervals = (Interval *)malloc(S * sizeof(Interval));
        for (int i = 0; i < S; i++) {
            scanf("%d %d", &intervals[i].start, &intervals[i].end);
        }

        // Ordenação dos intervalos pelo início (start)
        qsort(intervals, S, sizeof(Interval), compare);

        // Mesclagem dos intervalos
        Interval *mergedIntervals = (Interval *)malloc(S * sizeof(Interval));
        int mergedCount = 0;

        if (S > 0) {
            mergedIntervals[0] = intervals[0];
            mergedCount = 1;

            for (int i = 1; i < S; i++) {
                if (intervals[i].start <= mergedIntervals[mergedCount - 1].end) {
                    // Atualiza o fim do último intervalo mesclado se houver sobreposição
                    mergedIntervals[mergedCount - 1].end = intervals[i].end > mergedIntervals[mergedCount - 1].end
                                                            ? intervals[i].end
                                                            : mergedIntervals[mergedCount - 1].end;
                } else {
                    // Adiciona um novo intervalo mesclado
                    mergedIntervals[mergedCount] = intervals[i];
                    mergedCount++;
                }
            }
        }

        // Impressão do resultado para o conjunto de teste
        printf("Teste %d\n", testNumber++);
        for (int i = 0; i < mergedCount; i++) {
            printf("%d %d\n", mergedIntervals[i].start, mergedIntervals[i].end);
        }
        printf("\n");

        // Liberação de memória
        free(intervals);
        free(mergedIntervals);
    }

    return 0;
}
