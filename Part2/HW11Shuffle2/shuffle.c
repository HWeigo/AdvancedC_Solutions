#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void shuffleSingle(CardDeck origDeck, int cnt, int round);
void interleaveHelp(CardDeck leftDeck, CardDeck rightDeck, int l, int r,
        CardDeck output, int idx, int cnt, int round);
void interleave(CardDeck leftDeck, CardDeck rightDeck, int cnt, int round);

static void printDeck(CardDeck deck)
{
  int ind; 
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

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
    }
}

void interleaveHelp(CardDeck leftDeck, CardDeck rightDeck, int l, int r,
        CardDeck output, int idx, int cnt, int round)
{
    if(l >= 0)
    {
        output.cards[idx] = leftDeck.cards[l];
        interleaveHelp(leftDeck, rightDeck, l-1, r, output, idx-1, cnt, round);
    }
    if(r >= 0)
    {
        output.cards[idx] = rightDeck.cards[r];
        interleaveHelp(leftDeck, rightDeck, l, r-1, output, idx-1, cnt, round);
    }
    if(l < 0 && r<0)
    {
        if(cnt != round)
		{
			shuffleSingle(output, cnt+1, round);
		}
		else
		{
			printDeck(output);
		}
	}
    return;
}

void interleave(CardDeck leftDeck, CardDeck rightDeck, int cnt, int round)
{
    int size = leftDeck.size + rightDeck.size;
    
	CardDeck output =
    {
        .size = leftDeck.size + rightDeck.size,
        .cards = {0}
    };
    interleaveHelp(leftDeck, rightDeck, leftDeck.size - 1, rightDeck.size - 1, 
			output, size-1, cnt, round);
    return;
}

void shuffleSingle(CardDeck origDeck, int cnt, int round)
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
        interleave(leftDeck[i], rightDeck[i], cnt, round);
    }   

    free(leftDeck);
    free(rightDeck);
}

void shuffle(CardDeck origDeck, int round)
{
	shuffleSingle(origDeck, 1, round);
}


