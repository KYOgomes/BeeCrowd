import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Presente_1425 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int N = scanner.nextInt();
            int M = scanner.nextInt();
            if (N == 0 && M == 0) break;

            if (canReachStone(N, M)) {
                System.out.println("Let me try!");
            } else {
                System.out.println("Don't make fun of me!");
            }
        }
    }

    private static boolean canReachStone(int N, int M) {
        // BFS setup
        Queue<Position> queue = new LinkedList<>();
        boolean[] visited = new boolean[N + 2]; // Extra space for left and right bank

        // Start from the left bank (position 0)
        queue.add(new Position(0, 1));
        visited[0] = true;

        while (!queue.isEmpty()) {
            Position current = queue.poll();
            int currentPosition = current.position;
            int jumpNumber = current.jumpNumber;

            // Calculate the next jump distance
            int jumpDistance = 2 * jumpNumber - 1;

            // Jump forward
            int forwardPosition = currentPosition + jumpDistance;
            if (forwardPosition == M) return true; // Reached the target stone
            if (forwardPosition <= N && !visited[forwardPosition]) {
                visited[forwardPosition] = true;
                queue.add(new Position(forwardPosition, jumpNumber + 1));
            }

            // Jump backward
            int backwardPosition = currentPosition - jumpDistance;
            if (backwardPosition == M) return true; // Reached the target stone
            if (backwardPosition > 0 && !visited[backwardPosition]) {
                visited[backwardPosition] = true;
                queue.add(new Position(backwardPosition, jumpNumber + 1));
            }
        }

        return false;
    }

    // Helper class to store the position and the jump number
    static class Position {
        int position;
        int jumpNumber;

        Position(int position, int jumpNumber) {
            this.position = position;
            this.jumpNumber = jumpNumber;
        }
    }
}
