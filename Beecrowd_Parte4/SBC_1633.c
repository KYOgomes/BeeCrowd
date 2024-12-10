/*A Federação dos Apagadores e Celulares Esquisitos (FACE) assinou recentemente um contrato com o Governo Federal para desenvolver um telefone celular de baixo custo que será distribuído gratuitamente a populações de baixa renda. Apesar de simples, o aparelho contará com uma série de aplicativos, a fim de que as pessoas possam desfrutar de todas as facilidades que as plataformas móveis proporcionam. Um desafio, contudo, está intrigando os programadores da FACE: o aparelho não dispõe de muitos recursos de hardware, e os programadores estão tendo dificuldades em escrever o módulo que gerenciará os processos do sistema operacional SBC (Sistema Bonito para Celulares), desenvolvido especialmente para a arquitetura. Os programadores receberam dos analistas as seguintes diretivas, as quais precisam ser rigorosamente seguidas:

O sistema executa apenas um processo por vez, e cada processo até o fim.
O sistema jamais pode ficar ocioso se há processos esperando para serem atendidos.
Para que um processo não trave o sistema, cada processo, quando requisita sua execução, deve informar ao sistema o tempo exato, em ciclos de processamento, que sua execução durará. O sistema jamais permite que a execução de um processo dure mais que o tempo previsto, abortando-a se necessário. Ainda, se um processo se encerra antes do informado, o sistema aproveita os ciclos restantes para rotinas de coleta de dados e comunicação com o Governo. Dessarte, para todos os efeitos, a execução de um processo que informou precisar de c ciclos dura sempre exatos c ciclos.
O sistema garante que é mínima a soma, para todos os processos, do tempo que cada processo espera até entrar em execução.
Ajude a FACE a completar o SBC escrevendo o módulo que falta!

Entrada
A entrada é composta por vários casos de teste. A primeira linha de cada caso de teste consiste de um único inteiro N (1 ≤ N ≤ 105), o qual representa o número de processos que requisitaram sua execução ao SBC. Cada uma das N linhas seguintes corresponde, então, a um processo e é formada por dois inteiros t e c (1 ≤ t, c ≤ 103), os quais representavam respectivamente o tempo do sistema em que o processo fez sua requisição e o número de ciclos de processamento que durará a execução do processo. Considere que o tempo do sistema é contado em ciclos de processamento e que o contador começa em 1 em cada caso de teste. Considere ainda que a entrada é finalizada em fim de arquivo.

Saída
Para cada caso de teste, imprima o valor inteiro que representa a soma, para todos os processos, do tempo, em ciclos de processamento, que cada processo espera até entrar em execução. Por favor, note que este valor pode não caber em 32 bits.

Exemplo de Entrada
4
1 10
5 15
6 10
7 5
1
1 10

Exemplo de Saída
35
0
*/
#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um processo
typedef struct {
    int t;  // Tempo de requisição
    int c;  // Ciclos de processamento
} Processo;

// Função de comparação para o qsort (ordenar por tempo de requisição)
int compara_processos(const void *a, const void *b) {
    Processo *p1 = (Processo *)a;
    Processo *p2 = (Processo *)b;
    return p1->t - p2->t;
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;

        // Vetor de processos
        Processo processos[N];

        // Leitura dos processos
        for (int i = 0; i < N; ++i) {
            scanf("%d %d", &processos[i].t, &processos[i].c);
        }

        // Ordena os processos pelo tempo de requisição
        qsort(processos, N, sizeof(Processo), compara_processos);

        // Simulação do sistema
        long long total_waiting_time = 0;
        int current_time = 1;  // Começa no ciclo 1

        for (int i = 0; i < N; ++i) {
            int espera = current_time - processos[i].t;
            if (espera < 0) espera = 0;  // Se por algum motivo a espera for negativa, consideramos zero
            total_waiting_time += espera;
            current_time += processos[i].c;  // Avança o tempo atual
        }

        // Imprime a soma das esperas dos processos para este caso de teste
        printf("%lld\n", total_waiting_time);
    }

    return 0;
}
