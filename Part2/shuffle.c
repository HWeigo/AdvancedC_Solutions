// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}
 
#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
	int poss = origDeck.size - 1;
	for(int i=0; i<poss;++i)
	{
		leftDeck[i].size = i+1;
		memcpy(leftDeck[i].cards, origDeck.cards, 
				(i+1) * sizeof(origDeck.cards[0]));

		rightDeck[i].size = poss-i;
		memcpy(rightDeck[i].cards, &(origDeck.cards[i+1]),
		(poss-i) * sizeof(origDeck.cards[0]));
	//	printDeck(leftDeck[i]);
	//	printDeck(rightDeck[i]);
	}
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.

void interleaveHelp(CardDeck leftDeck, CardDeck rightDeck, int l, int r, 
		CardDeck output, int idx)
{
	if(l >= 0)
	{
		//output[idx] = leftDeck.cards[l];
		output.cards[idx] = leftDeck.cards[l]; 
		interleaveHelp(leftDeck, rightDeck, l-1, r, output, idx-1);
	}
	if(r >= 0)
	{
	//	output[idx] = rightDeck.cards[r];
		output.cards[idx] = rightDeck.cards[r];
		interleaveHelp(leftDeck, rightDeck, l, r-1, output, idx-1);
	}
	if(l < 0 && r<0)
	{
		printDeck(output);
		//int size = leftDeck.size + rightDeck.size;
		//for(int i = size-1; i>=0;--i)
		//{
		//	printf("%c ", output[i]);
		//}
		//printf("\n");
	}
	return;
}

void interleave(CardDeck leftDeck, CardDeck rightDeck)
{
	int size = leftDeck.size + rightDeck.size;
	//char *output;
	//output = malloc(size * sizeof(char));
	CardDeck output =
	{
		.size = leftDeck.size + rightDeck.size,
		.cards = {0}
	};
	interleaveHelp(leftDeck, rightDeck, leftDeck.size - 1, rightDeck.size - 1, output, size-1);
	return;
}


 
#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck)
{
	int size = origDeck.size;
	int poss = size - 1;

	CardDeck *leftDeck;
	CardDeck *rightDeck;
	
	leftDeck = malloc(poss * sizeof(CardDeck));
	rightDeck = malloc(poss * sizeof(CardDeck));

	divide(origDeck, leftDeck, rightDeck);

	for(int i=0; i<poss; ++i)
	{
		interleave(leftDeck[i], rightDeck[i]);
	}

	free(leftDeck);
	free(rightDeck);
}
#endif 
