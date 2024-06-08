#ifndef BINARY_SEARCH_TREE_C___BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_C___BINARY_SEARCH_TREE_HPP

#include <iostream>
using namespace std;

typedef int key_node;

class BST_node {
private:
	BST_node *left_node, *right_node;
	key_node info;
public:
	BST_node(key_node i = 0) : info(i), left_node(nullptr), right_node(nullptr) {}
	void set_info(key_node info) {
		this->info = info;
	}

	key_node get_info() {
		return this->info;
	}

	void display_info() {
		cout << this->get_info() << endl;
	}

	void set_left_node(BST_node *left_pointer) {
		this->left_node = left_pointer;
	}

	void set_right_node(BST_node *right_pointer) {
		this->right_node = right_pointer;
	}

	BST_node *get_left_node() {
		return this->left_node;
	}

	BST_node *get_right_node() {
		return this->right_node;
	}
};

class BSTree {
private:
	BST_node *root;
public:
	BSTree() : root(nullptr) {}

	BSTree(key_node i) {
		this->root = new BST_node(i);
	}

	BSTree(key_node i, BST_node* &pointer);
	void deleteBST(BST_node *pointer);

	void deleteBST();
	~BSTree() {
		deleteBST();
	}

	BST_node *get_BST_root() {
		return this->root;
	}

	void display_preorder(BST_node *pointer);
	void display_inorder(BST_node *pointer);
	void display_postorder(BST_node *pointer);
	BST_node *binary_search(key_node i, BST_node *pointer);
	BST_node *add_node(key_node i, BST_node *pointer);
};

#endif //BINARY_SEARCH_TREE_C___BINARY_SEARCH_TREE_HPP
