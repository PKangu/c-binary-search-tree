/*
 *
 *
 * AUTHOR: PKangu
 * THANKS TO: everlastingfire FOR: code testing and bug warnings
*/

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/*-----------private methods-----------*/

/*
 * drops the given node from his parent if exists
 *
 * param *deleting: the node that has to be dropped
*/
void start_deleting(tree_node *deleting) {
	if (deleting->parent) {
		if (deleting->parent->left_child) {
			if (deleting->parent->left_child->value == deleting->value) {
				deleting->parent->left_child = NULL;
			}
		} 
		if (deleting->parent->right_child) {
			if (deleting->parent->right_child->value == deleting->value) {
				deleting->parent->right_child = NULL;
			}
		}
	}
	
}

/*-----------public methods------------*/

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
	tree_node *deleting = find_node(root, to_delete);
	if (deleting) {
		if (deleting->left_child != NULL && deleting->right_child != NULL) {
			tree_node *temp = find_min(deleting->right_child);
			deleting->value = temp->value;
			start_deleting(temp);
			if (temp->right_child) {
				insert_node(temp->parent, temp->right_child);
			}
			free(temp);
			
		} else {
			start_deleting(deleting);
			if (deleting->right_child == NULL && deleting->left_child != NULL) {
				printf("deleting with left_child\n");
				insert_node(deleting->parent, deleting->left_child);
			} else if (deleting->left_child == NULL && deleting->right_child != NULL){
				printf("deleting with right_child\n");
				insert_node(deleting->parent, deleting->right_child);
			}
			free(deleting);
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

tree_node* find_node(tree_node *root, int to_search) {
	if (to_search == root->value) {
		return root;
	} else if (to_search < root->value) {
		return find_node(root->left_child, to_search);
	} else if (to_search > root->value) {
		return find_node(root->right_child, to_search);
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
