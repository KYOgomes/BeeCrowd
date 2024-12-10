import java.util.*;

public class A_Noiva_Do_Trevo_3149 {

    static class Relato implements Comparable<Relato> {
        String nome;
        int horario;

        public Relato(String nome, int horario) {
            this.nome = nome;
            this.horario = horario;
        }

        @Override
        public int compareTo(Relato other) {
            return Integer.compare(this.horario, other.horario);
        }
    }

    // Função para converter o horário HH:MM para minutos desde a meia-noite
    static int parseTime(String hora) {
        int horas = Integer.parseInt(hora.substring(0, 2));
        int minutos = Integer.parseInt(hora.substring(3));
        return horas * 60 + minutos;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int P = sc.nextInt(); // minutos para mais e para menos da meia-noite
        int Q = sc.nextInt(); // quantidade de pessoas que relataram

        List<Relato> relatos = new ArrayList<>();

        // Leitura dos relatos
        for (int i = 0; i < Q; i++) {
            String H = sc.next(); // horário do relato
            String N = sc.nextLine().trim(); // nome do morador

            int minutos = parseTime(H);

            // Verifica se está dentro do intervalo próximo à meia-noite
            if (minutos <= P || minutos >= 1440 - P) {
                relatos.add(new Relato(N, minutos));
            }
        }

        // Ordena os relatos pelo horário
        Collections.sort(relatos);

        // Saída dos nomes dos moradores ordenados pelo horário do relato
        for (Relato relato : relatos) {
            System.out.println(relato.nome);
        }
    }
}
