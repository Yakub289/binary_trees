#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * height_range - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height ranges or 0 if tree is NULL
 */
size_t height_range(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + height_range(tree->left);

	if (tree->right)
		height_right = 1 + height_range(tree->right);

	return (height_left + height_right);
}

/**
 * heap_to_sorted_array - A function that converts a Binary Max Heap,
 * to a sorted array of integers.
 * @heap: is a pointer to the root node of the heap to convert.
 * @size: is an address to store the size of the array.
 * Return: array must be sorted in descending order or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *age = NULL;

	if (!heap || !size)
		return (NULL);

	*size = height_range(heap) + 1;

	age = malloc(sizeof(int) * (*size));

	if (!age)
		return (NULL);

	for (i = 0; heap; i++)
		age[i] = heap_extract(&heap);

	return (age);
}
