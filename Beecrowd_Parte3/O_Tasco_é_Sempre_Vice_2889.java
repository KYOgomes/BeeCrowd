import java.util.*;

public class O_Tasco_é_Sempre_Vice_2889 
{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt(); // número de times
        int[] viceCampeonatos = new int[N + 1]; // índice 1 a N para representar os times, 0 não usado
        
        while (true) {
            int M = scanner.nextInt(); // número de partidas no campeonato
            if (M == 0) break; // fim da entrada
            
            int[] pontos = new int[N + 1];
            
            for (int i = 0; i < M; i++) {
                int time1 = scanner.nextInt();
                int placar1 = scanner.nextInt();
                int time2 = scanner.nextInt();
                int placar2 = scanner.nextInt();
                
                if (placar1 > placar2) {
                    pontos[time1] += 3; // time1 venceu
                } else if (placar1 < placar2) {
                    pontos[time2] += 3; // time2 venceu
                } else {
                    pontos[time1] += 1; // empate
                    pontos[time2] += 1; // empate
                }
            }
            
            // Encontrar o campeão e o vice-campeão deste campeonato
            int campeao = -1;
            int viceCampeao = -1;
            for (int time = 1; time <= N; time++) {
                if (campeao == -1 || pontos[time] > pontos[campeao]) {
                    viceCampeao = campeao;
                    campeao = time;
                } else if (viceCampeao == -1 || pontos[time] > pontos[viceCampeao]) {
                    viceCampeao = time;
                }
            }
            
            // Se o vice-campeão for o Tasco (time 1) e ele não for campeão
            if (viceCampeao == 1 && campeao != 1) {
                viceCampeonatos[1]++;
            }
        }
        
        // Verificar se o Tasco foi o que mais vezes foi vice-campeão
        int maxViceCampeonatos = 0;
        for (int time = 1; time <= N; time++) {
            if (time != 1 && viceCampeonatos[time] > maxViceCampeonatos) {
                maxViceCampeonatos = viceCampeonatos[time];
            }
        }
        
        // Se o Tasco foi o que mais vezes foi vice-campeão
        if (viceCampeonatos[1] > maxViceCampeonatos) {
            System.out.println("Y");
        } else {
            System.out.println("N");
        }
        
        scanner.close();
    }
}
