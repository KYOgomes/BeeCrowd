import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Palavra {
    String nome;
    int valor;

    Palavra(String nome, int valor) {
        this.nome = nome;
        this.valor = valor;
    }
}

public class SomaPalavras {
    
    public static int soma(List<Palavra> palavras, List<String> descricao, int total) {
        if (palavras.isEmpty() || descricao.isEmpty()) {
            return total;
        } else if (palavras.get(0).nome.equals(descricao.get(0))) {
            return soma(palavras, descricao.subList(1, descricao.size()), total + palavras.get(0).valor);
        } else if (palavras.get(0).nome.compareTo(descricao.get(0)) < 0) {
            return soma(palavras.subList(1, palavras.size()), descricao, total);
        } else {
            return soma(palavras, descricao.subList(1, descricao.size()), total);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] entradaInicial = sc.nextLine().split(" ");
        int m = Integer.parseInt(entradaInicial[0]);
        int n = Integer.parseInt(entradaInicial[1]);

        List<Palavra> palavras = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String[] entrada = sc.nextLine().split(" ");
            palavras.add(new Palavra(entrada[0], Integer.parseInt(entrada[1])));
        }

        palavras.sort(Comparator.comparing(p -> p.nome));

        for (int i = 0; i < n; i++) {
            List<String> descricao = new ArrayList<>();
            String entrada = sc.nextLine();
            while (!entrada.equals(".")) {
                String[] palavrasDescricao = entrada.split(" ");
                Collections.addAll(descricao, palavrasDescricao);
                entrada = sc.nextLine();
            }
            descricao.sort(String::compareTo);
            System.out.println(soma(palavras, descricao, 0));
        }

        sc.close();
    }
}
