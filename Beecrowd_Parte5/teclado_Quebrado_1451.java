import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.ListIterator;

public class teclado_Quebrado_1451 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            LinkedList<Character> list = new LinkedList<>();
            ListIterator<Character> it = list.listIterator();

            for (char c : line.toCharArray()) {
                if (c == '[') {
                    it = list.listIterator(0); // Move the cursor to the beginning of the list
                } else if (c == ']') {
                    it = list.listIterator(list.size()); // Move the cursor to the end of the list
                } else {
                    it.add(c); // Insert the character at the current cursor position
                }
            }

            StringBuilder sb = new StringBuilder();
            for (Character c : list) {
                sb.append(c);
            }

            System.out.println(sb.toString());
        }
    }
}