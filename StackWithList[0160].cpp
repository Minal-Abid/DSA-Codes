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
			itr->next->data = num;
			itr->next->next = nullptr;
		}
	}
	void display() {
		Node* itr = head;
		while (itr != nullptr) {
			cout << itr->data <<endl;
			itr = itr->next;
		}
		cout << endl;
	}

	void insertAtStart(int num){
		Node*itr1 = head;
		Node*itr = new Node;
		itr->data = num;
		itr->next = itr1;
		head = itr;
		
	}
	int getHead(){
		return head->data;
	}
	void removeHead()
	{
		Node*itr = head;
		head = itr->next;
		itr->next = nullptr;
		delete itr;

	}
	bool isEmpty(){
		if (head == nullptr){
			return true;
		}
		else{ return false; }
	}
};
class stack
{
private:
	Mylist l;
public:
	void push(int num){
		l.insertAtStart(num);
	}
	bool isStackEmpty(){
		if (l.isEmpty()){ return true; }
		else { return false; }
	}
	int pop(){
		
			int num = l.getHead();
			l.removeHead();
			return num;
		
	}
	int top(){
		return l.getHead();
	}
	void stackdisplay(){
		cout << endl;
		cout << "Your stack :" << endl;
		l.display();
	}


};

int main(){
	stack s;
	while (true)
	{
		cout << "Enter number to push in stack(press -1 to terminate) : "; int n; cin >> n;
		if (n == -1){ break; }
		else{
			s.push(n);
		}
	}
	while (true){


		cout << "1.pop" << endl;
		cout << "2.see top of stack" << endl;
		cout << "3.display stack" << endl;
		cout << "4.Exit" << endl;
		cout << endl;
		cout << endl;

		int n;
		cin >> n;
		if (n == 1){
			if (!s.isStackEmpty()) {
				cout << "The element popped out of of stack is : " << s.pop() << endl;
				cout << "-------------------------------" << endl;
			}
			else {
				cout << "Stack is empty!!" << endl;
				cout << "-------------------------------" << endl;
			}
		}

		if (n == 2){
			if (!s.isStackEmpty()) {
				cout << "The element at the top of stack is : " << s.top() << endl;
				cout << "-------------------------------" << endl;
			}
			else {
				cout << "Stack is empty!!" << endl;
				cout << "-------------------------------" << endl;
			}
		}

		if (n == 3){
			if (!s.isStackEmpty()) {
				s.stackdisplay();
				cout << "-------------------------------" << endl;
			}
			else {
				cout << "Cannot display stack" << endl;
				cout << "Reason: Stack is empty!!" << endl;
				cout << "-------------------------------" << endl;
			}
			

		}
		if (n == 4){
			cout << "Exiting..." << endl;
			cout << "-------------------------------" << endl;
			break;
		}
	}
	



}