#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_heap - heap from an array.
 * @array: array
 * @size: size
 * Return: 0
 */

heap_t *array_to_heap(int *array, size_t size)
{
	if (array == NULL || size == 0)
	{
		return (NULL);
	}

	heap_t *root = binary_tree_node(NULL, array[0]);
	if (root == NULL)
	{
		return (NULL);
	}
	for (size_t i = 1; i < size; i++)
	{
		heap_insert(&root, array[i]);
	}

	return (root);
}
