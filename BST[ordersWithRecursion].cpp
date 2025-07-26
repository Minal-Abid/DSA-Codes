#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* right;
	node* left;
};

class BST {
private:
	node* root;
	int cnt = 0;
	void count(node* itr) {
		if (itr == nullptr) return;

		count(itr->left);
		cnt++;
		count(itr->right);
	}

	void inOrder(node* itr) {
		if (itr == nullptr)
			return;
		inOrder(itr->left);
		cout << itr->data << " ";
		inOrder(itr->right);
	}

	void preOrder(node* itr) {
		if (itr == nullptr)
			return;
		cout << itr->data << " ";
		preOrder(itr->left);
		preOrder(itr->right);
	}

	void postOrder(node* itr) {
		if (itr == nullptr)
			return;
		postOrder(itr->left);
		postOrder(itr->right);
		cout << itr->data << " ";
	}

public:
	BST() {
		root = nullptr;
	}

	void insert(int val) {
		node* newNode = new node;
		newNode->data = val;
		newNode->left = nullptr;
		newNode->right = nullptr;

		if (root == nullptr) {
			root = newNode;
			return;
		}

		node* itr = root;
		node* parent = nullptr;

		while (itr != nullptr) {
			parent = itr;
			if (val < itr->data)
				itr = itr->left;
			else
				itr = itr->right;
		}

		if (val < parent->data)
			parent->left = newNode;
		else
			parent->right = newNode;
	}

	void inOrderTraversal() {
		cout << "InOrder Traversal: ";
		inOrder(root);
		cout << endl;
	}

	void preOrderTraversal() {
		cout << "PreOrder Traversal: ";
		preOrder(root);
		cout << endl;
	}

	void postOrderTraversal() {
		cout << "PostOrder Traversal: ";
		postOrder(root);
		cout << endl;
	}
	int getcount(){
		count(root); return cnt;
	}
};

// Menu-driven main
int main() {
	BST tree;
	int choice, value;

	while (true) {
		cout << "\n=== Binary Search Tree Menu ===\n";
		cout << "1. Insert a value\n";
		cout << "2. InOrder Traversal\n";
		cout << "3. PreOrder Traversal\n";
		cout << "4. PostOrder Traversal\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to insert: ";
			cin >> value;
			tree.insert(value);
			cout << "Inserted successfully.\n";
			break;
		case 2:
			tree.inOrderTraversal();
			break;
		case 3:
			tree.preOrderTraversal();
			break;
		case 4:
			tree.postOrderTraversal();
			break;
		case 5:
			cout << "Exiting the program.\n";
			return 0;
		default:
			cout << "Invalid choice! Please try again.\n";
		}
	}

	return 0;
}
