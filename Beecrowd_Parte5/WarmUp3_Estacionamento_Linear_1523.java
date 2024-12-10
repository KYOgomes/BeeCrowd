/*
Após muito tempo juntando dinheiro, Rafael finalmente conseguiu comprar seu carro (parcelado, é claro). Chega de pegar ônibus, agora sua vida será mais fácil. Pelo menos isso é o que ele pensava, até ouvir falar do estacionamento perto da faculdade onde ele decidiu estacionar o carro todos os dias.

O estacionamento tem apenas um corredor, com largura o suficiente para acomodar um carro, e profundidade suficiente para acomodar K carros, um atrás do outro. Como este estacionamento só tem um portão, só é possível entrar e sair por ele.

Quando o primeiro carro entra no estacionamento, o mesmo ocupa a posição próxima à parede, ao fundo do estacionamento. Todos os próximos carros estacionam logo atrás dele, formando uma fila. Obviamente, não é possível que um carro passe por cima de outro, portanto só é possível que um carro saia do estacionamento se ele for o último da fila.

Dados o horário de chegada e saída prevista de N motoristas, incluindo Rafael, diga se é possível que todos consigam estacionar e remover seus carros no estacionamento citado.

Entrada
Haverá diversos casos de teste. Cada caso de teste inicia com dois inteiros N e K (3 ≤ N ≤ 10⁴, 1 ≤ K ≤ 10³), representando o número de motoristas que farão uso do estacionamento, e o número de carros que o estacionamento consegue comportar, respectivamente.

Em seguida haverá N linhas, cada uma contendo dois inteiros Ci e Si (1 ≤ Ci, Si ≤ 10⁵), representando, respectivamente, o horário de chegada e saída do motorista i (1 ≤ i ≤ N). Os valores de Ci são dados de forma crescente, ou seja, Ci < Ci+1 para todo 1 ≤ i < N.

Não haverá mais de um motorista que chegam ao mesmo tempo, e nem mais de um motorista que saiam ao mesmo tempo. É possível que um motorista consiga estacionar no mesmo momento em que outro motorista deseja sair.

O último caso de teste é indicado quando N = K = 0, o qual não deverá ser processado.

Saída
Para cada caso de teste imprima uma linha, contendo a palavra “Sim”, caso seja possível que todos os N motoristas façam uso do estacionamento, ou “Nao” caso contrário.

Exemplo de Entrada
3 2
1 10
2 5
6 9
3 2
1 10
2 5
6 12
0 0

Exemplo de Saída
Sim
Nao
*/
import java.util.Scanner;

public class WarmUp3_Estacionamento_Linear_1523 {
    static final int MAX = 10000;

    static class Pilha {
        int topo;
        int[] chegada = new int[MAX];
        int[] saida = new int[MAX];
    }

    static Pilha cria_pilha() {
        Pilha p = new Pilha();
        p.topo = 0;
        return p;
    }

    static void liberar_pilha(Pilha p) {
        // Java garbage collection will handle freeing memory
    }

    static boolean esta_vazia(Pilha p) {
        return p.topo == 0;
    }

    static boolean esta_cheia(Pilha p, int vagas) {
        return p.topo == vagas;
    }

    static boolean push(Pilha p, int c, int s, int vagas) {
        if (!esta_cheia(p, vagas)) {
            p.chegada[p.topo] = c;
            p.saida[p.topo] = s;
            p.topo++;
            return true;
        } else {
            return false;
        }
    }

    static boolean pop(Pilha p) {
        if (!esta_vazia(p)) {
            p.topo--;
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k, n, ci, si;
        while (true) {
            n = scanner.nextInt();
            k = scanner.nextInt();
            if (k == 0 && n == 0) break;

            Pilha p = cria_pilha();
            boolean possivel = true;
            for (int i = 0; i < n; i++) {
                ci = scanner.nextInt();
                si = scanner.nextInt();
                if (possivel) {
                    if (esta_vazia(p)) {
                        push(p, ci, si, k);
                    } else {
                        while (ci >= p.saida[p.topo - 1]) {
                            pop(p);
                            if (esta_vazia(p)) break;
                        }
                        if (esta_cheia(p, k)) {
                            possivel = false;
                        } else {
                            push(p, ci, si, k);
                            if (p.topo > 1) {
                                if (p.chegada[p.topo - 1] > p.chegada[p.topo - 2] &&
                                        p.saida[p.topo - 1] < p.saida[p.topo - 2]) {
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
            if (possivel) {
                System.out.println("Sim");
            } else {
                System.out.println("Nao");
            }
            liberar_pilha(p);
        }
        scanner.close();
    }
}
