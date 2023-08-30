#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_height - A function that measures the height of a binary tree.
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: 0 If tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (tree)
	{
		height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((height_l > height_r) ? height_l : height_r);
	}
	return (0);
}

/**
 * print_lineage - print node, especific level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * @level: level to print
 */
void print_lineage(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_lineage(tree->left, func, level - 1);
			print_lineage(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder - A function that goes through
 * a binary tree using level-order traversal.
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t parental = 0, maternal = 1;

	if (tree && func)
	{
		parental = binary_tree_height(tree);
		while (maternal <= parental + 1)
		{
			print_lineage(tree, func, maternal);
			maternal++;
		}
	}

}
