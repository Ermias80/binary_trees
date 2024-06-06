#include "binary_trees.h"

/**
 * smallest_value - Gets the smallest_value node
 * @node: Tree which will contains value
 * Return: Node with the smallest value
 */
static bst_t *smallest_value(bst_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->left == NULL)
		return (node);
	return (smallest_value(node->left));
}

/**
 * remove_node - Removes a value from a binary search tree
 * @root: Tree which will contains value
 * @value: Value of node to removed
 * Return: The parent node
 */
static bst_t *remove_node(bst_t **root, int value)
{
	bst_t *node = *root, *parent = NULL, **p_link, *new, *p_node = NULL;

	while (node != NULL)
	{
		if (node->n == value)
		{
			parent = node->parent, p_node = parent;
			p_link = parent == NULL ? root : parent->n > node->n ? &parent->left
																													: &parent->right;
			if (node->right == NULL && node->left == NULL)
				*p_link = NULL;
			else if (node->right == NULL)
				*p_link = node->left, node->left->parent = node->parent;
			else if (node->left == NULL)
				*p_link = node->right, node->right->parent = node->parent;
			else
			{
				new = smallest_value(node->right);
				if (new == node->right)
					*p_link = new, new->parent = node->parent, p_node = node->parent,
					new->left = node->left, new->left->parent = new;
				else
				{
					new->parent->left = new->right, p_node = new->parent;
					if (new->right)
						new->right->parent = new->parent;
					*p_link = new, new->parent = parent, new->left = node->left;
					if (new->left)
						new->left->parent = new;
					new->right = node->right;
					if (new->right)
						new->right->parent = new;
				}
			}
			free(node);
			break;
		}
		node = value > node->n ? node->right : node->left;
	}
	return (p_node);
}

/**
 * fix_balance_1 - Fixs the balance of an AVL tree by
 * rotating the unbalanced subtree
 * @root: A pointer to the address of the root of the tree
 * @node: A pointer to the inserted node
 */
void fix_balance_1(avl_t **root, avl_t *node)
{
	avl_t *curr = node, *new_root = *root;
	int balance = 0;

	while (curr != NULL)
	{
		balance = binary_tree_balance(curr);
		if (!((balance >= -1) && (balance <= 1)))
		{
			if ((balance == 2) && ((binary_tree_balance(curr->left) == 1)
				|| (binary_tree_balance(curr->left) == 0)))
			{
				new_root = binary_tree_rotate_right(curr);
			}
			else if ((balance == 2) && (binary_tree_balance(curr->left) == -1))
			{
				curr->left = binary_tree_rotate_left(curr->left);
				new_root = binary_tree_rotate_right(curr);
			}
			else if ((balance == -2) && ((binary_tree_balance(curr->right) == -1)
				|| (binary_tree_balance(curr->right) == 0)))
			{
				new_root = binary_tree_rotate_left(curr);
			}
			else if ((balance == 2) && (binary_tree_balance(curr->left) == -1))
			{
				curr->right = binary_tree_rotate_right(curr->right);
				new_root = binary_tree_rotate_left(curr);
			}
			new_root = (curr == *root ? new_root : *root);
			break;
		}
		curr = curr->parent;
	}
	*root = new_root;
}

/**
 * avl_remove - A function that removes a node from an AVL tree
 * @root: A pointer to the root node of the tree for removing a node
 * @value: The value of the node to be removed
 *
 * Return: The new root node, otherwise NULL.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node = NULL, *new_root = root, *new_node = NULL, *parent = NULL;

	if (new_root != NULL)
	{
		(void)node;
		(void)new_node;
		parent = remove_node(&new_root, value);
		fix_balance_1(&new_root, parent);
	}
	return (new_root);
}
