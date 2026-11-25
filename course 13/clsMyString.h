#pragma once
#include <iostream>
#include "clsMyStackArr.h"
#include <string>
using namespace std;

class clsMyString
{
protected:
	
	clsMyStackArr<string> _clsUndo;
	clsMyStackArr<string> _clsRedo;
	string _Value = "";

public:

	clsMyString(string Value = "")
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_clsUndo.push(_Value);
		_Value = Value;

		while (!_clsRedo.IsEmpty())
		{
			_clsRedo.pop();
		}
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	void Undo()
	{
		if (!_clsUndo.IsEmpty())
		{
			_clsRedo.push(_Value);
			_Value = _clsUndo.Top();
			_clsUndo.pop();
		}
	}

	void Redo()
	{
		if (!_clsRedo.IsEmpty())
		{
			_clsUndo.push(_Value);
			_Value = _clsRedo.Top();
			_clsRedo.pop();
		}
	}

};

