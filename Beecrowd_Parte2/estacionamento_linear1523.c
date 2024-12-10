#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

typedef struct {
    int topo;
    int chegada[MAX];
    int saida[MAX];
} Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = 0;
}

bool estaVazia(Pilha *p) {
    return p->topo == 0;
}

bool estaCheia(Pilha *p, int vagas) {
    return p->topo == vagas;
}

bool push(Pilha *p, int c, int s, int vagas) {
    if (!estaCheia(p, vagas)) {
        p->chegada[p->topo] = c;
        p->saida[p->topo] = s;
        p->topo++;
        return true;
    } else {
        return false;
    }
}

bool pop(Pilha *p) {
    if (!estaVazia(p)) {
        p->topo--;
        return true;
    } else {
        return false;
    }
}

int getChegadaTopo(Pilha *p) {
    return p->chegada[p->topo - 1];
}

int getSaidaTopo(Pilha *p) {
    return p->saida[p->topo - 1];
}

int getChegada(Pilha *p, int index) {
    return p->chegada[index];
}

int getSaida(Pilha *p, int index) {
    return p->saida[index];
}

int main() {
    int k, n, ci, si;

    while (1) {
        scanf("%d %d", &n, &k);
        if (k == 0 && n == 0) break;

        Pilha p;
        inicializaPilha(&p);
        bool possivel = true;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &ci, &si);

            if (possivel) {
                if (estaVazia(&p)) {
                    push(&p, ci, si, k);
                    possivel = true;
                } else {
                    while (ci >= getSaidaTopo(&p)) {
                        pop(&p);
                        if (estaVazia(&p)) break;
                    }
                    if (estaCheia(&p, k)) {
                        possivel = false;
                    } else {
                        push(&p, ci, si, k);
                        if (p.topo > 1) {
                            if (getChegada(&p, p.topo - 1) > getChegada(&p, p.topo - 2) &&
                                getSaida(&p, p.topo - 1) < getSaida(&p, p.topo - 2)) {
                                possivel = true;
                            } else {
                                possivel = false;
                            }
                        } else {
                            possivel = true;
                        }
                    }
                }
            }
        }

        if (possivel) printf("Sim\n");
        else printf("Nao\n");
    }

    return 0;
}
