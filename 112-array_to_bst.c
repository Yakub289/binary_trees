#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * array_to_bst - A function that builds a Binary Search Tree from an array.
 * @array: is a pointer to the first element of the array to be converted.
 * @size: is the number of element in the array.
 * Return: a pointer to the root node of the created BST, or NULL on failure.
 * If a value of the array is already present in the tree.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t index_value;

	if (array == NULL)
	{
		return (NULL);
	}

	tree = NULL;
	for (index_value = 0; index_value < size; index_value++)
	{
		bst_insert(&tree, array[index_value]);
	}
	return (tree);
}
