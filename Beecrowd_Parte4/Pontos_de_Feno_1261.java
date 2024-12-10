/*
Cada funcionário de um serviço burocrático tem uma descrição do cargo - alguns parágrafos que descrevem as responsabilidades do trabalho. A descrição do cargo combinado com outros fatores, como por exemplo tempo de serviço, é utilizado para determinar qual é o salário deste funcionário.

Um sistema denominado Pontos de Feno (Hay Points) libera o departamento de Recursos Humanos de ter que fazer um julgamento inteligente do valor de cada empregado para a empresa. A descrição de um cargo ou função é feita através da verificação de palavras e frases que indicam responsabilidade. Em particular, descrições de cargo que indicam o controle sobre um grande orçamento ou gestão sobe um grande número de pessoas geram escores altos neste sistema.

Você deve implementar um sistema de Ponto de Feno simplificado. Você terá como informações um dicionário Hay Point que conterá algumas palavras-chaves que são as descrições dos cargos e um valor em dólares americanos associado com cada um destes cargos. Para cada descrição de trabalho você deverá calcular o salário associado com o trabalho, de acordo com este sistema.

Entrada
A entrada contém vários casos de teste. A primeira linha da entrada contém dois números inteiros positivos: M (M ≤ 1000), que é o número de palavras no dicionário Hay Point, e um número inteiro N (N ≤ 100) que corresponde à quantidade de descrições de cargos ou funções. M linhas seguem, cada um contém uma palavra (uma seqüência de até 16 letras minúsculas) e um valor de dólar (um número real entre 0 e 1000000). Logo na sequência, após o dicionário, estão as descrições de cada uma dos cargos N.

Cada descrição de cargo consiste em uma ou mais linhas de texto. Para sua conveniência, o texto contém somente letras minúsculas (de 'a' até 'z'). Cada descrição de cargo é finalizada por uma linha contendo um ponto ".".

Saída
Para cada caso de teste de entrada, imprima o salário do funcionário que é calculado através deste sistema Pontos de Feno (que nada mais é do que a soma do valor de todas as palavras que aparecem na descrição do cargo). Obs.: o valor das palavras que não aparecem no dicionário é zero (0).

Exemplo de Entrada	
7 2
administer 100000
spending 200000
manage 50000
responsibility 25000
expertise 100
skill 50
money 75000
the incumbent will administer the
spending of kindergarden milk money
and exercise responsibility for making
change he or she will share
responsibility for the task of managing
the money with the assistant
whose skill and expertise shall ensure
the successful spending exercise
.
this individual must have the skill to
perform a heart transplant and
expertise in rocket science
.

Exemplo de Saída
700150
150
*/
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Pontos_de_Feno_1261 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int M = scanner.nextInt();
        int N = scanner.nextInt();

        Map<String, Integer> dicionario = new HashMap<>();
        for (int i = 0; i < M; i++) {
            String palavra = scanner.next();
            int valor = scanner.nextInt();
            dicionario.put(palavra, valor);
        }

        scanner.nextLine(); // Consumir a quebra de linha após os valores do dicionário

        while (N-- > 0) {
            int salario = 0;
            String descricao;
            while (!(descricao = scanner.nextLine()).equals(".")) {
                String[] palavras = descricao.split(" ");
                for (String palavra : palavras) {
                    if (dicionario.containsKey(palavra)) {
                        salario += dicionario.get(palavra);
                    }
                }
            }
            System.out.println(salario);
        }
    }
}
