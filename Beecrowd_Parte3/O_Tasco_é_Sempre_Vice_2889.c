#include <stdio.h>

#define MAX_TEAMS 1000001 // considerando o índice 1-base

int main() {
    int t; // número de casos de teste
    scanf("%d", &t);
    
    while (t--) {
        int n; // número de times
        scanf("%d", &n);
        
        int viceCampeonatos[MAX_TEAMS] = {0}; // array para contar os vice-campeonatos de cada time
        int pontos[MAX_TEAMS] = {0}; // array para armazenar os pontos de cada time
        
        while (1) {
            int m; // número de partidas no campeonato
            scanf("%d", &m);
            if (m == 0) break; // fim da entrada
            
            // Reiniciar arrays de pontos para o campeonato atual
            for (int i = 1; i <= n; i++) {
                pontos[i] = 0;
            }
            
            // Ler as partidas e calcular os pontos
            for (int i = 0; i < m; i++) {
                int time1, placar1, time2, placar2;
                scanf("%d %d %d %d", &time1, &placar1, &time2, &placar2);
                
                if (placar1 > placar2) {
                    pontos[time1] += 3; // time1 venceu
                } else if (placar1 < placar2) {
                    pontos[time2] += 3; // time2 venceu
                } else {
                    pontos[time1] += 1; // empate
                    pontos[time2] += 1; // empate
                }
            }
            
            // Determinar o campeão e o vice-campeão deste campeonato
            int campeao = -1;
            int viceCampeao = -1;
            
            for (int i = 1; i <= n; i++) {
                if (campeao == -1 || pontos[i] > pontos[campeao]) {
                    viceCampeao = campeao;
                    campeao = i;
                } else if (viceCampeao == -1 || pontos[i] > pontos[viceCampeao]) {
                    viceCampeao = i;
                }
            }
            
            // Se o vice-campeão for o Tasco (time 1) e ele não for campeão
            if (viceCampeao == 1 && campeao != 1) {
                viceCampeonatos[1]++;
            }
        }
        
        // Verificar se o Tasco foi o que mais vezes foi vice-campeão
        int maxViceCampeonatos = 0;
        for (int i = 1; i <= n; i++) {
            if (i != 1 && viceCampeonatos[i] > maxViceCampeonatos) {
                maxViceCampeonatos = viceCampeonatos[i];
            }
        }
        
        // Se o Tasco foi o que mais vezes foi vice-campeão
        if (viceCampeonatos[1] > maxViceCampeonatos) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }
    
    return 0;
}
