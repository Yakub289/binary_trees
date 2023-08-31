#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * greater_than - Checks if all values in the tree are greater than a value
 * @tree: is a pointer to the tree to check subtree.
 * @value: value to check against greater than subtree.
 * Return: 1 if true or 0 if false.
 */
int greater_than(const binary_tree_t *tree, int value)
{
	int left, right;

	if (tree == NULL)
	{
		return (1);
	}
	else
		if (tree->n > value)
		{
			left = greater_than(tree->left, value);
			right = greater_than(tree->right, value);
			{
				if (left && right)
				{
					return (1);
				}
			}
		}
	return (0);
}

/**
 * less_than - Checks if all values in the tree are less than a specific value
 * @tree:is a pointer to the tree to check the subtree.
 * @value: value to check against a subtree.
 * Return: 1 if true or 0 if false.
 */
int less_than(const binary_tree_t *tree, int value)
{
	int left, right;

	if (tree == NULL)
	{
		return (1);
	}
	else
		if (tree->n < value)
		{
			left = less_than(tree->left, value);
			right = less_than(tree->right, value);
			{
				if (left && right)
				{
					return (1);
				}
			}
		}
	return (0);
}

/**
 * binary_tree_is_bst - a function that checks if a binary tree is a valid
 * Binary Search Tree.
 * @tree:  is a pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, otherwise 0
 * 0 if tree is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (less_than(tree->left, tree->n) && greater_than(tree->right, tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
			{
				return (1);
			}
		}

	}
	return (0);
}
