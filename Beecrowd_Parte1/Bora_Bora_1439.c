#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//tudo errado
#define MAX_PLAYERS 10
#define MAX_HAND_SIZE 11
#define MAX_DECK_SIZE 300

typedef struct {
    int value;
    char suit;
} Card;

typedef struct {
    Card hand[MAX_HAND_SIZE];
    int handSize;
} Player;

int compareCards(const void *a, const void *b) {
    Card *cardA = (Card *)a;
    Card *cardB = (Card *)b;
    if (cardA->value != cardB->value) {
        return cardA->value - cardB->value;
    }
    return cardA->suit - cardB->suit;
}

void sortHand(Player *player) {
    qsort(player->hand, player->handSize, sizeof(Card), compareCards);
}

int findPlayableCard(Player *player, Card topCard) {
    for (int i = player->handSize - 1; i >= 0; i--) {
        if (player->hand[i].value == topCard.value || player->hand[i].suit == topCard.suit) {
            return i;
        }
    }
    return -1;
}

int main() {
    int P, M, N;
    while (scanf("%d %d %d", &P, &M, &N) == 3 && (P != 0 || M != 0 || N != 0)) {
        Player players[MAX_PLAYERS];
        for (int i = 0; i < P; i++) {
            players[i].handSize = 0;
        }

        Card deck[MAX_DECK_SIZE];
        for (int i = 0; i < N; i++) {
            scanf("%d %c", &deck[i].value, &deck[i].suit);
        }

        int deckIndex = 0;
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < M; j++) {
                players[i].hand[players[i].handSize++] = deck[deckIndex++];
            }
        }

        for (int i = 0; i < P; i++) {
            sortHand(&players[i]);
        }

        Card topCard = deck[deckIndex++];
        int drawPileSize = N - deckIndex;
        int currentPlayer = 0;
        int direction = 1;

        while (1) {
            if (topCard.value == 7) {
                int nextPlayer = (currentPlayer + direction + P) % P;
                for (int i = 0; i < 2; i++) {
                    if (deckIndex < N) {
                        players[nextPlayer].hand[players[nextPlayer].handSize++] = deck[deckIndex++];
                    }
                }
                currentPlayer = (nextPlayer + direction + P) % P;
            } else if (topCard.value == 1) {
                int nextPlayer = (currentPlayer + direction + P) % P;
                if (deckIndex < N) {
                    players[nextPlayer].hand[players[nextPlayer].handSize++] = deck[deckIndex++];
                }
                currentPlayer = (nextPlayer + direction + P) % P;
            } else if (topCard.value == 11) {
                currentPlayer = (currentPlayer + 2 * direction + P) % P;
            } else {
                currentPlayer = (currentPlayer + direction + P) % P;
            }

            int playableIndex = findPlayableCard(&players[currentPlayer], topCard);
            if (playableIndex == -1) {
                if (deckIndex < N) {
                    Card drawnCard = deck[deckIndex++];
                    players[currentPlayer].hand[players[currentPlayer].handSize++] = drawnCard;
                    if (drawnCard.value == topCard.value || drawnCard.suit == topCard.suit) {
                        players[currentPlayer].handSize--;
                        topCard = drawnCard;
                    }
                }
            } else {
                Card playedCard = players[currentPlayer].hand[playableIndex];
                for (int i = playableIndex; i < players[currentPlayer].handSize - 1; i++) {
                    players[currentPlayer].hand[i] = players[currentPlayer].hand[i + 1];
                }
                players[currentPlayer].handSize--;
                topCard = playedCard;
                if (players[currentPlayer].handSize == 0) {
                    printf("%d\n", currentPlayer + 1);
                    break;
                }
                if (playedCard.value == 12) {
                    direction = -direction;
                }
            }
        }
    }
    return 0;
}
