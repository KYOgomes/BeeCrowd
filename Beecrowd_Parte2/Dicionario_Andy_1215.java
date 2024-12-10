import java.util.*;

public class Dicionario_Andy_1215 {

    static class Word {
        String word;

        public Word(String word) {
            this.word = word;
        }

        public String getWord() {
            return word;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Word> dictionary = new ArrayList<>();
        
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            normalizeAndAdd(line, dictionary);
        }

        dictionary.sort(new Comparator<Word>() {
            @Override
            public int compare(Word w1, Word w2) {
                return w1.getWord().compareToIgnoreCase(w2.getWord());
            }
        });

        for (Word word : dictionary) {
            System.out.println(word.getWord());
        }

        scanner.close();
    }

    static void normalizeAndAdd(String line, List<Word> dictionary) {
        String[] words = line.split("[^a-zA-Z]+");
        for (String word : words) {
            if (!word.isEmpty()) {
                Word normalizedWord = new Word(word.toLowerCase());
                if (!dictionary.contains(normalizedWord)) {
                    dictionary.add(normalizedWord);
                }
            }
        }
    }
}
