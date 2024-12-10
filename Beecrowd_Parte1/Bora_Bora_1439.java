import java.util.*;
//tudo errado
public class Bora_Bora_1439 {

    static class Card {
        int value;
        char suit;

        Card(int value, char suit) {
            this.value = value;
            this.suit = suit;
        }
    }

    static class Player {
        List<Card> hand;

        Player() {
            this.hand = new ArrayList<>();
        }

        void addCard(Card card) {
            this.hand.add(card);
        }

        void sortHand() {
            Collections.sort(this.hand, (a, b) -> {
                if (a.value != b.value) {
                    return a.value - b.value;
                }
                return a.suit - b.suit;
            });
        }

        Card playCard(Card topCard) {
            for (int i = this.hand.size() - 1; i >= 0; i--) {
                Card card = this.hand.get(i);
                if (card.value == topCard.value || card.suit == topCard.suit) {
                    this.hand.remove(i);
                    return card;
                }
            }
            return null;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int P = sc.nextInt();
            int M = sc.nextInt();
            int N = sc.nextInt();

            if (P == 0 && M == 0 && N == 0) {
                break;
            }

            Player[] players = new Player[P];
            for (int i = 0; i < P; i++) {
                players[i] = new Player();
            }

            for (int i = 0; i < P * M; i++) {
                int value = sc.nextInt();
                char suit = sc.next().charAt(0);
                players[i % P].addCard(new Card(value, suit));
            }

            for (Player player : players) {
                player.sortHand();
            }

            int discardIndex = P * M;
            Card topCard = new Card(sc.nextInt(), sc.next().charAt(0));
            LinkedList<Card> drawPile = new LinkedList<>();

            for (int i = discardIndex + 1; i < N; i++) {
                drawPile.add(new Card(sc.nextInt(), sc.next().charAt(0)));
            }

            int currentPlayer = 0;
            boolean clockwise = true;

            while (true) {
                if (topCard.value == 7) {
                    int nextPlayer = (currentPlayer + (clockwise ? 1 : -1) + P) % P;
                    for (int i = 0; i < 2; i++) {
                        players[nextPlayer].addCard(drawPile.poll());
                    }
                    currentPlayer = (nextPlayer + (clockwise ? 1 : -1) + P) % P;
                } else if (topCard.value == 1) {
                    int nextPlayer = (currentPlayer + (clockwise ? 1 : -1) + P) % P;
                    players[nextPlayer].addCard(drawPile.poll());
                    currentPlayer = (nextPlayer + (clockwise ? 1 : -1) + P) % P;
                } else if (topCard.value == 11) {
                    currentPlayer = (currentPlayer + (clockwise ? 2 : -2) + P) % P;
                } else {
                    currentPlayer = (currentPlayer + (clockwise ? 1 : -1) + P) % P;
                }

                Card playedCard = players[currentPlayer].playCard(topCard);
                if (playedCard == null) {
                    Card drawnCard = drawPile.poll();
                    players[currentPlayer].addCard(drawnCard);
                    if (drawnCard.value == topCard.value || drawnCard.suit == topCard.suit) {
                        players[currentPlayer].hand.remove(drawnCard);
                        playedCard = drawnCard;
                    }
                }

                if (players[currentPlayer].hand.isEmpty()) {
                    System.out.println(currentPlayer + 1);
                    break;
                }

                if (playedCard != null) {
                    topCard = playedCard;
                    if (playedCard.value == 12) {
                        clockwise = !clockwise;
                    }
                }
            }
        }

        sc.close();
    }
}
