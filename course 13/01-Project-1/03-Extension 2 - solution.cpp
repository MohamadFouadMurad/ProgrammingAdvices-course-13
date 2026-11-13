#include <iostream>
#include "../clsDbLinkedList.h"

using namespace std;

int main()
{
    clsDbLinkedList <int> MydblLinkedList;

    if (MydblLinkedList.IsEmpty())
        cout << "\n\nYes list is Empty.\n";
    else
        cout << "\n\nNo list is not Empty";

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MydblLinkedList.Size();

    if (MydblLinkedList.IsEmpty())
        cout << "\n\nYes list is Empty.\n";
    else
        cout << "\n\nNo list is not Empty";
}