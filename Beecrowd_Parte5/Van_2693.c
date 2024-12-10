#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa um aluno com nome, cidade e idade
typedef struct {
    char nome[21]; // 20 caracteres + 1 para o terminador null
    char cidade[21];
    int idade;
} Aluno;

// Função de comparação para qsort
int compararAluno(const void *a, const void *b) {
    Aluno *aluno1 = (Aluno *)a;
    Aluno *aluno2 = (Aluno *)b;

    if (aluno1->idade != aluno2->idade) {
        return aluno1->idade - aluno2->idade; // Ordena por idade crescente
    } else {
        int cmpCidade = strcmp(aluno1->cidade, aluno2->cidade);
        if (cmpCidade != 0) {
            return cmpCidade; // Ordena por cidade em ordem alfabética
        } else {
            return strcmp(aluno1->nome, aluno2->nome); // Ordena por nome em ordem alfabética
        }
    }
}

int main() {
    int q;
    while (scanf("%d", &q) == 1 && q > 0) {
        getchar(); // Consumir o newline após o número

        Aluno alunos[q];

        // Leitura dos alunos
        for (int i = 0; i < q; i++) {
            scanf("%s %s %d", alunos[i].nome, alunos[i].cidade, &alunos[i].idade);
            getchar(); // Consumir o newline após cada linha
        }

        // Ordenação dos alunos usando qsort com o comparador compararAluno
        qsort(alunos, q, sizeof(Aluno), compararAluno);

        // Imprimir os nomes dos alunos ordenados
        for (int i = 0; i < q; i++) {
            printf("%s\n", alunos[i].nome);
        }
    }

    return 0;
}
