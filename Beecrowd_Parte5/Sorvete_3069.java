import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Sorvete_3069 {

    static class Interval {
        int start;
        int end;

        Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testNumber = 1;

        while (true) {
            int P = sc.nextInt(); // Comprimento da praia
            int S = sc.nextInt(); // Número de sorveteiros

            if (P == 0 && S == 0) break;

            ArrayList<Interval> intervals = new ArrayList<>();

            for (int i = 0; i < S; i++) {
                int U = sc.nextInt();
                int V = sc.nextInt();
                intervals.add(new Interval(U, V));
            }

            // Ordena os intervalos pela coordenada de início
            Collections.sort(intervals, new Comparator<Interval>() {
                public int compare(Interval a, Interval b) {
                    return Integer.compare(a.start, b.start);
                }
            });

            // Mescla os intervalos
            ArrayList<Interval> mergedIntervals = new ArrayList<>();
            if (!intervals.isEmpty()) {
                Interval current = intervals.get(0);
                for (int i = 1; i < intervals.size(); i++) {
                    Interval next = intervals.get(i);
                    if (current.end >= next.start) {
                        // Atualiza o intervalo atual
                        current.end = Math.max(current.end, next.end);
                    } else {
                        // Adiciona o intervalo mesclado à lista final
                        mergedIntervals.add(current);
                        current = next;
                    }
                }
                // Adiciona o último intervalo mesclado
                mergedIntervals.add(current);
            }

            // Imprime o resultado do teste
            System.out.println("Teste " + testNumber++);
            for (Interval interval : mergedIntervals) {
                System.out.println(interval.start + " " + interval.end);
            }
            System.out.println(); // linha em branco entre testes
        }

        sc.close();
    }
}
