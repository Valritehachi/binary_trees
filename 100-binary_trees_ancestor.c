#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - .. 
 * @first: ..
 * @second: ..
 * Return: 0
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
	{
		return NULL;
	}

	ancestor = find_common_ancestor(first, second);
	return (binary_tree_t *)ancestor;
}

/**
 * find_common_ancestor - ..
 * @node: ..
 * @first: ..
 * @second: ..
 * Return: ...
 */
const binary_tree_t *find_common_ancestor(const binary_tree_t *node, const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *left, *right;

	if (node == NULL || first == NULL || second == NULL)
	{
		return NULL;
	}

	if (node == first || node == second)
	{
		return node;
	}

	left = find_common_ancestor(node->left, first, second);

	right = find_common_ancestor(node->right, first, second);

	if (left && right)
	{
		return node;
	}

	return (left != NULL) ? left : right;
}
