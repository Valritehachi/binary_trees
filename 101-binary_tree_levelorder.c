#include <stdlib.h>
#include "binary_trees.h"

/**
 * struct levelorder_queue_s - .. 
 * @node: node
 * @next: next
 * Return: 0.
 */
typedef struct levelorder_queue_s
{
	struct binary_tree_s *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

/**
 * create_node - ....
 * @node: node.
 * Return: 0.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - ....
 * @head: head.
 * Return: 0.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pint_push - ...
 * @node: node.
 * @head: head.
 * @tail: tail.
 * @func: function.
 * Return: 0.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t **head,
               levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(*head);
			exit(1);
		}
		if (*tail == NULL)
		{
			*head = new;
		}
		else
		{
			(*tail)->next = new;
			*tail = new;
		}
	}
		if (node->right != NULL)
		{
			new = create_node(node->right);
			if (new == NULL)
			{
				free_queue(*head);
				exit(1);
			}
			if (*tail == NULL)
			{
				*head = new;
			}
			else
			{
				(*tail)->next = new;
				*tail = new;
			}
		}
}

/**
 * binary_tree_levelorder - ....
 * @tree: tree.
 * @func: function.
 * Return: 0.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head = NULL, *tail = NULL;

	if (tree == NULL || func == NULL)
	{
		return;
	}

	pint_push((binary_tree_t *)tree, &head, &tail, func);
	while (head != NULL)
	{
		pint_push(head->node, &head, &tail, func);
		head = head->next;
	}

	free_queue(head);
}
