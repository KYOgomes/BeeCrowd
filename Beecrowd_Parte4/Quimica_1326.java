import java.util.*;
//saida errada
public class Quimica_1326 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int R = sc.nextInt();
            if (R == 0) break;
            sc.nextLine(); // Consumir a linha restante

            Map<String, Integer> inDegree = new HashMap<>();
            Map<String, List<String>> graph = new HashMap<>();
            List<String> reactions = new ArrayList<>();

            for (int i = 0; i < R; ++i) {
                String reaction = sc.nextLine();
                reactions.add(reaction);
                String[] parts = reaction.split(" ");
                String S1 = parts[0];
                String S2 = parts[2];
                String S3 = parts[4];

                graph.putIfAbsent(S1, new ArrayList<>());
                graph.putIfAbsent(S2, new ArrayList<>());
                graph.putIfAbsent(S3, new ArrayList<>());

                graph.get(S1).add(S3);
                graph.get(S2).add(S3);

                inDegree.put(S3, inDegree.getOrDefault(S3, 0) + 2);
                inDegree.putIfAbsent(S1, 0);
                inDegree.putIfAbsent(S2, 0);
            }

            // Encontrar a substância final
            String finalProduct = reactions.get(R - 1).split(" ")[4];

            // Realizar a ordenação topológica
            Queue<String> queue = new LinkedList<>();
            Map<String, Integer> level = new HashMap<>();

            for (String substance : inDegree.keySet()) {
                if (inDegree.get(substance) == 0) {
                    queue.add(substance);
                    level.put(substance, 1);
                }
            }

            while (!queue.isEmpty()) {
                String current = queue.poll();
                int currentLevel = level.get(current);

                for (String neighbor : graph.get(current)) {
                    inDegree.put(neighbor, inDegree.get(neighbor) - 1);
                    if (inDegree.get(neighbor) == 0) {
                        queue.add(neighbor);
                        level.put(neighbor, currentLevel + 1);
                    }
                }
            }

            // O número de recipientes necessários é a profundidade máxima da DAG
            int containersNeeded = level.get(finalProduct);
            System.out.printf("%s requires %d containers%n", finalProduct, containersNeeded);
        }

        sc.close();
    }
}
