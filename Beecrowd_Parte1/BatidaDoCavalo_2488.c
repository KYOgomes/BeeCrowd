#include <stdio.h>
#include <math.h>

#define MAX_N 1000

struct Point {
    int x, y;
};

double distance(struct Point p1, struct Point p2, int x, int y) {
    long dx = p2.x - p1.x;
    long dy = p2.y - p1.y;
    long dx2 = x - p1.x;
    long dy2 = y - p1.y;

    return sqrt(dx2 * dx2 + dy2 * dy2);
}

int main() {
    int N, P;
    struct Point points[MAX_N];
    
    // Leitura de entrada
    scanf("%d %d", &N, &P);
    
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        points[i].x = x;
        points[i].y = y;
    }
    
    // Processamento dos pontos P
    for (int i = 0; i < P; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        double maxDistance = 0.0;
        for (int j = 1; j < N; j++) {
            double dist1 = distance(points[j-1], points[j], x1, y1);
            double dist2 = distance(points[j-1], points[j], x2, y2);
            double dist = sqrt(dist1 * dist1 + dist2 * dist2);
            maxDistance = fmax(maxDistance, dist);
        }
        
        printf("%.2f\n", maxDistance);
    }
    
    return 0;
}
