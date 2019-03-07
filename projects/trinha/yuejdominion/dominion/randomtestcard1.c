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
  int failed_num_action = 0;
  int failed_deck_count = 0;
  int failed_hand_count = 0;
  int failed_card_effect = 0;
  int a = 0;
  int player = 0; // current player
  srand(time(NULL));
  // initialize a game state and player cards
  printf("----------------- Random Test #2: Village ----------------- \n");
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

    // test village
    // Check to see if cardEffect worked
    a = cardEffect(village, 0, 0, 0, &testG, 0, 0);
    if (a < 0) {
      failed_card_effect++;
    }

    //check to see if one card has been added and one card has been discard
    if(G.handCount[player] != testG.handCount[player]) {
      failed_hand_count++;
    }

    //check to see if two actions cards have been added (should be 1 extra after village is discarded)
    if(G.numActions + 1 != testG.numActions) {
      failed_num_action++;
    }

    //test to see if deck count failed should be one less
    if(G.deckCount[player] - 1 != testG.deckCount[player]) {
      failed_deck_count++;
    }

  }

  printf("Hand count failed: %d times after %d iterations\n", failed_hand_count, c);
  printf("Action card count failed: %d times after %d iterations\n", failed_num_action, c);
  printf("Deck count failed: %d times after %d iterations\n", failed_deck_count, c);
  printf("cardEffect() failed: %d times after %d iterations\n\n", failed_card_effect, c);


  return 0;
}
