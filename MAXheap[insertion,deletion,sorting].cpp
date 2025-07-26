#include<iostream>
using namespace std;
class maxheap{
	int *arr;
	int size;
	int totalsize;
public:
	maxheap(int t){
		size = 0;
		totalsize = t;
		arr = new int[totalsize];

	}
	void insert(int n)
	{
		if (size == totalsize){
			cout << "heap overflow!" << endl;
		}
		else{
			int index = size;

			arr[size++] = n;
			while (index > 0 && arr[(index - 1) / 2] < arr[index]){

				swap(arr[index], arr[(index - 1) / 2]);
				index=(index - 1) / 2;
			}


		}
		
	}
	void print(){
		for (int i = 0; i < size;i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

	void Heapify(int index)
	{
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		// Largest will store the index of the element which
		// is greater between parent, left child and right child
		//yahan left<size aur right<size yay check karay ga k right aur left exist kartay bhi hain ya nahi
		if (left < size && arr[left] > arr[largest])
			largest = left;
		if (right < size && arr[right] > arr[largest])
			largest = right;
		//agr largest no longer index k equal hay that means k parent(index) say larger value kisi child may thi aur us ka index ab largest may hay so we'll swap the parent with it
		if (largest != index)
		{
			swap(arr[index], arr[largest]);
			Heapify(largest);
		}
	}



	void Deletelargest()
	{
		if (size == 0)
		{
			cout << "Heap Underflow\n";
			return;
		}

swap(arr[0] ,arr[size - 1]);
		size--;

		if (size == 0)
			return;

		Heapify(0);
	}
	void sortedafterdeletion(){
		int s = size;
		for (int i = 0; i < s-1; i++){
			Deletelargest();
		}
		for (int i = 0; i < s ; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

};
int main()
{
	maxheap h1(10);
	h1.insert(110);
	h1.insert(14);
	h1.insert(100);
	h1.insert(90);
	h1.print();
	h1.sortedafterdeletion();



}