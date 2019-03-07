#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
  struct gameState G;
  int count = 0;
  int i;
  int seed = 1000;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
  int random_num_players = 0;
  int random_deck_size = 0;
  int random_hand_size = 0;
  int failed_deck_count = 0;
  int failed_coin_count = 0;
  int failed_hand_count = 0;
  int failed_card_effect = 0;
  int failed_discard_count = 0;
  int a = 0;
  int player = 0; // current player
  srand(time(NULL));
  // initialize a game state and player cards
  printf("----------------- Random Test #3: Steward ----------------- \n");
  int c;
  for (c = 0; c < 1000; c++) {
    // get random values
    random_num_players = (rand() % (MAX_PLAYERS-1) + 2); // randomize number of players 2-4
    random_deck_size = (rand() % (MAX_DECK-2) + 3); // randomize deck size 3-500
    random_hand_size = (rand() % (MAX_HAND-4) + 5); // randomize hand size 5-500
    initializeGame(random_num_players, k, seed, &G);
    player = (rand() % (random_num_players)); //random current player
    // store random values in current player
    G.handCount[player] = random_hand_size;
    G.whoseTurn = player;
    G.deckCount[player] = random_deck_size;

    struct gameState testG;
    memcpy(&testG, &G, sizeof(struct gameState));

    // test steward
    // Check to see if cardEffect worked
    a = cardEffect(steward, 1, 0, 0, &testG, 0, 0);
    if (a < 0) {
      failed_card_effect++;
    }

    //check to see if two card has been added and one card has been discard
    if(G.handCount[player] + 1 != testG.handCount[player]) {
      failed_hand_count++;
    }

    //test to see if 2 coins have been added
    a = cardEffect(steward, 2, 0, 0, &testG, 0, 0);
    if(G.coins + 2 != testG.coins) {
      failed_coin_count++;
    }

    if(G.deckCount[player] - 2 != testG.deckCount[player]) {
      failed_deck_count++;
    }


    if(G.discardCount[player] != testG.discardCount[player]) {
      failed_discard_count++;
  }

  }
  printf("Hand count failed: %d times after %d iterations\n", failed_hand_count, c);
  printf("Discarded count failed: %d times after %d iterations\n", failed_discard_count, c);
  printf("Deck count failed: %d times after %d iterations\n", failed_deck_count, c);
  printf("Coin count failed: %d times after %d iterations\n", failed_coin_count, c);
  printf("cardEffect() failed: %d times after %d iterations\n\n", failed_card_effect, c);

  return 0;
}
