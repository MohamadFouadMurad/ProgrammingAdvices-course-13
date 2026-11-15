#include <iostream>
#include "../clsMyQueue.h"
using namespace std;

int main()
{
	clsMyQueue <int> MyQueue;

	MyQueue.push(10);
	MyQueue.push(20);
	MyQueue.push(30);
	MyQueue.push(40);
	MyQueue.push(50);

	cout << "\nQueue: \n";
	MyQueue.Print();

	cout << "\nQueue Size: " << MyQueue.Size();
	cout << "\nQueue Front: " << MyQueue.front();
	cout << "\nQueue Back: " << MyQueue.back();

	MyQueue.pop();

	cout << "\n\nQueue after pop() : \n";
	MyQueue.Print();

	//Extension #1
	cout << "\n\n Item(2) : " << MyQueue.GetItem(2);

	//Extension #2
	MyQueue.Reverse();
	cout << "\n\n Queue after Reverse() :\n";
	MyQueue.Print();

	//Extension #3
	MyQueue.UpdateItem(2,600);
	cout << "\n\n Queue after Updating item(2) to 600 : \n";
	MyQueue.Print();

	//Extension #4
	MyQueue.InsertAfter(2, 800);
	cout << "\n\nQueue after inserting 800 after Item(2) : \n";
	MyQueue.Print();

	//Extension #5
	MyQueue.InsertAtFront(1000);
	cout << "\n\nQueue after inserting 1000 at front: \n";
	MyQueue.Print();

	//Extension #6
	MyQueue.InsertAtBack(2000);
	cout << "\n\nQueue after inserting 2000 at back(): \n";
	MyQueue.Print();

	//Extension #7
	MyQueue.clear();
	cout << "\n\nQueue after clear(): \n";
	MyQueue.Print();

	return 0;
}