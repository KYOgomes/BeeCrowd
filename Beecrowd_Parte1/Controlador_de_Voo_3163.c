#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aviao {
    char id[5];
    struct Aviao* next;
} Aviao;

typedef struct {
    Aviao* head;
    Aviao* tail;
} Fila;

void inicializarFila(Fila* fila) {
    fila->head = NULL;
    fila->tail = NULL;
}

void adicionarNaFila(Fila* fila, char* id) {
    Aviao* novoAviao = (Aviao*)malloc(sizeof(Aviao));
    strcpy(novoAviao->id, id);
    novoAviao->next = NULL;

    if (fila->tail != NULL) {
        fila->tail->next = novoAviao;
    }
    fila->tail = novoAviao;

    if (fila->head == NULL) {
        fila->head = novoAviao;
    }
}

char* removerDaFila(Fila* fila) {
    if (fila->head == NULL) {
        return NULL;
    }
    Aviao* aviao = fila->head;
    fila->head = aviao->next;
    if (fila->head == NULL) {
        fila->tail = NULL;
    }
    char* id = (char*)malloc(5 * sizeof(char));
    strcpy(id, aviao->id);
    free(aviao);
    return id;
}

int main() {
    Fila oeste, norte, sul, leste;
    inicializarFila(&oeste);
    inicializarFila(&norte);
    inicializarFila(&sul);
    inicializarFila(&leste);

    int pontoCardeal;
    char id[5];

    while (1) {
        scanf("%d", &pontoCardeal);
        if (pontoCardeal == 0) {
            break;
        }

        scanf("%s", id);

        switch (pontoCardeal) {
            case -1:
                adicionarNaFila(&oeste, id);
                break;
            case -2:
                adicionarNaFila(&sul, id);
                break;
            case -3:
                adicionarNaFila(&norte, id);
                break;
            case -4:
                adicionarNaFila(&leste, id);
                break;
            default:
                break;
        }
    }

    while (oeste.head != NULL || norte.head != NULL || sul.head != NULL || leste.head != NULL) {
        if (oeste.head != NULL) {
            printf("%s ", removerDaFila(&oeste));
        }
        if (norte.head != NULL) {
            printf("%s ", removerDaFila(&norte));
        }
        if (sul.head != NULL) {
            printf("%s ", removerDaFila(&sul));
        }
        if (leste.head != NULL) {
            printf("%s ", removerDaFila(&leste));
        }
    }
    printf("\n");

    return 0;
}
