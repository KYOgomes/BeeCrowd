import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

// Classe que representa um aluno com nome, cidade e idade
class Aluno {
    String nome;
    String cidade;
    int idade;

    // Construtor
    public Aluno(String nome, String cidade, int idade) {
        this.nome = nome;
        this.cidade = cidade;
        this.idade = idade;
    }

    // Método toString para facilitar a impressão
    @Override
    public String toString() {
        return nome;
    }
}

public class Main {
    // Comparator para ordenação de Alunos
    static class AlunoComparator implements Comparator<Aluno> {
        @Override
        public int compare(Aluno a, Aluno b) {
            if (a.idade != b.idade) {
                return Integer.compare(a.idade, b.idade); // Ordena por idade crescente
            } else if (!a.cidade.equals(b.cidade)) {
                return a.cidade.compareTo(b.cidade); // Ordena por cidade em ordem alfabética
            } else {
                return a.nome.compareTo(b.nome); // Ordena por nome em ordem alfabética
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int q = scanner.nextInt();
        scanner.nextLine(); // Consumir o newline após o número

        while (q > 0) {
            List<Aluno> alunos = new ArrayList<>();

            // Leitura dos alunos
            for (int i = 0; i < q; i++) {
                String[] a = scanner.nextLine().split(" ");
                String nome = a[0];
                String cidade = a[1];
                int idade = Integer.parseInt(a[2]);
                Aluno aluno = new Aluno(nome, cidade, idade);
                alunos.add(aluno);
            }

            // Ordenação dos alunos usando o comparator AlunoComparator
            Collections.sort(alunos, new AlunoComparator());

            // Imprimir os nomes dos alunos ordenados
            for (Aluno aluno : alunos) {
                System.out.println(aluno.nome);
            }

            q = scanner.nextInt();
            scanner.nextLine(); // Consumir o newline após o número
        }

        scanner.close();
    }
}
