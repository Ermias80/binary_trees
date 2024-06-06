#include "binary_trees.h"

/**
 * tree_creator - Builds an AVL tree from a sorted array.
 * @parent: The AVL tree's parent node
 * @array: The sorted array of integers
 * @size: The number of element in the array
 * Return: A pointer to the root node of the created AVL tree, otherwise NULL
 */
avl_t *tree_creator(avl_t *parent, int *array, int size)
{
	int *left_array = NULL, *right_array = NULL;
	int size_l = 0, size_r = 0, len = 0;
	avl_t *p = NULL, *l = NULL, *r = NULL;

	if ((size > 0) && (array != NULL))
	{
		p = malloc(sizeof(avl_t));
		if (p != NULL)
		{
			len = size - 1;
			size_l = (len / 2);
			size_r = len - (len / 2);
			if (size_l > 0)
			{
				left_array = array;
				l = tree_creator(p, left_array, size_l);
			}
			if (size_r > 0)
			{
				right_array = array + size_l + 1;
				r = tree_creator(p, right_array, size_r);
			}
			p->parent = parent;
			p->left = l;
			p->right = r;
			p->n = *(array + (size / 2) - (size % 2 == 0 ? 1 : 0));
		}
	}
	return (p);
}

/**
 * sorted_array_to_avl - A function that builds an AVL tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 * Return: A pointer to the root node of the created AVL tree, otherwise NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array != NULL)
	{
		root = tree_creator(root, array, (int)size);
	}
	return (root);
}
