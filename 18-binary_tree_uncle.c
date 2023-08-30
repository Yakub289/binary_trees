#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - A function that finds the uncle of a node.
 * @node:  is a pointer to the node to find the uncle.
 * Return: pointer to the uncle node
 * NULL if node is NULL
 * NULL if the parent is NULL
 * NULL if the node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
	{
		return (NULL);
	}
	else
		if (node->parent->parent->left == node->parent)
		{
			return (node->parent->parent->right);
		}
	return (node->parent->parent->left);
}
