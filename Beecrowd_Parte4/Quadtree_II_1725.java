import java.util.Scanner;

public class Quadtree_II_1725_ERRO {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ler o tamanho da imagem
        String line1 = scanner.nextLine();
        int width = Integer.parseInt(line1.split(" ")[2]);

        String line2 = scanner.nextLine();
        int height = Integer.parseInt(line2.split(" ")[2]);

        // Ler os dados hexadecimais
        StringBuilder hexData = new StringBuilder();
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine().trim();
            if (line.equals("};")) {
                break;
            }
            if (line.startsWith("0x")) {
                hexData.append(line.substring(2).replaceAll("\\s+", ""));
            }
        }

        scanner.close();

        // Processar os dados hexadecimais
        char[][] pixels = new char[width][height];
        int index = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                // Converter o caractere hexadecimal para um número inteiro
                char hexChar = hexData.charAt(index);
                int hexValue = Character.digit(hexChar, 16);

                // Determinar o valor do pixel (B ou W)
                int bitPosition = 7 - (index % 8); // Posição do bit dentro do byte
                int bitValue = (hexValue >> bitPosition) & 1;

                pixels[x][y] = (bitValue == 0) ? 'B' : 'W';

                index++;
            }
        }

        // Construir o quadtree
        StringBuilder quadtree = new StringBuilder();
        buildQuadtree(pixels, quadtree, 0, 0, width);

        // Imprimir resultado
        System.out.println(width);
        System.out.println(quadtree.toString());
    }

    private static void buildQuadtree(char[][] pixels, StringBuilder quadtree, int x, int y, int size) {
        if (size == 1) {
            quadtree.append(pixels[x][y]);
            return;
        }

        char firstPixel = pixels[x][y];
        boolean same = true;

        // Verificar se todos os pixels na área são iguais
        for (int dy = 0; dy < size; dy++) {
            for (int dx = 0; dx < size; dx++) {
                if (pixels[x + dx][y + dy] != firstPixel) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }

        if (same) {
            quadtree.append(firstPixel);
        } else {
            int newSize = size / 2;
            quadtree.append('Q');
            buildQuadtree(pixels, quadtree, x, y, newSize); // Top-left
            buildQuadtree(pixels, quadtree, x + newSize, y, newSize); // Top-right
            buildQuadtree(pixels, quadtree, x, y + newSize, newSize); // Bottom-left
            buildQuadtree(pixels, quadtree, x + newSize, y + newSize, newSize); // Bottom-right
        }
    }
}
