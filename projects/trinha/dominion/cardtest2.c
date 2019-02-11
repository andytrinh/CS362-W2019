/*
 * cardtest2.c
 *

 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

  printf("----------------- CARD TEST 2: %s ----------------\n", TESTCARD);

  printf("----------------- TEST 1: Check for 2+ Treasure cards----------------- \n");
  memcpy(&testG, &G, sizeof(struct gameState));
  cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
  int numTreasure = 0;
  int currentCard = 0;
  for (int i = 0; i < 5; i++) {
    currentCard = testG.hand[thisPlayer][i];
    if(currentCard == copper || currentCard == silver || currentCard == gold)
      numTreasure++;
  }
  printf("Treasure Card: 2 or more, Actual: %d\n", numTreasure);
  assert(numTreasure >= 2);
  printf("----------------- TEST 2: Check to see that other player's values are unaffected----------------- \n");
  newCards = 0;
  discarded = 0;
  printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer] + newCards - discarded);
  printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer] - newCards + shuffledCards);
  printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
  assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer] + newCards - discarded);
  assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer] - newCards + shuffledCards);
  assert(testG.coins == G.coins + xtraCoins);
  printf("----------------- TEST 3: Check for expected Kingdom cards----------------- \n");
  printf("kingdom card: %d, expected: %d\n", testG.supplyCount[thisPlayer], G.supplyCount[thisPlayer]);
  assert(testG.supplyCount[thisPlayer] == G.supplyCount[thisPlayer]);
  printf("----------------- TEST 4: Check for expected Victory cards----------------- \n");
  printf("Duchy: %d, Expected: %d\n", testG.supplyCount[duchy], G.supplyCount[duchy]);
  printf("Province: %d, Expected: %d\n", testG.supplyCount[province], G.supplyCount[province]);
  printf("Estate: %d, Expected: %d\n", testG.supplyCount[estate], G.supplyCount[estate]);
  assert(testG.supplyCount[duchy] == G.supplyCount[duchy]);
  assert(testG.supplyCount[province] == G.supplyCount[province]);
  assert(testG.supplyCount[estate] == G.supplyCount[estate]);


  printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

  return 0;
}
