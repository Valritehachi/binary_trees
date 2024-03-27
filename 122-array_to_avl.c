#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_avl - ...
 * @array: array.
 * @size: size.
 * Return: 0.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
			{
				break;
			}
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
			{
				return (NULL);
			}
		}
	}

	return (tree);
}
