import java.util.*;

class BinarySearchTree {
    static class Node {
        int matricula;
        Node left, right;

        Node(int matricula) {
            this.matricula = matricula;
            left = right = null;
        }
    }

    Node root;

    // Insere um novo nó na árvore e retorna o tutor
    int insert(int matricula) {
        Node newNode = new Node(matricula);
        if (root == null) {
            root = newNode;
            return -1; // O primeiro aluno não possui tutor
        }

        Node current = root;
        Node parent = null;
        while (current != null) {
            parent = current;
            if (matricula < current.matricula) {
                current = current.left;
            } else {
                current = current.right;
            }
        }

        if (matricula < parent.matricula) {
            parent.left = newNode;
        } else {
            parent.right = newNode;
        }
        return parent.matricula;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] matriculas = new int[N];
        for (int i = 0; i < N; i++) {
            matriculas[i] = scanner.nextInt();
        }

        int Q = scanner.nextInt();
        int[] queries = new int[Q];
        for (int i = 0; i < Q; i++) {
            queries[i] = scanner.nextInt();
        }

        int[] tutors = new int[N];
        BinarySearchTree bst = new BinarySearchTree();

        tutors[0] = bst.insert(matriculas[0]); // O primeiro aluno não possui tutor

        for (int i = 1; i < N; i++) {
            tutors[i] = bst.insert(matriculas[i]);
        }

        for (int i = 0; i < Q; i++) {
            System.out.println(tutors[queries[i] - 1]);
        }

        scanner.close();
    }
}
