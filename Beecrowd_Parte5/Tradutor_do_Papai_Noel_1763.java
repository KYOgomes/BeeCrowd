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
import java.util.Scanner;

// Classe para representar o par país e mensagem de Natal
class CumprimentoNatal {
    String pais;
    String mensagem;

    CumprimentoNatal(String pais, String mensagem) {
        this.pais = pais;
        this.mensagem = mensagem;
    }
}

public class Tradutor_do_Papai_Noel_1763 {
    public static void main(String[] args) {
        // Array de cumprimentos de Natal
        CumprimentoNatal[] natal = {
            new CumprimentoNatal("alemanha", "Frohliche Weihnachten!"),
            new CumprimentoNatal("antardida", "Merry Christmas!"),
            new CumprimentoNatal("argentina", "Feliz Navidad!"),
            new CumprimentoNatal("australia", "Merry Christmas!"),
            new CumprimentoNatal("austria", "Frohe Weihnacht!"),
            new CumprimentoNatal("belgica", "Zalig Kerstfeest!"),
            new CumprimentoNatal("brasil", "Feliz Natal!"),
            new CumprimentoNatal("canada", "Merry Christmas!"),
            new CumprimentoNatal("chile", "Feliz Navidad!"),
            new CumprimentoNatal("coreia", "Chuk Sung Tan!"),
            new CumprimentoNatal("espanha", "Feliz Navidad!"),
            new CumprimentoNatal("estados-unidos", "Merry Christmas!"),
            new CumprimentoNatal("grecia", "Kala Christougena!"),
            new CumprimentoNatal("inglaterra", "Merry Christmas!"),
            new CumprimentoNatal("irlanda", "Nollaig Shona Dhuit!"),
            new CumprimentoNatal("italia", "Buon Natale!"),
            new CumprimentoNatal("japao", "Merii Kurisumasu!"),
            new CumprimentoNatal("libia", "Buon Natale!"),
            new CumprimentoNatal("marrocos", "Milad Mubarak!"),
            new CumprimentoNatal("mexico", "Feliz Navidad!"),
            new CumprimentoNatal("portugal", "Feliz Natal!"),
            new CumprimentoNatal("siria", "Milad Mubarak!"),
            new CumprimentoNatal("suecia", "God Jul!"),
            new CumprimentoNatal("turquia", "Mutlu Noeller")
        };

        // Scanner para entrada de dados
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            String pais = scanner.next();
            boolean encontrado = false;

            // Busca o cumprimento de Natal para o país fornecido
            for (CumprimentoNatal cn : natal) {
                if (cn.pais.equals(pais)) {
                    System.out.println(cn.mensagem);
                    encontrado = true;
                    break;
                }
            }

            // Se não encontrou, imprime "--- NOT FOUND ---"
            if (!encontrado) {
                System.out.println("--- NOT FOUND ---");
            }
        }

        // Fechar o scanner
        scanner.close();
    }
}
