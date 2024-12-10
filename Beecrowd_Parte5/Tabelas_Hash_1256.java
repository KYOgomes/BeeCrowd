import java.util.Scanner;

// Definição da classe para o nó da lista encadeada
class ListaNo {
    int valor;         // Valor armazenado no nó
    ListaNo prox;      // Referência para o próximo nó na lista

    // Construtor para criar um novo nó com um valor dado
    ListaNo(int valor) {
        this.valor = valor;
        this.prox = null;
    }
}

// Definição da classe para a lista encadeada
class ListaEncadeada {
    ListaNo lista;     // Referência para o primeiro nó da lista

    // Construtor para inicializar a lista como vazia
    ListaEncadeada() {
        this.lista = null;
    }

    // Método para adicionar um novo nó com um valor dado ao fim da lista
    void adicionaNo(int valor) {
        ListaNo novo = new ListaNo(valor);

        if (lista == null) {
            lista = novo;
        } else {
            ListaNo p = lista;
            while (p.prox != null) {
                p = p.prox;
            }
            p.prox = novo;
        }
    }

    // Método para imprimir os elementos da lista
    void imprimeLista() {
        ListaNo p = lista;
        while (p != null) {
            System.out.print(p.valor + " -> ");
            p = p.prox;
        }
        System.out.println("\\");
    }
}

// Definição da classe para a tabela hash
class TabelaHash {
    int n;                // Número de listas na tabela hash
    ListaEncadeada[] tabela;  // Array de listas encadeadas para a tabela hash

    // Construtor para criar uma tabela hash com 'n' listas vazias
    TabelaHash(int n) {
        this.n = n;
        this.tabela = new ListaEncadeada[n];
        for (int i = 0; i < n; ++i) {
            this.tabela[i] = new ListaEncadeada();
        }
    }

    // Método para calcular o índice na tabela hash para um dado valor
    int funcaoHash(int valor) {
        return valor % n;
    }

    // Método para adicionar um valor à tabela hash
    void adicionaElemento(int valor) {
        int indice = funcaoHash(valor);
        tabela[indice].adicionaNo(valor);
    }

    // Método para imprimir toda a tabela hash
    void imprimeTabelaHash() {
        for (int i = 0; i < n; ++i) {
            System.out.print(i + " -> ");
            tabela[i].imprimeLista();
        }
    }
}

// Classe principal do programa
public class Tabelas_Hash_1256 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Número de casos de teste

        for (int k = 0; k < N; ++k) {
            if (k > 0)
                System.out.println();

            int M = scanner.nextInt();  // Número de listas na tabela hash
            int C = scanner.nextInt();  // Número de elementos a serem adicionados

            TabelaHash tabela = new TabelaHash(M);  // Inicializa a tabela hash com M listas

            for (int i = 0; i < C; ++i) {
                int numero = scanner.nextInt();  // Lê o próximo número a ser adicionado
                tabela.adicionaElemento(numero); // Adiciona o número à tabela hash
            }

            tabela.imprimeTabelaHash();  // Imprime a tabela hash após a inserção dos números
        }

        scanner.close();
    }
}
