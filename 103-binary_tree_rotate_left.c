#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates.
 * @tree: tree .
 * Return: 0
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pivot = tree->right;
	tmp = pivot->left;
	pivot->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
	{
		tmp->parent = tree;
	}
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
		{
			tmp->left = pivot;
		}
		else
		{
			tmp->right = pivot;
		}
	}

	return (pivot);
}
