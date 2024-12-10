/*
Conan é um importante membro do Clube Atlético de Desrugenstein, que possui um time de futebol de campo profissional: ele é o responsável pelo gramado do campo onde ocorrem os jogos em casa. Em 2048 anos de história, o campo do CAD sempre esteve em perfeitas condições para os jogos, graças a Conan. Ele já ganhou vários prêmios por isso, sendo o mais importante deles o "Grama de Ouro", prêmio que ganhou 1024 vezes.

Amanhã acontecerá a final do campeonato Universal de futebol, e o CAD é um dos finalistas. Como o jogo será em casa, Conan foi ver o estado do gramado e reparar se necessário. Chegando lá, entrou em desespero ao ver várias schweisen no campo, estragando todo o gramado!!

Sendo assim, Conan precisa de sua ajuda para determinar quanto irá gastar com deswevileutssen para matar todas as schweisen. Cada deswevileutssen mata uma schwisen. Conan pode lhe mandar mensagens de dois tipos: dizendo que encontrou algumas schweisen, ou perguntando quanto ele vai gastar para matar certas schweisen.

Entrada
A entrada possui vários casos de teste. A primeira linha de um caso de teste contém 3 inteiros X (≤ 1000), Y (≤ 1000) e P (≤ 10), que representam, respectivamente, o tamanho (X e Y) do campo e o preço de cada deswevileutssen. A próxima linha contém um inteiro Q (≤ 10000). As próximas Q linhas representam mensagens de Conan para você, e estão em uma das duas seguintes formas:

- A N X Y - “Achei N (≤ 10) schweisen em (X,Y) - (0 ≤ X < Largura), (0 ≤ Y < Altura)”

- P X Y Z W - “Quanto vou gastar para matar todas as schweisen na área retangular de (X,Y) até (Z,W)?”

Considere que no início nenhuma schweisen foi vista.

A entrada termina quando X, Y e P são iguais a 0.

Saída
Para cada mensagem do tipo "P", imprima o valor que responde a pergunta feita. Deixe uma linha em branco após cada caso de teste, inclusive após o último.

Exemplo de Entrada	
2 2 10
7
A 5 1 1
A 9 1 0
A 2 0 0
P 1 0 1 1
A 4 0 1
A 7 1 0
P 0 1 1 0
0 0 0

Exemplo de Saída
140
270
*/
#include <stdio.h>

int main() {
    int X, Y, P, Q;
    while (1) {
        scanf("%d %d %d", &X, &Y, &P);
        if (X == 0 && Y == 0 && P == 0)
            break;

        int field[X][Y];
        for (int i = 0; i < X; i++)
            for (int j = 0; j < Y; j++)
                field[i][j] = 0;

        scanf("%d", &Q);
        while (Q--) {
            char type;
            int N, x, y, z, w;
            scanf(" %c", &type);

            if (type == 'A') {
                scanf("%d %d %d", &N, &x, &y);
                field[x][y] += N;
            } else if (type == 'P') {
                scanf("%d %d %d %d", &x, &y, &z, &w);
                // Garantir que x <= z e y <= w
                int x_start = x < z ? x : z;
                int x_end = x < z ? z : x;
                int y_start = y < w ? y : w;
                int y_end = y < w ? w : y;
                
                int cost = 0;
                for (int i = x_start; i <= x_end; i++)
                    for (int j = y_start; j <= y_end; j++)
                        cost += field[i][j] * P;
                printf("%d\n", cost);
            }
        }
        printf("\n");
    }
    return 0;
}
