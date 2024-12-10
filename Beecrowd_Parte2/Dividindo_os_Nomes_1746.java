/*
 A Rainha da Nlogônia decidiu mudar a capital do reino para uma nova cidade chamada Sortonia. O projeto da cidade é uma grade de N × N consistindo de N avenidas na direção Norte-Sul e N ruas direção Leste-Oeste. Assim, cada avenida cruza todas as ruas, e não há duas ruas ou duas avenidas que cruzam entre si.

Como a cidade está quase terminada, agora é hora de atribuir nomes as suas ruas e avenidas. O povo de Nlogônia já votou nos 2×N nomes que eles querem usar, mas não foi decidido ainda qual desses será usado para as ruas e que para as avenidas. A questão não é tão simples, porque em cada cruzamento deve ter uma placa de identificação da rua e da avenida que se cruzam ali, e a rainha ordenou expressamente que as letras destas placas deve ser escritas em ouro cravejado com rubis.

Como você é o Contador Oficial de Dinheiro (Accountant who Counts the Money - ACM), é sua tarefa encontrar uma forma de minimizar o número total de letras escritas nas placas dos cruzamentos, por razões óbvias. Felizmente, você pensou em uma maneira muito inteligente atingir esse objetivo, que é a utilização de abreviaturas nas placas para os nomes das ruas e avenidas. A abreviação do nome de uma avenida (e da mesma forma para uma rua) é o prefixo mais curto de seu nome, que não é um prefixo do nome de qualquer outra avenida (e da mesma forma para outra rua). Naturalmente, a abreviatura a ser utilizada para cada nome depende de como o conjunto de 2×N nomes é dividido em dois conjuntos disjuntos composto de N nomes a ser utilizado para as ruas e avenidas.

Por exemplo, considere o caso de N = 2, onde os quatro nomes escolhidos são "GAUSS", "GALOIS", "ERDOS" e "EULER". Se são atribuídos os nomes "GAUSS" e "GALOIS" para as ruas, ao passo que são atribuídos os nomes "ERDOS" e "EULER" as avenidas, então as abreviaturas seriam "GAU" para "GAUSS", "GAL" para "Galois", "ER" para "ERDOS" e "EU" para "EULER". Com essa divisão, o número total de letras a serem escritas nas placas seria 20, já que as quatro interseções seriam rotuladas como "GAU|ER", "GAU|UE", "GAL|ER" e "GAL|UE".

No entanto, no exemplo acima, seria mais conveniente atribuir para as ruas os nomes "GAUSS" e "ERDOS", deixando "GALOIS" e "EULER" para as avenidas. Assim, as abreviaturas seriam "G" para "GAUSS", "E" para "ERDOS", "G" para "GALOIS" e "E" para "EULER", e o número total de letras a serem escritas nas placas seria apenas 8 (pois as intersecções seriam rotuladas como “G|G”, “G|E”, “E|G” e “E|E”).

Felizmente, o conjunto de nomes que foi escolhido é tal que nenhum nome nele é um prefixo de algum outro nome no conjunto, garantindo assim que o sistema que você propõe será sempre viável. Você pode calcular o número mínimo de letras a ser escritas nos sinais se você dividir os nomes na forma ideal?

Entrada
A primeira linha contém um número inteiro N (2 ≤ N ≤ 100) que representa tanto o número de ruas quanto o número de avenidas em Sortonia. Cada uma das próximas 2 × N linhas contém uma string não-vazia de no máximo 18 letras maiúsculas, indicando um dos nomes que foram escolhidos. Você pode assumir que nenhuma das strings dadas é um prefixo de outra string na entrada.

Saída
Imprima uma linha contendo um inteiro que representa o número mínimo total de letras a serem escritas nas placas, quando a divisão dos nomes das ruas e avenidas é escolhida de forma otimizada.

Exemplos de Entrada	
2
GAUSS
GALOIS
ERDOS
EULER

Exemplos de Saída
8
 */
import java.util.*;

public class Dividindo_os_Nomes_1746_ERRO {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine(); // Consome a quebra de linha após a entrada do inteiro
        
        String[] nomes = new String[2 * N];
        for (int i = 0; i < 2 * N; i++) {
            nomes[i] = scanner.nextLine().trim();
        }
        
        // Calcula os prefixos mínimos únicos para cada nome
        String[] abreviacoes = new String[2 * N];
        for (int i = 0; i < 2 * N; i++) {
            String nome = nomes[i];
            abreviacoes[i] = calcularPrefixoMinimo(nome, nomes);
        }
        
        // Ordena as abreviações lexicograficamente
        Arrays.sort(abreviacoes);
        
        // Calcula o número mínimo total de letras
        int totalLetras = 0;
        for (int i = 0; i < N; i++) {
            totalLetras += abreviacoes[i].length();
        }
        
        // Imprime o resultado
        System.out.println(totalLetras);
    }
    
    private static String calcularPrefixoMinimo(String nome, String[] nomes) {
        for (int len = 1; len <= nome.length(); len++) {
            String prefixo = nome.substring(0, len);
            boolean encontrouPrefixo = false;
            for (String outroNome : nomes) {
                if (!outroNome.equals(nome) && outroNome.startsWith(prefixo)) {
                    encontrouPrefixo = true;
                    break;
                }
            }
            if (!encontrouPrefixo) {
                return prefixo;
            }
        }
        return nome; // Não deveria acontecer porque o problema garante que não há prefixos comuns
    }
}
