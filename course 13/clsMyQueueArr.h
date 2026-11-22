#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray <T> _MyArray;

public:
	
	void push(T Value)
	{
		_MyArray.InsertAtEnd(Value);
	}

	void pop()
	{
		_MyArray.DeleteFirstItem();
	}

	void Print()
	{
		_MyArray.PrintList();
	}

	int Size()
	{
		return _MyArray.Size();
	}

	bool IsEmpty()
	{
		return _MyArray.IsEmpty();
	}

	T front()
	{
		return 	_MyArray.GetItem(0);
	}

	T back()
	{
		if (Size() == 0)
		{
			return T();
		}

		return  _MyArray.GetItem(Size() - 1);
	}

	T GetItem(int Index)
	{
		return _MyArray.GetItem(Index);
	}

	void Reverse()
	{
		_MyArray.Reverse();
	}

	bool UpdateItem(int Index, T NewValue)
	{
		return _MyArray.SetItem(Index, NewValue);
	}

	bool InsertAfter(int Index, T NumToAdd)
	{
		return _MyArray.InsertAfter(Index, NumToAdd);
	}

	void InsertAtFront(T Value)
	{
		_MyArray.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		push(Value);


		//or
		//_MyArray.InsertAtEnd(Value);
	}

	void clear()
	{
		_MyArray.Clear();
	}
};

