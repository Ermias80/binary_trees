#include "binary_trees.h"

/**
 * array_to_avl - A function that builds an AVL root from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 * Return: A pointer to the root node of the created AVL root, NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&root, array[i]) == NULL)
				return (NULL);
		}
	}

	return (root);
}
