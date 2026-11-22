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

	void ReSize(int NewSize)
	{
		if (NewSize < 0)
		{
			NewSize = 0;
		}

		if (NewSize == _Size)
		{
			return;
		}

		T* TempArray = new T[NewSize];

		for (int i = 0; i < _Size && i < NewSize; i++)
		{
			TempArray[i] = _OrgArray[i];
		}

		_Size = NewSize;

		delete[] _OrgArray;

		_OrgArray = TempArray;
	}

	T GetItem(int Index)
	{
		if (Index < 0 || Index >= _Size)
		{
			return T();
		}

		return _OrgArray[Index];
	}

	void Reverse()
	{
		T* TempArray = new T[_Size];

		for (int Index = 0; Index < _Size; Index++)
		{
			TempArray[Index] = _OrgArray[_Size - Index - 1];
		}

		//Another way
		/*
		T Temp;
		for (int i = 0; i < _Size /2; i++)
		{
			Temp = _OrgArray[i];
			_OrgArray[i] = _OrgArray[_Size - i - 1];
			_OrgArray[_Size - i - 1] = Temp;
		}
		*/

		delete[] _OrgArray;

		_OrgArray = TempArray;
	}

	void Clear()
	{
		 ReSize(0);

		 //Another way
		/*
		if (_Size == 0)
		{
		return;
		}

		delete[] _OrgArray;

		_Size = 0;

		_OrgArray = new T[0];
		*/
	}

	void DeleteItemAt(int Index)
	{
		if (Index < 0 || Index >= _Size)
		{
			return;
		}

		_Size--;
		T* TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			if (i < Index)
			{
				TempArray[i] = _OrgArray[i];
			}
			else
			{
				TempArray[i] = _OrgArray[i + 1];
			}
		}

		delete[] _OrgArray;

		_OrgArray = TempArray;
	}

	void DeleteFirstItem()
	{
		if (_Size == 0)
		{
			return;
		}

		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		if (_Size == 0)
		{
			return;
		}

		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (_OrgArray[i] == Value)
			{
				return i;
			}
		}

		return -1;
	}

	void DeleteItem(T Value)
	{
		int Index = Find(Value);

		DeleteItemAt(Index);
	}

	bool InsertAt(int Index, T value)
	{
		if (Index < 0 || Index > _Size)
		{
			return false;
		}

		_Size++;
		T* TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			if (i == Index)
			{
				TempArray[i] = value;
			}
			else
			{
				if (i < Index)
				{
					TempArray[i] = _OrgArray[i];
				}
				else
				{
					TempArray[i] = _OrgArray[i-1];
				}
			}
		}

		delete[] _OrgArray;

		_OrgArray = TempArray;
		return true;


		//Another way
		/*
		if (Index > _Size || Index < 0)
		{
			return false;
		}

		_Size++;

		T * TempArray = new T[_Size];

		//copy all before index
		for (int i = 0; i < Index; i++)
		{
			TempArray[i] = _OrgArray[i];
		}

		TempArray[Index] = value;

		//copy all after index
		for (int i = Index; i < _Size - 1; i++)
		{
			TempArray[i + 1] = _OrgArray[i];
		}

		delete[] _OrgArray;
		_OrgArray = TempArray;
		return true;
		*/
	}
};

