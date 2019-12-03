//Write automated test generator for the Baron, req 90% statement and branch coverage
//use -b and -f options when generating coverage, target <5min for coverage

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[])
{
	/*
	struct gameState {
		int numPlayers; //number of players
		int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
		int embargoTokens[treasure_map+1];
		int outpostPlayed;
		int outpostTurn;
		int whoseTurn;
		int phase;
		int numActions; 	// Starts at 1 each turn
		int coins; 			// Use as you see fit!
		int numBuys; 		// Starts at 1 each turn
		int hand[MAX_PLAYERS][MAX_HAND];
		int handCount[MAX_PLAYERS];
		int deck[MAX_PLAYERS][MAX_DECK];
		int deckCount[MAX_PLAYERS];
		int discard[MAX_PLAYERS][MAX_DECK];
		int discardCount[MAX_PLAYERS];
		int playedCards[MAX_DECK];
		int playedCardCount;
	};*/		
	
	int r = 0;
	int seed = 30;
	
	
	// set your card array
	int k[10] = { minion, council_room, tribute, gardens, mine, remodel, smithy, village, baron, feast };
	
	// declare the game state
	struct gameState G;

	srand(time(0));

	//Initilize the game struct
	r = initializeGame(2, k, seed, &G); // initialize a new game
	
	/*This section is where the requirements are set*/
	int q = G.whoseTurn;
	int w = G.handCount[q];	//current hand size of the player
	
	r = gainCard( feast, &G, 2, q);		//player gains 'feast' to their hand
	if( r == 1) {
		printf("Error adding 'feast' to hand\n");
	}
	
	
	/*This section feast to test it*/
	int n = G.handCount[G.whoseTurn];
	r = playCard(n-1, tribute, 0, 0, &G);		//play 'feast' which is the last card in hand, and attempt to buy tribute (a valid choice)
	
	
	
	/*This section tests the validity of scoreFor()*/
	if( G.handCount[q] != w)	{
		printf("Error calculating hand addition/substraction\n");
	}

	if( G.discardCount[q] != 2)	{
		printf("Error getting both 'feast' and/or 'tribute' to the discard pile");
	}
	
}










