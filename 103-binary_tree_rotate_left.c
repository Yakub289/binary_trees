#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - A function that performs
 * a left-rotation on a binary tree.
 * @tree: is a pointer to the root node of the tree to rotate.
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *aux, *temp;

	if (tree == NULL)
	{
		return (NULL);
	}
	else
		if (tree->right)
		{
			temp = tree->right->left;
			aux = tree->right;
			aux->parent = tree->parent;
			aux->left = tree;
			tree->parent = aux;
			tree->right = temp;
			{
				if (temp)
				{
					temp->parent = tree;
				}
				return (aux);
			}
		}
	return (NULL);
}
