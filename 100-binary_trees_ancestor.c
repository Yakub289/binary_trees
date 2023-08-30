#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - A function that finds the lowest
 * common ancestor of two nodes.
 * @first: is a pointer to the first node.
 * @second: is a pointer to the second node.
 * Return: NULL If no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *linage;

	if (!first || !second)
	{
		return (NULL);
	}

	linage = (binary_tree_t *) second;
	while (first)
	{
		while (second)
		{
			if (first == second)
			{
				return ((binary_tree_t *) first);
			}
			second = second->parent;
		}
		second = linage;
		first = first->parent;
	}
	return (NULL);
}
