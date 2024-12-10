#include <stdio.h>
#include <math.h>

#define DEG_TO_RAD(deg) ((deg) * (M_PI / 180.0))

// Função para calcular o ângulo de elevação do sol em um dado tempo
double sunElevationAngle(double time) {
    double total_minutes = (21.5 - 5.5) * 60.0;
    double minutes_since_sunrise = (time - 5.5) * 60.0;
    double elevation_angle = (minutes_since_sunrise / total_minutes) * 180.0;
    return DEG_TO_RAD(elevation_angle);
}

// Função para calcular a altura da sombra de um prédio
double shadowLength(double height, double angle) {
    return height / tan(angle);
}

int main() {
    int N, L, D;
    while (scanf("%d %d %d", &N, &L, &D) != EOF) {
        int heights[N];
        int garden_index = -1;
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &heights[i]);
            if (heights[i] == 0) {
                garden_index = i;
            }
        }
        
        double total_minutes = 0.0;
        double time_increment = 0.01; // Incremento de tempo em horas (36 segundos)

        for (double time = 5.5; time <= 21.5; time += time_increment) {
            double angle = sunElevationAngle(time);
            int can_see_sun = 1;

            // Verificar sombras de prédios à esquerda
            for (int i = garden_index - 1; i >= 0 && can_see_sun; i--) {
                double shadow_length = shadowLength(heights[i], angle);
                double distance = (garden_index - i) * (L + D);
                if (shadow_length >= distance) {
                    can_see_sun = 0;
                }
            }
            
            // Verificar sombras de prédios à direita
            for (int i = garden_index + 1; i < N && can_see_sun; i++) {
                double shadow_length = shadowLength(heights[i], angle);
                double distance = (i - garden_index) * (L + D);
                if (shadow_length >= distance) {
                    can_see_sun = 0;
                }
            }
            
            if (can_see_sun) {
                total_minutes += time_increment * 60.0; // Converter horas em minutos
            }
        }
        
        printf("%.2f\n", total_minutes);
    }
    return 0;
}
