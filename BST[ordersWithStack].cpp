#include <iostream>
#include <stack>
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

	// InOrder Traversal (non-recursive)
	void inOrderTraversal() {
		cout << "InOrder Traversal: ";
		stack<node*> s;
		node* current = root;

		while (current != nullptr || !s.empty()) {
			while (current != nullptr) {
				s.push(current);
				current = current->left;
			}
			current = s.top();
			s.pop();
			cout << current->data << " ";
			current = current->right;
		}
		cout << endl;
	}

	// PreOrder Traversal (non-recursive)
	void preOrderTraversal() {
		cout << "PreOrder Traversal: ";
		if (root == nullptr)
			return;

		stack<node*> s;
		s.push(root);

		while (!s.empty()) {
			node* curr = s.top();
			s.pop();
			cout << curr->data << " ";

			if (curr->right)
				s.push(curr->right);
			if (curr->left)
				s.push(curr->left);
		}
		cout << endl;
	}

	// PostOrder Traversal (non-recursive)
	void postOrderTraversal() {
		cout << "PostOrder Traversal: ";
		if (root == nullptr)
			return;

		stack<node*> s1, s2;
		s1.push(root);

		while (!s1.empty()) {
			node* curr = s1.top();
			s1.pop();
			s2.push(curr);

			if (curr->left)
				s1.push(curr->left);
			if (curr->right)
				s1.push(curr->right);
		}

		while (!s2.empty()) {
			cout << s2.top()->data << " ";
			s2.pop();
		}
		cout << endl;
	}
};
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
