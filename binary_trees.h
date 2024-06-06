#ifndef BINARY_TREES_H
#define BINARY_TREES_H
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Represents a binary tree node.
 * @n: Integer stored in the node.
 * @parent: Pointer to the parent node.
 * @left: Pointer to the left child node.
 * @right: Pointer to the right child node.
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *dequeue_i(binary_tree_t **queue_h,
	binary_tree_t **queue_t, int *n);
void enqueue_i(binary_tree_t **queue_h, binary_tree_t **queue_t,
	int *n, void *i);
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *dequeue_i1(binary_tree_t **queue_h,
	binary_tree_t **queue_t, int *n);
void enqueue_i1(binary_tree_t **queue_h, binary_tree_t **queue_t,
	int *n, void *i);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst_checker(const binary_tree_t *tree, int low, int high);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
size_t tree_height2(const binary_tree_t *tree);
int is_avl_valid(const binary_tree_t *tree, int low, int high);
void tree_height(const binary_tree_t *tree, int n, int *height);
avl_t *avl_insert(avl_t **tree, int value);
void fix_balance(avl_t **root, avl_t *node);
int tree_height_1(const binary_tree_t *tree);
bst_t *bst_insert_node(bst_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
void fix_balance_1(avl_t **root, avl_t *node);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *tree_creator(avl_t *parent, int *array, int size);
int binary_tree_is_heap(const binary_tree_t *tree);
int check_parent(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int tree_is_complete(const binary_tree_t *tree, int i, int num_codes);
size_t binary_tree_size(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_size(const binary_tree_t *tree);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
void enqueue_i_4(heap_t **queue_h, heap_t **queue_t,
	int *n, void *item);
heap_t *dequeue_i_4(heap_t **queue_h,
	heap_t **queue_t, int *n);
heap_t *find_last_heap_node(const heap_t *root);
void swap_tree_node_with_parent_1(heap_t **node, heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
