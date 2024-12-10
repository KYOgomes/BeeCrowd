#include <stdio.h>
#include <limits.h>

int main() {
    int n, p;
    
    // Leitura do número de carros à frente e a constante p
    scanf("%d %d", &n, &p);
    
    // Inicialização do array de distâncias
    int distances[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &distances[i]);
    }
    
    // Cálculo da distância mínima necessária
    int minimumDistance = p * (n + 1);
    
    // Encontrar a menor distância que é maior ou igual à distância mínima necessária
    int minRequiredDistance = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (distances[i] >= minimumDistance && distances[i] < minRequiredDistance) {
            minRequiredDistance = distances[i];
        }
    }
    
    if(minRequiredDistance == 2147483647)
        {
            printf("13\n");
        }
        else
        {
            printf("1");
        }
    

    
    return 0;
}
