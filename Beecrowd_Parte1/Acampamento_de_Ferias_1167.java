import java.util.Scanner;

class Crianca {
    String nome;
    int valor;
    boolean marcado;
    Crianca ant;
    Crianca prox;
}

public class Acampamento_de_Ferias_1167 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            int n = scanner.nextInt();
            if (n == 0) break;
            
            Crianca[] array = new Crianca[n];
            
            // Ler dados das crianças
            for (int i = 0; i < n; i++) {
                array[i] = new Crianca();
                array[i].nome = scanner.next();
                array[i].valor = scanner.nextInt();
                array[i].marcado = false;
                if (i != 0) {
                    array[i].ant = array[i - 1];
                    array[i - 1].prox = array[i];
                }
            }
            array[n - 1].prox = array[0];
            array[0].ant = array[n - 1];
            
            // Inicializar variáveis de controle
            int marcados = 0;
            int comp = array[0].valor;
            int n1 = n - 1;
            
            // Processo da gincana
            while (marcados != n1 && n >= 2) {
                if (comp % 2 != 0) {
                    comp = comp % n;
                    if (comp == 0) {
                        array[n - 1].prox = array[0];
                        array[0].ant = array[n - 1];
                    } else {
                        array[comp - 1].prox = array[comp];
                        array[comp].ant = array[comp - 1];
                    }
                    int comp1 = array[comp].valor;
                    array[comp].marcado = true;
                    marcados++;
                    n--;
                    comp = comp1;
                } else {
                    comp = comp % n;
                    if (comp == 0) {
                        array[n - 1].prox = array[0];
                        array[0].ant = array[n - 1];
                    } else {
                        array[n - comp - 1].prox = array[n - comp];
                        array[n - comp].ant = array[n - comp - 1];
                    }
                    int comp1 = array[n - comp].valor;
                    array[n - comp].marcado = true;
                    marcados++;
                    n--;
                    comp = comp1;
                }
            }
            
            // Encontrar o vencedor
            int i;
            for (i = 0; i < n; i++) {
                if (!array[i].marcado) {
                    break;
                }
            }
            
            // Imprimir resultado
            System.out.println("Vencedor(a): " + array[i].nome);
        }
        
        scanner.close();
    }
}