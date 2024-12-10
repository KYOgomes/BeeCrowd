import java.util.*;

public class Eu_posso_Adivinha_sua_estrutura_de_Dados_1340 {

    // Fila
    static class Fila {
        LinkedList<Integer> list = new LinkedList<>();

        void push(int x) {
            list.addLast(x);
        }

        void pop() {
            list.removeFirst();
        }

        int front() {
            return list.getFirst();
        }

        boolean isEmpty() {
            return list.isEmpty();
        }
    }

    // Pilha
    static class Pilha {
        LinkedList<Integer> list = new LinkedList<>();

        void push(int x) {
            list.addFirst(x);
        }

        void pop() {
            list.removeFirst();
        }

        int top() {
            return list.getFirst();
        }

        boolean isEmpty() {
            return list.isEmpty();
        }
    }

    // Fila de prioridade
    static class PriorityQueueCustom {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        void push(int x) {
            pq.add(x);
        }

        void pop() {
            pq.poll();
        }

        int top() {
            return pq.peek();
        }

        boolean isEmpty() {
            return pq.isEmpty();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int n = sc.nextInt();
            boolean isQueue = true;
            boolean isStack = true;
            boolean isPQueue = true;

            Fila queue = new Fila();
            Pilha stack = new Pilha();
            PriorityQueueCustom pQueue = new PriorityQueueCustom();

            for (int i = 0; i < n; i++) {
                int command = sc.nextInt();
                int x = sc.nextInt();

                if (command == 1) {
                    if (isQueue) queue.push(x);
                    if (isStack) stack.push(x);
                    if (isPQueue) pQueue.push(x);
                } else {
                    if (isQueue) {
                        if (queue.isEmpty() || queue.front() != x) isQueue = false;
                        else queue.pop();
                    }

                    if (isStack) {
                        if (stack.isEmpty() || stack.top() != x) isStack = false;
                        else stack.pop();
                    }

                    if (isPQueue) {
                        if (pQueue.isEmpty() || pQueue.top() != x) isPQueue = false;
                        else pQueue.pop();
                    }
                }
            }

            if (!isQueue && !isStack && !isPQueue) {
                System.out.println("impossible");
            } else if ((isQueue && isStack) || (isQueue && isPQueue) || (isStack && isPQueue)) {
                System.out.println("not sure");
            } else if (isQueue) {
                System.out.println("queue");
            } else if (isStack) {
                System.out.println("stack");
            } else if (isPQueue) {
                System.out.println("priority queue");
            }
        }

        sc.close();
    }
}
