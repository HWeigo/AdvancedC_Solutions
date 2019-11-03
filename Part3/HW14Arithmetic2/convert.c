// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

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
// *** You MUST modify the convert function
// ***
#ifdef TEST_CONVERT
bool convert(List * arithlist)
{

	if (arithlist == NULL)
    {
      return true;
    }
	if ((arithlist -> head) == NULL)
    {
      return true;
    }
	
	List *oper;
	oper = malloc(sizeof(List));
	oper -> head = NULL;
	oper -> tail = NULL;

	List *output;
	output = malloc(sizeof(List));
	output -> head = NULL;
	output -> tail = NULL;
	
	ListNode *p;
	ListNode *q = NULL;
	ListNode *tmp = NULL;
	ListNode *operLast = NULL;
	p = arithlist->head;
	operLast = oper->tail;
	while(p != NULL)
	{
		switch(isOperator(p->word)){
			case -1:
				addNode(output, p->word);
				break;

			case 0:
			case 1:
			case 2:
				if(operLast == NULL)
				{
					addNode(oper, p->word);
					operLast = oper->tail;
					break;
				}
				/*
				if(isOperator(operLast->word) == 2)
				{
					addNode(output, operLast->word);
					deleteNode(oper, operLast);
					addNode(oper, p->word);
				}
				*/
				if(isOperator(operLast->word) == 2)
				{
					while(operLast != NULL)
					{
						addNode(output, operLast->word);
						tmp = operLast;
						operLast = operLast->prev;
						deleteNode(oper, tmp);
						tmp = NULL;
					}
					addNode(oper, p->word);
				}
				else
				{
					addNode(oper, p->word);
				}	
				operLast = oper->tail;
				break;
			case 3:
				addNode(oper, p->word);
				operLast = oper->tail;
				break;
			case 4:
				q = operLast;
				while(isOperator(q->word) != 3)
				{
					addNode(output, q->word);
					tmp = q;
					q = q->prev;
					deleteNode(oper, tmp);
					tmp = NULL;
				}
				deleteNode(oper, q);
				operLast = oper->tail;
				break;

			default:
				break;
		}
		p = p->next;
	}
	q = NULL;
	
	// copy operations to output 
	p = oper->tail;
	while(p != NULL)
	{
		addNode(output, p->word);
		p = p->prev;
	}

	// delete original list 
	p = arithlist->head;
	while(p != NULL)
	{
		deleteNode(arithlist, p);
		p = arithlist->head;	
	}

	// copy list 
	p = output->head;
	while(p != NULL)
	{
		addNode(arithlist, p->word);
		p = p->next;
	}


	deleteList(output);
	deleteList(oper);
	return true;
}
#endif 
