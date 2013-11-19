/*
 *
 *
 *  AUTHOR: PKangu
*/
#ifndef bst
#define bst

/* The tree Node struct, it includes parent node pointer for a faster deleting function */
typedef struct tree_node {
	int value;
	struct tree_node *left_child;
	struct tree_node *right_child;
	struct tree_node *parent;
} tree_node;

/* The tree struct, it has only the root Node pointer */
typedef struct search_tree {
	tree_node *root;
} binary_search_tree;

/* Dinamically declare a new node in the Heap and returns the pointer to that memory address */
tree_node* new_node(int value);
/* Dinamically declare a new tree in the Heap and returns the pointer to that memory address */
binary_search_tree* new_bst(tree_node *root);

/*
 * Inserts a Node into a tree starting from the given root node
 * 
 * @param *root: the starting node where to insert the new one
 * @param *node: the new node that has to be inserted
*/
void insert_node (tree_node *root, tree_node *node);
/*
 * Simply delete the node with the given value searching it into the given tree root
 *
 * @param *root: the node from which starts the research of the node with given value
 * @param to_delete: the value of the node that has to be deleted 
*/
void delete_node (tree_node *root, int to_delete);
/*
 * Find the node with the minimum value starting from a given node
 * 
 * @param *root: the root node from which starting the researh
 * 
 * RETURNS: the node with the minimum value founded
*/
tree_node* find_min(tree_node *root);
/*
 * Find the node with the maximum value starting from a given node
 * 
 * @param *root: the root node from which starting the researh
 * 
 * RETURNS: the node with the maximum value founded
*/
tree_node* find_max(tree_node * root);
/*
 * Find the node with the given value starting from a given node
 * 
 * @param *root: the root node from which starting the researh
 * @param to_search: the value of the node that has to be founded
 * 
 * RETURNS: the node with the given value if exists or NULL
*/
tree_node* find_node(tree_node *root, int to_search);

/* Displays a node in a linear way */
void display_node(tree_node *node);
/* Displays a tree from the given node (the root is shown before ordering)*/
void display_pre_order(tree_node *root);
/* Displays a tree from the given node (the root is shown after ordering)*/
void display_post_order(tree_node *root);
/* Displays a tree from the given node (the root is shown in the middle of ordering)*/
void display_in_order(tree_node *root);

#endif
