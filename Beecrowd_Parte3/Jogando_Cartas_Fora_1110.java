/*
 
Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base. A seguinte operação é
realizada enquanto tiver 2 ou mais cartas na pilha.

Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.

Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.

Cada linha de entrada (com exceção da última) contém um número n ≤ 50. A última linha contém 0 e não deve ser processada. Cada número de entrada produz duas linhas de saída. A primeira linha apresenta a sequência de cartas descartadas e a segunda linha apresenta a carta remanescente.

Entrada
A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. A última linha contém o valor 0.

Saída
Para cada caso de teste, imprima duas linhas. A primeira linha apresenta a sequência de cartas descartadas, 
cada uma delas separadas por uma vírgula e um espaço. A segunda linha apresenta o número da carta que restou. Nenhuma linha tem espaços extras no início ou no final. Veja exemplo para conferir o formato esperado.

Exemplo de Entrada	
7
19
10
6
0

Exemplo de Saída
Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4
*/
 
import java.util.*;

public class Jogando_Cartas_Fora_1110 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int n = scanner.nextInt();
            if (n == 0) break;

            List<Integer> discarded = new ArrayList<>();
            Deque<Integer> deck = new ArrayDeque<>();
            
            // Inicializa o deque com os números de 1 até n
            for (int i = 1; i <= n; i++) {
                deck.addLast(i);
            }
            
            // Simulação do processo de descarte
            while (deck.size() >= 2) {
                // Descarta a carta do topo
                discarded.add(deck.removeFirst());
                // Move a próxima carta para a base da pilha
                deck.addLast(deck.removeFirst());
            }

            // Formatação da saída conforme especificado
            System.out.print("Discarded cards: ");
            for (int i = 0; i < discarded.size(); i++) {
                if (i > 0) System.out.print(", ");
                System.out.print(discarded.get(i));
            }
            System.out.println();
            System.out.println("Remaining card: " + deck.peekFirst());
        }

        scanner.close();
    }
}
