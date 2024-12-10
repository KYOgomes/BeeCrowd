import java.util.*;
//tudo errado
class Presente implements Comparable<Presente> {
    String nome;
    double preco;
    int preferencia;

    Presente(String nome, double preco, int preferencia) {
        this.nome = nome;
        this.preco = preco;
        this.preferencia = preferencia;
    }

    @Override
    public int compareTo(Presente outro) {
        if (this.preferencia != outro.preferencia) {
            return Integer.compare(outro.preferencia, this.preferencia); // ordem decrescente de preferência
        } else if (this.preco != outro.preco) {
            return Double.compare(this.preco, outro.preco); // ordem crescente de preço
        } else {
            return this.nome.compareTo(outro.nome); // ordem alfabética do nome
        }
    }
}

public class Presentes_de_Natal_2022 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            String nomeDono = scanner.next();
            int Q = scanner.nextInt();
            List<Presente> presentes = new ArrayList<>();

            for (int i = 0; i < Q; i++) {
                String nomePresente = scanner.next();
                double preco = scanner.nextDouble();
                int preferencia = scanner.nextInt();
                scanner.nextLine(); // consome a quebra de linha após a preferência

                Presente presente = new Presente(nomePresente, preco, preferencia);
                presentes.add(presente);
            }

            // Ordenar os presentes de acordo com as regras especificadas
            Collections.sort(presentes);

            // Imprimir resultado conforme especificado
            System.out.println("Lista de " + nomeDono);
            for (Presente presente : presentes) {
                System.out.printf("%s - R$%.2f\n", presente.nome, presente.preco);
            }
            System.out.println(); // linha em branco após cada lista
        }

        scanner.close();
    }
}