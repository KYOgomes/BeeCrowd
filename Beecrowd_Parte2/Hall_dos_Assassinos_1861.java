import java.util.*;
import java.io.*;
//errado
public class Hall_dos_Assassinos_1861 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        Map<String, Integer> assassins = new TreeMap<>();
        Set<String> victims = new HashSet<>();
        
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            if (line.isEmpty()) break;

            String[] parts = line.split(" ");
            String assassin = parts[0];
            String victim = parts[1];

            victims.add(victim);

            if (!victims.contains(assassin)) {
                assassins.put(assassin, assassins.getOrDefault(assassin, 0) + 1);
            }
        }

        sc.close();
        
        System.out.println("HALL OF MURDERERS");
        for (Map.Entry<String, Integer> entry : assassins.entrySet()) {
            if (!victims.contains(entry.getKey())) {
                System.out.println(entry.getKey() + " " + entry.getValue());
            }
        }
    }
}
