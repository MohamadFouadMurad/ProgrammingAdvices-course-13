#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDbLinkedList
{
public:

	class Node
	{
	public:

		T Value;
		Node* next;
		Node* prev;
	};

protected:
	Node* head = nullptr;
	int _Size = 0;

public:

	~clsDbLinkedList()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void InsertAtBeginning(T Value)
	{
		Node* new_node = new Node();
		new_node->prev = nullptr;
		new_node->Value = Value;
		new_node->next = nullptr;

		if (head == nullptr)
		{
			head = new_node;
			new_node->prev = nullptr;
			_Size++;
			return;
		}

		new_node->next = head;
		head->prev = new_node;
		head = new_node;
		_Size++;
	}

	void PrintList()
	{
		Node* current = head;

		while (current != nullptr)
		{
			cout << current->Value << "  ";
			current = current->next;
		}

		cout << endl;
	}

	Node* Find(T Value)
	{
		Node* current = head;

		while (current != nullptr)
		{
			if (current->Value == Value)
			{
				return current;
			}

			current = current->next;
		}

		return nullptr;
	}

	void InsertAfter(Node* current, T Value)
	{
		if (current == nullptr)
		{
			return;
		}

		Node* new_node = new Node();
		new_node->prev = nullptr;
		new_node->next = nullptr;
		new_node->Value = Value;

		if (current->next != nullptr)
		{
			current->next->prev = new_node;
		}

		new_node->next = current->next;
		new_node->prev = current;
		current->next = new_node;
		_Size++;
	}

	void InsertAtEnd(T Value)
	{
		Node* new_node = new Node();
		new_node->Value = Value;

		if (head == nullptr)
		{
			new_node->next = head;
			new_node->prev = nullptr;
			head = new_node;
			_Size++;
			return;
		}

		Node* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		new_node->next = nullptr;
		new_node->prev = current;
		current->next = new_node;
		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == nullptr || NodeToDelete == nullptr)
		{
			return;
		}

		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}

		if (NodeToDelete->next != nullptr)
		{
			NodeToDelete->next->prev= NodeToDelete->prev;
		}

		if (NodeToDelete->prev != nullptr)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		delete NodeToDelete;
		NodeToDelete = nullptr;
		_Size--;
 	}

	void DeleteFirstNode()
	{
		if (head == nullptr)
		{
			return;
		}

		Node* current = head;
		head = head->next;
		
		if (head != nullptr)
		{
			head->prev = nullptr;
		}

		delete current;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == nullptr)
		{
			return;
		}

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			_Size--;
			return;
		}

		Node* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->prev->next = nullptr;
		delete current;
		_Size--;
	}

	int Size()
	{
		/*  O(N)
		int counter = 0;

		Node* current = head;

		while (current != nullptr)
		{
			counter++;
			current = current->next;
		}

		return counter;
		*/

		// O(1)
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);

		// Another way
		//return head == nullptr;
	}
};