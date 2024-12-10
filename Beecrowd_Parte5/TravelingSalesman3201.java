import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class TravelingSalesman3201 {

    static class Country {
        List<Point> vertices;
        List<Integer> neighbors;

        public Country() {
            vertices = new ArrayList<>();
            neighbors = new ArrayList<>();
        }
    }

    static class Point {
        int x, y, z;

        public Point(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringTokenizer tokenizer;

        while ((line = reader.readLine()) != null && !line.equals("0")) {
            int c = Integer.parseInt(line.trim()); // número de países
            if (c == 0) break;

            Country[] countries = new Country[c + 1];

            // Leitura dos países
            for (int i = 1; i <= c; i++) {
                countries[i] = new Country();
                tokenizer = new StringTokenizer(reader.readLine());
                int n = Integer.parseInt(tokenizer.nextToken()); // número de vértices do polígono
                for (int j = 0; j < n; j++) {
                    int x = Integer.parseInt(tokenizer.nextToken());
                    int y = Integer.parseInt(tokenizer.nextToken());
                    int z = Integer.parseInt(tokenizer.nextToken());
                    countries[i].vertices.add(new Point(x, y, z));
                }
            }

            // Construção das fronteiras (arestas que formam fronteiras entre países)
            for (int i = 1; i <= c; i++) {
                int ni = countries[i].vertices.size();
                for (int j = i + 1; j <= c; j++) {
                    int nj = countries[j].vertices.size();
                    for (int vi = 0; vi < ni; vi++) {
                        Point p1 = countries[i].vertices.get(vi);
                        Point p2 = countries[i].vertices.get((vi + 1) % ni);
                        for (int vj = 0; vj < nj; vj++) {
                            Point q1 = countries[j].vertices.get(vj);
                            Point q2 = countries[j].vertices.get((vj + 1) % nj);
                            if (doIntersect(p1, p2, q1, q2)) {
                                countries[i].neighbors.add(j);
                                countries[j].neighbors.add(i);
                                break; // Apenas uma interseção é necessária
                            }
                        }
                    }
                }
            }

            // Leitura do número de consultas
            int m = Integer.parseInt(reader.readLine().trim());

            // Processamento de cada consulta
            for (int q = 0; q < m; q++) {
                tokenizer = new StringTokenizer(reader.readLine());
                int ca = Integer.parseInt(tokenizer.nextToken());
                int cb = Integer.parseInt(tokenizer.nextToken());

                // BFS para encontrar o menor número de fronteiras cruzadas
                int[] distance = new int[c + 1];
                Arrays.fill(distance, Integer.MAX_VALUE);
                distance[ca] = 0;

                Queue<Integer> queue = new LinkedList<>();
                queue.offer(ca);

                while (!queue.isEmpty()) {
                    int current = queue.poll();
                    if (current == cb) break;

                    for (int neighbor : countries[current].neighbors) {
                        if (distance[neighbor] == Integer.MAX_VALUE) {
                            distance[neighbor] = distance[current] + 1;
                            queue.offer(neighbor);
                        }
                    }
                }

                System.out.println(distance[cb]);
            }
        }
    }

    // Função para verificar se dois segmentos de linha 2D se intersectam
    static boolean doIntersect(Point p1, Point q1, Point p2, Point q2) {
        // Orientações dos pontos
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        // Caso geral
        if (o1 != o2 && o3 != o4)
            return true;

        // Casos especiais
        // p1, q1 e p2 são colineares e p2 está no segmento p1q1
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;

        // p1, q1 e q2 são colineares e q2 está no segmento p1q1
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;

        // p2, q2 e p1 são colineares e p1 está no segmento p2q2
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;

        // p2, q2 e q1 são colineares e q1 está no segmento p2q2
        if (o4 == 0 && onSegment(p2, q1, q2)) return true;

        return false; // Não se interceptam
    }

    // Função para determinar a orientação do trio de pontos (p, q, r)
    // Retorna:
    // 0 -> p, q e r são colineares
    // 1 -> Sentido horário
    // 2 -> Sentido anti-horário
    static int orientation(Point p, Point q, Point r) {
        int val = (q.y - p.y) * (r.x - q.x) -
                  (q.x - p.x) * (r.y - q.y);
        if (val == 0) return 0; // Colinear
        return (val > 0) ? 1 : 2; // Sentido horário ou anti-horário
    }

    // Função para verificar se o ponto q está no segmento p-r
    static boolean onSegment(Point p, Point q, Point r) {
        if (q.x <= Math.max(p.x, r.x) && q.x >= Math.min(p.x, r.x) &&
            q.y <= Math.max(p.y, r.y) && q.y >= Math.min(p.y, r.y))
            return true;
        return false;
    }
}
