#pragma once
#include <iostream>

using namespace std; 




template <class T>
class clsDBlLinkedList
{

protected:
	int _Size = 0;

public:

	class Node {
	public:
	T _value;
	Node* _next;
	Node* _prev;
	};

	Node* head = NULL;


	void printList()
	{
		Node* temp = head; 
		while (temp != NULL)
		{
			cout << temp->_value << "   ";
			temp = temp->_next;
		}
	}
	Node* Find(T value)
	{
		Node* current = head; 
		while (current != NULL)
		{
			if (current->_value == value)
			{
				return current;
			}
			current = current->_next;
		}
		return NULL; 
	}

	void InsertAtBeginig(T Value)
	{
		Node* NewNode = new Node;
		NewNode->_value = Value;
		NewNode->_next = head;
		NewNode->_prev = NULL;
		if (head != NULL)
		{
			head->_prev = NewNode;
		}
		head = NewNode;
		_Size++;
	}
	void InserAftar(Node* current,T Value)
	{
		if (current == NULL)
		{
			// ??????? ?? ?????? ????? ???? ?????? ??????? null
			cout << "Node IS NULL \n";
			return;
		}

		Node* NewNode = new Node;
		NewNode->_value = Value;
		NewNode->_next = current->_next;
		NewNode->_prev = current;
		if (current->_next != NULL)
		{
			current->_next->_prev= NewNode;
		
		}
		current->_next = NewNode;
		_Size++;
		
	}
	void InsertAtEnd(T Value)
	{

		Node* newNode = new Node;
		newNode->_value = Value;
		newNode->_next = NULL;
		if (head == NULL) {
			newNode->_prev = NULL;
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->_next != NULL) {
				current = current->_next;
			}
			current->_next = newNode;
			newNode->_prev = current;
		}
		_Size++;
	}
	
	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL) {
			return;
		}
		if (head == NodeToDelete) {
			head = NodeToDelete->_next;
		}
		if (NodeToDelete->_next != NULL) {
			NodeToDelete->_next->_prev = NodeToDelete->_prev;
		}
		if (NodeToDelete->_prev != NULL) {
			NodeToDelete->_prev->_next = NodeToDelete->_next;
		}
		delete NodeToDelete;
		_Size--;
	}
	void DeleteFirstNode() {
		if (head == NULL) {
			return;
		}
		Node* temp = head;
		head = head->_next;
		if (head != NULL) {
			head->_prev = NULL;
		}
		delete temp;
		_Size--;
	}
	void DeleteLastNode()
	{

		if (head == NULL) {
			return;
		}
		if (head->_next == NULL) {
			delete head;
			head = NULL;
			return;
		}
		Node* current = head;
		while (current->_next->_next != NULL) {
			current = current->_next;
		}
		Node* temp = current->_next;
		current->_next = NULL;
		delete temp;
		_Size--;
	}

	//time compxlity is big O(n)
	/*int Size()
	{
		int Count = 0;
		Node* current = head;
		while (current != NULL)
		{
			Count++;
			current = current->_next;
		}

		return Count;
	}*/
	//time compxlity is big O(1)
	int Size()
	{
		return _Size;
	}
	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}
	void Clear()
	{
		while (_Size>0)
		{
			DeleteFirstNode();
		}
		
	}

	//void Reverse() {
	//	Node* current = head;
	//	while (current->_next != NULL) {
	//		current = current->_next;
	//	}
	//
	//	while (current!=NULL)
	//	{
	//		cout << current->_value << "   ";
	//		current = current->_prev;

	//	}
	void Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr)
		{
			temp = current->_prev;
			current->_prev = current->_next;
			current->_next = temp;
			current = current->_prev;
		}
		if (temp != nullptr)
		{
			head = temp->_prev;
		}
	}
	//serch By Index
	/*Node* GetNode(int Index)
	{
		Node* current = head; 
		int Count = 0;
		while (current != NULL)
		{
			
			if (Index ==Count)
			{
				return current;
			}
			Count++;
			current = current->_next;
		}
		return NULL;
	}*/
	Node* GetNode(int Index)
	{

		int Counter = 0;

		if (Index > _Size - 1 || Index < 0)
			return NULL;

		Node* Current = head;
		while (Current != NULL && (Current->_next != NULL)) {

			if (Counter == Index)
				break;

			Current = Current->_next;
			Counter++;

		}

		return Current;
	}

	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->_value;
	}
	bool UpdaateItem(int Index,T NewValue)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL)
		{
			ItemNode->_value = NewValue;
			return true;
		}
		else return false;

	}
	bool InserAftar(int Index, T Value)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL)
		{
			InserAftar(ItemNode, Value);
				 return true;
		}
		else return false;
	}
};

