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
		new_node->prev = NULL;
		new_node->Value = Value;
		new_node->next = NULL;

		if (head == NULL)
		{
			head = new_node;
			new_node->prev = NULL;
			return;
		}

		new_node->next = head;
		head->prev = new_node;
		head = new_node;

	}

	void PrintList()
	{
		Node* current = head;

		while (current != NULL)
		{
			cout << current->Value << "  ";
			current = current->next;
		}

		cout << endl;
	}

	Node* Find(T Value)
	{
		Node* current = head;

		while (current != NULL)
		{
			if (current->Value == Value)
			{
				return current;
			}

			current = current->next;
		}

		return NULL;
	}

	void InsertAfter(Node* current, T Value)
	{
		if (current == NULL)
		{
			return;
		}

		Node* new_node = new Node();
		new_node->prev = NULL;
		new_node->next = NULL;
		new_node->Value = Value;

		if (current->next != NULL)
		{
			current->next->prev = new_node;
		}

		new_node->next = current->next;
		new_node->prev = current;
		current->next = new_node;
	}

	void InsertAtEnd(T Value)
	{
		Node* new_node = new Node();
		new_node->Value = Value;

		if (head == NULL)
		{
			new_node->next = head;
			new_node->prev = NULL;
			head = new_node;
			return;
		}

		Node* current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		new_node->next = NULL;
		new_node->prev = current;
		current->next = new_node;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
		{
			return;
		}

		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}

		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev= NodeToDelete->prev;
		}

		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		delete NodeToDelete;
		NodeToDelete = NULL;
 	}

	void DeleteFirstNode()
	{
		if (head == NULL)
		{
			return;
		}

		Node* current = head;
		head = head->next;
		
		if (head != NULL)
		{
			head->prev = NULL;
		}

		delete current;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
		{
			return;
		}

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}

		Node* current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->prev->next = NULL;
		delete current;

	}
};

