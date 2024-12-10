/*
 /*
O San Antonio é o time da cidade na NBA. Já foi algumas vezes campeão de sua conferência e revelou vários excelentes jogadores.

Em um campeonato de basquete os times jogam todos entre si em turno único. A vitória vale dois pontos e a derrota vale um ponto (não há empates no basquete). Havendo empates na pontuação do campeonato ﬁca na frente o time com melhor “cesta average” que é dado pela razão entre o número de pontos marcados pelo time dividido pelo número de pontos recebidos (na improvável hipótese de um time vencer todos os jogos do campeonato sem levar cestas seu cesta average é dado pelo número de pontos marcados). Persistindo o empate, leva vantagem quem marcou mais pontos. Ainda havendo empate, o time com o menor número de inscrição na liga ﬁca na frente.

Sua tarefa neste problema é fazer um programa que recebe os resultados dos jogos de um campeonato e imprime a classiﬁcação ﬁnal.

Entrada
São dadas várias instâncias. Para cada instância é dada o número 0 ≤ n ≤ 100 de times no campeonato. O valor n = 0 indica o ﬁm dos dados. A seguir vêm n (n−1) / 2 linhas indicando os resultados das partidas. Em cada linha são dados quatro inteiros x, y, z e w. Os inteiros x e z pertencem ao conjunto {1, 2, . . . , n} e representam os números de inscrição dos times na liga. Os inteiros y e w são, respectivamente, os números de pontos do time x e do time z na partida descrita.

Saída
Para cada instância solucionada, você deverá imprimir um identiﬁcador "Instancia h" em que h é um número inteiro, sequencial e crescente a partir de 1. Na linha seguinte, deve ser impressa a permutação dos inteiros 1 a n da classiﬁcação do campeonato.

Obs: Um espaço em branco deve ser impresso entre cada um desses inteiros e uma linha em branco deve deve ser impressa entre as saídas de dois casos de teste.

Exemplo de Entrada	
5
1 102 2 62
1 128 3 127
1 144 4 80
1 102 5 101
2 62 3 61
2 100 4 80
2 88 5 82
3 79 4 90
3 87 5 100
4 110 5 99
0

Exemplo de Saída
Instancia 1
1 2 4 5 3

*/
 
import java.util.Arrays;
import java.util.Scanner;

class Time implements Comparable<Time> {
    int numero;
    int pontos;
    int marcados;
    int tomados;

    Time() {
        this.numero = 0;
        this.pontos = 0;
        this.marcados = 0;
        this.tomados = 0;
    }

    public int compareTo(Time other) {
        if (this.pontos != other.pontos) {
            return other.pontos - this.pontos;
        }
        float thisRatio = (this.tomados == 0) ? this.marcados : (float) this.marcados / this.tomados;
        float otherRatio = (other.tomados == 0) ? other.marcados : (float) other.marcados / other.tomados;
        if (thisRatio != otherRatio) {
            return Float.compare(otherRatio, thisRatio);
        }
        if (this.marcados != other.marcados) {
            return other.marcados - this.marcados;
        }
        return other.numero - this.numero;
    }
}

public class Spurs_Rocks_1303 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = 0;

        while (true) {
            int n = sc.nextInt();
            if (n == 0) break;
            if (h != 0) System.out.println();
            h++;

            Time[] array = new Time[n];
            for (int i = 0; i < n; i++) {
                array[i] = new Time();
            }

            int p = n * (n - 1) / 2;
            for (int i = 0; i < p; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                int z = sc.nextInt();
                int w = sc.nextInt();

                if (array[x - 1].numero == 0) array[x - 1].numero = x;
                if (array[z - 1].numero == 0) array[z - 1].numero = z;

                array[x - 1].marcados += y;
                array[x - 1].tomados += w;
                array[z - 1].marcados += w;
                array[z - 1].tomados += y;

                if (y - w > 0) {
                    array[x - 1].pontos += 2;
                    array[z - 1].pontos += 1;
                } else {
                    array[z - 1].pontos += 2;
                    array[x - 1].pontos += 1;
                }
            }

            Arrays.sort(array);

            System.out.println("Instancia " + h);
            for (int i = 0; i < n; i++) {
                System.out.print(array[i].numero);
                if (i < n - 1) System.out.print(" ");
            }
            System.out.println();
        }
        sc.close();
    }
}
