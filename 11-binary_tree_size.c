#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_size - A function that measures the size of a binary tree.
 * @tree:is a pointer to the root node of the tree to measure the size.
 * Return: 0 on success if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_bt = 0;

	if (tree)
	{
		size_bt += 1;
		size_bt += binary_tree_size(tree->left);
		size_bt += binary_tree_size(tree->right);
	}
	return (size_bt);
}
