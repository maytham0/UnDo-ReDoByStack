#pragma once
#include "clsMyStack.h"
#include <iostream>
using namespace std;
class clsMyString
{
private : 

	string _Value = "";
	
protected :
	clsMyStack<string> _MyStack;
	clsMyStack<string> _MyStackToReDo;

public:
	clsMyString()
	{
		_MyStack.InsertFront(_Value) ;
	}


	void setValue(string Value)
	{/*
		_Value = Value;*/
		_MyStack.InsertFront(Value);
		_Value=_MyStack.GetItem(0);
	}
	string GetValue()
	{

		return _Value;

	}
	__declspec(property(get = GetValue, put = setValue))string Value;



	void UnDo()
	{
		
		if (_MyStack.Size() <0) {
        
			return;
		}
		_MyStackToReDo.InsertFront(_Value);
              _MyStack.pop();
			 _Value = _MyStack.GetItem(0);
	}
	void ReDo()
	{
		if (_MyStackToReDo.Size() < 0)
		{
			return;
	
	}
		else 
		_Value = _MyStackToReDo.GetItem(0);

		_MyStackToReDo.pop();
	
	}


};

