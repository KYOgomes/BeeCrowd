import java.util.*;

public class Cache_Introspectivo_3186 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int C = scanner.nextInt(); // Capacidade do cache
        int N = scanner.nextInt(); // Número de objetos diferentes no sistema
        int A = scanner.nextInt(); // Número de acessos

        int[] acessos = new int[A];
        for (int i = 0; i < A; i++) {
            acessos[i] = scanner.nextInt();
        }

        System.out.println(calculaMinimoLeituras(C, acessos));
    }

    public static int calculaMinimoLeituras(int capacidade, int[] acessos) {
        if (capacidade == 0) return acessos.length;

        Set<Integer> cache = new HashSet<>();
        Map<Integer, Integer> proximoUso = new HashMap<>();
        int leiturasForaDoCache = 0;

        for (int i = 0; i < acessos.length; i++) {
            proximoUso.put(acessos[i], i);
        }

        for (int i = 0; i < acessos.length; i++) {
            int obj = acessos[i];

            if (!cache.contains(obj)) {
                leiturasForaDoCache++;
                if (cache.size() == capacidade) {
                    int removivel = encontraRemovivel(cache, proximoUso, i);
                    cache.remove(removivel);
                }
                cache.add(obj);
            }

            proximoUso.remove(obj);
            for (int j = i + 1; j < acessos.length; j++) {
                if (acessos[j] == obj) {
                    proximoUso.put(obj, j);
                    break;
                }
            }
        }

        return leiturasForaDoCache;
    }

    private static int encontraRemovivel(Set<Integer> cache, Map<Integer, Integer> proximoUso, int atual) {
        int ultimoUso = -1;
        int removivel = -1;

        for (int obj : cache) {
            if (!proximoUso.containsKey(obj)) {
                return obj;
            }
            if (proximoUso.get(obj) > ultimoUso) {
                ultimoUso = proximoUso.get(obj);
                removivel = obj;
            }
        }

        return removivel;
    }
}
