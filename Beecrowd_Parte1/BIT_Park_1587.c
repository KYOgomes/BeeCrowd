/*

 A Final Nacional da Maratona de Programação da Sociedade Brasileira de Computação (SBC) de 2014 será em Fortaleza, e os desbravadores maratonistas chapecoenses, ansiosos, já começam a fazer as malas, esperançosos da classificação na Etapa Regional. A capital do Ceará, com uma população de 2.551.805 habitantes (segundo o Censo Populacional de 2013 do IBGE), é mundialmente conhecida por suas belas praias, seus luxuosos hotéis, pousadas e restaurantes, suas magníficas obras de Arquitetura, seu povo alegre e hospitaleiro, e também pelos seus extraordinários parques aquáticos. Visando derrubar a hegemonia do maior parque aquático da cidade, uma empresa local de TI, denominada NCC (Núcleo de Computação Cearense), construiu um parque aquático maior ainda, denominado BIT Park, o qual será inaugurado ainda neste ano. Para a inauguração toda a população da cidade foi convidada, e o NCC promete várias atividades para entreter o povo a tarde toda.

Uma das atividades previstas para a inauguração ocorrerá na maior piscina do BIT Park: um colossal jogo de futebol aquático, do qual poderão participar todos os habitantes de Fortaleza, já que a piscina em questão possui nada mais nada menos que 1 km de largura por 2 km de comprimento. O futebol aquático funciona basicamente como o futebol convencional, mas com algumas diferenças:

o jogo ocorre dentro d'água, então, a bola é passada com as mãos, não com os pés;
o jogo pode ser jogado por qualquer número par de jogadores, desde que haja o mesmo número de jogadores nos dois times --- e desde que todos os jogadores caibam na piscina;
não há goleiros, já que todos os jogadores podem defender a bola com as mãos;
assim como no futebol convencional, a legalidade da posição de um jogador é avaliada de acordo com a linha paralela à linha do gol adversário em que se encontra, considerando-se também as linhas em que se encontram os jogadores adversários: a posição de um jogador J é considerada ilegal — e o jogador, consequentemente, considerado impedido — se menos de 2/11 dos jogadores adversários encontram-se em linhas mais próximas da linha do gol adversário que a linha em que se encontra J;
apenas pode pegar a bola um jogador que esteja numa posição legal, diferentemente do que ocorre no futebol convencional, em que o impedimento é avaliado no momento do passe, não no momento da recepção.
Na Figura, em que o time A joga contra o time B, estão impedidos os jogadores A4 e A5.



O NCC percebeu que avaliar as legalidades das posições dos jogadores durante o jogo seria impraticável; afinal, toda a população de Fortaleza poderia estar na piscina. A decisão, então, foi deixar o jogo rolar para depois reavaliar todos os eventos e recalcular o placar através de um programa. A partir do momento em que um jogador impedido recebe a bola, o próximo gol que ocorre na partida deve ser anulado, a menos que a bola saia da piscina. No início do jogo, e toda vez que a bola sai da piscina ou que ocorre algum gol, o árbitro sorteia um jogador qualquer — não necessariamente não impedido — e lhe concede a bola para dar continuidade à atividade.

Entrada
A entrada é composta por diversos casos de teste. A primeira linha de cada caso de teste é composta por dois inteiros N e E (1 < N < 2.551.805, 1 < E < 104), os quais encerram a entrada quando são ambos nulos. N é um número par que indica o número de fortalezenses que participaram do jogo. E é o número de eventos que aconteceram durante o jogo. Os times são chamados de A e de B, e os jogadores, de A1, A2, A3… e de B1, B2, B3… Todas as posições são determinadas pela distância em milímetros da linha do gol do time A, ou seja, o gol do time A está na posição 0 e o gol do time B está na posição 2.000.000. A segunda linha de um caso de teste contém N / 2 inteiros xiA (0 ≤ xiA ≤ 2.000.000, 1 ≤ i ≤ N / 2), indicando cada xiA a posição do jogador Ai no início da partida. De igual modo, a terceira linha contém N / 2 inteiros xiB (0 ≤ xiB ≤ 2.000.000, 1 ≤ i ≤ N / 2), indicando cada xiB a posição inicial do jogador Bi. Seguem, então, E linhas, cada uma descrevendo um evento do jogo. O quadro abaixo lista todos os eventos possíveis e como cada um deles é descrito na entrada.

I Xi	o árbitro concede a bola ao jogador Xi (X ∈ {A, B}, 1 ≤ i ≤ N / 2 ) para iniciar uma jogada

M Xi x	o jogador Xi (X ∈ {A, B}, 1 ≤ i ≤ N / 2) se movimenta para a posição X (0 ≤ X ≤ 2000000)

P Xi	a bola passa para as mãos do jogador Xi (X ∈ {A, B}, 1 ≤ i ≤ N / 2)

G X	a bola entra no gol do time X (X ∈ {A, B})

S	a bola sai da piscina

Assuma que um evento I ocorre se e somente se é o primeiro evento da partida ou o evento anterior é um evento G ou S.

Saída
Imprima uma linha revelando o placar final do jogo de acordo com os eventos fornecidos e com as regras descritas. Os exemplos esclarecem o formato em que o placar deve ser impresso.

Exemplo de Entrada	
6 4
0 700000 0
1500000 2000000 2000000
I B1
M A2 2000000
P A2
G B
6 4
0 700000 0
1500000 2000000 2000000
I B1
M A2 1999999
P A2
G B
6 5
0 700000 0
1500000 2000000 2000000
I B1
M A2 1999999
P A2
P B2
G B
6 5
0 700000 0
1500000 2000000 2000000
I B1
M A2 1999999
P A2
P B2
G A
0 0

Exemplo de Saída
0 X 0
1 X 0
1 X 0
0 X 1
 */

#include <stdio.h>
#include <stdlib.h> // Para utilizar a função atoi
#include <stdbool.h>

// Função para verificar se uma posição é legal
bool ehPosicaoLegal(int posicaoJogador, int posicoesAdversarios[], int numAdversarios) {
    int contLegalAdversarios = 0;
    // Percorre as posições dos adversários e conta quantos estão em posição legal
    for (int i = 0; i < numAdversarios; i++) {
        if (posicoesAdversarios[i] < posicaoJogador) { // Verifica se o adversário está mais próximo do gol do que o jogador atual
            contLegalAdversarios++;
        }
    }
    // Verifica se o número de adversários em posição legal atende ao critério mínimo (2/11)
    return contLegalAdversarios >= numAdversarios * 2 / 11;
}

int main() {
    int N, E; // Variáveis para o número de participantes e número de eventos
    
    while (true) {
        // Leitura do número de participantes e número de eventos
        scanf("%d %d", &N, &E);
        
        // Verifica se é o fim da entrada
        if (N == 0 && E == 0) {
            break;
        }
        
        int posicoesA[N / 2], posicoesB[N / 2]; // Arrays para armazenar as posições iniciais dos jogadores A e B
        
        // Leitura das posições iniciais dos jogadores A
        for (int i = 0; i < N / 2; i++) {
            scanf("%d", &posicoesA[i]);
        }
        
        // Leitura das posições iniciais dos jogadores B
        for (int i = 0; i < N / 2; i++) {
            scanf("%d", &posicoesB[i]);
        }
        
        int placarA = 0, placarB = 0; // Variáveis para armazenar o placar dos times A e B
        bool ultimoJogadorImpedido = false; // Flag para indicar se o último jogador estava impedido
        bool bolaNaPiscina = true; // Flag para indicar se a bola está na piscina
        bool proximoGolAnulado = false; // Flag para indicar se o próximo gol deve ser anulado
        
        // Processamento dos eventos do jogo
        for (int i = 0; i < E; i++) {
            char evento[3]; // String para armazenar o tipo de evento
            scanf("%s", evento); // Leitura do tipo de evento
            
            if (evento[0] == 'I') {
                // Início de uma jogada
                char jogador[3];
                scanf("%s", jogador);
                proximoGolAnulado = false; // Reinicia o próximo gol anulado
                bolaNaPiscina = false; // A bola não está mais na piscina
            } else if (evento[0] == 'M') {
                // Movimentação de um jogador
                char jogador[3];
                int novaPosicao;
                scanf("%s %d", jogador, &novaPosicao);
                // Aqui poderia haver um processamento da movimentação do jogador se necessário
            } else if (evento[0] == 'P') {
                // Passe para um jogador
                char jogador[3];
                scanf("%s", jogador);
                // Verificar se o jogador está em posição legal para receber o passe
                int posicaoJogador = atoi(&jogador[1]); // Converte a posição do jogador de string para inteiro
                int *posicoesAdversarios = (jogador[0] == 'A') ? posicoesB : posicoesA; // Determina as posições dos adversários
                int numAdversarios = N / 2; // Número de adversários
                if (!ehPosicaoLegal(posicaoJogador, posicoesAdversarios, numAdversarios)) {
                    proximoGolAnulado = true; // Marca o próximo gol como anulado se o passe for ilegal
                }
            } else if (evento[0] == 'G') {
                // Gol marcado
                char time[2];
                scanf("%s", time);
                if (bolaNaPiscina && proximoGolAnulado) {
                    // Anular o gol se a bola ainda está na piscina e o último passe foi anulado
                    proximoGolAnulado = false;
                } else {
                    if (time[0] == 'A') {
                        placarA++; // Incrementa o placar do time A
                    } else {
                        placarB++; // Incrementa o placar do time B
                    }
                    bolaNaPiscina = true; // A bola volta para a piscina após o gol
                }
            } else if (evento[0] == 'S') {
                // Bola sai da piscina
                bolaNaPiscina = false; // A bola não está mais na piscina
            }
        }
        
        // Impressão do placar final do jogo
        printf("%d X %d\n", placarA, placarB);
    }
    
    return 0;
}
