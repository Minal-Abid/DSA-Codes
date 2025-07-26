#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

class Mylist{
	Node* head;
public:
	Mylist(){
		head = nullptr;
	}
	void addNode(int num){
		if (head == nullptr)
		{
			head = new Node;
			head->next = nullptr;
			head->data = num;
		}
		else
		{
			Node *itr = head;
			while (itr->next != nullptr)
			{
				itr = itr->next;
			}
			itr->next = new Node;
			itr->next-> data = num;
			itr->next->next = nullptr;
		}
	}

	void disply(){
		Node* itr = head;
		while (itr != nullptr)
		{
			cout << itr->data << " ";
			itr = itr->next;
		}
	}
};