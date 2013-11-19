/*
 *
 *
 *  AUTHOR: PKangu
*/

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


tree_node* new_node(int value) {
	tree_node *n = malloc(sizeof(tree_node));
	n->value = value;
	n->right_child  = NULL;
	n->left_child = NULL;
	n->parent = NULL;
	return n;
}

binary_search_tree* new_bst(tree_node *root) {
	binary_search_tree *tree = malloc(sizeof(binary_search_tree));
	tree->root = root;
	return tree;
}

void insert_node (tree_node *root, tree_node *node) {
	
	if (node->value > root->value) {
		if (root->right_child != NULL) {
			insert_node(root->right_child, node);
		} else {
			root->right_child = node;
			node->parent = root;
		}
	} else if (node->value < root->value) {
		if (root->left_child != NULL) {
			insert_node(root->left_child, node);
		} else {
			root->left_child = node;
			node->parent = root;
		}
	}
}

void delete_node(tree_node *root, int to_delete) {
	
	if (to_delete > root->value) {
		delete_node(root->right_child, to_delete);
	} else if (to_delete < root->value) {
		delete_node(root->left_child, to_delete);
	} else {
		printf("trovato!");
		if (root->left_child != NULL && root->right_child != NULL) {
			tree_node *temp = root->right_child;
			temp = find_min(temp);
			root->value = temp->value;
			temp->parent->left_child = NULL;
			free(temp);
			
		} else if (root->right_child == NULL) {
			root->value = root->left_child->value;
			free(root->left_child);
			root->left_child = NULL;
		} else {
			root->value = root->right_child->value;
			free(root->right_child);
			root->right_child = NULL;
		}
	}
}

tree_node* find_min(tree_node *root) {
	if (root->left_child == NULL) {
		return root;
	} else {
		return find_min(root->left_child);
	}
}

tree_node* find_max(tree_node *root) {
	if (root->right_child == NULL) {
		return root;
	} else {
		return find_max(root->right_child);
	}
}

tree_node* find_node(tree_node *root, int *to_search) {
	if (*to_search == root->value) {
		return root;
	} else if (*to_search < root->value) {
		return find_node(root->left_child, to_search);
	} else if (*to_search > root->value) {
		return find_node(root->right_child, to_search);
	} else {
		return NULL;
	}
}

void display_node (tree_node *node) {
	int parent = 0;
	if (node->parent != NULL) {
		parent = node->parent->value;
	}
	
	if (node->left_child != NULL && node->right_child != NULL) {
		printf("node %i, %i, %i - %i;\n", node->value, node->left_child->value, node->right_child->value, parent);
	} else if (node->left_child != NULL) {
		printf("node %i, %i, NULL - %i;\n", node->value, node->left_child->value, parent);
	} else if (node->right_child != NULL) {
		printf("node %i, NULL, %i - %i;\n", node->value, node->right_child->value, parent);
	} else {
		printf("node %i, NULL, NULL - %i;\n", node->value, parent);
	}
}

void display_pre_order(tree_node *root) {
	if(root != NULL) {
		display_node(root);
		display_pre_order(root->left_child);
		display_pre_order(root->right_child);
	}
}

void display_post_order(tree_node *root) {
	if(root != NULL) {
		display_pre_order(root->left_child);
		display_pre_order(root->right_child);
		display_node(root);
	}
}

void display_in_order(tree_node *root) {
	if(root != NULL) {
		display_pre_order(root->left_child);
		display_node(root);
		display_pre_order(root->right_child);
	}
}
