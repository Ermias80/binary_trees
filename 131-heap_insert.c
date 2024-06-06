#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the tree to be measured
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * heap_insert- a function that inserts a value in Max Binary Heap
 * @root: A double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_nodes, *invert;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_nodes = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_nodes) : (tree->left = new_nodes);

	invert = new_nodes;
	for (; invert->parent && (invert->n > invert->parent->n)
			; invert = invert->parent)
	{
		tmp = invert->n;
		invert->n = invert->parent->n;
		invert->parent->n = tmp;
		new_nodes = new_nodes->parent;
	}

	return (new_nodes);
}
