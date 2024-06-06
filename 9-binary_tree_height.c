#include "binary_trees.h"

/**
 * binary_tree_height - A function that measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lft = 0, rght = 0;

		lft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rght = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((lft > rght) ? lft : rght);
	}

	return (0);
}
