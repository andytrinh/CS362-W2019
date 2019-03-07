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

  printf("----------------- Unit Test 3: getCost() ----------------\n");
  printf("TEST 1: Check for cost of curse card\n");
  int actualCost = getCost(0);
  printf("Expected: 0, Actual: %d\n", actualCost);
  assert(actualCost == 0);
  printf("-----------------------------------------------------------\n");

  printf("TEST 2: Check for cost of estate card\n");
  actualCost = getCost(1);
  printf("Expected: 2, Actual: %d\n", actualCost);
  assert(actualCost == 2);
  printf("-----------------------------------------------------------\n");

  printf("TEST 3: Check for cost of duchy card\n");
  actualCost = getCost(2);
  printf("Expected: 5, Actual: %d\n", actualCost);
  assert(actualCost == 5);
  printf("-----------------------------------------------------------\n");

  printf("TEST 4: Check for cost of province card\n");
  actualCost = getCost(3);
  printf("Expected: 8, Actual: %d\n", actualCost);
  assert(actualCost == 8);
  printf("-----------------------------------------------------------\n");

  printf("TEST 5: Check for cost of copper card\n");
  actualCost = getCost(4);
  printf("Expected: 0, Actual: %d\n", actualCost);
  assert(actualCost == 0);
  printf("-----------------------------------------------------------\n");

  printf("TEST 6: Check for cost of silver card\n");
  actualCost = getCost(5);
  printf("Expected: 3, Actual: %d\n", actualCost);
  assert(actualCost == 3);
  printf("-----------------------------------------------------------\n");

  printf("TEST 7: Check for cost of gold card\n");
  actualCost = getCost(6);
  printf("Expected: 6, Actual: %d\n", actualCost);
  assert(actualCost == 6);
  printf("-----------------------------------------------------------\n");

  printf("TEST 8: Check for cost of adventurer card\n");
  actualCost = getCost(7);
  printf("Expected: 6, Actual: %d\n", actualCost);
  assert(actualCost == 6);
  printf("-----------------------------------------------------------\n");

  printf("TEST 9: Check for cost of council_room card\n");
  actualCost = getCost(8);
  printf("Expected: 5, Actual: %d\n", actualCost);
  assert(actualCost == 5);
  printf("-----------------------------------------------------------\n");

  printf("TEST 10: Check for cost of feast card\n");
  actualCost = getCost(9);
  printf("Expected: 4, Actual: %d\n", actualCost);
  assert(actualCost == 4);
  printf("-----------------------------------------------------------\n");

  printf("TEST 11: Check for cost of gardens card\n");
  actualCost = getCost(10);
  printf("Expected: 4, Actual: %d\n", actualCost);
  assert(actualCost == 4);
  printf("-----------------------------------------------------------\n");

  printf("TEST 12: Check for cost of mine card\n");
  actualCost = getCost(11);
  printf("Expected: 5, Actual: %d\n", actualCost);
  assert(actualCost == 5);
  printf("-----------------------------------------------------------\n");

  printf("TEST 13: Check for cost of remodel card\n");
  actualCost = getCost(12);
  printf("Expected: 4, Actual: %d\n", actualCost);
  assert(actualCost == 4);
  printf("-----------------------------------------------------------\n");

  printf("TEST 14: Check for cost of smithy card\n");
  actualCost = getCost(13);
  printf("Expected: 4, Actual: %d\n", actualCost);
  assert(actualCost == 4);
  printf("-----------------------------------------------------------\n");

  printf("TEST 15: Check for cost of village card\n");
  actualCost = getCost(14);
  printf("Expected: 3, Actual: %d\n", actualCost);
  assert(actualCost == 3);
  printf("-----------------------------------------------------------\n");

  printf("TEST 16: Check for cost of baron card\n");
  actualCost = getCost(15);
  printf("Expected: 4, Actual: %d\n", actualCost);
  assert(actualCost == 4);
  printf("-----------------------------------------------------------\n");
  printf("TEST 17: Check for cost of great_hall card\n");
  actualCost = getCost(16);
  printf("Expected: 3, Actual: %d\n", actualCost);
  assert(actualCost == 3);
  printf("-----------------------------------------------------------\n");
  printf("TEST 18: Check for cost of minion card\n");
  actualCost = getCost(17);
  printf("Expected: 5, Actual: %d\n", actualCost);
  assert(actualCost == 5);
  printf("-----------------------------------------------------------\n");

  printf("TEST 19: Check for cost of steward card\n");
  actualCost = getCost(18);
  printf("Expected: 3, Actual: %d\n", actualCost);
  assert(actualCost == 3);
  printf("-----------------------------------------------------------\n");

  printf("TEST 20: Check for cost of tribute card\n");
  actualCost = getCost(19);
  printf("Expected: 5, Actual: %d\n", actualCost);
  assert(actualCost == 5);
  printf("-----------------------------------------------------------\n");

  printf("TEST 21: Check for cost of ambassador card\n");
  actualCost = getCost(20);
  printf("Expected: 3, Actual: %d\n", actualCost);
  assert(actualCost == 3);
  printf("-----------------------------------------------------------\n");

  printf("TEST 22: Check for cost of cutpurse card\n");
  actualCost = getCost(21);
  printf("Expected: 4, Actual: %d\n", actualCost);
  assert(actualCost == 4);
  printf("-----------------------------------------------------------\n");

  printf("TEST 23: Check for cost of embargo card\n");
  actualCost = getCost(22);
  printf("Expected: 2, Actual: %d\n", actualCost);
  assert(actualCost == 2);
  printf("-----------------------------------------------------------\n");

  printf("TEST 24: Check for cost of outpost card\n");
  actualCost = getCost(23);
  printf("Expected: 5, Actual: %d\n", actualCost);
  assert(actualCost == 5);
  printf("-----------------------------------------------------------\n");

  printf("TEST 25: Check for cost of salvager card\n");
  actualCost = getCost(24);
  printf("Expected: 4, Actual: %d\n", actualCost);
  assert(actualCost == 4);
  printf("-----------------------------------------------------------\n");

  printf("TEST 26: Check for cost of sea_hag card\n");
  actualCost = getCost(25);
  printf("Expected: 4, Actual: %d\n", actualCost);
  assert(actualCost == 4);
  printf("-----------------------------------------------------------\n");

  printf("TEST 27: Check for cost of treasure_map card\n");
  actualCost = getCost(26);
  printf("Expected: 4, Actual: %d\n", actualCost);
  assert(actualCost == 4);

  printf("----------------------END OF UNIT TEST 3-----------------------\n\n");

}
