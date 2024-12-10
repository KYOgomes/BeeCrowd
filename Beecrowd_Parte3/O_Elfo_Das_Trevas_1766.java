import java.util.*;
import java.io.*;

class Rena {
    String nome;
    int peso;
    int idade;
    double altura;

    public Rena(String nome, int peso, int idade, double altura) {
        this.nome = nome;
        this.peso = peso;
        this.idade = idade;
        this.altura = altura;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        for (int i = 1; i <= T; i++) {
            int N = scanner.nextInt();
            int M = scanner.nextInt();
            scanner.nextLine(); // Consome a linha pendente

            List<Rena> renas = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                String linha = scanner.nextLine();
                String[] partes = linha.split(" ");
                String nome = partes[0];
                int peso = Integer.parseInt(partes[1]);
                int idade = Integer.parseInt(partes[2]);
                double altura = Double.parseDouble(partes[3]);

                renas.add(new Rena(nome, peso, idade, altura));
            }

            // Ordenação das renas conforme as regras especificadas
            Collections.sort(renas, new Comparator<Rena>() {
                @Override
                public int compare(Rena r1, Rena r2) {
                    if (r1.peso != r2.peso) {
                        return r2.peso - r1.peso; // ordem decrescente de peso
                    } else if (r1.idade != r2.idade) {
                        return r1.idade - r2.idade; // ordem crescente de idade
                    } else if (Double.compare(r1.altura, r2.altura) != 0) {
                        return Double.compare(r1.altura, r2.altura); // ordem crescente de altura
                    } else {
                        return r1.nome.compareTo(r2.nome); // ordem lexicográfica de nome
                    }
                }
            });

            // Exibindo o resultado para o caso de teste atual
            System.out.println("CENARIO {" + i + "}");
            for (int k = 0; k < M; k++) {
                System.out.println((k + 1) + " - " + renas.get(k).nome);
            }
        }

        scanner.close();
    }
}
