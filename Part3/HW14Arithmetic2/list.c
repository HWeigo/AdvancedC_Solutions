// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
	FILE *fptr;
	fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		return false;
	}

	char temp[11];
	char word[10];
	while(fgets(temp, 11 , fptr) != NULL)
	{
		if(strlen(temp) > 9)
		{
			// free memory of the list 
			deleteList(arithlist);
			fclose(fptr);
			fprintf(stderr, "A line is too long.\n");
			return false;
		}
		else
		{
			strcpy(word, temp);
			addNode(arithlist, word);
		}
	}
	fclose(fptr);
	return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
void deleteList(List * arithlist)
{
	ListNode *p = NULL;
	p = arithlist->head;
	while(p != NULL)
	{
		ListNode *q = p;
		p = p->next;
		deleteNode(arithlist, q);
	}
	free(arithlist);
}
#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
	if(arithlist == NULL)
	{
		fprintf(stderr, "Arithlist is NULL.\n");
		return;
	}
	if(arithlist->head == NULL)
	{
		ListNode *p;
		p = malloc(sizeof(ListNode));
		strcpy(p->word, word);
		p->next = NULL;
		p->prev = NULL;
		arithlist->head = p;
		arithlist->tail = p;
	}
	else
	{
		ListNode *p = NULL;
		p = malloc(sizeof(ListNode));
		strcpy(p->word, word);
		p->next = NULL;
		p->prev = arithlist->tail;
		(arithlist->tail)->next = p;
		arithlist->tail = p;
	}
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
	if(arithlist == NULL)
	{
		fprintf(stderr, "arithlist is NULL.\n");
		return false;
	}
	if((arithlist->head == NULL) || (arithlist->tail == NULL))
	{
		fprintf(stderr, "arithlist is empty.\n");
		return false;
	}
	ListNode *p = NULL;
	p = arithlist->head;
	while((p != ln) && (p != NULL))
	{
		p = p->next;
	}
	if(p == NULL)
	{
		fprintf(stderr, "ln is not in the list.\n");
		return false;
	}
	else
	{
		if(p == arithlist->head)
		{
			if(p == arithlist->tail)
			{
				arithlist->head = NULL;
				arithlist->tail = NULL;
				free(p);
				return true;
			}
			(p->next)->prev = NULL;
			arithlist->head = p->next;
			free(p);
		}
		else if(p == arithlist->tail)
		{
			(p->prev)->next = NULL;
			arithlist->tail = p->prev;
			free(p);
		}
		else
		{
			ListNode *q = NULL;
			q = p->prev;
			q->next = p->next;
			(p->next)->prev = q;
			free(p);
		}
	}
	return true;
}
#endif

