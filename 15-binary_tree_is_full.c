#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_is_full - A unction that checks if a binary tree is full.
 * @tree: is a pointer to the root node of the tree to check.
 * Return: 0 If tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	else if (!tree->right && !tree->left)
	{
		return (1);
	}
	else
		if (tree->right && tree->left)
		{
			return (binary_tree_is_full(tree->left) &&
					binary_tree_is_full(tree->right));
		}

	return (0);
}
