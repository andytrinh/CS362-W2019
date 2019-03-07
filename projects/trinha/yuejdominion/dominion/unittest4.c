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
  G.supplyCount[feast] = 5;
  G.supplyCount[gold] = 3;
  G.supplyCount[silver] = 2;

  printf("----------------- Unit Test 4: supplyCount() ----------------\n");
  printf("TEST 1: Check for number of feast card left in supply\n");
  int actualNumber = supplyCount(feast, &G);
  printf("Expected: 5, Actual: %d\n", actualNumber);
    assert(actualNumber == 5);
  printf("-----------------------------------------------------------\n");

  printf("TEST 2: Check for number of gold card left in supply\n");
  actualNumber = supplyCount(gold, &G);
  printf("Expected: 3, Actual: %d\n", actualNumber);
  assert(actualNumber == 3);
  printf("-----------------------------------------------------------\n");

  printf("TEST 3: Check for number of silver card left in supply\n");
  actualNumber = supplyCount(silver, &G);
  printf("Expected: 2, Actual: %d\n", actualNumber);
  assert(actualNumber == 2);
  printf("-----------------------------------------------------------\n");


  printf("----------------------END OF UNIT TEST 4-----------------------\n\n");

}
