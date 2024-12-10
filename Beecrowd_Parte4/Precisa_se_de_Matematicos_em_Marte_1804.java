/*
Aconteceu na semana passada em Beberibe, CE, o VIII Latin-American Algorithms, Graphs and Optimisation Symposium (LAGOS 2015), uma conferência que reuniu matemáticos e cientistas da Computação do mundo todo para discutirem alguns desafios computacionais. A fim de que os participantes pudessem relaxar um pouco, os organizadores do evento contrataram buggies para levar os pesquisadores a alguns pontos turísticos da região. Os buggies saíram do hotel numa fila, um atrás do outro.

Quem conhece os passeios de buggy do Ceará sabe que o turista pode pedir ao bugueiro um passeio com emoção ou sem emoção. No entanto, a excursão do LAGOS contou com uma emoção extra. Como em Marte atualmente há uma carência de pesquisadores em Algoritmos, Grafos e Otimização, alienígenas marcianos começaram a abduzir alguns buggies, com todas as pessoas a bordo (inclusive o pobre bugueiro, que nada tinha a ver com a história). Foi muito triste nosso planeta ter perdido mentes tão brilhantes para Marte, mas a tragédia teria sido menor se cada bugueiro mantivesse atualizada a informação de quantas pessoas no total estavam nos buggies atrás dele — assim ele poderia perceber a aproximação da sonda alienígena e acelerar o buggy.

Entrada
Um inteiro N (1 ≤ N ≤ 105) constitui a primeira linha da entrada, o qual representa o número de buggies que deixaram o hotel. A segunda linha da entrada é constituída por N inteiros pi (1 ≤ pi ≤ 5, 1 ≤ i ≤ N), cada um representando o número de pessoas no buggy i (incluindo o bugueiro). Cada uma das linhas seguintes pode ser constituída:

por um caractere 'a' seguido de um inteiro i (1 ≤ i ≤ N), o qual caracteriza a abdução do buggy i (que ainda não havia sido abduzido);
por um caractere '?' seguido de um inteiro i (1 ≤ i ≤ N), o qual caracteriza que, naquele momento, o bugueiro do (ainda) não abduzido buggy i gostaria de saber quantas pessoas da excursão restavam atrás do seu buggy.
Considere que o identificador i de um buggy não muda. Assim, o terceiro buggy a deixar o hotel deverá sempre ser identificado pelo inteiro 3, mesmo que os buggies 1 e 2 sejam abduzidos.

Saída
Para cada linha "? i", imprima uma linha contendo o número de pessoas da excursão ainda remascentes atrás do buggy i naquele momento. Mas não seja bugueiro (nada de pôr bugs em seu código)!

Exemplo de Entrada	
10
1 2 3 4 5 4 3 2 1 2
a 9
? 10
a 2
a 5
? 6
a 6
? 10

Exemplo de Saída
24
8
13
*/
import java.util.Scanner;

public class Precisa_se_de_Matematicos_em_Marte_1804 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        int[] pessoas = new int[N];
        int[] totalPessoasAtras = new int[N];
        int totalPessoas = 0;
        
        // Leitura do número de pessoas em cada buggy
        for (int i = 0; i < N; i++) {
            pessoas[i] = scanner.nextInt();
            totalPessoas += pessoas[i];
            if (i > 0) {
                totalPessoasAtras[i] = totalPessoasAtras[i - 1] + pessoas[i - 1];
            } else {
                totalPessoasAtras[i] = 0;
            }
        }
        
        // Processamento dos comandos
        while (scanner.hasNext()) {
            String comando = scanner.next();
            int id = scanner.nextInt();
            
            if (comando.equals("a")) {
                // Abdução do buggy id
                totalPessoas -= pessoas[id - 1];
                if (id < N) {
                    for (int j = id; j < N; j++) {
                        totalPessoasAtras[j] -= pessoas[id - 1];
                    }
                }
                pessoas[id - 1] = 0; // Buggy id foi abduzido
            } else if (comando.equals("?")) {
                // Consulta do número de pessoas atrás do buggy id
                System.out.println(totalPessoasAtras[id - 1]);
            }
        }
        
        scanner.close();
    }
}
