#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * cycle - A function that examines the hiearchary
 * @tree:  is a pointer to the root node of the tree to check.
 * Return: 1 if all nodes cycle is check completely, 0 in other cases.
 */
int cycle(const binary_tree_t *tree)
{
	int tmp1 = 1, tmp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tmp1 = cycle(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tmp2 = cycle(tree->right);
	}
	return (tmp1 && tmp2);
}

/**
 * binary_tree_is_complete - A function that checks,
 * if a binary tree is complete.
 * @tree: is a pointer to the root node of the tree to check.
 * Return: 0 on success if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	left = tree->left;
	right = tree->right;
	l_height = binary_tree_height(left);
	r_height = binary_tree_height(right);
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(left) &&
				binary_tree_is_complete(right))
		{
			return (1);
		}
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(left) &&
				binary_tree_is_perfect(right))
		{
			return (1);
		}
	}
	return (0);
}

/**
 * binary_tree_is_heap - A function that checks if a binary tree is a
 * valid Max Binary Heap.
 * @tree: is a pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 * 0 If tree is NULL.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);
	return (cycle(tree));
}
