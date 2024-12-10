import java.util.*;

public class O_Fantastico_Jaspion_1449 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        sc.nextLine(); // Consume the newline after T

        for (int t = 0; t < T; t++) {
            int M = sc.nextInt();
            int N = sc.nextInt();
            sc.nextLine(); // Consume the newline after M and N

            Map<String, String> dictionary = new HashMap<>();

            // Reading dictionary
            for (int i = 0; i < M; i++) {
                String japaneseWord = sc.nextLine();
                String portugueseTranslation = sc.nextLine();
                dictionary.put(japaneseWord, portugueseTranslation);
            }

            // Reading song lyrics and translating
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                String[] words = sc.nextLine().split(" ");
                for (int j = 0; j < words.length; j++) {
                    String translatedWord = dictionary.getOrDefault(words[j], words[j]);
                    sb.append(translatedWord);
                    if (j < words.length - 1) {
                        sb.append(" ");
                    }
                }
                sb.append("\n"); // Append newline after each line of lyrics
            }

            // Print translated lyrics for current instance
            System.out.print(sb.toString());

            if (t < T - 1) {
                System.out.println(); // Print an extra newline between instances
            }
        }

        sc.close();
    }
}
