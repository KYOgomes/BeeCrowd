#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa um Ser com nome, poder, kill e morte
typedef struct {
    char nome[21]; // 20 caracteres + 1 para o terminador null
    int poder;
    int kill;
    int morte;
} Ser;

// Função de comparação para qsort
int compararSer(const void *a, const void *b) {
    Ser *s1 = (Ser *)a;
    Ser *s2 = (Ser *)b;

    if (s1->poder != s2->poder) {
        return s2->poder - s1->poder; // Ordena por poder decrescente
    } else if (s1->kill != s2->kill) {
        return s2->kill - s1->kill; // Ordena por kill decrescente
    } else if (s1->morte != s2->morte) {
        return s1->morte - s2->morte; // Ordena por morte crescente
    } else {
        return strcmp(s1->nome, s2->nome); // Ordena por nome crescente
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // Consumir o newline após o número

    Ser seres[n];

    // Leitura dos seres
    for (int i = 0; i < n; i++) {
        char nome[21];
        int poder, kill, morte;
        scanf("%s %d %d %d", nome, &poder, &kill, &morte);
        strcpy(seres[i].nome, nome);
        seres[i].poder = poder;
        seres[i].kill = kill;
        seres[i].morte = morte;
    }

    // Ordenação dos seres usando qsort com o comparador compararSer
    qsort(seres, n, sizeof(Ser), compararSer);

    // Imprimir o nome do primeiro ser (godofor)
    if (n > 0) {
        printf("%s\n", seres[0].nome);
    }

    return 0;
}
