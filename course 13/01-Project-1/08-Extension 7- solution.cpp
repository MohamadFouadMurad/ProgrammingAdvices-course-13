#include <iostream>
#include "../clsDbLinkedList.h"

using namespace std;

int main()
{
    clsDbLinkedList <int> MydblLinkedList;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.UpdateItem(2, 500);

    cout << "\nAfter Updating Item(2): " << endl;
    MydblLinkedList.PrintList();

    return 0;
}