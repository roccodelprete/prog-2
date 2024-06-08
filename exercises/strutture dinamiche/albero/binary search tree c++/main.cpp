#include "binary_search_tree.hpp"

int main() {
	cout << "BUILD A BINARY SEARCH TREE" << endl;

	BSTree ABR(6);      /* nodo radice */
	BST_node *BST_root = ABR.get_BST_root();

	ABR.add_node(8, BST_root);
	ABR.add_node(7, BST_root);
	ABR.add_node(2, BST_root);
	ABR.add_node(4, BST_root);
	ABR.add_node(3, BST_root);
	ABR.add_node(5, BST_root);
	ABR.add_node(1, BST_root);
	ABR.add_node(9, BST_root);
	ABR.add_node(0, BST_root);

	cout << endl << "PREORDER VISIT" << endl << endl;
	ABR.display_preorder(ABR.get_BST_root());
	cout << endl << "VISIT ENDED" << endl;

	cout << endl << "INORDER VISIT" << endl << endl;
	ABR.display_inorder(ABR.get_BST_root());
	cout << endl << "VISIT ENDED" << endl;

	cout << endl << "POSTORDER VISIT" << endl << endl;
	ABR.display_postorder(ABR.get_BST_root());
	cout << endl << "VISIT ENDED" << endl;

	key_node info = 5;
	BST_node *pointer = ABR.binary_search(info, ABR.get_BST_root());
	if (pointer == nullptr)
		cout << "\ninfo " << info << " -> info not found" << endl;
	else {
		cout << "\ninfo " << info << " -> info found at address " << (unsigned long long)pointer << endl;
	}

	info = 100;
	pointer = ABR.binary_search(info, ABR.get_BST_root());
	if (pointer == nullptr)
		cout << "\ninfo " << info << " -> info not found" << endl;
	else {
		cout << "\ninfo " << info << " -> info found at address " << (unsigned long long)pointer << endl;
	}

	return 0;
}
