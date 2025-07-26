#include<iostream>
using namespace std;

class myArray
{
private:
    int* a;
    int size;
public:
    myArray();
    myArray(int s);
    myArray(int *d, int s);
    void insertAtStart(int num);
    void insertAtEnd(int num);
    void insert(int loc, int num);
    bool deleteNum(int num);
    bool deleteLoc(int loc);
    bool resize(int s);
    void deleteFromStart();
    void deleteFromEnd();
    void sort();
    bool find(int num);
    void IncBy1();
    void DcrBy1();
    void moveLeft(int loc);
    void moveRight(int loc);
	void dec_sort();
	void esnd_sort();
	friend istream& operator >> (istream& in,myArray&obj);
	friend ostream& operator << (ostream& os,myArray&obj);
    void show();
};