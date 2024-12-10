/*
O professor Rolien organizou junto às suas turmas de Ciência da Computação a confecção de uma camiseta polo que fosse ao mesmo tempo bonita e barata. Após algumas conversas, ficou decidido com os alunos que seriam feitas somente camisetas da cor preta, o que facilitaria a confecção. Os alunos poderiam escolher entre o logo do curso e os detalhes em branco ou vermelho. Assim sendo, Rolien precisa de sua ajuda para organizar as listas de quem quer a camiseta em cada uma das turmas, relacionando estas camisetas pela cor do logo do curso, tamanho (P, M ou G) e por último pelo nome.

Entrada
A entrada contém vários casos de teste. Cada caso de teste inicia com um valor N, (1 ≤ N ≤ 60) inteiro e positivo, que indica a quantidade de camisetas a serem feitas para aquela turma. As próximas N*2 linhas contém informações de cada uma das camisetas (serão duas linhas de informação para cada camiseta). A primeira linha irá conter o nome do estudante e a segunda linha irá conter a cor do logo da camiseta ("branco" ou "vermelho") seguido por um espaço e pelo tamanho da camiseta "P" "M" ou "G". A entrada termina quando o valor de N for igual a zero (0) e esta valor não deverá ser processado.

Saída
Para cada caso de entrada deverão ser impressas as informações ordenadas pela cor dos detalhes em ordem ascendente, seguido pelos tamanhos em ordem descendente e por último por ordem ascendente de nome, conforme o exemplo abaixo.

Obs.: Deverá ser impressa uma linha em branco entre dois casos de teste.

Exemplo de Entrada	
9
Maria Jose
branco P
Mangojata Mancuda
vermelho P
Cezar Torres Mo
branco P
Baka Lhau
vermelho P
JuJu Mentina
branco M
Amaro Dinha
vermelho P
Adabi Finho
branco G
Severina Rigudinha
branco G
Carlos Chade Losna
vermelho P
3
Maria Joao
branco P
Marcio Guess
vermelho P
Maria Jose
branco P
0

Exemplo de Saída
branco P Cezar Torres Mo
branco P Maria Jose
branco M JuJu Mentina
branco G Adabi Finho
branco G Severina Rigudinha
vermelho P Amaro Dinha
vermelho P Baka Lhau
vermelho P Carlos Chade Losna
vermelho P Mangojata Mancuda

branco P Maria Joao
branco P Maria Jose
vermelho P Marcio Guess
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações de cada camiseta
typedef struct {
    char nome[100];
    char cor[20];
    char tamanho;
} Camiseta;

// Função de comparação para qsort (ordenação)
int comparar(const void *a, const void *b) {
    Camiseta *camisetaA = (Camiseta *)a;
    Camiseta *camisetaB = (Camiseta *)b;

    // Primeiro critério: cor do logo
    int cmpCor = strcmp(camisetaA->cor, camisetaB->cor);
    if (cmpCor != 0) {
        return cmpCor;
    }

    // Segundo critério: tamanho (ordem descendente)
    if (camisetaA->tamanho > camisetaB->tamanho) {
        return -1;
    } else if (camisetaA->tamanho < camisetaB->tamanho) {
        return 1;
    }

    // Terceiro critério: nome (ordem ascendente)
    return strcmp(camisetaA->nome, camisetaB->nome);
}

int main() {
    int N;
    int primeiro = 1; // variável para controlar a impressão de linha em branco entre casos de teste

    while (scanf("%d", &N) == 1 && N != 0) {
        if (!primeiro) {
            printf("\n"); // imprimir linha em branco entre casos de teste
        }
        primeiro = 0;

        Camiseta camisetas[N];
        getchar(); // capturar o '\n' após o número N

        // Leitura das camisetas
        for (int i = 0; i < N; i++) {
            fgets(camisetas[i].nome, sizeof(camisetas[i].nome), stdin);
            camisetas[i].nome[strcspn(camisetas[i].nome, "\n")] = '\0'; // remover o '\n' do final
            scanf("%s %c\n", camisetas[i].cor, &camisetas[i].tamanho);
        }

        // Ordenação das camisetas
        qsort(camisetas, N, sizeof(Camiseta), comparar);

        // Impressão das camisetas ordenadas
        for (int i = 0; i < N; i++) {
            printf("%s %c %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }
    }

    return 0;
}
