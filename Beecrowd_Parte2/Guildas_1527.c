/*
Rafael está jogando um novo e excitante jogo de RPG, e acaba de notar a existência de algo chamado Guilda. Para aqueles que não sabem, Guilda se trata de um grupo de jogadores que se unem com um objetivo em comum dentro do jogo, tirando assim vantagem do trabalho em equipe.

O jogo que Rafael joga tem um sistema de GVG (Guilda versus Guilda) bem disputado, e logo percebeu que deveria tomar algumas providencias para se sair bem nessas batalhas.

O sistema de GVG funciona da seguinte maneira: a batalha acontece entre duas guildas, e vence a guilda que tiver o maior número de pontos. O número de pontos de uma guilda é dado pela soma do número de pontos de todos os jogadores presentes na guilda. Cada jogador tem um número de pontos, que corresponde ao seu nível atual.

Considere que inicialmente, todos os jogadores fazem parte de uma guilda, contendo apenas o próprio jogador. A união entre duas guildas faz com que todos os jogadores de ambas as guildas passem a participar apenas de uma guilda, e a outra deixa de existir.

Dada uma lista de ações no decorrer do jogo, entre elas união entre duas guildas e batalhas entre duas guildas, diga o número de vezes em que a guilda em que Rafael estava saiu vitoriosa de uma batalha.

Entrada
Haverá diversos casos de teste. Cada caso de teste inicia com dois inteiros N e M (1 ≤ N ≤ 10⁵, 1 ≤ M ≤ 5 * 10⁵), representando o número de jogadores dentro do jogo, e o número de ações no decorrer do jogo, respectivamente.

Em seguida haverá N inteiros Pi (1 ≤ Pi ≤ 100), onde o i-ésimo inteiro representa o número de pontos que o i-ésimo jogador tem, para todo 1 ≤ i ≤ N. Rafael é o jogador número 1, sempre.

Em seguida, haverá M linhas, contendo três inteiros cada, Q, A e B (1 ≤ Q ≤ 2, 1 ≤ A, B ≤ N), representando o tipo da ação, e as duas guildas envolvidas na ação. Se Q for igual a 1, significa que a guilda que contém o jogador A e a guilda que contém o jogador B estão se unindo. Se Q for igual a 2, significa que a guilda que contém o jogador A e a guilda que contém o jogador B participarão de uma batalha.

O último caso de teste é indicado quando N = M = 0, o qual não deverá ser processado.

Saída
Para cada caso de teste imprima uma linha, contendo um inteiro, indicando o número de batalhas em que a guilda em que Rafael está participando ganhou uma batalha. Note que empates não são considerados vitórias.

Exemplo de Entrada	
5 5
5 3 4 3 2
1 1 2
1 3 4
2 2 4
1 4 5
2 1 3
0 0

Exemplo de Saída
1

*/
#include <stdio.h>

#define MAXN 100001

int pai[MAXN];
int altura[MAXN];
int tamanho[MAXN];

void criar_conjunto(int v) {
    pai[v] = v;
    altura[v] = 0;
    tamanho[v] = 1;
}

int encontrar_conjunto(int v) {
    if (v != pai[v]) {
        pai[v] = encontrar_conjunto(pai[v]);
    }
    return pai[v];
}

void unir_conjuntos(int a, int b) {
    a = encontrar_conjunto(a);
    b = encontrar_conjunto(b);
    if (a != b) {
        if (altura[a] < altura[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        pai[b] = a;
        if (altura[a] == altura[b]) {
            altura[a]++;
        }
        tamanho[a] += tamanho[b];
    }
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) && (N != 0 || M != 0)) {
        // Inicialização
        for (int i = 1; i <= N; ++i) {
            criar_conjunto(i);
        }
        
        // Leitura dos pontos dos jogadores
        int pontos[MAXN];
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &pontos[i]);
        }
        
        // Processamento das ações
        int vitorias = 0;
        for (int i = 0; i < M; ++i) {
            int Q, A, B;
            scanf("%d %d %d", &Q, &A, &B);
            
            if (Q == 1) {
                unir_conjuntos(A, B);
            } else if (Q == 2) {
                int guildaA = encontrar_conjunto(A);
                int guildaB = encontrar_conjunto(B);
                
                if (guildaA != guildaB) {
                    int pontosA = tamanho[guildaA] > 1 ? pontos[A] : 0;
                    int pontosB = tamanho[guildaB] > 1 ? pontos[B] : 0;
                    
                    if (guildaA == encontrar_conjunto(1)) {
                        if (pontosA > pontosB) {
                            vitorias++;
                        }
                    } else if (guildaB == encontrar_conjunto(1)) {
                        if (pontosB > pontosA) {
                            vitorias++;
                        }
                    }
                }
            }
        }
        
        // Resultado para este caso de teste
        printf("%d\n", vitorias);
    }
    
    return 0;
}
