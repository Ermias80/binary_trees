#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if the given node is a leaf node
 *
 * @node: A pointer to the node to be checked
 *
 * Return: 1 if node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
