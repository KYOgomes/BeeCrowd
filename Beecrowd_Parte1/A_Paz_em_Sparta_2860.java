import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Edge {
    int dest;
    int weight;

    public Edge(int dest, int weight) {
        this.dest = dest;
        this.weight = weight;
    }
}

class Graph {
    int V;
    List<Edge>[] adjList;

    public Graph(int V) {
        this.V = V;
        adjList = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            adjList[i] = new ArrayList<>();
        }
    }

    public void addEdge(int src, int dest, int weight) {
        adjList[src].add(new Edge(dest, weight));
        adjList[dest].add(new Edge(src, weight));
    }

    public long primMST() {
        long[] key = new long[V]; // Para armazenar as chaves de seleção
        boolean[] mstSet = new boolean[V]; // Para representar os vértices incluídos na AGM
        Arrays.fill(key, Long.MAX_VALUE);

        // Min-Heap usando PriorityQueue
        PriorityQueue<Edge> pq = new PriorityQueue<>(V, Comparator.comparingLong(e -> e.weight));

        // Começando com o vértice 0
        pq.add(new Edge(0, 0));
        key[0] = 0;

        while (!pq.isEmpty()) {
            int u = pq.poll().dest;

            mstSet[u] = true;

            for (Edge e : adjList[u]) {
                int v = e.dest;
                int weight = e.weight;

                if (!mstSet[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.add(new Edge(v, key[v]));
                }
            }
        }

        // Encontra a maior distância na AGM
        long maxDistance = 0;
        for (int i = 0; i < V; i++) {
            maxDistance += key[i];
        }

        return maxDistance;
    }
}

public class A_Paz_em_Spar {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); // Número de casos de teste

        StringBuilder sb = new StringBuilder();

        for (int caseNum = 0; caseNum < t; caseNum++) {
            int n = Integer.parseInt(br.readLine().trim()); // Número de cidades
            Graph graph = new Graph(n);

            // Lê as arestas do grafo
            for (int i = 0; i < n - 1; i++) {
                String[] edgeInfo = br.readLine().trim().split(" ");
                int a = Integer.parseInt(edgeInfo[0]);
                int b = Integer.parseInt(edgeInfo[1]);
                graph.addEdge(a, b, 1); // Todas as arestas têm peso 1
            }

            int q = Integer.parseInt(br.readLine().trim()); // Número de novas estradas a serem consideradas

            // Para cada nova estrada
            for (int i = 0; i < q; i++) {
                String[] newRoadInfo = br.readLine().trim().split(" ");
                int u = Integer.parseInt(newRoadInfo[0]);
                int v = Integer.parseInt(newRoadInfo[1]);

                // Adiciona a nova estrada ao grafo temporariamente
                graph.addEdge(u, v, 1);

                // Calcula a Árvore Geradora Mínima (AGM) e a maior distância
                long maxDistance = graph.primMST();

                // Remove a nova estrada do grafo para o próximo cálculo
                graph.adjList[u].removeIf(e -> e.dest == v);
                graph.adjList[v].removeIf(e -> e.dest == u);

                // Adiciona a resposta ao StringBuilder
                sb.append(maxDistance).append("\n");
            }

            if (caseNum < t - 1) {
                sb.append("\n"); // Linha em branco entre os casos de teste
            }
        }

        System.out.print(sb.toString());
    }
}
