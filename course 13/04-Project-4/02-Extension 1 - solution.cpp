#include <iostream>
#include "../clsDynamicArray.h"
using namespace std;

int main()
{

	clsDynamicArray <int> MyDynamicArray(5);

	MyDynamicArray.SetItem(0, 10);
	MyDynamicArray.SetItem(1, 20);
	MyDynamicArray.SetItem(2, 30);
	MyDynamicArray.SetItem(3, 40);
	MyDynamicArray.SetItem(4, 50);

	cout << "\nIs Empty? " << MyDynamicArray.IsEmpty();
	cout << "\nArray Size: " << MyDynamicArray.Size();
	cout << "\n\nArray Items: \n";

	MyDynamicArray.PrintList();


	MyDynamicArray.ReSize(2);
	cout << "\n\nArray Size: " << MyDynamicArray.Size();
	cout << "\n\nArray After resize is:\n";
	MyDynamicArray.PrintList();

	MyDynamicArray.ReSize(10);
	cout << "\n\nArray Size: " << MyDynamicArray.Size();
	cout << "\n\nArray After resize is:\n";
	MyDynamicArray.PrintList();

	return 0;
}