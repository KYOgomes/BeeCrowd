#include <stdio.h>

#define MAX_SIZE 512

// Função para construir o quadtree recursivamente
void build_quadtree(char pixels[MAX_SIZE][MAX_SIZE], char *quadtree, int x, int y, int size) {
    if (size == 1) {
        *quadtree = pixels[x][y];
        return;
    }

    char first_pixel = pixels[x][y];
    int same = 1;

    // Verifica se todos os pixels na área são iguais
    for (int dx = 0; dx < size; dx++) {
        for (int dy = 0; dy < size; dy++) {
            if (pixels[x + dx][y + dy] != first_pixel) {
                same = 0;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        *quadtree = first_pixel;
    } else {
        *quadtree = 'Q';
        int new_size = size / 2;
        build_quadtree(pixels, quadtree + 1, x, y, new_size);  // Top-left
        build_quadtree(pixels, quadtree + 1 + new_size * new_size, x + new_size, y, new_size);  // Top-right
        build_quadtree(pixels, quadtree + 1 + 2 * new_size * new_size, x, y + new_size, new_size);  // Bottom-left
        build_quadtree(pixels, quadtree + 1 + 3 * new_size * new_size, x + new_size, y + new_size, new_size);  // Bottom-right
    }
}

int main() {
    int N;
    char pixels[MAX_SIZE][MAX_SIZE];

    // Ler tamanho da imagem
    scanf("#define quadtree_width %d\n", &N);
    scanf("#define quadtree_height %d\n", &N);

    // Pular a linha de definição dos bits
    scanf("static char quadtree_bits[] = {\n");

    // Ler os pixels em formato hexadecimal
    int index = 0;
    char hexValue;
    while (scanf("0x%c%c,", &hexValue, &hexValue) == 2) {
        int byte = hexValue >= 'a' ? hexValue - 'a' + 10 : hexValue - '0';
        for (int i = 7; i >= 0; i--) {
            pixels[index / N][index % N] = (byte >> i) & 1 ? 'W' : 'B';
            index++;
        }
    }

    // Pular o caractere de fechamento do array
    getchar();

    // Construir o quadtree
    char quadtree[MAX_SIZE * MAX_SIZE / 3];  // Estimativa de tamanho máximo
    build_quadtree(pixels, quadtree, 0, 0, N);

    // Imprimir o resultado
    printf("%d\n", N);
    printf("%s\n", quadtree);

    return 0;
}
