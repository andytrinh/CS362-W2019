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
  struct gameState G, GG, GGG;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


  printf("----------------- Unit Test 1: initalizeGame() ----------------\n");
  printf("TEST 1: Checking for a game with 2 players\n");
  printf("-----------------------------------------------------------\n");
  initializeGame(numPlayers, k, seed, &G);
  printf("numPlayers = 2, actual = %d\n", G.numPlayers);
  assert(G.numPlayers == 2);
  printf("~Checking for number of curse cards~\n");
  printf("Curse cards: 10, actual: %d\n", G.supplyCount[curse]);
  assert(G.supplyCount[curse] == 10);
  printf("~Checking for number of estate cards~\n");
  printf("Estate cards: 8, actual: %d\n", G.supplyCount[estate]);
  assert(G.supplyCount[estate] == 8);
  printf("~Checking for number of duchy cards~\n");
  printf("Duchy cards: 8, actual: %d\n", G.supplyCount[duchy]);
  assert(G.supplyCount[duchy] == 8);
  printf("~Checking for number of province cards~\n");
  printf("Province cards: 8, actual: %d\n", G.supplyCount[province]);
  assert(G.supplyCount[province] == 8);
  printf("-----------------------------------------------------------\n");
  printf("TEST 2: Checking for a game with 3 players\n");
  printf("-----------------------------------------------------------\n");
  initializeGame(3, k, seed, &GG);
  printf("numPlayers = 3, actual = %d\n", GG.numPlayers);
  assert(GG.numPlayers == 3);
  printf("~Checking for number of curse cards~\n");
  printf("Curse cards: 20, actual: %d\n", GG.supplyCount[curse]);
  assert(GG.supplyCount[curse] == 20);
  printf("~Checking for number of estate cards~\n");
  printf("Estate cards: 12, actual: %d\n", GG.supplyCount[estate]);
  assert(GG.supplyCount[estate] == 12);
  printf("~Checking for number of duchy cards~\n");
  printf("Duchy cards: 12, actual: %d\n", GG.supplyCount[duchy]);
  assert(GG.supplyCount[duchy] == 12);
  printf("~Checking for number of province cards~\n");
  printf("Province cards: 12, actual: %d\n", GG.supplyCount[province]);
  assert(GG.supplyCount[province] == 12);
  printf("-----------------------------------------------------------\n");
  printf("TEST 3: Checking for a game with 4 players\n");
  printf("-----------------------------------------------------------\n");
  initializeGame(4, k, seed, &GGG);
  printf("numPlayers = 4, actual = %d\n", GGG.numPlayers);
  assert(GGG.numPlayers == 4);
  printf("~Checking for number of curse cards~\n");
  printf("Curse cards: 30, actual: %d\n", GGG.supplyCount[curse]);
  assert(GGG.supplyCount[curse] == 30);
  printf("~Checking for number of estate cards~\n");
  printf("Estate cards: 12, actual: %d\n", GGG.supplyCount[estate]);
  assert(GGG.supplyCount[estate] == 12);
  printf("~Checking for number of duchy cards~\n");
  printf("Duchy cards: 12, actual: %d\n", GGG.supplyCount[duchy]);
  assert(GGG.supplyCount[duchy] == 12);
  printf("~Checking for number of province cards~\n");
  printf("Province cards: 12, actual: %d\n", GGG.supplyCount[province]);
  assert(GGG.supplyCount[province] == 12);

  printf("----------------------END OF UNIT TEST 1-----------------------\n\n");



}
