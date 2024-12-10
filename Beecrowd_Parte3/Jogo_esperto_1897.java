import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Jogo_esperto_1897 {

    public static int minOperations(int N, int M) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[10001];
        
        queue.offer(N);
        visited[N] = true;
        int operations = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                int current = queue.poll();
                
                if (current == M) {
                    return operations;
                }
                
                // Operações possíveis
                if (current * 2 <= 10000 && !visited[current * 2]) {
                    queue.offer(current * 2);
                    visited[current * 2] = true;
                }
                if (current * 3 <= 10000 && !visited[current * 3]) {
                    queue.offer(current * 3);
                    visited[current * 3] = true;
                }
                if (current % 2 == 0 && !visited[current / 2]) {
                    queue.offer(current / 2);
                    visited[current / 2] = true;
                }
                if (current % 3 == 0 && !visited[current / 3]) {
                    queue.offer(current / 3);
                    visited[current / 3] = true;
                }
                if (!visited[current + 7]) {
                    queue.offer(current + 7);
                    visited[current + 7] = true;
                }
                if (current - 7 >= 0 && !visited[current - 7]) {
                    queue.offer(current - 7);
                    visited[current - 7] = true;
                }
            }
            operations++;
        }
        
        return -1; // Caso não encontre, embora não seja necessário para o problema dado as condições
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.close();
        
        int result = minOperations(N, M);
        System.out.println(result);
    }
}