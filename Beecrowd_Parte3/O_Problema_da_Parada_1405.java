import java.util.*;
//erro de tudo
public class O_Problema_da_Parada_1405 {
    static final int MAX = 1000;
    static int[] R = new int[10];
    static String[] program;
    static boolean[][] visited;
    static int L;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            L = sc.nextInt();
            int N = sc.nextInt();
            if (L == 0 && N == 0) break;
            program = new String[L];
            visited = new boolean[L][MAX];
            for (int i = 0; i < L; i++) {
                program[i] = sc.nextLine().trim();
            }
            Arrays.fill(R, 0);
            R[0] = N;
            int result = run(0);
            if (result == -1) {
                System.out.println("*");
            } else {
                System.out.println(result);
            }
        }
        sc.close();
    }

    static int run(int line) {
        if (line == L) return R[9];
        if (visited[line][R[0]]) return -1;
        visited[line][R[0]] = true;
        String[] parts = program[line].split(" ");
        String cmd = parts[0];
        if (cmd.equals("MOV")) {
            int[] args = parseArgs(parts[1]);
            R[args[0]] = args[1];
            return run(line + 1);
        } else if (cmd.equals("ADD")) {
            int[] args = parseArgs(parts[1]);
            R[args[0]] = (R[args[0]] + args[1]) % MAX;
            return run(line + 1);
        } else if (cmd.equals("SUB")) {
            int[] args = parseArgs(parts[1]);
            R[args[0]] = (R[args[0]] - args[1] + MAX) % MAX;
            return run(line + 1);
        } else if (cmd.equals("MUL")) {
            int[] args = parseArgs(parts[1]);
            R[args[0]] = (R[args[0]] * args[1]) % MAX;
            return run(line + 1);
        } else if (cmd.equals("DIV")) {
            int[] args = parseArgs(parts[1]);
            R[args[0]] = args[1] == 0 ? 0 : R[args[0]] / args[1];
            return run(line + 1);
        } else if (cmd.equals("MOD")) {
            int[] args = parseArgs(parts[1]);
            R[args[0]] = args[1] == 0 ? 0 : R[args[0]] % args[1];
            return run(line + 1);
        } else if (cmd.equals("IFEQ")) {
            int[] args = parseArgs(parts[1]);
            if (R[args[0]] == args[1]) return run(line + 1);
            else return run(findEndif(line) + 1);
        } else if (cmd.equals("IFNEQ")) {
            int[] args = parseArgs(parts[1]);
            if (R[args[0]] != args[1]) return run(line + 1);
            else return run(findEndif(line) + 1);
        } else if (cmd.equals("IFG")) {
            int[] args = parseArgs(parts[1]);
            if (R[args[0]] > args[1]) return run(line + 1);
            else return run(findEndif(line) + 1);
        } else if (cmd.equals("IFL")) {
            int[] args = parseArgs(parts[1]);
            if (R[args[0]] < args[1]) return run(line + 1);
            else return run(findEndif(line) + 1);
        } else if (cmd.equals("IFGE")) {
            int[] args = parseArgs(parts[1]);
            if (R[args[0]] >= args[1]) return run(line + 1);
            else return run(findEndif(line) + 1);
        } else if (cmd.equals("IFLE")) {
            int[] args = parseArgs(parts[1]);
            if (R[args[0]] <= args[1]) return run(line + 1);
            else return run(findEndif(line) + 1);
        } else if (cmd.equals("CALL")) {
            int arg = parseArg(parts[1]);
            int result = run(0);
            if (result == -1) return -1;
            R[9] = result;
            return run(line + 1);
        } else if (cmd.equals("RET")) {
            return parseArg(parts[1]);
        } else {
            return -1;
        }
    }

    static int[] parseArgs(String s) {
        String[] parts = s.split(",");
        return new int[]{parseArg(parts[0]), parseArg(parts[1])};
    }

    static int parseArg(String s) {
        if (s.charAt(0) == 'R') {
            return R[s.charAt(1) - '0'];
        } else {
            return Integer.parseInt(s);
        }
    }

    static int findEndif(int line) {
        int count = 1;
        while (count > 0) {
            line++;
            if (program[line].startsWith("IF")) count++;
            else if (program[line].equals("ENDIF")) count--;
        }
        return line;
    }
}