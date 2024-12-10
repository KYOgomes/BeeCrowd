/*
Existe uma estrutura de dados do tipo sacola, suportando duas operações:

1 x
Jogue um elemento x na sacola.

2
Tire um elemento da sacola.

Dada uma sequencia de operações que retornam valores, você vai adivinhar a estrutura de dados. É uma pilha (último-dentro, primeiro-fora), uma fila (primeiro-dentro, primeiro-fora), uma fila de prioridade (sempre tire os elementos grandes por primeiro) ou qualquer outra coisa que você dificilmente consegue imaginar!

Entrada
Existem muitos casos de testes. Cada caso de teste começa com a linha contando um único inteiro n (1 <= n <= 1000). Cada uma das seguintes n linhas é um comando do tipo 1, ou um número inteiro 2, seguido de um número inteiro x. Isso significa que depois de executar um comando do tipo 2, obtemos um elemento x sem erros. O valor de x é sempre um número inteiro, positivo e não maior do que 100. O final da entrada é determinado pelo final do arquivo (EOF). O tamanho do arquivo de entrada não excede 1MB.

Saída
Para cada caso de teste, mostre um dos seguintes:

stack
É definitivamente uma pilha.

queue
É definitivamente uma fila.

priority queue
É definitivamente uma fila de prioridade.

impossible
Não pode ser uma pilha, uma fila ou uma fila de prioridade.

not sure
Pode ser mais de uma das três estruturas mencionadas acima.


Exemplo de Entrada	
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4

Exemplo de Saída
queue
not sure
impossible
stack
priority queue

*/
import java.util.*;

class Pilha {
    private int[] dados;
    private int topo;

    public Pilha(int tamanhoMaximo) {
        dados = new int[tamanhoMaximo];
        topo = -1;
    }

    public void empilhar(int numero) {
        dados[++topo] = numero;
    }

    public void desempilhar() {
        topo--;
    }

    public int topo() {
        return dados[topo];
    }

    public boolean vazia() {
        return topo == -1;
    }
}

class Fila {
    private int[] dados;
    private int inicio, fim;

    public Fila(int tamanhoMaximo) {
        dados = new int[tamanhoMaximo];
        inicio = 0;
        fim = 0;
    }

    public void enfileirar(int numero) {
        dados[fim++] = numero;
    }

    public void desenfileirar() {
        inicio++;
    }

    public int frente() {
        return dados[inicio];
    }

    public boolean vazia() {
        return inicio == fim;
    }
}

class FilaPrioridade {
    private int[] dados;
    private int tamanho;

    public FilaPrioridade(int tamanhoMaximo) {
        dados = new int[tamanhoMaximo];
        tamanho = 0;
    }

    public void enfileirar(int numero) {
        dados[tamanho++] = numero;
    }

    public void desenfileirar() {
        int maxIndex = 0;
        for (int i = 1; i < tamanho; ++i) {
            if (dados[i] > dados[maxIndex]) {
                maxIndex = i;
            }
        }
        for (int i = maxIndex; i < tamanho - 1; ++i) {
            dados[i] = dados[i + 1];
        }
        tamanho--;
    }

    public int frente() {
        int maxIndex = 0;
        for (int i = 1; i < tamanho; ++i) {
            if (dados[i] > dados[maxIndex]) {
                maxIndex = i;
            }
        }
        return dados[maxIndex];
    }

    public boolean vazia() {
        return tamanho == 0;
    }
}

public class Eu_Posso_Adivinhar_a_Estrutura_de_Dados_1340 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();

            Pilha pilha = new Pilha(n);
            Fila fila = new Fila(n);
            FilaPrioridade filaPrioridade = new FilaPrioridade(n);

            boolean p = true, f = true, fp = true;

            for (int i = 0; i < n; ++i) {
                int operacao = scanner.nextInt();
                int numero = scanner.nextInt();

                if (operacao == 1) {
                    if (p)
                        pilha.empilhar(numero);
                    if (f)
                        fila.enfileirar(numero);
                    if (fp)
                        filaPrioridade.enfileirar(numero);
                } else {
                    if (p) {
                        if (pilha.vazia() || pilha.topo() != numero)
                            p = false;
                        else
                            pilha.desempilhar();
                    }

                    if (f) {
                        if (fila.vazia() || fila.frente() != numero)
                            f = false;
                        else
                            fila.desenfileirar();
                    }

                    if (fp) {
                        if (filaPrioridade.vazia() || filaPrioridade.frente() != numero)
                            fp = false;
                        else
                            filaPrioridade.desenfileirar();
                    }
                }
            }

            if (p && !f && !fp)
                System.out.println("stack");
            else if (!p && f && !fp)
                System.out.println("queue");
            else if (!p && !f && fp)
                System.out.println("priority queue");
            else if (!p && !f && !fp)
                System.out.println("impossible");
            else
                System.out.println("not sure");
        }

        scanner.close();
    }
}
