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
	int k[10] = { minion, council_room, tribute, gardens, mine, remodel, smithy, village, baron, great_hall };
	
	// declare the game state
	struct gameState G;

	srand(time(0));


	//Initilize the game struct
	r = initializeGame(2, k, seed, &G); // initialize a new game
		
				
	/*This section is where the requirements are set*/
	int q = G.whoseTurn;
		
	for( int i = 0; i < 6; ++i)	{
		r = gainCard( copper, &G, 0, q);		//player gains 6 'copper' cards to their discard pile making numDiscard > numDeck
		if( r == 1) {
			printf("Error adding card to discard pile\n");
		}
	}
		
	/*This section calls the scoreFor() to test it*/
	//get score for each player
    int player0 = scoreFor(0, &G);
	int player1 = scoreFor(1, &G);
	
	/*This section tests the validity of scoreFor()*/
	if( player0 != 9)	{
		printf("Error calculating player 0's score\n");
	}
	
	if( player1 != 3)	{
		printf("Error calculating player 1's score\n");
	}
	
}










