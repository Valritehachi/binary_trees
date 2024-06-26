#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Entry point
 * @parent: ...
 * @value: ...
 * Return: Always 0 (Success)
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (node == NULL)
	{
		return (NULL);
	}
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;
	return (node);
}
