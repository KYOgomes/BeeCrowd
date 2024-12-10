/*
Devido às constantes estiagens que aconteceram nos últimos tempos em algumas regiões do Brasil, o governo federal criou um órgão para a avaliação do consumo destas regiões com finalidade de verificar o comportamento da população na época de racionamento. Este órgão responsável irá pegar algumas cidades (por amostragem) e verificará como está sendo o consumo de cada uma das pessoas da cidade e o consumo médio de cada cidade por habitante.

Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 1*106), indicando a quantidade de imóveis. As N linhas contém um par de valores X (1 ≤ X ≤ 10) e Y (1 ≤ Y ≤ 200), indicando a quantidade de moradores de cada imóvel e o respectivo consumo total de cada imóvel (em m3). Com certeza, nenhuma residência consome mais do que 200 m3 por mês. O final da entrada é representado pelo número zero.

Saída
Para cada entrada, deve-se apresentar a mensagem “Cidade# n:”, onde n é o número da cidade seguindo a sequência (1, 2, 3, ...) e em seguida deve-se listar, por ordem ascendente de consumo, a quantidade de pessoas seguido de um hífen e o consumo destas pessoas, arredondando o valor para baixo. Na terceira linha da saída deve-se mostrar o consumo médio por pessoa da cidade, com 2 casas decimais sem arredondamento, considerando o consumo real total. Imprimir uma linha em branco entre dois casos de teste consecutivos. No fim da saída não deve haver uma linha em branco.

Exemplo de Entrada
3
3 22
2 11
3 39
5
1 25
2 20
3 31
2 40
6 70
2
1 1
3 2
0

Exemplo de Saída
Cidade# 1:
2-5 3-7 3-13
Consumo medio: 9.00 m3.

Cidade# 2:
5-10 6-11 2-20 1-25
Consumo medio: 13.28 m3.

Cidade# 3:
3-0 1-1
Consumo medio: 0.75 m3.

*/

import java.util.Scanner;

public class Estiagem_1023 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = 0;
        
        while (true) {
            int N = scanner.nextInt();
            if (N == 0)
                break;

            if (T > 0)
                System.out.println();

            // Inicializando o array consumos com zeros
            int[] consumos = new int[201];
            int totalX = 0, totalY = 0;

            for (int i = 0; i < N; i++) {
                int X = scanner.nextInt();
                int Y = scanner.nextInt();

                totalX += X;
                totalY += Y;
                consumos[Y / X] += X;
            }

            System.out.printf("Cidade# %d:\n", ++T);
            boolean first = true;
            for (int i = 0; i < 201; i++) {
                if (consumos[i] > 0) {
                    if (!first)
                        System.out.print(" ");
                    else
                        first = false;
                    
                    System.out.printf("%d-%d", consumos[i], i);
                }
            }

            double consumo_medio = ((100.0 * totalY) / totalX) / 100.0;
            System.out.printf("\nConsumo medio: %.2f m3.\n", consumo_medio);
        }

        scanner.close();
    }
}
