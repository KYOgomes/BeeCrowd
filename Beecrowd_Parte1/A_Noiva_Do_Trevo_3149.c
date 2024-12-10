#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Q 1000

// Estrutura para armazenar os relatos
struct Relato {
    char nome[101]; // Nome do morador
    int horario;    // Horário do avistamento em minutos desde a meia-noite
};

// Função para converter o horário HH:MM para minutos desde a meia-noite
int parseTime(char *hora) {
    int horas, minutos;
    sscanf(hora, "%d:%d", &horas, &minutos);
    return horas * 60 + minutos;
}

// Função de comparação para ordenar os relatos por horário
int compararRelatos(const void *a, const void *b) {
    struct Relato *relatoA = (struct Relato *)a;
    struct Relato *relatoB = (struct Relato *)b;
    return relatoA->horario - relatoB->horario;
}

int main() {
    int P, Q;
    struct Relato relatos[MAX_Q];

    // Leitura de P e Q
    scanf("%d %d", &P, &Q);

    // Leitura dos relatos
    for (int i = 0; i < Q; i++) {
        char hora[6], nome[101];
        scanf("%s %[^\n]", hora, nome);

        // Converte o horário para minutos desde a meia-noite
        int minutos = parseTime(hora);

        // Verifica se está dentro do intervalo próximo à meia-noite
        if (minutos <= P || minutos >= 1440 - P) {
            strcpy(relatos[i].nome, nome);
            relatos[i].horario = minutos;
        } else {
            // Não armazena relatos fora do intervalo
            i--;
            Q--;
        }
    }

    // Ordena os relatos pelo horário
    qsort(relatos, Q, sizeof(struct Relato), compararRelatos);

    // Saída dos nomes dos moradores ordenados pelo horário do relato
    for (int i = 0; i < Q; i++) {
        printf("%s\n", relatos[i].nome);
    }
    return 0;
}
