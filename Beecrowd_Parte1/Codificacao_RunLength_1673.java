/*
Sua tarefa é escrever um programa que realiza uma simples Codificação Run-Length, como descrita nas regras abaixo. Qualquer sequencia entre 2 e 9 caracteres idênticos é codificada por dois caracteres. O primeiro caractere é a largura da sequência, representada por um dos caracteres entre 2 a 9. O segundo caractere é o valor do caractere repetido. Uma sequência de mais de 9 caracteres identicos repetidos é resolvida com primeiro codificando 9 caracteres, depois os caracteres restantes.

Qualquer sequência de caracteres que não contém repetições consecutivas de qualquer caracteres é representada por um caractere '1' seguido da sequência de caracteres e terminado com outro '1'. Se um '1' aparecer como parte da sequencia, ele será terminado com um '1', tendo então dois caracteres '1' como saída.
Entrada
A entrada consiste de letras(maiúsculas e minúsculas), digitos, espaços e pontuação. Toda linha é terminada com um caractere terminador de linha.
Saída
Cada linha da entrada é codificada separadamente como descrito acima. A nova linha no final de cada linha não é codificada, mas é passada diretamente para a saída.
Exemplo de Entrada	
AAAAAABCCCC
12344

Exemplo de Saída
6A1B14C
11123124
 */
import java.util.Scanner;

public class Codificacao_RunLength_1673 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (scanner.hasNextLine()) {
            String linha = scanner.nextLine();
            String linhaCodificada = codificarRunLength(linha);
            System.out.println(linhaCodificada);
        }
        
        scanner.close();
    }
    
    public static String codificarRunLength(String linha) {
        StringBuilder resultado = new StringBuilder();
        
        int count = 1;
        char caractereAtual = linha.charAt(0);
        
        for (int i = 1; i < linha.length(); i++) {
            char proximoCaractere = linha.charAt(i);
            
            if (proximoCaractere == caractereAtual) {
                count++;
            } else {
                resultado.append(codificarSegmento(count, caractereAtual));
                caractereAtual = proximoCaractere;
                count = 1;
            }
        }
        
        // Último segmento
        resultado.append(codificarSegmento(count, caractereAtual));
        
        return resultado.toString();
    }
    
    public static String codificarSegmento(int count, char caractere) {
        StringBuilder segmento = new StringBuilder();
        
        if (count == 1) {
            segmento.append("1").append(caractere);
        } else {
            while (count > 0) {
                if (count >= 9) {
                    segmento.append("9").append(caractere);
                    count -= 9;
                } else {
                    segmento.append(count).append(caractere);
                    count = 0;
                }
            }
        }
        
        return segmento.toString();
    }
}
