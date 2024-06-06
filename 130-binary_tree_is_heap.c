#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Root of the binary tree
 * Return: Size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - Checks if tree is complete
 * @tree: Pointer to the tree root.
 * @i: Index of the node
 * @num_codes: Number of nodes
 * Return: 1 if tree is complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int i, int num_codes)
{
	if (tree == NULL)
		return (1);

	if (i >= num_codes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, num_codes) &&
		tree_is_complete(tree->right, (2 * i) + 2, num_codes));
}

/**
 * binary_tree_is_complete - Calls to tree_is_complete function
 * @tree: Root of the binary tree
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t num_codes;

	if (tree == NULL)
		return (0);

	num_codes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, num_codes));
}

/**
 * check_parent - Checks if parent has a greater value than its childs
 * @tree: A pointer to the  parent node to be checked
 * Return: 1 if parent has a greater value, 0 otherwise
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - A function that checks if a binary
 * tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to be checked
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
