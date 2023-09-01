#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * array_to_heap - A function that builds a Max Binary Heap tree from an array
 * @array: is a pointer to the first element of the array to be converted.
 * @size: is the number of element in the array.
 * Return: a pointer to the root node of the created Binary Heap,
 * or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int heap;
	heap_t *root = NULL;

	for (heap = 0; heap < size; heap++)
		heap_insert(&root, array[heap]);

	return (root);
}
