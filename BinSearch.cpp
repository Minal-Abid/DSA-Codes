#include<iostream>

using namespace std;

bool BinSearch(int arr[], int size, int n)
{
	int start = 0, end = size - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (n == arr[mid])
		{
			return 1;
		}
		else if (n > arr[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return 0;
}

int main()
{
	const int size = 6;
	int arr[size], n;

	cout << "Enter you array data: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter you Number: ";
	cin >> n;

	if (BinSearch(arr,size,n))
	{
		cout << "Number is found in array...!";
	}
	else
	{
		cout << "Number is NOT found...!";
	}

	return 0;
}