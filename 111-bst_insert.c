#include "binary_trees.h"

/**
 * bst_insert -  A function that inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, otherwise NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent, *new_node;

	if (tree != NULL)
	{
		parent = *tree;
		if (parent == NULL)
		{
			new_node = binary_tree_node(parent, value);
			if (new_node == NULL)
				return (NULL);
			return (*tree = new_node);
		}
		if (value < parent->n)
		{
			if (parent->left != NULL)
				return (bst_insert(&parent->left, value));
			new_node = binary_tree_node(parent, value);
			if (new_node == NULL)
				return (NULL);
			return (parent->left = new_node);
		}
		if (value > parent->n)
		{
			if (parent->right != NULL)
				return (bst_insert(&parent->right, value));
			new_node = binary_tree_node(parent, value);
			if (new_node == NULL)
				return (NULL);
			return (parent->right = new_node);
		}
	}

	return (NULL);
}
