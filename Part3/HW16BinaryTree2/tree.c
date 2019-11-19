// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
//Tree * buildTree(int * inArray, int * postArray, int size)
//{
//}
TreeNode *newNode(int value)
{
    TreeNode *node = malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int *inArray, int inStrt, int inEnd, int value)
{
    for(int i= inStrt; i<=inEnd;++i)
    {
        if(inArray[i] == value)
        {
            return i;
            break;
        }
    }
    fprintf(stderr, "Do not find the value in inArray.\n");
    return 0;
}

TreeNode * buildTreeHelp(int *inArray, int *postArray, int inStrt, int inEnd, int *pIndex)
{
    if(inStrt > inEnd)
    {
        return NULL;
    }

    TreeNode *node = newNode(postArray[*pIndex]);
    (*pIndex)--;

    if(inStrt == inEnd)
    {
        return node;
    }

    int iIndex = search(inArray, inStrt, inEnd, node->value);

    node->right = buildTreeHelp(inArray, postArray, iIndex + 1, inEnd, pIndex);
    node->left = buildTreeHelp(inArray, postArray, inStrt, iIndex - 1, pIndex);

    return node;
}

Tree * buildTree(int * inArray, int * postArray, int size)
{
    int pIndex = size - 1;
    Tree *tree = malloc(sizeof(Tree));
    tree->root = buildTreeHelp(inArray, postArray, 0, size-1, &pIndex);
    return tree;
}

#endif

#ifdef TEST_PRINTPATH
/*
TreeNode * Tree_search(TreeNode *tn, int val)
{
	if(tn == NULL)
	{
		return NULL;
	}
	if((tn->value) == val)
	{
		return tn;
	}
	if((tn->value) > val)
	{
		return Tree_search(tn->left, val);
	}
	else
	{
		return Tree_search(tn->right, val);
	}
}
*/ 
bool printPathHelp(TreeNode * tn, int val)
{
	if(tn == NULL)
	{
		return false;
	}
	if((tn->value) == val)
	{
		printf("%d\n",tn->value);
		return true;
	}
	if(printPathHelp(tn->left, val))
	{
		printf("%d\n",tn->value);
		return true;
	}
	if(printPathHelp(tn->right, val))
	{
		printf("%d\n",tn->value);
		return true;
	}
	return false;
}
void printPath(Tree * tr, int val)
{
	printPathHelp(tr->root, val);
}
#endif 
