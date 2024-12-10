/*
Nicolau já está bastante cansado e sua memória não é mais a mesma. Você, como navegador, deverá auxiliar o Papai Noel a gritar a frase "Feliz Natal" no idioma correto de cada país de que trenó está sobrevoando.

Como você é um elfo muito esperto, você já criou um pequeno app no seu celular (sim, elfos tem celular) que irá lhe informar a frase no idioma correto dado o nome do país. Como o trenó é moderno (foi atualizado no ano 2000) ele exibe no painel de navegação o nome do país atual

Os dados inseridos no seu app foram:

brasil              Feliz Natal!
alemanha            Frohliche Weihnachten!
austria             Frohe Weihnacht!
coreia              Chuk Sung Tan!
espanha             Feliz Navidad!
grecia              Kala Christougena!
estados-unidos      Merry Christmas!
inglaterra          Merry Christmas!
australia           Merry Christmas!
portugal            Feliz Natal!
suecia              God Jul!
turquia             Mutlu Noeller
argentina           Feliz Navidad!
chile               Feliz Navidad!
mexico              Feliz Navidad!
antardida           Merry Christmas!
canada              Merry Christmas!
irlanda             Nollaig Shona Dhuit!
belgica             Zalig Kerstfeest!
italia              Buon Natale!
libia               Buon Natale!
siria               Milad Mubarak!
marrocos            Milad Mubarak!
japao               Merii Kurisumasu!
Para não correr o risco de infomar o nome errado você decidiu testar o aplicativo mais algumas vezes.

Entrada
Você irá testar o seu aplicativo com diversos nomes de paises, simulando os dados informados pelo painel de navegação do trenó.

Saída
O seu aplicativo deverá mostrar na tela a frase no idioma correto. Caso ela não esteja cadastrada, você deverá exibir a mensagem "--- NOT FOUND ---" para que depois dos testes você possa completar o banco de dados.

Exemplo de Entrada	
uri-online-judge
alemanha
brasil
austria

Exemplo de Saída
--- NOT FOUND ---
Frohliche Weihnachten!
Feliz Natal!
Frohe Weihnacht!
*/

#include <stdio.h>
#include <string.h>

// Definição da estrutura para os cumprimentos de Natal
typedef struct {
    const char *pais;
    const char *mensagem;
} CumprimentoNatal;

// Array de cumprimentos de Natal
CumprimentoNatal natal[] = {
    {"alemanha", "Frohliche Weihnachten!"},
    {"antardida", "Merry Christmas!"},
    {"argentina", "Feliz Navidad!"},
    {"australia", "Merry Christmas!"},
    {"austria", "Frohe Weihnacht!"},
    {"belgica", "Zalig Kerstfeest!"},
    {"brasil", "Feliz Natal!"},
    {"canada", "Merry Christmas!"},
    {"chile", "Feliz Navidad!"},
    {"coreia", "Chuk Sung Tan!"},
    {"espanha", "Feliz Navidad!"},
    {"estados-unidos", "Merry Christmas!"},
    {"grecia", "Kala Christougena!"},
    {"inglaterra", "Merry Christmas!"},
    {"irlanda", "Nollaig Shona Dhuit!"},
    {"italia", "Buon Natale!"},
    {"japao", "Merii Kurisumasu!"},
    {"libia", "Buon Natale!"},
    {"marrocos", "Milad Mubarak!"},
    {"mexico", "Feliz Navidad!"},
    {"portugal", "Feliz Natal!"},
    {"siria", "Milad Mubarak!"},
    {"suecia", "God Jul!"},
    {"turquia", "Mutlu Noeller"}
};

int main() {
    char pais[50];
    int encontrado;

    while (scanf("%s", pais) != EOF) {
        encontrado = 0;

        for (int i = 0; i < sizeof(natal) / sizeof(natal[0]); i++) {
            if (strcmp(natal[i].pais, pais) == 0) {
                printf("%s\n", natal[i].mensagem);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("--- NOT FOUND ---\n");
        }
    }

    return 0;
}
