#include <stdio.h>
#include <limits.h> // Para usar LLONG_MIN e LLONG_MAX
#include <stdint.h> // Para usar INT_MIN e INT_MAX

#define MAX_N 100000

int main() {
    int N;
    scanf("%d", &N);
    
    char actions[MAX_N + 1];
    scanf("%s", actions);
    
    // Tabelas de custo de água e emissão de gases
    int waterUsage[7] = {400, 100, 300, 700, 450, 0, 0};
    int gasEmission[7] = {0, 100, 200, 300, 150, 100, 50};
    
    // Tabelas de nutrição e velocidade
    int nutrition[7] = {300, 500, 400, 200, 1000, 0, 0};
    int speed[7] = {0, 80, 60, 40, 20, 80, 50};
    
    // Array para guardar o custo benefício acumulado
    long long costBenefit[MAX_N + 1] = {0};
    
    // Calcula o custo benefício acumulado
    for (int i = 1; i <= N; i++) {
        char action = actions[i - 1];
        if (action != 'N') {
            int index = action - 'A';
            if (index >= 0 && index < 7) {
                if (index < 4) {
                    costBenefit[i] = costBenefit[i - 1] + nutrition[index] - waterUsage[index];
                } else {
                    costBenefit[i] = costBenefit[i - 1] + speed[index] - gasEmission[index];
                }
            } else {
                costBenefit[i] = costBenefit[i - 1];
            }
        } else {
            costBenefit[i] = costBenefit[i - 1];
        }
    }
    
    // Encontrar o maior e o menor intervalo de custo benefício
    long long maxSubarraySum = LLONG_MIN;
    long long minSubarraySum = LLONG_MAX;
    long long currentSum = 0;
    
    for (int i = 1; i <= N; i++) {
        currentSum += costBenefit[i];
        if (currentSum > maxSubarraySum) {
            maxSubarraySum = currentSum;
        }
        if (currentSum < minSubarraySum) {
            minSubarraySum = currentSum;
        }
    }
    
    // Imprimir resultado
    printf("%lld %lld\n", maxSubarraySum, minSubarraySum);
    
    return 0;
}
