import java.util.Scanner;

class Pilha 
{
    private int topo;
    private int[] chegada;
    private int[] saida;

    public Pilha(int max) {
        this.topo = 0;
        this.chegada = new int[max];
        this.saida = new int[max];
    }

    public boolean estaVazia() {
        return this.topo == 0;
    }

    public boolean estaCheia(int vagas) {
        return this.topo == vagas;
    }

    public boolean push(int c, int s, int vagas) {
        if (!estaCheia(vagas)) {
            this.chegada[this.topo] = c;
            this.saida[this.topo] = s;
            this.topo++;
            return true;
        } else {
            return false;
        }
    }

    public boolean pop() {
        if (!estaVazia()) {
            this.topo--;
            return true;
        } else {
            return false;
        }
    }

    public int getTopo() {
        return this.topo;
    }

    public int getChegadaTopo() {
        return this.chegada[this.topo - 1];
    }

    public int getSaidaTopo() {
        return this.saida[this.topo - 1];
    }

    public int getChegada(int index) {
        return this.chegada[index];
    }

    public int getSaida(int index) {
        return this.saida[index];
    }
}

public class estacionamento_linear1523 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k, n, ci, si;

        while (true) {
            n = scanner.nextInt();
            k = scanner.nextInt();
            if (k == 0 && n == 0) break;

            Pilha p = new Pilha(10000);
            boolean possivel = true;

            for (int i = 0; i < n; i++) {
                ci = scanner.nextInt();
                si = scanner.nextInt();

                if (possivel) {
                    if (p.estaVazia()) {
                        p.push(ci, si, k);
                        possivel = true;
                    } else {
                        while (ci >= p.getSaidaTopo()) {
                            p.pop();
                            if (p.estaVazia()) break;
                        }
                        if (p.estaCheia(k)) {
                            possivel = false;
                        } else {
                            p.push(ci, si, k);
                            if (p.getTopo() > 1) {
                                if (p.getChegada(p.getTopo() - 1) > p.getChegada(p.getTopo() - 2) &&
                                    p.getSaida(p.getTopo() - 1) < p.getSaida(p.getTopo() - 2)) {
                                    possivel = true;
                                } else {
                                    possivel = false;
                                }
                            } else {
                                possivel = true;
                            }
                        }
                    }
                }
            }

            if (possivel) System.out.println("Sim");
            else System.out.println("Nao");
        }
        scanner.close();
    }
}
