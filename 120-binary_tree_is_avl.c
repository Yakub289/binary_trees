#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"


/**
 * girth - Measures the girth of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the girth.
 * Return: If tree is NULL, your function must return 0, else return girth.
 */
size_t girth(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + girth(tree->left) : 1;
		r = tree->right ? 1 + girth(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_checker - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_checker(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = girth(tree->left);
		rhgt = girth(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_checker(tree->left, lo, tree->n - 1) &&
			is_avl_checker(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - A function that checks;
 * if a binary tree is a valid AVL tree.
 * @tree: is a pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise,
 * 0 If tree is NULL.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_checker(tree, INT_MIN, INT_MAX));
}
