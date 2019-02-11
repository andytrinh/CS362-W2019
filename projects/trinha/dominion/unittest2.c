#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


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
  struct gameState G;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  initializeGame(numPlayers, k, seed, &G); //initialize game to get proper values

  printf("----------------- Unit Test 2: numHandCards() ----------------\n");
  printf("TEST 1: Checking for a correct number of cards in hand\n");
  printf("-----------------------------------------------------------\n");
  int actual = numHandCards(&G);
  printf("numCards = 5, actual = %d\n", actual);
  assert(actual == 5);
  printf("-----------------------------------------------------------\n");
  printf("TEST 2: Checking for a correct number of cards in hand of other player\n");
  printf("-----------------------------------------------------------\n");
  endTurn(&G);
  actual = numHandCards(&G);
  printf("numCards = 5, actual = %d\n", actual);
  assert(actual == 5);

  printf("----------------------END OF UNIT TEST 2-----------------------\n\n");

}
