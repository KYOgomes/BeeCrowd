/*
Recentemente foi descoberto um planeta intitulado como Gliese 581g. Ele tem apenas três vezes a massa da Terra, e está à 20 anos-luz de distancia, orbitando uma estrela da constelação de Libra conhecida como Gliese 581, uma anã vermelha. Astrônomos da Universidade da Califórnia e da Carnegie Institution de Washington afirmam que o planeta é o primeiro a apresentar potencial real para conter vida. Eles disseram que essa descoberta só foi possível através da análise de antigas escrituras egípcias, remanescentes da biblioteca de Alexandria. Foram encontradas anotações com uma sequencia estranha, que supostamente indicaria as posições dos planetas com vida no universo. Cada elemento é traduzido em coordenadas tridimensionais utilizando um algoritmo extremamente complexo descrito nas anotações, no entanto o algoritmo para cálculo da sequencia se perdeu por causa das páginas queimadas no incêndio da biblioteca.

O livro contém apenas os oito primeiros valores dessa sequência, detectada nas páginas legíveis das escrituras, e para conseguir encontrar as outras coordenadas a Universidade da Califórnia lançou um desafio mundial para estudantes de matemática, engenharia e computação. Dados os primeiros elementos da sequência, deve-se escrever um algoritmo capaz de calcular qualquer elemento da série. Os elementos conhecidos são {B, BA, CB, BAA, BCB, CBA, DAB, BAAA}.

Acredita-se que seja possível encontrar qualquer elemento da série, cujos elementos parecem estar escritos em um base numérica alienígena.

Entrada
Cada linha de entrada contém um inteiro N (1 ≤ N ≤ 100000), que descreve a posição na sequência alienígena do elemento a ser calculado. A entrada é finalizada quando N = 0.

Saída
Para cada valor lido, deve ser impresso na tela o elemento na n-ésima posição da sequência alienígena, sempre com uma quebra de linha.

Exemplo de Entrada	
1
2
3
4
5
6
7
8
0

Exemplo de Saída
B
BA
CB
BAA
BCB
CBA
DAB
BAAA
*/

#include <stdio.h>
#include <string.h>

void print_alien_sequence(int n) {
    char result[100];
    int index = 0;
    
    while (n > 0) {
        int remainder = (n - 1) % 4; // remainder in base 4 (0, 1, 2, 3)
        switch (remainder) {
            case 0: result[index++] = 'B'; break;
            case 1: result[index++] = 'A'; break;
            case 2: result[index++] = 'C'; break;
            case 3: result[index++] = 'D'; break;
        }
        n = (n - 1) / 4; // update n to next place value
    }
    
    // Print result in correct order (reverse)
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        print_alien_sequence(n);
    }
    
    return 0;
}
