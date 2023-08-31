#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * bst_search - A function that searches for a value in a Binary Search Tree.
 * @tree: is a pointer to the root node of the BST to search.
 * @value: is the value to search in the tree.
 * Return: a pointer to the node containing a value equals to value,
 * If tree is NULL or if nothing is found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
		{
			return ((bst_t *)tree);
		}
		else if (tree->n > value)
		{
			return (bst_search(tree->left, value));
		}
		else
		{
			return (bst_search(tree->right, value));
		}
	}
	return (NULL);
}
