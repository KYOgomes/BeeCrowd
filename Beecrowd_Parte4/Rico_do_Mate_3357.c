#include <stdio.h>

// Função para leitura de entrada em C
float leia_reais() {
    float entrada;
    scanf("%f", &entrada);
    return entrada;
}

// Função principal
int main() {
    float entrada;
    int n, l, q, r, rei;
    float agua;
    char participantes[100][100]; // Matriz para armazenar os nomes dos participantes

    // Leitura da entrada para n, l, q
    scanf("%f", &entrada);
    n = (int)entrada; // Valor inteiro da primeira parte da entrada
    entrada = entrada * 10;
    l = (int)entrada; // Segunda parte da entrada, arredondada e convertida para inteiro
    entrada = entrada * 10;
    q = (int)entrada; // Terceira parte da entrada, arredondada e convertida para inteiro

    // Leitura dos nomes dos participantes
    for (int i = 0; i < n; i++) {
        scanf("%s", participantes[i]);
    }

    // Cálculo de r
    r = l % (n * q);

    // Condição principal do código pseudo-Cripto
    if (r % q == 0) {
        agua = q / 10.0;
        rei = (l - 1) % (n * q) / q + 1;
        printf("%s %.1f\n", participantes[rei], agua);
    } else {
        agua = r % q / 10.0;
        rei = r / q + 1;
        printf("%s %.1f\n", participantes[rei], agua);
    }

    return 0;
}
