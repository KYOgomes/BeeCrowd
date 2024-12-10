/*
O professor Rolien organizou junto às suas turmas de Ciência da Computação a confecção de uma camiseta polo que fosse ao mesmo tempo bonita e barata. Após algumas conversas, ficou decidido com os alunos que seriam feitas somente camisetas da cor preta, o que facilitaria a confecção. Os alunos poderiam escolher entre o logo do curso e os detalhes em branco ou vermelho. Assim sendo, Rolien precisa de sua ajuda para organizar as listas de quem quer a camiseta em cada uma das turmas, relacionando estas camisetas pela cor do logo do curso, tamanho (P, M ou G) e por último pelo nome.

Entrada
A entrada contém vários casos de teste. Cada caso de teste inicia com um valor N, (1 ≤ N ≤ 60) inteiro e positivo, que indica a quantidade de camisetas a serem feitas para aquela turma. As próximas N*2 linhas contém informações de cada uma das camisetas (serão duas linhas de informação para cada camiseta). A primeira linha irá conter o nome do estudante e a segunda linha irá conter a cor do logo da camiseta ("branco" ou "vermelho") seguido por um espaço e pelo tamanho da camiseta "P" "M" ou "G". A entrada termina quando o valor de N for igual a zero (0) e esta valor não deverá ser processado.

Saída
Para cada caso de entrada deverão ser impressas as informações ordenadas pela cor dos detalhes em ordem ascendente, seguido pelos tamanhos em ordem descendente e por último por ordem ascendente de nome, conforme o exemplo abaixo.

Obs.: Deverá ser impressa uma linha em branco entre dois casos de teste.

Exemplo de Entrada	
9
Maria Jose
branco P
Mangojata Mancuda
vermelho P
Cezar Torres Mo
branco P
Baka Lhau
vermelho P
JuJu Mentina
branco M
Amaro Dinha
vermelho P
Adabi Finho
branco G
Severina Rigudinha
branco G
Carlos Chade Losna
vermelho P
3
Maria Joao
branco P
Marcio Guess
vermelho P
Maria Jose
branco P
0

Exemplo de Saída
branco P Cezar Torres Mo
branco P Maria Jose
branco M JuJu Mentina
branco G Adabi Finho
branco G Severina Rigudinha
vermelho P Amaro Dinha
vermelho P Baka Lhau
vermelho P Carlos Chade Losna
vermelho P Mangojata Mancuda

branco P Maria Joao
branco P Maria Jose
vermelho P Marcio Guess
*/
import java.util.*;

// Classe para representar uma camiseta
class Camiseta {
    String nome;
    String cor;
    char tamanho;

    public Camiseta(String nome, String cor, char tamanho) {
        this.nome = nome;
        this.cor = cor;
        this.tamanho = tamanho;
    }
}

public class Camisetas_1258 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        boolean primeiro = true; // variável para controlar a impressão de linha em branco entre casos de teste

        while (scanner.hasNext()) {
            int N = scanner.nextInt();
            if (N == 0) {
                break;
            }
            if (!primeiro) {
                System.out.println(); // imprimir linha em branco entre casos de teste
            }
            primeiro = false;

            scanner.nextLine(); // consumir a quebra de linha após o número N

            List<Camiseta> camisetas = new ArrayList<>();

            // Leitura das camisetas
            for (int i = 0; i < N; i++) {
                String nome = scanner.nextLine().trim();
                String[] info = scanner.nextLine().split(" ");
                String cor = info[0];
                char tamanho = info[1].charAt(0);
                camisetas.add(new Camiseta(nome, cor, tamanho));
            }

            // Ordenação das camisetas
            Collections.sort(camisetas, new Comparator<Camiseta>() {
                @Override
                public int compare(Camiseta c1, Camiseta c2) {
                    // Primeiro critério: cor do logo
                    int cmpCor = c1.cor.compareTo(c2.cor);
                    if (cmpCor != 0) {
                        return cmpCor;
                    }

                    // Segundo critério: tamanho (ordem descendente)
                    if (c1.tamanho > c2.tamanho) {
                        return -1;
                    } else if (c1.tamanho < c2.tamanho) {
                        return 1;
                    }

                    // Terceiro critério: nome (ordem ascendente)
                    return c1.nome.compareTo(c2.nome);
                }
            });

            // Impressão das camisetas ordenadas
            for (Camiseta camiseta : camisetas) {
                System.out.println(camiseta.cor + " " + camiseta.tamanho + " " + camiseta.nome);
            }
        }

        scanner.close();
    }
}
