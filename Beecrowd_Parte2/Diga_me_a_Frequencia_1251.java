/*
Dada uma linha de texto, você deve encontrar as frequências de cada um dos caracteres presentes nela. As linhas fornecidas não conterão nenhum dos primeiros 32 ou dos últimos 128 caracteres da tabela ASCII. É claro que não estamos levando em conta o caracter de fim de linha.

Entrada
A entrada contém vários casos de teste. Cada caso de teste é composto por uma única linha de texto com até 1000 caracteres.

Saída
Imprima o valor ASCII de todos os caracteres presentes e a sua frequência de acordo com o formato abaixo. Uma linha em branco deverá separar 2 conjuntos de saída. Imprima os caracteres ASCII em ordem ascendente de frequência. Se dois caracteres estiverem presentes com a mesma quantidade de frequência, imprima primeiro o caracter que tem valor ASCII maior. A entrada é terminada por final de arquivo (EOF).

Exemplo de Entrada	
AAABBC
122333

Exemplo de Saída
67 1
66 2
65 3

49 1
50 2
51 3
*/
import java.util.*;

// Classe para armazenar os dados do caractere e sua frequência
class Dados {
    char ascii;
    int frequencia;

    Dados(char ascii, int frequencia) {
        this.ascii = ascii;
        this.frequencia = frequencia;
    }
}

public class Diga_me_a_Frequencia_1251 {

    // Método de ordenação Quicksort para ordenar por ASCII
    private static void quickSort(Dados[] caractere, int inicio, int fim) {
        if (inicio < fim) {
            int pivoIndex = partition(caractere, inicio, fim);
            quickSort(caractere, inicio, pivoIndex - 1);
            quickSort(caractere, pivoIndex + 1, fim);
        }
    }

    private static int partition(Dados[] caractere, int inicio, int fim) {
        Dados pivo = caractere[fim];
        int i = inicio - 1;

        for (int j = inicio; j < fim; j++) {
            if (caractere[j].ascii < pivo.ascii || (caractere[j].ascii == pivo.ascii && caractere[j].frequencia > pivo.frequencia)) {
                i++;
                Dados temp = caractere[i];
                caractere[i] = caractere[j];
                caractere[j] = temp;
            }
        }

        Dados temp = caractere[i + 1];
        caractere[i + 1] = caractere[fim];
        caractere[fim] = temp;

        return i + 1;
    }

    // Método de ordenação Insertion Sort para ordenar por frequência
    private static void insertionSort(Dados[] caractere, int tam) {
        for (int i = 1; i < tam; i++) {
            Dados pivo = caractere[i];
            int j = i - 1;

            while (j >= 0 && (caractere[j].frequencia > pivo.frequencia || (caractere[j].frequencia == pivo.frequencia && caractere[j].ascii < pivo.ascii))) {
                caractere[j + 1] = caractere[j];
                j--;
            }

            caractere[j + 1] = pivo;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Dados> listaCaracteres = new ArrayList<>();

        // Enquanto houver entrada para processar
        while (scanner.hasNextLine()) {
            String texto = scanner.nextLine();
            int[] frequencia = new int[128]; // Frequência de caracteres ASCII

            // Conta a frequência de cada caractere no texto
            for (char c : texto.toCharArray()) {
                if (c >= 32 && c <= 127) {
                    frequencia[c]++;
                }
            }

            // Adiciona os caracteres e suas frequências na lista
            for (int i = 0; i < 128; i++) {
                if (frequencia[i] > 0) {
                    listaCaracteres.add(new Dados((char) i, frequencia[i]));
                }
            }

            // Ordena por ASCII utilizando Quicksort
            Dados[] arrayCaracteres = listaCaracteres.toArray(new Dados[0]);
            quickSort(arrayCaracteres, 0, listaCaracteres.size() - 1);

            // Ordena por frequência utilizando Insertion Sort
            insertionSort(arrayCaracteres, listaCaracteres.size());

            // Imprime os resultados conforme especificado
            for (Dados dado : arrayCaracteres) {
                System.out.println((int) dado.ascii + " " + dado.frequencia);
            }
            System.out.println(); // Linha em branco entre conjuntos de saída

            // Limpa a lista para o próximo conjunto de entrada
            listaCaracteres.clear();
        }
        scanner.close();
    }
}
