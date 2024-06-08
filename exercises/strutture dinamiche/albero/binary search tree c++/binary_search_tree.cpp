#include "binary_search_tree.hpp"

BSTree::BSTree(key_node i, BST_node *&pointer) {
	pointer = new BST_node(i);
}

void BSTree::deleteBST(BST_node *pointer) {
	if (pointer == nullptr)
		return;
	deleteBST(pointer->get_left_node());
	deleteBST(pointer->get_right_node());
	delete pointer;
}

void BSTree::deleteBST() {
	deleteBST(this->root);
}

void BSTree::display_preorder(BST_node *pointer) {
	if (pointer == nullptr)
		return;
	pointer->display_info();
	display_preorder(pointer->get_left_node());
	display_preorder(pointer->get_right_node());
}

void BSTree::display_inorder(BST_node *pointer) {
	if (pointer == nullptr)
		return;
	display_inorder(pointer->get_left_node());
	pointer->display_info();
	display_inorder(pointer->get_right_node());
}

void BSTree::display_postorder(BST_node *pointer) {
	if (pointer == nullptr)
		return;
	display_postorder(pointer->get_left_node());
	display_postorder(pointer->get_right_node());
	pointer->display_info();
}

BST_node *BSTree::binary_search(key_node i, BST_node *pointer) {
	if (pointer == nullptr)
		return nullptr;
	else {
		if (i == pointer->get_info())
			return pointer;     /* trovato */
		if (i < pointer->get_info())
			return binary_search(i, pointer->get_left_node());
		else
			return binary_search(i, pointer->get_right_node());
	}
}

BST_node *BSTree::add_node(key_node i, BST_node *pointer) {
	if (pointer == nullptr)
		BSTree(i, pointer);
	else {
		if (i <= pointer->get_info()) {
			if (pointer->get_left_node() == nullptr)
				pointer->set_left_node(new BST_node(i));    /* inserisce nodo come figlio sinistro */
			else
				pointer->set_left_node(add_node(i, pointer->get_left_node()));
		} else {
			if (pointer->get_right_node() == nullptr)
				pointer->set_right_node(new BST_node(i));    /*inserisce nodo come figlio destro */
			else
				pointer->set_right_node(add_node(i, pointer->get_right_node()));
		}
	}
	return pointer;
}
