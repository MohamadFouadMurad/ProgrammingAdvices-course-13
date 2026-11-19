#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:

	T* _OrgArray;
	int _Size = 0;

public:

	clsDynamicArray(int Size=0)
	{		
		if (Size < 0)
		{
			Size = 0;
		}

		_Size = Size;
		_OrgArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] _OrgArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index < 0 || Index >= _Size)
		{
			return false;
		}

		_OrgArray[Index] = Value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void PrintList()
	{
		if (_Size == 0)
		{
			return ;
		}

		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << _OrgArray[i] << "  ";
		}

		// _OrgArray[i] === *(_OrgArray + i)
	}



};

