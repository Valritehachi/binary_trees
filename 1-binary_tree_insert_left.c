#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Entry point
 * @parent: ...
 * @value: ...
 * Return: Always 0 (Success)
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
	{
		return (NULL);
	}

	node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (node == NULL)
	{
		return (NULL);
	}
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	if (parent->left != NULL)
	{
		binary_tree_t *child = parent->left;

		child->parent  = node;
		node->left = child;

		node->parent = parent;
		parent->left = node;
	}
	else
	{
		node->parent = parent;
		parent->left = node;
	}
	return (node);
}
