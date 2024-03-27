#include <stdlib.h>
#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - ...
 * @tree: tree .
 * @lo: ...
 * @hi: ....
 * Return: 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
		{
			return (0);
		}
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - ...
 * @tree: tree to check.
 * Return: 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
