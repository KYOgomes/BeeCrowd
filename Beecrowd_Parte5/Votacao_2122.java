import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Candidato {
    int indice;
    int votos_primeiro;
    int votos_total;

    Candidato(int indice) {
        this.indice = indice;
        this.votos_primeiro = 0;
        this.votos_total = 0;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int N = sc.nextInt(); // número de eleitores
            int K = sc.nextInt(); // número de candidatos
            int V = sc.nextInt(); // número de vagas

            // Inicializa os candidatos
            Candidato[] candidatos = new Candidato[K];
            for (int i = 0; i < K; i++) {
                candidatos[i] = new Candidato(i + 1);
            }

            // Lê os votos dos eleitores
            for (int i = 0; i < N; i++) {
                int Li = sc.nextInt(); // número de votos do eleitor

                for (int j = 0; j < Li; j++) {
                    int voto = sc.nextInt(); // índice do candidato votado
                    if (voto >= 1 && voto <= K) {
                        candidatos[voto - 1].votos_total++;
                        if (j == 0) {
                            candidatos[voto - 1].votos_primeiro++;
                        }
                    }
                }
            }

            // Ordena os candidatos conforme as regras especificadas
            Arrays.sort(candidatos, new Comparator<Candidato>() {
                @Override
                public int compare(Candidato c1, Candidato c2) {
                    // Ordena primeiro pelo número total de votos decrescente
                    if (c1.votos_total != c2.votos_total) {
                        return Integer.compare(c2.votos_total, c1.votos_total);
                    }
                    
                    // Em caso de empate nos votos totais, ordena pelos votos no primeiro lugar decrescente
                    if (c1.votos_primeiro != c2.votos_primeiro) {
                        return Integer.compare(c2.votos_primeiro, c1.votos_primeiro);
                    }
                    
                    // Em caso de empate nos votos totais e no primeiro lugar, ordena pelo índice crescente
                    return Integer.compare(c1.indice, c2.indice);
                }
            });

            // Imprime os índices dos candidatos eleitos ordenados
            int eleitos = 0;
            for (int i = 0; i < K; i++) {
                if (eleitos < V && candidatos[i].votos_total > 0) {
                    if (eleitos > 0) {
                        System.out.print(" ");
                    }
                    System.out.print(candidatos[i].indice);
                    eleitos++;
                }
            }
            System.out.println();
        }

        sc.close();
    }
}
