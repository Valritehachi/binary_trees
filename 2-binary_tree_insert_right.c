#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right -... 
 * @parent: Pointer
 * @value: value
 * Return: 0 
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	if (parent->right != NULL)
	{
		node->right = parent->right;
		node->right->parent = node;
	}
    
	parent->right = node;

	return (node);
}
