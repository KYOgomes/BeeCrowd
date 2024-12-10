/*
 * Rafael está jogando um novo e excitante jogo de RPG, e acaba de notar a existência de algo chamado Guilda. Para aqueles que não sabem, Guilda se trata de um grupo de jogadores que se unem com um objetivo em comum dentro do jogo, tirando assim vantagem do trabalho em equipe.

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
import java.util.Scanner;

public class Guildas_1527 {
    static class UnionFind {
        int[] pai;
        int[] altura;
        int[] tamanho;

        public UnionFind(int n) {
            pai = new int[n + 1];
            altura = new int[n + 1];
            tamanho = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                pai[i] = i;
                altura[i] = 0;
                tamanho[i] = 1;
            }
        }

        public int encontrar(int v) {
            if (v != pai[v]) {
                pai[v] = encontrar(pai[v]);
            }
            return pai[v];
        }

        public void unir(int a, int b) {
            int raizA = encontrar(a);
            int raizB = encontrar(b);

            if (raizA != raizB) {
                if (altura[raizA] > altura[raizB]) {
                    pai[raizB] = raizA;
                    tamanho[raizA] += tamanho[raizB];
                } else {
                    pai[raizA] = raizB;
                    tamanho[raizB] += tamanho[raizA];
                    if (altura[raizA] == altura[raizB]) {
                        altura[raizB]++;
                    }
                }
            }
        }

        public int tamanhoConjunto(int v) {
            return tamanho[encontrar(v)];
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int N = scanner.nextInt();
            int M = scanner.nextInt();
            if (N == 0 && M == 0) {
                break;
            }

            UnionFind uf = new UnionFind(N);
            int[] pontos = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                pontos[i] = scanner.nextInt();
            }

            int vitorias = 0;
            for (int i = 0; i < M; i++) {
                int Q = scanner.nextInt();
                int A = scanner.nextInt();
                int B = scanner.nextInt();

                if (Q == 1) {
                    uf.unir(A, B);
                } else if (Q == 2) {
                    int guildaA = uf.encontrar(A);
                    int guildaB = uf.encontrar(B);

                    if (guildaA != guildaB) {
                        int pontosA = uf.tamanhoConjunto(guildaA) > 1 ? pontos[A] : 0;
                        int pontosB = uf.tamanhoConjunto(guildaB) > 1 ? pontos[B] : 0;

                        if (guildaA == uf.encontrar(1)) {
                            if (pontosA > pontosB) {
                                vitorias++;
                            }
                        } else if (guildaB == uf.encontrar(1)) {
                            if (pontosB > pontosA) {
                                vitorias++;
                            }
                        }
                    }
                }
            }

            System.out.println(vitorias);
        }
        scanner.close();
    }
}
