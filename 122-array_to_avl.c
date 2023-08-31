#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * array_to_avl - A function that builds an AVL tree from an array.
 * @array: is a pointer to the first element of the array to be converted.
 * @size: is the number of element in the array.
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure;
 * If a value of the array is already present in the tree,
 * this value must be ignored.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t ink;
	size_t jar;

	if (array == NULL)
	{
		return (NULL);
	}

	for (ink = 0; ink < size; ink++)
	{
		for (jar = 0; jar < ink; jar++)
		{
			if (array[jar] == array[ink])
				break;
		}
		if (jar == ink)
		{
			if (avl_insert(&tree, array[ink]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (tree);
}
