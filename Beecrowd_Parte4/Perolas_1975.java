import java.util.*;

public class Perolas_1975 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int P = scanner.nextInt(); // número de pérolas
            int A = scanner.nextInt(); // número de alunos
            int R = scanner.nextInt(); // número de respostas por aluno

            if (P == 0 && A == 0 && R == 0) break;

            // Ler as pérolas
            scanner.nextLine(); // para consumir o newline após os ints
            Map<String, Integer> ocorrencias = new HashMap<>();

            for (int i = 0; i < P; i++) {
                scanner.nextLine(); // ignorar a pérola
            }

            // Ler os alunos e suas respostas
            for (int i = 0; i < A; i++) {
                String nomeAluno = scanner.nextLine().trim(); // ler nome do aluno
                int count = 0;

                for (int j = 0; j < R; j++) {
                    String resposta = scanner.nextLine();
                    if (resposta.contains("ERRO")) {
                        count++;
                    }
                }

                // Atualizar contagem de ocorrências do aluno
                ocorrencias.put(nomeAluno, count);
            }

            // Encontrar o aluno com mais aparições
            int maxCount = -1;
            List<String> melhoresAlunos = new ArrayList<>();

            for (Map.Entry<String, Integer> entry : ocorrencias.entrySet()) {
                int count = entry.getValue();
                if (count > maxCount) {
                    maxCount = count;
                    melhoresAlunos.clear();
                    melhoresAlunos.add(entry.getKey());
                } else if (count == maxCount) {
                    melhoresAlunos.add(entry.getKey());
                }
            }

            // Ordenar os alunos em ordem alfabética
            Collections.sort(melhoresAlunos);

            // Imprimir resultado
            for (int i = 0; i < melhoresAlunos.size(); i++) {
                if (i > 0) {
                    System.out.print(", ");
                }
                System.out.print(melhoresAlunos.get(i));
            }
            System.out.println(); // imprimir linha em branco após cada caso de teste
        }

        scanner.close();
    }
}
