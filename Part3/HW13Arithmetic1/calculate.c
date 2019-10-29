// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false

bool calculate(List * arithlist)
{
	if(arithlist == NULL)
	{
		return true;
	}
	if((arithlist->head) == NULL)
	{
		return true;
	}
  // go through the list until there is only node in the list
  // find the next operator
  // If no operator can be found, return false
  // If an operator is found, find the two previous nodes as operands
  // If cannot find previous two operands, return false
  // If two operands can be found, perform the arithmetic operation
  // Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
  //    not 2 - 4
  // After the operation,
  //     put the result back to the list
  //     remove the two nodes used to store the two operands
  // After going through the entire list and performing the operations,
  //     the list should have exactly one node left. If this is not
  //     true, return false
  // If the input is valud, return true
	ListNode *p = NULL;
	ListNode *q = NULL;
	p = arithlist->head;
	int oper = -1;
	int num1 = 0;
	int num2 = 0;
	int result = 0;
	char output[WORDLENGTH];
	while(p->next != NULL)
	{
		oper = isOperator(p->word);
		while(oper == -1)
		{
			if(p->next == NULL)
			{
				fprintf(stderr, "last node is not an operator.\n");
				return false;
			}
			p = p->next;
			oper = isOperator(p->word);
		}
		q = p->prev;
		
		if((p->prev == NULL) || (q->prev == NULL))
		{
			fprintf(stderr, "cannot find previous two operands.\n");
			return false;
		}

		num1 = (int)strtol((q->prev)->word, NULL, 10);
		num2 = (int)strtol((p->prev)->word, NULL, 10); 
		if(oper == 0)
		{
			result = num1 + num2;
			sprintf(output, "%d\n", result);
			deleteNode(arithlist, q->prev);
			deleteNode(arithlist, p->prev);
			strcpy(p->word, output);
		}
		if(oper == 1)
		{
			result = num1 - num2;
			sprintf(output, "%d\n", result);
			deleteNode(arithlist, q->prev);
			deleteNode(arithlist, p->prev);
			strcpy(p->word, output);
		}
		if(oper == 2)
		{
			result = num1 * num2;
			sprintf(output, "%d\n", result);
			deleteNode(arithlist, q->prev);
			deleteNode(arithlist, p->prev);
			strcpy(p->word, output);
		}
		q = NULL;
	}
  
  // if more than one node left, return false
	if(arithlist->head != arithlist->tail)
	{
		fprintf(stderr, "more than one node left.\n");
		return false;
	}
  // if the remaining node is an operator, return false
	p = arithlist->head;
	if(isOperator(p->word) != -1)
	{
		fprintf(stderr, "remaining node is an operator.\n");
		return false;
	}
  // if everything is OK, return true
  return true;
}
#endif
