import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Menor_da_Pilha_2929 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine().trim());
        
        // Pilha principal para armazenar os valores
        Stack<Integer> stack = new Stack<>();
        // Pilha auxiliar para armazenar os menores valores
        Stack<Integer> minStack = new Stack<>();
        
        StringBuilder sb = new StringBuilder();
        
        while (N-- > 0) {
            String[] operation = br.readLine().split(" ");
            
            switch (operation[0]) {
                case "PUSH":
                    int value = Integer.parseInt(operation[1]);
                    stack.push(value);
                    if (minStack.isEmpty() || value <= minStack.peek()) {
                        minStack.push(value);
                    }
                    break;
                case "POP":
                    if (!stack.isEmpty()) {
                        int popped = stack.pop();
                        if (!minStack.isEmpty() && popped == minStack.peek()) {
                            minStack.pop();
                        }
                    }
                    break;
                case "MIN":
                    if (minStack.isEmpty()) {
                        sb.append("EMPTY\n");
                    } else {
                        sb.append(minStack.peek()).append("\n");
                    }
                    break;
            }
        }
        
        System.out.print(sb.toString());
        br.close();
    }
}
