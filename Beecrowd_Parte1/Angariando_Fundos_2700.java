import java.util.*;

class Candidato {
    int B; // Beleza
    int F; // Fortuna
    int D; // Doação

    Candidato(int B, int F, int D) {
        this.B = B;
        this.F = F;
        this.D = D;
    }
}

public class Angariando_Fundos_2700 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        Candidato[] candidatos = new Candidato[N];

        // Leitura dos candidatos
        for (int i = 0; i < N; i++) {
            int B = scanner.nextInt();
            int F = scanner.nextInt();
            int D = scanner.nextInt();
            candidatos[i] = new Candidato(B, F, D);
        }

        // Ordenação dos candidatos conforme a estratégia descrita
        Arrays.sort(candidatos, new Comparator<Candidato>() {
            public int compare(Candidato c1, Candidato c2) {
                if (c1.B != c2.B)
                    return c2.B - c1.B;
                if (c1.F != c2.F)
                    return c2.F - c1.F;
                return c2.D - c1.D;
            }
        });

        // Variável para armazenar a soma máxima das doações
        long somaMaxima = 0;
        int prevB = -1; // Beleza do convidado anterior
        int prevF = -1; // Fortuna do convidado anterior

        // Seleção dos candidatos que não causam discussões
        for (int i = 0; i < N; i++) {
            if (candidatos[i].B >= prevB && candidatos[i].F >= prevF) {
                somaMaxima += candidatos[i].D;
                prevB = candidatos[i].B; // Atualiza a beleza do convidado anterior
                prevF = candidatos[i].F; // Atualiza a fortuna do convidado anterior
            }
        }

        // Imprime o resultado final
        System.out.println(somaMaxima * 2);
    }
}