#include "binary_trees.h"

/**
 * is_bst_checker - Checks if a binary tree is a valid binary search tree
 * @tree: A pointer to the root node of the tree to check
 * @low: The value of the smallest node visited thus far
 * @high: The value of the largest node visited this far
 * Return: If the tree is a valid BST, 1, otherwise, 0
 */
int is_bst_checker(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (is_bst_checker(tree->left, low, tree->n - 1) &&
			is_bst_checker(tree->right, tree->n + 1, high));
	}

	return (1);
}

/**
 * binary_tree_is_bst - A function that checks if a binary tree
 * is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_checker(tree, INT_MIN, INT_MAX));
}
