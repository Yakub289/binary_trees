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

/**
 * binary_tree_height - A function that measures the height of a binary tree.
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: 0 If tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_is_perfect - Checks if the binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if excellent, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);
	l = tree->left;
	r = tree->right;
	if (binary_tree_leaves(tree))
		return (1);
	if (l == NULL || r == NULL)
		return (0);
	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
