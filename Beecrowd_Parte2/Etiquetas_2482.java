/*Como de costume, neste ano Noel recebeu muitos pedidos de presentes. Só que em função de alguns imprevistos, não terá 
como entregar todos os presentes pessoalmente neste ano. Daí então decidiu utilizar o velho e bom correio tradicional, 
para alguns pedidos que podem ser entregues por carta.

Para esta tarefa, pediu ajuda ao elfo Evergreen Xadada, para que ele imprimisse etiquetas a todos os envelopes que serão
 destinados a algumas destas crianças, cujo pedido pode ser entregue por carta. Cada uma destas etiquetas deverá conter 
 apenas o nome da criança e a saudação "Feliz Natal" no respectivo idioma desta criança. Para auxiliar nesta tarefa, 
 Noel disponibilizou uma tabela com vários idiomas e o nome e o país de cada uma das crianças selecionadas, de acordo 
 com o exemplo abaixo. Você deve ajudar Evergreen fazendo um programa que imprima estas etiquetas.

Entrada
A entrada é composta por um único caso de teste. A primeira linha de entrada contém um inteiro N (1 < N < 100) que indica
a quantidade de traduções da palavra "Feliz Natal" existentes na entrada. As próximas N * 2 linhas contém 
respectivamente o nome de uma língua seguido da tradução de "Feliz Natal" para esta língua. 
Segue um inteiro M (1 < M < 100) que indica a quantidade de crianças que receberão as cartas. 
As próximas M * 2 linhas conterão, respectivamente, o nome da criança e a língua nativa desta criança.
Obs.: É garantido que nenhuma tradução apareça repetida ou duplicada e os países de todas as crianças estejam presentes 
na relação dos países.

Saída
Seu programa deverá imprimir todas as etiquetas de acordo com a entrada, conforme o exemplo abaixo, sempre com uma 
linha em branco após a impressão de cada uma das etiquetas, inclusive após a última etiqueta.*/

//Daniel Salgado Magalhães - 821429

public class Etiquetas{
    public static void main(String[] args){
        int qntEntrada = 0;
        qntEntrada = MyIO.readInt();

        String[] mensagem = new String[qntEntrada];
        String[] idioma = new String[qntEntrada];

        //for que receba o idioma e suas respectivas mensagens
        for(int i=0; i < qntEntrada; i++){
            idioma[i] = MyIO.readLine();
            mensagem[i] = MyIO.readLine();
        }

        //variável que receba as crianças que receberão a mensagem
        int qntCrianca = 0;
        qntCrianca = MyIO.readInt();

        String[] nomeCrianca = new String[qntCrianca];
        String[] nacionalidade = new String[qntCrianca];

        for(int j = 0; j < qntCrianca; j++){
            nomeCrianca[j] = MyIO.readLine();
            nacionalidade[j] = MyIO.readLine();
        }

        for(int aux = 0; aux < qntCrianca; aux++){
            MyIO.println(nomeCrianca[aux]);
            //percorre as mensagens e nacionalidades pra ver se tem alguma igual
            for(int percorre = 0; percorre < qntEntrada; percorre++){
                if(nacionalidade[aux].equals(idioma[percorre])){
                    MyIO.println(mensagem[percorre]);
                    MyIO.print("\n");
                }
            }
        }
    }
}