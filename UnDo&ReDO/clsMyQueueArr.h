#pragma once
#include "clsDynamicArray.h"
#include <iostream>
using namespace std;


template <class T>
class clsMyQueueArr
{
protected:

	clsDynamicArray<T> _MyArr;

public:

	void push(T Value) 
	{
		_MyArr.InsertAtEnd(Value);

	}
	void Print()
	{
		_MyArr.PrintList();
	}
	int Size() {
		
		return _MyArr.Size();
	}
	T front()
	{
		return _MyArr.GetItem(0);

	}
	bool IsEmpty()
	{
		return _MyArr.IsEmpty();
	}
	T back()

	{
		return _MyArr.GetItem(_MyArr.Size() - 1);
	}
	void pop()
	{
		_MyArr.DeleteFirstItem();
	}
	T GetItem(int Index)
	{
	return 	_MyArr.GetItem(Index);
	}
	void Reverse()
	{
		_MyArr.Reverse();
	}
	void UpdateItem(int Index, T Value)
	{
		_MyArr.SetItem(Index, Value);
	}
	void InsertAfter(int Index, T Value)
	{
		_MyArr.InsertAfter(Index, Value);
	}
	void InsertFront(T Value)
	{
		_MyArr.InsertAtBegining(Value);
	}
	void InsertBack(T Value)
	{
		_MyArr.InsertAtEnd(Value);
	}
	void Clear()
	{
		_MyArr.Clear();
	}

};

