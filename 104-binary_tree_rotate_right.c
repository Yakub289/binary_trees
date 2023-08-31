#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - A function that performs
 * a right-rotation on a binary tree.
 * @tree: is a pointer to the root node of the tree to rotate.
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *aux, *temp;

	if (tree == NULL)
	{
		return (NULL);
	}
	else
		if (tree->left)
		{
			temp = tree->left->right;
			aux = tree->left;
			aux->parent = tree->parent;
			aux->right = tree;
			tree->parent = aux;
			tree->left = temp;
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
