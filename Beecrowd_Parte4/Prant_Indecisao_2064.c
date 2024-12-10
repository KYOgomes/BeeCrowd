#include <stdio.h>
#include <string.h>

#define MAX_LEN 100001

int main() {
    int k, m, n;
    char favoritas[MAX_LEN];
    char nome_inicial[MAX_LEN];
    char operacoes[MAX_LEN][3];

    while (scanf("%d %d %d\n", &k, &m, &n) != EOF) {
        // Leitura das letras favoritas
        fgets(favoritas, sizeof(favoritas), stdin);
        favoritas[strlen(favoritas) - 1] = '\0'; // remover o '\n' final

        // Leitura do nome inicial do cachorro
        fgets(nome_inicial, sizeof(nome_inicial), stdin);
        nome_inicial[strlen(nome_inicial) - 1] = '\0'; // remover o '\n' final

        // Encontrar o nome com maior número de letras favoritas
        int max_favoritas = 0;
        char melhor_nome[MAX_LEN];
        strcpy(melhor_nome, nome_inicial);

        // Processamento das operações de troca
        for (int i = 0; i < n; i++) {
            fgets(operacoes[i], sizeof(operacoes[i]), stdin);
            operacoes[i][2] = '\0'; // garantir que termina com '\0'

            char a = operacoes[i][0];
            char b = operacoes[i][2];

            for (int j = 0; j < m; j++) {
                if (nome_inicial[j] == a) {
                    nome_inicial[j] = b;
                } else if (nome_inicial[j] == b) {
                    nome_inicial[j] = a;
                }
            }

            // Verificação do número de letras favoritas no novo nome
            int favoritas_count = 0;
            for (int j = 0; j < m; j++) {
                if (favoritas[nome_inicial[j] - 'a'] == '1') {
                    favoritas_count++;
                }
            }

            // Atualizar o melhor nome, se necessário
            if (favoritas_count > max_favoritas) {
                max_favoritas = favoritas_count;
                strcpy(melhor_nome, nome_inicial);
            }
        }

        // Imprimir resultado
        printf("%d\n", max_favoritas);
        printf("%s\n", melhor_nome);
    }

    return 0;
}