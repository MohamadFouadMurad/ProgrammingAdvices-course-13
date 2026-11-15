#pragma once
#include <iostream>
#include "clsDbLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue
{
protected:
	clsDbLinkedList <T> _MyList;

public:

	void push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return 	_MyList.GetItem(0);
	}

	T back()
	{
		if (Size() == 0)
		{
			return T();
		}

		return  _MyList.GetItem(Size() -1);
	}

};

