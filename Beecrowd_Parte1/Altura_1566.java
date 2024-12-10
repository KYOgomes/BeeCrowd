/*
Cheio de boas ideias, agora o governo brasileiro resolveu criar a "bolsa altura". Desta forma, você foi incumbido de fazer o levantamento da altura da população de várias cidades e ordenar esta população por ordem crescente de altura. Você sabe que as cidades as quais terá que fazer isso tem menos de 3 milhões de habitantes e que ninguém, segundo o IBGE, tem mais do que 230 cm de altura nestas cidades.

Entrada
A entrada contém vários casos de teste. A primeira linha de entrada contém um inteiro NC (NC < 100) que indica a quantidade de casos de teste, ou seja de cidades. Para cada caso de teste, a primeira linha conterá um inteiro N (1 < N ≤ 3000000), indicando a quantidade de pessoas da cidade. A próxima linha irá conter a altura de cada uma destas pessoas, em centímetros, representado pela letra h (20 ≤ h  ≤ 230) e separados por um espaço em branco.

Saída
Para cada caso de teste de entrada, imprima uma linha contendo os valores das alturas de todos os moradores da cidade (em cm), por ordem crescente de altura, separados por um espaço em branco.

Obs.: O arquivo de entrada é bastante grande, portanto, utilize um método rápido para leitura / escrita.

Exemplo de Entrada	
6
10
65 31 37 37 72 76 61 35 57 37
12
45 186 185 55 51 51 22 78 64 26 49 21
10
20 93 203 67 64 225 112 81 58 180
8
169 189 220 228 68 32 214 180
6
133 55 67 166 112 41
4
39 38 120 55

Exemplo de Saída
31 35 37 37 37 57 61 65 72 76
21 22 26 45 49 51 51 55 64 78 185 186
20 58 64 67 81 93 112 180 203 225
32 68 169 180 189 214 220 228
41 55 67 112 133 166
38 39 55 120
*/

import java.util.Scanner;

public class Altura_1566 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int NC = scanner.nextInt();  // Número de casos de teste

        for (int k = 0; k < NC; ++k) {
            int N = scanner.nextInt();  // Número de alturas no caso de teste atual
            int[] alturas = new int[231];  // Array para contar as alturas (0 a 230)

            // Contagem de frequência das alturas
            for (int i = 0; i < N; ++i) {
                int altura = scanner.nextInt();
                alturas[altura]++;
            }

            boolean first = true;  // Flag para controlar a formatação da impressão
            // Impressão das alturas ordenadas
            for (int i = 20; i < 231; ++i) {
                for (int j = 0; j < alturas[i]; ++j) {
                    if (!first)
                        System.out.print(" ");
                    System.out.print(i);
                    first = false;
                }
            }
            System.out.println();  // Nova linha após cada caso de teste
        }

        scanner.close();
    }
}
