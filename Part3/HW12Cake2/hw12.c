// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw12.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode *Node_construct(int v)
{
	ListNode *p = malloc(sizeof(ListNode));
	p -> value = v;
	p -> next = NULL;
	return p;
}

ListNode *List_insert(ListNode * head, int v)
{
	ListNode *p;
	p = Node_construct(v);
	p -> next = head;
	return p;
}

ListNode * createList(int valn)
{
	ListNode *head = NULL;
	for(int i=0; i<valn; ++i)
	{
		head = List_insert(head, valn-(i+1)); 
	}
	return head;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
int List_count(ListNode * head)
{
	int n=0;
	ListNode *p =head;
	while(p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

void eliminate(ListNode * head, int valk)
{
	int left = List_count(head);
	int idx = valk;
	ListNode *p = head;
	while(left != 1)
	{
		while(idx != 1)
		{
			if(p->next == NULL)
			{
				p = head;
				idx --;
			}
			else
			{
				p = p->next;
				idx --;
			}
		}
#ifdef DEBUG
  // this #ifdef ... #endif should be inside the condition *BEFORE* a
  // node' value is printed and it is deleted
		ListNode * todelete = p;
		printListNode (todelete); 
#endif 
		ListNode q = *p;
		printf("%d\n", p->value);
		head = deleteNode(head, p);
#ifdef DEBUG_HW
		printf("After\n");
		printListNode(head);
#endif 
		if(q.next == NULL)
		{
			p = head;
		}
		else
		{
			p = q.next;
		}
		left--;
		idx = valk;
	}
	printf("%d\n", head -> value);

	free(head);
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
	if(head == NULL) return NULL;
	if(todelete == NULL) return head;
	
	ListNode *p = head;
	ListNode *q = head->next;
	if(p == todelete)
	{
		free(p);
#ifdef DEBUG_HW
		printf("Delete first.\n");
		printListNode(q);
#endif 
		return q;
	}
	while(q != todelete )
	{
		if(q == NULL)
		{
			return head;
		}
		p = q;
		q = q->next;
	}
	p->next = q->next;
	free(q);
	
	return head;
}
#endif


