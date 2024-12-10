import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Duende {
    String nome;
    int idade;

    public Duende(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }
}

public class Time_De_Duendes_3176 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lendo o número de duendes
        int N = scanner.nextInt();
        scanner.nextLine(); // Consumir a nova linha

        List<Duende> duendes = new ArrayList<>();

        // Lendo os nomes e idades dos duendes
        for (int i = 0; i < N; i++) {
            String nome = scanner.next();
            int idade = scanner.nextInt();
            duendes.add(new Duende(nome, idade));
        }

        // Ordenar a lista de duendes por idade decrescente e, em caso de empate, por nome crescente
        Collections.sort(duendes, new Comparator<Duende>() {
            @Override
            public int compare(Duende d1, Duende d2) {
                if (d2.idade != d1.idade) {
                    return Integer.compare(d2.idade, d1.idade);
                } else {
                    return d1.nome.compareTo(d2.nome);
                }
            }
        });

        // Número de times
        int T = N / 3;

        // Formar e imprimir os times
        for (int i = 0; i < T; i++) {
            System.out.println("Time " + (i + 1));
            System.out.println(duendes.get(i).nome + " " + duendes.get(i).idade);
            System.out.println(duendes.get(i + T).nome + " " + duendes.get(i + T).idade);
            System.out.println(duendes.get(i + 2 * T).nome + " " + duendes.get(i + 2 * T).idade);
            System.out.println();
        }

        scanner.close();
    }
}
