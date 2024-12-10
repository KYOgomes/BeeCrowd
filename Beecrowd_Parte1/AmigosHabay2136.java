import java.util.HashSet;
import java.util.Set;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        Set<String> yesSet = new TreeSet<>(); // Utiliza TreeSet para ordenar os nomes automaticamente
        Set<String> noSet = new TreeSet<>();  // Utiliza TreeSet para ordenar os nomes automaticamente
        String amigo = "";
        
        String[] entrada = sc.nextLine().split(" ");
        
        while (!entrada[0].equals("FIM")) {
            String nome = entrada[0];
            String status = entrada[1];
            
            if (status.equals("YES")) {
                yesSet.add(nome);
                if (nome.length() > amigo.length()) {
                    amigo = nome;
                }
            } else {
                noSet.add(nome);
            }
            
            entrada = sc.nextLine().split(" ");
        }
        
        for (String nome : yesSet) {
            System.out.println(nome);
        }
        
        for (String nome : noSet) {
            System.out.println(nome);
        }
        
        System.out.println("\nAmigo do Habay:");
        System.out.println(amigo);
        
        sc.close();
    }
}
