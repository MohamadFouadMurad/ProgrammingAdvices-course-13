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


    MydblLinkedList.Reverse();
    cout << "\nLinked list content after reverse:\n";
    MydblLinkedList.PrintList();

    return 0;
}