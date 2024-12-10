import java.util.*;

public class Main {

    static class Aluno {
        String nome;
        int habilidade;

        public Aluno(String nome, int habilidade) {
            this.nome = nome;
            this.habilidade = habilidade;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int T = scanner.nextInt();
        scanner.nextLine(); // Consumir o newline após os inteiros

        List<Aluno> alunos = new ArrayList<>();

        // Leitura dos alunos
        for (int i = 0; i < N; i++) {
            String nome = scanner.next();
            int habilidade = scanner.nextInt();
            alunos.add(new Aluno(nome, habilidade));
        }

        // Ordenar os alunos pela habilidade (decrescente)
        Collections.sort(alunos, (a1, a2) -> Integer.compare(a2.habilidade, a1.habilidade));

        // Array de times
        List<List<String>> times = new ArrayList<>();
        for (int i = 0; i < T; i++) {
            times.add(new ArrayList<>());
        }

        // Distribuir os alunos nos times
        for (int i = 0; i < N; i++) {
            Aluno aluno = alunos.get(i);
            int timeIndex = i % T; // Seleciona o time alternadamente
            times.get(timeIndex).add(aluno.nome);
        }

        // Ordenar os nomes dos alunos nos times
        for (List<String> time : times) {
            Collections.sort(time);
        }

        // Imprimir os times
        for (int i = 0; i < T; i++) {
            System.out.println("Time " + (i + 1));
            for (String nome : times.get(i)) {
                System.out.println(nome);
            }
            System.out.println(); // linha em branco após cada time
        }

        scanner.close();
    }
}
