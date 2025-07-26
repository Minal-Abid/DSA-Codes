#include <iostream>
using namespace std;

class myArray {
private:
	int* arr;
	int size;

	void copyArray(const int* src, int* dest, int s) {
		for (int i = 0; i < s; i++) {
			dest[i] = src[i];
		}
	}
	
	void resizeArray(int newSize) {
		if (newSize < 0) return; 

		int* temp = new int[newSize]; 
		int minSize = (size < newSize) ? size : newSize;

		if (arr) { 
			copyArray(arr, temp, minSize); 
			delete[] arr;
		}

		arr = temp;
		size = newSize;
	}


	void shiftRight(int loc) {
		for (int i = size - 1; i > loc; i--) {
			arr[i] = arr[i - 1];
		}
	}

	void shiftLeft(int loc) {
		for (int i = loc; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
	}

public:
	myArray() : size(0), arr(nullptr) {}

	myArray(int s) : size(s) {
		arr = (size > 0) ? new int[size] : nullptr;
	}

	
	myArray(int* a, int s) : size(s) {
		arr = (size > 0) ? new int[size] : nullptr;
		if (arr) copyArray(a, arr, size);
	}


	

	~myArray() { delete[] arr; }

	void createArray(int s) {
		if (s <= 0) {
			cout << "Invalid size! Size must be greater than zero.\n";
			return;
		}
		if (arr) delete[] arr; 
		size = s;
		arr = new int[size]; 
	}


	void insertAtStart(int num) {
		resizeArray(size + 1);
		shiftRight(0);
		arr[0] = num;
	}

	void insertAtEnd(int num) {
		resizeArray(size + 1);
		arr[size - 1] = num;
	}

	void insert(int loc, int num) {
		if (loc < 0 || loc > size) {
			cout << "Invalid location!\n";
			return;
		}
		resizeArray(size + 1);
		shiftRight(loc);
		arr[loc] = num;
	}

	bool deleteNum(int num) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == num) {
				shiftLeft(i);
				resizeArray(size - 1);
				return true;
			}
		}
		return false;
	}

	bool deleteLoc(int loc) {
		if (loc < 0 || loc >= size) return false;
		shiftLeft(loc);
		resizeArray(size - 1);
		return true;
	}

	void deleteFromStart() { deleteLoc(0); }

	void deleteFromEnd() { resizeArray(size - 1); }

	void sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	bool find(int num) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == num) return true;
		}
		return false;
	}

	void moveLeft(int loc) {
		if (loc < 1 || loc >= size) return;
		swap(arr[loc], arr[loc - 1]);
	}

	void moveRight(int loc) {
		if (loc < 0 || loc >= size - 1) return;
		swap(arr[loc], arr[loc + 1]);
	}

	void dec_sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] < arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	void show() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	friend istream& operator>>(istream& in, myArray& obj) {
		if (!obj.arr || obj.size <= 0) {
			cout << "Array is empty or uninitialized.\n";
			return in;
		}
		cout << "Enter " << obj.size << " elements: ";
		for (int i = 0; i < obj.size; i++) {
			in >> obj.arr[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& os, const myArray& obj) {
		if (!obj.arr || obj.size <= 0) {
			os << "Array is empty.";
			return os;
		}
		for (int i = 0; i < obj.size; i++) {
			os << obj.arr[i] << " ";
		}
		return os;
	}

};

int main() {
	myArray obj;
	int choice, num, loc, size;

	do {
		cout << "\nMENU:\n";
		cout << "1. Create Array\n";
		cout << "2. Insert At Start\n";
		cout << "3. Insert At End\n";
		cout << "4. Insert At Location\n";
		cout << "5. Delete Number\n";
		cout << "6. Delete From Location\n";
		cout << "7. Delete From Start\n";
		cout << "8. Delete From End\n";
		cout << "9. Sort (Ascending)\n";
		cout << "10. Sort (Descending)\n";
		cout << "11. Find Element\n";
		cout << "12. Move Left\n";
		cout << "13. Move Right\n";
		cout << "14. Show Array\n";
		cout << "15. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter size: ";
			cin >> size;

			obj.createArray(size);  

			cout << "Enter " << size << " elements: ";
			cin >> obj;
			break;


		case 2:
			cout << "Enter number: ";
			cin >> num;
			obj.insertAtStart(num);
			break;

		case 3:
			cout << "Enter number: ";
			cin >> num;
			obj.insertAtEnd(num);
			break;

		case 4:
			cout << "Enter location and number: ";
			cin >> loc >> num;
			obj.insert(loc, num);
			break;

		case 5:
			cout << "Enter number to delete: ";
			cin >> num;
			if (obj.deleteNum(num))
				cout << "Deleted successfully.\n";
			else
				cout << "Number not found!\n";
			break;

		case 6:
			cout << "Enter location to delete: ";
			cin >> loc;
			if (obj.deleteLoc(loc))
				cout << "Deleted successfully.\n";
			else
				cout << "Invalid location!\n";
			break;

		case 7:
			obj.deleteFromStart();
			cout << "Deleted from start.\n";
			break;

		case 8:
			obj.deleteFromEnd();
			cout << "Deleted from end.\n";
			break;

		case 9:
			obj.sort();
			cout << "Sorted in ascending order.\n";
			break;

		case 10:
			obj.dec_sort();
			cout << "Sorted in descending order.\n";
			break;

		case 11:
			cout << "Enter number to find: ";
			cin >> num;
			cout << (obj.find(num) ? "Found!" : "Not found!") << endl;
			break;

		case 12:
			cout << "Enter index to move left: ";
			cin >> loc;
			obj.moveLeft(loc);
			break;

		case 13:
			cout << "Enter index to move right: ";
			cin >> loc;
			obj.moveRight(loc);
			break;

		case 14:
			cout << obj;
			break;

		case 15:
			cout << "Exiting...\n";
			break;

		default:
			cout << "Invalid choice!\n";
		}

	} while (choice != 15);

	return 0;
}
