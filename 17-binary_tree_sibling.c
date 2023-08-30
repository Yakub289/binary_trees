#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - A function that finds the sibling of a node.
 * @node:is a pointer to the node to find the sibling.
 * Return: pointer to the sibling node,
 * NULL if node is NULL,
 * NULL if the parent is NULL,
 * NULL if the node has no siblings.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	else
		if (node->parent->left == node)
		{
			return (node->parent->right);
		}
	return (node->parent->left);
}
