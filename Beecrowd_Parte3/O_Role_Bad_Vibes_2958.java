import java.util.*;

public class O_Role_Bad_Vibes_2958 {
    
    static class Problema {
        int criticidade;
        char tipo; // 'V' para vida, 'D' para disciplina
        
        public Problema(int criticidade, char tipo) {
            this.criticidade = criticidade;
            this.tipo = tipo;
        }
        
        public String toString() {
            return criticidade + "" + tipo;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt(); // número de linhas
        int M = sc.nextInt(); // número de colunas
        
        // Leitura da matriz de problemas
        Problema[][] matriz = new Problema[N][M];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                String entrada = sc.next();
                int criticidade = Character.getNumericValue(entrada.charAt(0));
                char tipo = entrada.charAt(1);
                matriz[i][j] = new Problema(criticidade, tipo);
            }
        }
        
        sc.close();
        
        // Armazenar os problemas em uma lista para ordenação
        List<Problema> problemas = new ArrayList<>();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                problemas.add(matriz[i][j]);
            }
        }
        
        // Ordenar os problemas conforme o critério especificado
        Collections.sort(problemas, new Comparator<Problema>() {
            @Override
            public int compare(Problema p1, Problema p2) {
                // Problemas de vida ('V') devem vir antes
                if (p1.tipo == 'V' && p2.tipo == 'D') {
                    return -1; // p1 vem antes de p2
                } else if (p1.tipo == 'D' && p2.tipo == 'V') {
                    return 1; // p2 vem antes de p1
                } else {
                    // Mesmo tipo ('V' ou 'D'), ordenar por criticidade
                    return p2.criticidade - p1.criticidade; // decrescente
                }
            }
        });
        
        // Imprimir os problemas ordenados
        for (Problema problema : problemas) {
            System.out.println(problema);
        }
    }
}
