#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * order - A function taht sort the array of the elemetn in order
 * @parent: parent of the node to create
 * @array: sorted array
 * @first: position where the array starts
 * @last: position where the array ends
 * Return: tree created
 */
avl_t *order(avl_t *parent, int *array, int first, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int middle = 0;

	if (first <= last)
	{
		middle = (first + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[middle]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = order(root, array, first, middle - 1);
		root->right = order(root, array, middle + 1, last);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - A function that builds an AVL tree from an array.
 * @array: is a pointer to the first element of the array to be converted.
 * @size: is the number of element in the array.
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (order(NULL, array, 0, ((int)(size)) - 1));
}
