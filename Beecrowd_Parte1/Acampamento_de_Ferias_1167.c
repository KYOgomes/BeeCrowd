#include <stdio.h>
#include <string.h>

struct crianca {
    char nome[30];
    int valor;
    int marcado;
    struct crianca *ant;
    struct crianca *prox;
};

int main() {
    int n, i, comp, comp1;
    
    while (scanf("%d", &n) && n) {          
        struct crianca array[n];
        
        // Ler dados das crianças
        for (i = 0; i < n; i++) {
            scanf(" %s %d", array[i].nome, &array[i].valor);
            array[i].marcado = 0;
            if (i != 0) {
                array[i].ant = &array[i - 1];
                array[i - 1].prox = &array[i];
            }
        }
        array[n - 1].prox = &array[0];
        array[0].ant = &array[n - 1];
        
        // Inicializar variáveis de controle
        int marcados = 0;
        comp = array[0].valor;
        int n1 = n - 1;
        
        // Processo da gincana
        while (marcados != n1 && n >= 2) {
            if (comp % 2 != 0) {
                comp = comp % n;
                if (comp == 0) {
                    array[n - 1].prox = &array[0];
                    array[0].ant = &array[n - 1];
                } else {
                    array[comp - 1].prox = &array[comp + 1];
                    array[comp + 1].ant = &array[comp - 1];
                }
                comp1 = array[comp].valor;
                array[comp].marcado = 1;
                marcados++;
                n--;
                comp = comp1;
            } else {
                comp = comp % n;
                if (comp == 0) {
                    array[n - 1].prox = &array[0];
                    array[0].ant = &array[n - 1];
                } else {
                    array[n - comp - 1].prox = &array[n - comp + 1];
                    array[n - comp + 1].ant = &array[n - comp - 1];
                }
                comp1 = array[n - comp].valor;
                array[n - comp].marcado = 1;
                marcados++;
                n--;
                comp = comp1;
            }
        }
        
        // Encontrar o vencedor
        for (i = 0; i < n; i++) {
            if (array[i].marcado == 0) {
                break;
            }
        }
        
        // Imprimir resultado
        printf("Vencedor(a): %s\n", array[i].nome);
    }
    
    return 0;
}
