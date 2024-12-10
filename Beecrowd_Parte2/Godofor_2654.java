import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

// Classe que representa um Ser com nome, poder, kill e morte
class Ser {
    String nome;
    int poder;
    int kill;
    int morte;

    // Construtor
    public Ser(String nome, int poder, int kill, int morte) {
        this.nome = nome;
        this.poder = poder;
        this.kill = kill;
        this.morte = morte;
    }

    // Método toString para facilitar a impressão
    @Override
    public String toString() {
        return nome;
    }
}

public class Main {
    // Comparator para ordenação de Seres
    static class SerComparator implements java.util.Comparator<Ser> {
        @Override
        public int compare(Ser s1, Ser s2) {
            if (s1.poder != s2.poder) {
                return s2.poder - s1.poder; // Ordena por poder decrescente
            } else if (s1.kill != s2.kill) {
                return s2.kill - s1.kill; // Ordena por kill decrescente
            } else if (s1.morte != s2.morte) {
                return s1.morte - s2.morte; // Ordena por morte crescente
            } else {
                return s1.nome.compareTo(s2.nome); // Ordena por nome crescente
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine(); // Consumir o newline após o número

        List<Ser> seres = new ArrayList<>();

        // Leitura dos seres
        for (int i = 0; i < n; i++) {
            String[] a = scanner.nextLine().split(" ");
            String nome = a[0];
            int poder = Integer.parseInt(a[1]);
            int kill = Integer.parseInt(a[2]);
            int morte = Integer.parseInt(a[3]);
            Ser ser = new Ser(nome, poder, kill, morte);
            seres.add(ser);
        }

        // Ordenação dos seres usando o comparator SerComparator
        Collections.sort(seres, new SerComparator());

        // Imprimir o nome do primeiro ser (godofor)
        if (!seres.isEmpty()) {
            System.out.println(seres.get(0).nome);
        }

        scanner.close();
    }
}
