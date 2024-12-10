import java.util.*;

public class Permutacao_Ordenadas_1401 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n-- > 0) {
            char[] s = sc.next().toCharArray();
            Arrays.sort(s);
            do {
                System.out.println(new String(s));
            } while (nextPermutation(s));
            System.out.println();
        }
        sc.close();
    }

    static boolean nextPermutation(char[] array) {
        for (int i = array.length - 2; i >= 0; i--) {
            if (array[i] < array[i + 1]) {
                for (int j = array.length - 1; ; j--) {
                    if (array[j] > array[i]) {
                        swap(array, i, j);
                        reverse(array, i + 1, array.length - 1);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    static void swap(char[] array, int i, int j) {
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    static void reverse(char[] array, int i, int j) {
        while (i < j) {
            swap(array, i++, j--);
        }
    }
}