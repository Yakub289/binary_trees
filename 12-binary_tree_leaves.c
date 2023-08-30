#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - A function that counts the leaves in a binary tree.
 * @tree: is a pointer to the root node of the tree,
 * to count the number of leaves.
 * Return: 0 If tree is NULL;NULL pointer is not a leaf.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
		{
			return (1);
		}
		return (binary_tree_leaves(tree->left) +
				binary_tree_leaves(tree->right));
	}
	return (leaves);
}
