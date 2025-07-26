#include <iostream>
#include <string>

using namespace std;

// Node structure for the Binary Search Tree
class node {
public:
	int data;
	node* left;
	node* right;

	// Constructor to easily initialize a new node
	node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
	node* root;

	// Recursive helper for inOrder traversal
	void inOrder(node* itr) {
		if (itr == nullptr) {
			return;
		}
		else {
			inOrder(itr->left);
			cout << itr->data << " ";
			inOrder(itr->right);
		}
	}

	// Recursive helper for counting nodes
	void count(node* itr, int& cnt) {
		if (itr == nullptr) {
			return;
		}
		else {
			count(itr->left, cnt);
			cnt++;
			count(itr->right, cnt);
		}
	}
	void max(node* itr, int& mx) {
		if (itr == nullptr) {
			return;
		}
		else {
			mx = itr->data;
			max(itr->left, mx);
			if (mx < itr->data){ mx = itr->data; }
			
			max(itr->right, mx);
		}
	}
	
	// Recursive helper for finding the height
	// This is the core logic for height calculation
	int getHeightRecursive(node* itr) {
		// Base case: If the current node is null, it means we've gone past a leaf.
		// Its "height" contribution is -1, ensuring a single-node tree has height 0.
		if (itr == nullptr) {
			return -1;
		}

		// Recursively find the height of the left subtree
		int leftSubtreeHeight = getHeightRecursive(itr->left);

		// Recursively find the height of the right subtree
		int rightSubtreeHeight = getHeightRecursive(itr->right);

		// The height of the current node is 1 (for the current node itself)
		// plus the maximum height of its left or right subtree.
		// In getHeightRecursive:
		return 1 + (leftSubtreeHeight > rightSubtreeHeight ? leftSubtreeHeight : rightSubtreeHeight);
	}

	// Helper to delete all nodes (good practice for memory management)
	void destroyTree(node* itr) {
		if (itr == nullptr) {
			return;
		}
		destroyTree(itr->left);
		destroyTree(itr->right);
		delete itr;
	}

public:
	BST() {
		root = nullptr;
	}

	// Destructor to clean up memory when BST object goes out of scope
	~BST() {
		destroyTree(root);
	}

	void insert(int val) {
		// Use the node constructor for consistent initialization
		node* newNode = new node(val);

		if (root == nullptr) {
			root = newNode;
		}
		else {
			node* itr = root;
			node* parent = nullptr; // To keep track of the parent for linking
			while (itr != nullptr) {
				parent = itr;
				if (val > itr->data) {
					itr = itr->right;
				}
				else {
					itr = itr->left; // Assuming values equal to data go to left as per your count logic
				}
			}

			if (val > parent->data) {
				parent->right = newNode;
			}
			else {
				parent->left = newNode;
			}
		}
	}

	void printInOrder() {
		inOrder(root);
		cout << endl; // Add a newline for cleaner output
	}

	int countNodes() {
		int c = 0;
		count(root, c);
		return c;
	}

	// Public interface for getting the height
	int getTreeHeight() {
		return getHeightRecursive(root);
	}
	int getmin(){ 
	node*itr = root;
	while (itr->left != nullptr){
		itr = itr->left;
	}
	
	return itr->data;
	
	
	
	}

	int getmax(){ int m = 0; max(root, m); return m; }


	//// This function is used to find floor 
	//// of given number x
	//int floor(Node* root, int x) {

	//	// Initialize variable to store the floor value
	//	int floorValue = -1;

	//	while (root != nullptr) {

	//		// If the root's data is equal to x, 
	//		// we've found the floor
	//		if (root->data == x) {
	//			return root->data;
	//		}

	//		// If root's data is greater than x, 
	//		// search in the left subtree
	//		if (root->data > x) {
	//			root = root->left;
	//		}
	//		else {

	//			// Update floorValue and move to the 
	//			// right subtree
	//			floorValue = root->data;
	//			root = root->right;
	//		}
	//	}

	//	return floorValue;
	//}

//-------------------------------------------------------
	//// Helper function to find ceil of a given key in BST
	//int findCeil(Node* root, int key) {

	//	int ceil = -2;

	//	while (root) {

	//		// If root itself is ceil
	//		if (root->data == key) {
	//			return root->data;
	//		}

	//		// If root is smaller, the ceil
	//		// must be in the right subtree
	//		if (key > root->data) {
	//			root = root->right;
	//		}

	//		// Else either root can be ceil
	//		// or a node in the left child
	//		else {
	//			ceil = root->data;
	//			root = root->left;
	//		}
	//	}
	//	return ceil;
	//}




};

int main() {
	BST t1;
	while (true) {
		cout << "\n1. Insert\n";
		cout << "2. Print [InOrder]\n";
		cout << "3. Count Nodes\n";
		cout << "4. Get Tree Height\n"; 
		cout << "5. Get Tree max\n";
		cout << "6. Get Tree min\n";

		cout << "7. Exit\n"; 
		int c;
		cin >> c;

		if (c == 1) {
			int d;
			cout << "Enter data: ";
			cin >> d;
			t1.insert(d);
		}
		else if (c == 2) {
			t1.printInOrder();
		}
		else if (c == 3) {
			cout << "The BST has " << t1.countNodes() << " nodes." << endl;
		}
		else if (c == 4) { 
			cout << "The height of the BST is: " << t1.getTreeHeight() << endl;
		}
		else if (c == 5) {
			cout << "The max of the BST is: " << t1.getmax() << endl;
		}
		else if (c == 6) {
			cout << "The min of the BST is: " << t1.getmin() << endl;
		}
		else if (c == 7) { 
			cout << "Exiting...." << endl;
			break;
		}
		else {
			cout << "Invalid choice. Please try again." << endl;
		}
	}

	return 0;
}