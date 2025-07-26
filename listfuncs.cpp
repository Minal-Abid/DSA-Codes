#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class Mylist {
	Node* head;
public:
	Mylist() {
		head = nullptr;
	}

	void addNode(int num) {
		Node* newNode = new Node;
		newNode->data = num;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* itr = head;
			while (itr->next != nullptr) {
				itr = itr->next;
			}
			itr->next = newNode;
		}
	}

	void disply() {
		Node* itr = head;
		while (itr != nullptr) {
			cout << itr->data << " ";
			itr = itr->next;
		}
		cout << endl;
	}

	int getsize() {
		int count = 0;
		Node* itr = head;
		while (itr != nullptr) {
			count++;
			itr = itr->next;
		}
		return count;
	}

	static Mylist mergefunc(Mylist& l1, Mylist& l2) {
		Mylist merged;
		Node* itr = l1.head;
		while (itr != nullptr) {
			merged.addNode(itr->data);
			itr = itr->next;
		}
		itr = l2.head;
		while (itr != nullptr) {
			merged.addNode(itr->data);
			itr = itr->next;
		}
		return merged;
	}

	void reversefunc() {
		Node* prev = nullptr;
		Node* curr = head;
		Node* next = nullptr;
		while (curr != nullptr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

	void sort() {
		if (head == nullptr) return;
		bool swapped;
		Node* ptr1;
		Node* lptr = nullptr;
		do {
			swapped = false;
			ptr1 = head;
			while (ptr1->next != lptr) {
				if (ptr1->data > ptr1->next->data) {
					swap(ptr1->data, ptr1->next->data);
					swapped = true;
				}
				ptr1 = ptr1->next;
			}
			lptr = ptr1;
		} while (swapped);
	}

	void insert(int num) {
		sort();
		Node* newNode = new Node;
		newNode->data = num;
		newNode->next = nullptr;

		if (head == nullptr || head->data > num) {
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* itr = head;
		while (itr->next != nullptr && itr->next->data <= num) {
			itr = itr->next;
		}

		newNode->next = itr->next;
		itr->next = newNode;
	}

	void deleteNode(int num) {
		if (head == nullptr) return;
		if (head->data == num) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* prev = head;
		Node* curr = head->next;
		while (curr != nullptr && curr->data != num) {
			prev = curr;
			curr = curr->next;
		}
		if (curr != nullptr) {
			prev->next = curr->next;
			delete curr;
		}
	}

	bool search(int num) {
		Node* itr = head;
		while (itr != nullptr) {
			if (itr->data == num)
				return true;
			itr = itr->next;
		}
		return false;
	}

	void printReverseHelper(Node* node) {
		if (node == nullptr) return;
		printReverseHelper(node->next);
		cout << node->data << " ";
	}

	void printReverse() {
		printReverseHelper(head);
		cout << endl;
	}
};

// ===================== MENU DRIVEN MAIN =====================

int main() {
	Mylist list1, list2, merged;
	int choice, num;

	do {
		cout << "\n---- MENU ----\n";
		cout << "1. Add Node\n";
		cout << "2. Display List\n";
		cout << "3. Get Size\n";
		cout << "4. Reverse List\n";
		cout << "5. Sort List\n";
		cout << "6. Insert Sorted\n";
		cout << "7. Delete Node\n";
		cout << "8. Search Node\n";
		cout << "9. Print in Reverse\n";
		cout << "10. Merge Another List\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter number to add: ";
			cin >> num;
			list1.addNode(num);
			break;

		case 2:
			cout << "List: ";
			list1.disply();
			break;

		case 3:
			cout << "Size: " << list1.getsize() << endl;
			break;

		case 4:
			list1.reversefunc();
			cout << "List Reversed.\n";
			break;

		case 5:
			list1.sort();
			cout << "List Sorted.\n";
			break;

		case 6:
			cout << "Enter number to insert: ";
			cin >> num;
			list1.insert(num);
			cout << "Number inserted.\n";
			break;

		case 7:
			cout << "Enter number to delete: ";
			cin >> num;
			list1.deleteNode(num);
			cout << "Node deleted (if found).\n";
			break;

		case 8:
			cout << "Enter number to search: ";
			cin >> num;
			if (list1.search(num))
				cout << "Found.\n";
			else
				cout << "Not Found.\n";
			break;

		case 9:
			cout << "List in reverse: ";
			list1.printReverse();
			break;

		case 10:
			cout << "Enter 5 elements for second list:\n";
			for (int i = 0; i < 5; i++) {
				cin >> num;
				list2.addNode(num);
			}
			merged = Mylist::mergefunc(list1, list2);
			cout << "Merged List: ";
			merged.disply();
			break;

		case 0:
			cout << "Exiting...\n";
			break;

		default:
			cout << "Invalid option.\n";
		}

	} while (choice != 0);

	return 0;
}