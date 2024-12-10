/*
João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados. O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando .<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.

Entrada
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."

Saída
Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.

Exemplo de Entrada	
2
<..><.<..>>
<<<..<......<<<<....>

Exemplo de Saída
3
1

*/
 

import java.util.Scanner;

public class Diamantes_e_Areia_1069 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();  // Consumir o newline após o número

        for (int k = 0; k < N; ++k) {
            String expressao = sc.nextLine();

            int resposta = 0;
            int parenteses = 0;
            int tam = expressao.length();

            for (int i = 0; i < tam; ++i) {
                if (expressao.charAt(i) == '<') {
                    ++parenteses;
                } else if (expressao.charAt(i) == '>' && parenteses > 0) {
                    --parenteses;
                    ++resposta;
                }
            }

            System.out.println(resposta);
        }

        sc.close();
    }
}
