#include "binary_trees.h"

/**
 * tree_height2 - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, your function must return 0, else return height
 */
size_t tree_height2(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + tree_height2(tree->left) : 1;
		r = tree->right ? 1 + tree_height2(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_valid - Checks if a binary tree is a valid AVL tree
 * @tree: A pointer to the root node of the tree to check
 * @low: The value of the smallest node visited thus far
 * @high: The value of the largest node visited thighs far
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0
 */
int is_avl_valid(const binary_tree_t *tree, int low, int high)
{
	size_t left_ht, right_ht, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		left_ht = tree_height2(tree->left);
		right_ht = tree_height2(tree->right);
		diff = left_ht > right_ht ? left_ht - right_ht : right_ht - left_ht;
		if (diff > 1)
			return (0);
		return (is_avl_valid(tree->left, low, tree->n - 1) &&
			is_avl_valid(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - A function that checks if a binary
 * tree is a valid AVL Tree
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_valid(tree, INT_MIN, INT_MAX));
}
