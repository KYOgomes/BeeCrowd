#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNTRIES 6000
#define MAX_VERTICES 20
#define MAX_QUERIES 50

typedef struct {
    int x, y, z;
} Point3D;

typedef struct {
    Point3D vertices[MAX_VERTICES];
    int num_vertices;
} Country;

// Função para verificar a orientação de três pontos (p, q, r)
// Retorna:
// 0 -> p, q e r são colineares
// 1 -> Sentido horário
// 2 -> Sentido anti-horário
int orientation(Point3D p, Point3D q, Point3D r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Colinear
    return (val > 0) ? 1 : 2; // Sentido horário ou anti-horário
}

// Função para verificar se os segmentos de linha 3D p1q1 e p2q2 se intersectam
int doIntersect(Point3D p1, Point3D q1, Point3D p2, Point3D q2) {
    // Encontrar as orientações necessárias
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // Caso geral
    if (o1 != o2 && o3 != o4)
        return 1; // Intersectam

    // Casos especiais
    // p1, q1 e p2 são colineares e p2 está no segmento p1q1
    if (o1 == 0 && (p2.x >= p1.x && p2.x <= q1.x && p2.y >= p1.y && p2.y <= q1.y &&
                    p2.z >= p1.z && p2.z <= q1.z))
        return 1;

    // p1, q1 e q2 são colineares e q2 está no segmento p1q1
    if (o2 == 0 && (p2.x >= p1.x && p2.x <= q1.x && p2.y >= p1.y && p2.y <= q1.y &&
                    p2.z >= p1.z && p2.z <= q1.z))
        return 1;

    // p2, q2 e p1 são colineares e p1 está no segmento p2q2
    if (o3 == 0 && (p1.x >= p2.x && p1.x <= q2.x && p1.y >= p2.y && p1.y <= q2.y &&
                    p1.z >= p2.z && p1.z <= q2.z))
        return 1;

    // p2, q2 e q1 são colineares e q1 está no segmento p2q2
    if (o4 == 0 && (q1.x >= p2.x && q1.x <= q2.x && q1.y >= p2.y && q1.y <= q2.y &&
                    q1.z >= p2.z && q1.z <= q2.z))
        return 1;

    return 0; // Não se intersectam
}

// Função para calcular o número mínimo de fronteiras que devem ser cruzadas
int minBordersCrossed(Country countries[], int c, int ca, int cb) {
    int visited[MAX_COUNTRIES] = {0};
    int distance[MAX_COUNTRIES] = {0};

    // BFS para encontrar o caminho mínimo entre ca e cb
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, ca);
    visited[ca] = 1;

    while (!isEmpty(&queue)) {
        int current = dequeue(&queue);

        if (current == cb) break;

        // Verificar vizinhos não visitados
        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                // Verificar se há fronteira entre current e i
                int ni = countries[current].num_vertices;
                int nj = countries[i].num_vertices;
                int hasBorder = 0;

                // Verificar todas as arestas entre current e i
                for (int vi = 0; vi < ni && !hasBorder; vi++) {
                    Point3D p1 = countries[current].vertices[vi];
                    Point3D p2 = countries[current].vertices[(vi + 1) % ni];

                    for (int vj = 0; vj < nj && !hasBorder; vj++) {
                        Point3D q1 = countries[i].vertices[vj];
                        Point3D q2 = countries[i].vertices[(vj + 1) % nj];

                        if (doIntersect(p1, p2, q1, q2)) {
                            hasBorder = 1;
                            break; // Apenas uma interseção é necessária
                        }
                    }
                }

                if (hasBorder && !visited[i]) {
                    visited[i] = 1;
                    distance[i] = distance[current] + 1;
                    enqueue(&queue, i);
                }
            }
        }
    }

    // Retorna a distância mínima entre ca e cb
    return distance[cb];
}

int main() {
    int c, m;
    int i, j, k;

    while (1) {
        scanf("%d", &c);
        if (c == 0) break;

        Country countries[MAX_COUNTRIES + 1];

        // Leitura dos países
        for (i = 1; i <= c; i++) {
            scanf("%d", &countries[i].num_vertices);
            for (j = 0; j < countries[i].num_vertices; j++) {
                scanf("%d %d %d", &countries[i].vertices[j].x,
                                  &countries[i].vertices[j].y,
                                  &countries[i].vertices[j].z);
            }
        }

        // Construção das fronteiras (arestas que formam fronteiras entre países)
        for (i = 1; i <= c; i++) {
            for (j = i + 1; j <= c; j++) {
                int ni = countries[i].num_vertices;
                int nj = countries[j].num_vertices;
                int hasBorder = 0;

                // Verificar todas as arestas entre i e j
                for (k = 0; k < ni && !hasBorder; k++) {
                    Point3D p1 = countries[i].vertices[k];
                    Point3D p2 = countries[i].vertices[(k + 1) % ni];

                    for (int l = 0; l < nj && !hasBorder; l++) {
                        Point3D q1 = countries[j].vertices[l];
                        Point3D q2 = countries[j].vertices[(l + 1) % nj];

                        if (doIntersect(p1, p2, q1, q2)) {
                            // i e j têm uma fronteira comum
                            countries[i].neighbors[countries[i].num_neighbors++] = j;
                            countries[j].neighbors[countries[j].num_neighbors++] = i;
                            hasBorder = 1;
                            break; // Apenas uma interseção é necessária
                        }
                    }
                }
            }
        }

        scanf("%d", &m);

        // Processamento de cada consulta
        for (i = 0; i < m; i++) {
            int ca, cb;
            scanf("%d %d", &ca, &cb);

            // Calcular o número mínimo de fronteiras que precisam ser cruz
