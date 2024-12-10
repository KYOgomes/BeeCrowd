/*Analógimôn Go! é um jogo bastante popular. Em sua jornada, o jogador percorre diversas cidades capturando pequenos monstrinhos virtuais, chamados analógimôns. As cidades contém localidades especiais chamadas de ginásios. Ao chegar a um ginásio, um jogador pode tentar colocar um de seus analógimôns dentro dele.

Cada anlógimôn tem dois inteiros associados a ele: seu Poder de Combate (PC) e seu Número de Ataques (NA). Além disso, um ginásio tem associado a ele um Intervalo de Poder (IP). Ao tentar colocar um analógimôn em um ginásio, o jogo verifica quantos são os analógimôns já presentes no ginásio cuja diferença do seu PC para o PC do analógimôn sendo colocado é de no máximo IP. Se esta quantidade for menor ou igual ao NA do analógimôn sendo colocado, o monstrinho é inserido no ginásio com sucesso. Caso contrário, ele não é colocado no ginásio. Em ambos os casos, os analógimôns que já estavam no ginásio continuam no ginásio. Como exemplo, considere um ginásio com IP=3 com analógimôns de PC iguais a 5, 8, 13 e 20. Se um jogador tenta colocar um analógimôn de PC=10 e NA=4, o jogo contará quantos analógimôns há no ginásio com PC entre 10 - 3 = 7 e 10 + 3 = 13, inclusive. Como há dois analógimôns neste caso, o monstrinho é colocado com sucesso no ginásio, pois 2 ≤ 4. O ginásio passa a conter analógimôns de PC iguais a 5, 8, 10, 13 e 20.

Dadas as informações sobre um ginásio e as tentativas de colocar analógimôns dentro dele, determine quantos analógimôns ficarão no ginásio após todas as tentativas. Considere que o ginásio inicialmente não contém nenhum analógimôn.

Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso contém os inteiros IP e M (1 ≤ IP, M ≤ 105), o IP do ginásio e o número de tentativas, respectivamente. As próximas M linhas descrevem as tentativas de colocar um analógimôn no ginásio, na ordem em que são feitas. Cada linha contém dois inteiros PC e NA (1 ≤ PC, NA ≤ 105), indicando o PC e o NA do analógimôn, respectivamente. O Poder de Combate de todos analógimôns são distintos.

A entrada termina com fim-de-arquivo (EOF).

Saída
Para cada caso de teste, imprima uma linha com um inteiro indicando quantos analógimôns ficarão no ginásio. */

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int IP = scanner.nextInt();
            int M = scanner.nextInt();
            int[] analogimons = new int[100005]; // Ginásio com no máximo 100005 analógimôns

            for (int i = 0; i < M; i++) {
                int PC = scanner.nextInt();
                int NA = scanner.nextInt();

                // Verifica quantos analógimôns já estão no ginásio com PC no intervalo [PC-IP, PC+IP]
                int count = 0;
                for (int j = PC - IP; j <= PC + IP; j++) {
                    if (j >= 1 && j <= 100000) {
                        count += analogimons[j];
                    }
                }

                // Se a quantidade é menor ou igual ao NA, adiciona o analógimôn ao ginásio
                if (count <= NA) {
                    analogimons[PC]++;
                }
            }

            int totalAnalogimons = 0;
            for (int i = 1; i <= 100000; i++) {
                totalAnalogimons += analogimons[i];
            }
            System.out.println(totalAnalogimons);
        }
        scanner.close();
    }
}
