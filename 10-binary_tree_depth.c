#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - A function that measures the depth,
 * of a node in a binary tree.
 * @tree: is a pointer to the node to measure the depth.
 * Return: 0 If tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
	{
		return (0);
	}
	else
	{
		return (1 + binary_tree_depth(tree->parent));
	}
}
