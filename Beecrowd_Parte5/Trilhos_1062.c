/*
Há uma famosa estação de trem na cidade PopPush. Esta cidade fica em um país incrivelmente acidentado e a estação foi criada no último século. 
Infelizmente os fundos eram extremamente limitados naquela época. Foi possível construir somente uma pista. Além disso, devido a problemas de espaço, 
foi feita uma pista apenas até a estação (veja figura abaixo).

A tradição local é que todos os comboios que chegam vindo da direção A continuam na direção B com os vagões  reorganizados, de alguma forma. Suponha que o trem que está chegando da direção A tem N <= 1000 vagões numerados sempre em ordem crescente 1,2, ..., N. O primeiro que chega é o 1 e o último que chega é o N. Existe um chefe de reorganizações de trens que quer saber se é possível reorganizar os vagões para que os mesmos saiam na direção B na ordem a1, a2, an..

O  chefe pode utilizar qualquer estratégia para obter a saída desejada. No caso do desenho ilustrado acima, por exemplo, basta o chefe deixar todos os vagões entrarem na estação (do 1 ao 5) e depois retirar um a um: retira o 5, retira o 4, retira o 3, retira o 2 e por último retira o 1.  Desta forma, se o chefe quer saber se a saída 5,4,3,2,1 é possível em B, a resposta seria Yes. Vagão que entra na estação só pode sair para a direção B e é possível incluir quantos forem necessários para retirar o primeiro vagão desejado.

Entrada
O arquivo de entrada consiste de um bloco de linhas, cada bloco, com exceção do último, descreve um trem e possivelmente mais do que uma requisição de reorganização. Na primeira linha de cada bloco há um inteiro N que é a quantidade de vagões. Em cada uma das próximas linhas de entrada haverá uma permutação dos valores 1,2, …, N. A última linha de cada bloco contém apenas 0. Um bloco iniciando com zero (0) indica o final da entrada.

Saída
O arquivo de saída contém a quantidade de linhas correspondente às linhas com permutações no arquivo de entrada. Cada linha de saída deve ser Yes se for possível organizar os vagões da forma solicitada e No, caso contrário. Há também uma linha em branco após cada bloco de entrada. No exemplo abaixo,  O primeiro caso de teste tem 3 permutações para 5 vagões. O ultimo zero dos testes de entrada não devem ser processados.

Exemplo de Entrada	
5
5 4 3 2 1
1 2 3 4 5
5 4 1 2 3
0
6
1 3 2 5 4 6
0
0

Exemplo de Saída
Yes
Yes
No

Yes
*/

#include <stdlib.h>
#include <stdio.h>

struct pilhaNo{
    int valor;
    struct pilhaNo* abaixo;
};

struct pilha{
    int tamanho;
    struct pilhaNo* topo;
};

void push(struct pilha* p, int valor){
    p->tamanho += 1;
    struct pilhaNo* novoTopo = (struct pilhaNo*) malloc(sizeof(struct pilhaNo));

    novoTopo->valor = valor;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void pop(struct pilha* p){
    if(p->tamanho > 0){
        p->tamanho -= 1;
        struct pilhaNo* velhoTopo = p->topo;
        p->topo = p->topo->abaixo;
        free(velhoTopo);
    }
}

int top(struct pilha* p){
    return p->topo->valor;
}

int size(struct pilha* p){
    return p->tamanho;
}

int empty(struct pilha* p){
    return p->tamanho == 0;
}

void inicializa(struct pilha* p){
    p->tamanho = 0;
    p->topo = NULL;
}

void destroi(struct pilha* p){
    while(!empty(p)){
        pop(p);
    }
}

int main(){
    int N, x;
    struct pilha A, estacao, B;

    while(scanf("%d", &N) != EOF){
        if(!N)  break;

        while(scanf("%d", &x)){
            if(!x){
                printf("\n");
                break;
            }

            inicializa(&A);
            inicializa(&estacao);
            inicializa(&B);

            push(&A, x);
            push(&B, 1);
            for(int i = 2; i <= N; ++i){
                scanf("%d", &x);
                push(&A, x);
                push(&B, i);
            }

            while(!empty(&A) || !empty(&estacao) || !empty(&B)){
                if(!empty(&A) && !empty(&B) && top(&A) == top(&B)){
                    pop(&A);
                    pop(&B);
                }else if(!empty(&estacao) && !empty(&B) && top(&estacao) == top(&B)){
                    pop(&estacao);
                    pop(&B);
                }else if(!empty(&A)){
                    push(&estacao, top(&A));
                    pop(&A);
                }else{
                    break;
                }
            }

            if(empty(&A) && empty(&estacao) && empty(&B)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }

            destroi(&A);
            destroi(&estacao);
            destroi(&B);
        }
    }

    return 0;
}