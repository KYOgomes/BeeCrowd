/*
Será dado a você um vetor com N números, onde todos estarão em pares. Porém um desses números acabou
ficando sem par, você consegue identificar qual é esse número ?

Por exemplo, A = {1, 1, 3, 3, 5, 5, 5}, o número que ficou sozinho foi o 5.

Entrada
A entrada é composta por vários casos de teste. Cada caso de teste é composto por uma linha contendo um inteiro N (1 ≤ N < 10^5), seguida por N números A (0 ≤ A ≤ 10^12). A entrada termina quando N = 0 e não deve ser processada.

Saída
Para cada caso de teste imprima apenas o número que ficou sozinho. É garantido que apenas um número está sozinho.

Exemplo de Entrada	
5
1 3 4 3 1
3
1 1 1
7
1 1 3 3 5 5 5
0

Exemplo de Saída
4
1
5

*/
#include <stdio.h>

int main() {
    int N; // Variável para armazenar o número de elementos no vetor para cada caso de teste
    while (1) { // Loop infinito para ler vários casos de teste
        scanf("%d", &N); // Lê o número de elementos do vetor para este caso de teste
        if (N == 0) break; // Se N for zero, termina o loop (fim da entrada)
        
        long long int xor_result = 0; // Variável para armazenar o resultado do XOR de todos os números do vetor
        for (int i = 0; i < N; ++i) { // Loop para ler os N números do vetor
            long long int num;
            scanf("%lld", &num); // Lê cada número do vetor
            xor_result ^= num; // Aplica o operador XOR para encontrar o número sem par
        }
        
        printf("%lld\n", xor_result); // Imprime o número que ficou sem par
    }
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}

