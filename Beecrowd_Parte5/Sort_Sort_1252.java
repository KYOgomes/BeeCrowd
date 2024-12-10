import java.util.*;

class Numero {
    int numero;
    int modulo;

    Numero(int numero, int modulo) {
        this.numero = numero;
        this.modulo = modulo;
    }
}

public class Sort_Sort_1252 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int N = sc.nextInt();
            int M = sc.nextInt();

            if (N == 0 && M == 0) {
                break;
            }

            Numero[] numeros = new Numero[N];

            // Leitura dos números e cálculo dos módulos
            for (int i = 0; i < N; i++) {
                int numero = sc.nextInt();
                numeros[i] = new Numero(numero, Math.abs(numero) % M);
            }

            // Ordenação dos números de acordo com as regras
            Arrays.sort(numeros, (num1, num2) -> {
                if (num1.modulo != num2.modulo) {
                    return num1.modulo - num2.modulo;
                } else {
                    // Mesmo módulo, aplicar as regras adicionais
                    if (Math.abs(num1.numero) % 2 != Math.abs(num2.numero) % 2) {
                        // Se um é ímpar e o outro é par, o ímpar vem antes
                        return (Math.abs(num1.numero) % 2 == 1) ? -1 : 1;
                    } else {
                        // Ambos são pares ou ambos são ímpares
                        if (Math.abs(num1.numero) % 2 == 1) {
                            // Ambos são ímpares
                            return num2.numero - num1.numero; // maior ímpar vem antes
                        } else {
                            // Ambos são pares
                            return num1.numero - num2.numero; // menor par vem antes
                        }
                    }
                }
            });

            // Impressão do resultado para este caso de teste
            System.out.println(N + " " + M);
            for (Numero num : numeros) {
                System.out.println(num.numero);
            }
        }

        sc.close();
    }
}