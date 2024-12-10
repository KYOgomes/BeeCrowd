import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Aviao {
    String id;

    Aviao(String id) {
        this.id = id;
    }
}

class Fila {
    Queue<Aviao> queue;

    Fila() {
        queue = new LinkedList<>();
    }

    void adicionarNaFila(String id) {
        queue.add(new Aviao(id));
    }

    String removerDaFila() {
        return queue.poll().id;
    }

    boolean isEmpty() {
        return queue.isEmpty();
    }
}

public class Controlador_de_Voo_3163 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Fila oeste = new Fila();
        Fila norte = new Fila();
        Fila sul = new Fila();
        Fila leste = new Fila();

        while (true) {
            int pontoCardeal = scanner.nextInt();
            if (pontoCardeal == 0) {
                break;
            }

            scanner.nextLine();  // Consumir a nova linha
            String id = scanner.nextLine();

            switch (pontoCardeal) {
                case -1:
                    oeste.adicionarNaFila(id);
                    break;
                case -2:
                    sul.adicionarNaFila(id);
                    break;
                case -3:
                    norte.adicionarNaFila(id);
                    break;
                case -4:
                    leste.adicionarNaFila(id);
                    break;
                default:
                    break;
            }
        }

        StringBuilder resultado = new StringBuilder();
        while (!oeste.isEmpty() || !norte.isEmpty() || !sul.isEmpty() || !leste.isEmpty()) {
            if (!oeste.isEmpty()) {
                resultado.append(oeste.removerDaFila()).append(" ");
            }
            if (!norte.isEmpty()) {
                resultado.append(norte.removerDaFila()).append(" ");
            }
            if (!sul.isEmpty()) {
                resultado.append(sul.removerDaFila()).append(" ");
            }
            if (!leste.isEmpty()) {
                resultado.append(leste.removerDaFila()).append(" ");
            }
        }

        System.out.println(resultado.toString().trim());

        scanner.close();
    }
}
