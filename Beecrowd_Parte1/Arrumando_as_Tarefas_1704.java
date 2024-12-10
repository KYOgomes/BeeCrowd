/*
 Você trabalha para uma empresa muito grande e que tem uma cultura move-fast. Hoje, um dos seus colegas ficou doente e você precisa repor o trabalho dele.

Seu chefe disse que você tem apenas um computador para realizar algumas tarefas. Cada uma delas dá v de lucro e deve ser terminada até t horas a partir de agora. Após esse tempo, não pode ser mais realizada e não possui nenhum valor. O computador realiza exatamente uma tarefa por hora.

Você deseja impressionar o seu chefe e assim ganhar uma promoção. Para isso, você pretende usar suas habilidades de programador e selecionar quais tarefas executar de tal forma a minimizar a quantidade de dinheiro perdida.

Entrada
A entrada é composta por diversos casos teste e termina com o final do arquivo. Cada um descreve uma lista de tarefas e começa com dois inteiros N (1 ≤ N) e H (H ≤ 1000), o número de tarefas e a quantidade de horas disponível do computador, respectivamente. As próximas N linhas contém cada uma v (1 ≤v ≤ 1000) e t (1 ≤ t ≤ H) como descrito acima.

Saída
Para cada teste imprima uma única linha representando a menor quantidade de dinheiro perdida.

Exemplo de Entrada	
3 3
5 1
10 2
20 3
4 2
1 2
2 1
4 1
2 2

Exemplo de Saída
0
3
 */

 import java.util.*;

 public class Arrumando_as_Tarefas_1704_ERRO {
     public static void main(String[] args) {
         Scanner scanner = new Scanner(System.in);
         
         while (scanner.hasNext()) {
             int N = scanner.nextInt();
             int H = scanner.nextInt();
             
             if (N == 0 && H == 0) break;
             
             int[] profits = new int[N];
             int[] times = new int[N];
             
             for (int i = 0; i < N; i++) {
                 profits[i] = scanner.nextInt();
                 times[i] = scanner.nextInt();
             }
             
             // Using DP to find the maximum profit we can get with H hours
             int[] dp = new int[H + 1];
             
             for (int i = 0; i < N; i++) {
                 int v = profits[i];
                 int t = times[i];
                 
                 // Update dp[j] from back to front to prevent using the same task multiple times
                 for (int j = H; j >= t; j--) {
                     dp[j] = Math.max(dp[j], dp[j - t] + v);
                 }
             }
             
             System.out.println(dp[H]);
         }
         
         scanner.close();
     }
 }
 