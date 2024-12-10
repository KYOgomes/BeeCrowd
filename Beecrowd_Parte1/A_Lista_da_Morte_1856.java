import java.util.*;

class Node {
    int value;
    Node next, prev;

    Node(int value) {
        this.value = value;
        this.next = this.prev = null;
    }
}

class DoublyLinkedList {
    Node head, tail;

    DoublyLinkedList() {
        this.head = this.tail = null;
    }

    void insertAfter(Node afterNode, int value) {
        Node newNode = new Node(value);
        if (afterNode.next != null) {
            newNode.next = afterNode.next;
            afterNode.next.prev = newNode;
        } else {
            tail = newNode;
        }
        newNode.prev = afterNode;
        afterNode.next = newNode;
    }

    void removeNode(Node node) {
        if (node.prev != null) {
            node.prev.next = node.next;
        } else {
            head = node.next;
        }
        if (node.next != null) {
            node.next.prev = node.prev;
        } else {
            tail = node.prev;
        }
    }
}

public class A_Lista_da_Morte_1856 {

    static final int TABLE_SIZE = 100003;
    static Map<Integer, Node> hashTable = new HashMap<>(TABLE_SIZE);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        DoublyLinkedList list = new DoublyLinkedList();
        
        Node lastNode = null;
        for (int i = 0; i < N; i++) {
            int enemy = sc.nextInt();
            Node newNode = new Node(enemy);
            if (list.head == null) {
                list.head = list.tail = newNode;
            } else {
                lastNode.next = newNode;
                newNode.prev = lastNode;
                list.tail = newNode;
            }
            lastNode = newNode;
            hashTable.put(enemy, newNode);
        }

        int Q = sc.nextInt();
        for (int i = 0; i < Q; i++) {
            String command = sc.next();
            if (command.equals("I")) {
                int p = sc.nextInt();
                int e = sc.nextInt();
                Node eNode = hashTable.get(e);
                list.insertAfter(eNode, p);
                hashTable.put(p, eNode.next);
            } else if (command.equals("R")) {
                int e = sc.nextInt();
                Node eNode = hashTable.get(e);
                list.removeNode(eNode);
                hashTable.remove(e);
            } else if (command.equals("Q")) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                System.out.println(countBetween(list, a, b));
            }
        }

        sc.close();
    }

    static int countBetween(DoublyLinkedList list, int a, int b) {
        Node nodeA = hashTable.get(a);
        Node nodeB = hashTable.get(b);
        int count = 0;
        if (nodeA == null || nodeB == null) return -1;
        
        Node start = nodeA.next;
        while (start != null && start != nodeB) {
            count++;
            start = start.next;
        }
        
        if (start == null) {
            count = 0;
            start = nodeB.next;
            while (start != null && start != nodeA) {
                count++;
                start = start.next;
            }
        }
        
        return count;
    }
}
