#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts node as right-child.
 * @parent: Parent
 * @value: value.
 * Return: node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (parent == NULL)
	{
		return (NULL);
	}

	if (node == NULL)
	{
		return (NULL);
	}

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	if (parent->right != NULL)
	{
		binary_tree_t *child = parent->right;
		child->parent  = node;
		node->right = child;

		node->parent = parent;
		parent->right = node;
	}
	else
	{
		node->parent = parent;
		parent->left = node;
	}

	return (node);
}

