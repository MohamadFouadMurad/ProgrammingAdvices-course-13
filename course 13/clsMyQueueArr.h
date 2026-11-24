#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray <T> _MyList;

public:
	
	void push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void pop()
	{
		_MyList.DeleteFirstItem();
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

		return  _MyList.GetItem(Size() - 1);
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	bool UpdateItem(int Index, T NewValue)
	{
		return _MyList.SetItem(Index, NewValue);
	}

	bool InsertAfter(int Index, T NumToAdd)
	{
		return _MyList.InsertAfter(Index, NumToAdd);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		push(Value);


		//or
		//_MyList.InsertAtEnd(Value);
	}

	void clear()
	{
		_MyList.Clear();
	}
};

