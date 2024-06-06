#include "binary_trees.h"

/**
 * binary_trees_ancestor -  A function that finds the lowest
 * common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 * Return: A pointer to the lowest common ancestor node of the two given nodes,
 * NULL If no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *nd1, *nd2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	nd1 = first->parent, nd2 = second->parent;
	if (first == nd2 || !nd1 || (!nd1->parent && nd2))
		return (binary_trees_ancestor(first, nd2));
	else if (nd1 == second || !nd1 || (!nd2->parent && nd1))
		return (binary_trees_ancestor(nd1, second));

	return (binary_trees_ancestor(nd1, nd2));
}
