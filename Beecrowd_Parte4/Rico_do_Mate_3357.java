import java.util.Scanner;

public class Rico_do_Mate_3357 
{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ler entrada
        int n = scanner.nextInt();
        double l = scanner.nextDouble();
        double q = scanner.nextDouble();
        scanner.nextLine();  // Consumir a linha restante
        String[] participantes = new String[n];
        for (int i = 0; i < n; i++) {
            participantes[i] = scanner.next();
        }

        // Convertendo l e q para inteiros
        int lInt = (int) Math.round(l * 10);
        int qInt = (int) Math.round(q * 10);

        // Calculando r
        int r = lInt % (n * qInt);

        int rei;
        double agua;
        
        if (r % qInt == 0) {
            agua = q;
            rei = ((lInt - 1) % (n * qInt)) / qInt;
        } else {
            agua = (r % qInt) / 10.0;
            rei = r / qInt;
        }

        // Imprimir o resultado
        System.out.printf("%s %.1f\n", participantes[rei], agua);

        scanner.close();
    }
}
