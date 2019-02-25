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
  int failed_draw_treasure = 0;
  int failed_card_effect = 0;
  int failed_deck_count = 0;
  int failed_hand_count = 0;
  int a = 0;
  int player = 0; // current player
  srand(time(NULL));
	// initialize a game state and player cards
  printf("----------------- Random Test #1: Adventurer ----------------- \n");
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

    // test adventurer
    struct gameState testG;
    memcpy(&testG, &G, sizeof(struct gameState));

    // Check for 2+ Treasure cards
    a = cardEffect(adventurer, 1, 0, 0, &testG, 0, 0);
    //test to see if cardEffect() failed
    if (a < 0) {
      failed_card_effect++;
    }


    //test to see if hand count failed

    if(G.handCount[player] != testG.handCount[player]-5) {
      failed_hand_count++;
    }

    //test to see if deck count failed
    if(G.deckCount[player] != testG.deckCount[player]) {
      failed_deck_count++;
    }

    int numTreasure = 0;
    int currentCard = 0;
    int i;
    for (i = 0; i < testG.handCount[player]; i++) {
      currentCard = testG.hand[player][i];
      if(currentCard == copper || currentCard == silver || currentCard == gold)
        numTreasure++;

    }

    if(numTreasure < 2) {
      failed_draw_treasure++;
    }
  //  printf("%d\n", numTreasure);
//   printf("%d = %d\n", G.handCount[player], testG.handCount[player]);
  }
  printf("Treasure count failed: %d times after %d iterations\n", failed_draw_treasure, c);
  printf("Hand count failed: %d times after %d iterations\n", failed_hand_count, c);
//  printf("Deck count failed: %d times after %d iterations\n", failed_deck_count, c);
  printf("cardEffect() failed: %d times after %d iterations\n\n", failed_card_effect, c);


  return 0;

}
