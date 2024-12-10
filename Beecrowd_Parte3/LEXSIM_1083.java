import java.util.Scanner;
import java.util.Stack;

public class LEXSIM_1083 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String expression = scanner.next();
            if (expression.equals("EOF()"))
                break;

            if (isValidExpression(expression)) {
                String postfix = infixToPostfix(expression);
                System.out.println(postfix);
            }
        }
    }

    private static boolean isValidExpression(String expression) {
        Stack<Character> stack = new Stack<>();
        for (char c : expression.toCharArray()) {
            if (isOperand(c) || isOperator(c) || c == '(' || c == ')') {
                if (c == '(') {
                    stack.push(c);
                } else if (c == ')') {
                    if (stack.isEmpty() || stack.peek() != '(') {
                        System.out.println("Syntax Error!");
                        return false;
                    }
                    stack.pop();
                }
            } else {
                System.out.println("Lexical Error!");
                return false;
            }
        }
        if (!stack.isEmpty()) {
            System.out.println("Syntax Error!");
            return false;
        }
        return true;
    }

    private static boolean isOperand(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    private static boolean isOperator(char c) {
        return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-' || c == '>' || c == '<' || c == '=' || c == '#' || c == '.' || c == '|');
    }

    private static int getPriority(char c) {
        switch (c) {
            case '^':
                return 6;
            case '*':
            case '/':
                return 5;
            case '+':
            case '-':
                return 4;
            case '>':
            case '<':
            case '=':
            case '#':
                return 3;
            case '.':
                return 2;
            case '|':
                return 1;
            default:
                return 0;
        }
    }

    private static String infixToPostfix(String expression) {
        StringBuilder postfix = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for (char c : expression.toCharArray()) {
            if (isOperand(c)) {
                postfix.append(c);
            } else if (isOperator(c)) {
                while (!stack.isEmpty() && getPriority(stack.peek()) >= getPriority(c)) {
                    postfix.append(stack.pop());
                }
                stack.push(c);
            }
        }

        while (!stack.isEmpty()) {
            postfix.append(stack.pop());
        }

        return postfix.toString();
    }
}
