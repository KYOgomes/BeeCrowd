/*
 Fibo é um grande fã de números, especialmente números grandes. Ele ama sequências que crescem rápido, sua favorita é a tão famosa: sequência de Fibonacci. Um dia ele decidiu criar uma nova sequência usando a sua favorita. Sua nova sequência é criada multiplicando números consecutivos da sequência de Fibonacci. A partir de números de Fibonacci de índices A e B. O primeiro elemento de sua nova sequência será o número de fibonacci de índice A multiplicado pelo número de Fibonacci de índice B, o segundo número é o número de Fibonacci de índice A+1 multiplicado pelo número de Fibonacci de índice B+1 e assim por diante. Ele sabe como obter cada elemento dessa nova sequência eficientemente, mas ele gostaria de calcular outra coisa. Ele gostaria de calcular a soma dos N primeiros números de sua nova sequência.Você pode ajudá-lo?

Obs: Fibonnaci(0) = 0 e Fibonnaci(1) = 1

Entrada
A entra contém diversos casos testes. Cada caso teste contém três inteiros, A, B e N (1 <= A, B, N <= 1000000000), os significados foram explicados acima. A entrada termina com três zeros.

Saída
Para cada caso teste você deve imprimir um número, a soma dos N primeiros elementos da sequência de Fibo. Esse número pode ser muito grande, então você deve imprimi-lo MOD 1000000007.

Exemplo de Entrada	
1 1 5
3 4 5
0 0 0

Exemplo de Saída
40
438
 */
import java.util.Scanner;

public class Sequencia_de_Fibo_1701 {
    final static long MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            int N = scanner.nextInt();
            
            if (A == 0 && B == 0 && N == 0) {
                break;
            }
            
            // Calcula Fibonacci de A e B
            long fibA = fibonacci(A) % MOD;
            long fibB = fibonacci(B) % MOD;
            
            // Soma dos primeiros N números da sequência gerada
            long soma = calcularSomaSequencia(fibA, fibB, N, A, B);
            
            // Imprime resultado
            System.out.println(soma);
        }
        
        scanner.close();
    }
    
    // Função para calcular o número de Fibonacci módulo MOD
    private static long fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        long a = 0;
        long b = 1;
        long resultado = 0;
        
        for (int i = 2; i <= n; i++) {
            resultado = (a + b) % MOD;
            a = b;
            b = resultado;
        }
        
        return resultado;
    }
    
    // Função para calcular a soma dos primeiros N elementos da sequência
    private static long calcularSomaSequencia(long fibA, long fibB, int N, int A, int B) {
        long soma = 0;
        long termoAtualA = fibA;
        long termoAtualB = fibB;
        
        for (int i = 1; i <= N; i++) {
            long produtoAtual = (termoAtualA * termoAtualB) % MOD;
            soma = (soma + produtoAtual) % MOD;
            
            // Atualiza para os próximos termos
            long proximoTermoA = fibonacci(i + A) % MOD;
            long proximoTermoB = fibonacci(i + B) % MOD;
            
            termoAtualA = proximoTermoA;
            termoAtualB = proximoTermoB;
        }
        
        return soma;
    }
}
