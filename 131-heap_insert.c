#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - inserts a value.
 * @root: root
 * @value: value
 * Return: 0
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
	{
		return (NULL);
	}
	if (!(*root))
	{
		return (*root = binary_tree_node(NULL, value));
	}
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - ..
 * @tree: tree.
 * Return: 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
