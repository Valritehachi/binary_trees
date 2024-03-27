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
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
