#pragma once
#include <iostream>
#include <vector>
#include "clsDBlLinkedList.h"

template<class T>
class clsMyQueue
{

          
	/*int _Count = 0;*/
protected:

	//Composition 
	clsDBlLinkedList<T> _MyLinkedList;
public:
	
	/*vector<T>vQueue;
	
	void push(T value)
	{
		vQueue.push_back(value);
		 _Count++;
		
	}
	void Print()
	{
		for (int i = 0; i < _Count; i++)
		{
			cout << vQueue[i] << "  ";
		} 
	}
	int Size()
	{
		return vQueue.size();
	}
	T front()
	{
		return vQueue.front();

	}
	T back()

	{
		return vQueue.back();
	}
	void pop()
	{
		vQueue[0].pop_back();
		_Count--;
	}*/

	void push(T Value) {
		_MyLinkedList.InsertAtEnd(Value);
	}
	void Print()
	{
		_MyLinkedList.printList();
	}
	int Size() {
		return _MyLinkedList.Size();
	}
	T front()
	{
		return _MyLinkedList.GetItem(0);

	}
	bool IsEmpty()
	{
		return _MyLinkedList.IsEmpty();
	}
	T back()

	{
		return _MyLinkedList.GetItem(Size()-1);
	}
	void pop()
	{
		return _MyLinkedList.DeleteFirstNode();
	}
	T GetItem(int Index)
	{
		return _MyLinkedList.GetItem(Index);
	}
	void Reverse()
	{
		_MyLinkedList.Reverse();
	}
	void UpdateItem(int Index, T Value)
	{
		_MyLinkedList.UpdaateItem(Index, Value);
	}
	void InsertAfter(int Index, T Value)
	{
		_MyLinkedList.InserAftar(Index, Value);
	}
	void InsertFront(T Value)
	{
		_MyLinkedList.InsertAtBeginig(Value);
	}
	void InsertBack(T Value)
	{
		_MyLinkedList.InsertAtEnd(Value);
	}
	void Clear()
	{
		 _MyLinkedList.Clear();
	}
};

