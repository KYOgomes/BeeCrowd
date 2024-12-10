/*
João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados. O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando .<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.

Entrada
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."

Saída
Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.

Exemplo de Entrada	
2
<..><.<..>>
<<<..<......<<<<....>

Exemplo de Saída
3
1

*/

#include <string.h>
#include <stdio.h>

int main(){
    char expressao[1001];
    int N, tam, resposta, parenteses;

    scanf("%d\n", &N);
    
    for(int k = 0; k < N; ++k){
        scanf("%s\n", &expressao);

        resposta = 0;
        parenteses = 0;
        tam = strlen(expressao);
        for(int i = 0; i < tam; ++i){
            if(expressao[i] == '<'){
                ++parenteses;
            }else if(expressao[i] == '>' && parenteses > 0){
                --parenteses;
                ++resposta;
            }
        }

        printf("%d\n", resposta);
    }

    return 0;
}