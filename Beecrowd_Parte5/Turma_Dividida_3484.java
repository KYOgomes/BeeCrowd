import java.util.*;

class TreeNode {
    int height;
    TreeNode left;
    TreeNode right;

    TreeNode(int height) {
        this.height = height;
        this.left = null;
        this.right = null;
    }
}

public class Turma_Dividida_3484 {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Leitura do número de alunos
        int n = scanner.nextInt();
        int[] heights = new int[n];
        
        // Leitura das alturas dos alunos
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextInt();
        }
        
        // Construção da árvore
        TreeNode root = new TreeNode(heights[0]);
        for (int i = 1; i < n; i++) {
            insertNode(root, heights[i]);
        }
        
        // Obtenção da menor altura em cada nível
        List<Integer> result = findMinHeightsByLevel(root);
        
        // Impressão dos resultados
        for (int i = 0; i < result.size(); i++) {
            System.out.println(i + " " + result.get(i));
        }
        
        scanner.close();
    }
    
    // Função para inserir um nó na árvore
    public static void insertNode(TreeNode root, int height) {
        TreeNode current = root;
        while (true) {
            if (height < current.height) {
                if (current.left == null) {
                    current.left = new TreeNode(height);
                    break;
                } else {
                    current = current.left;
                }
            } else {
                if (current.right == null) {
                    current.right = new TreeNode(height);
                    break;
                } else {
                    current = current.right;
                }
            }
        }
    }
    
    // Função para encontrar a menor altura em cada nível usando BFS
    public static List<Integer> findMinHeightsByLevel(TreeNode root) {
        List<Integer> minHeights = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            int minHeight = Integer.MAX_VALUE;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                minHeight = Math.min(minHeight, node.height);
                
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            
            minHeights.add(minHeight);
        }
        
        return minHeights;
    }
}
