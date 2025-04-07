﻿#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{

protected:
    int _Size = 0;
    T* _TempArray;

public:
    T* OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];

    }

    ~clsDynamicArray()
    {

        delete[]  OriginalArray;

    }

    bool SetItem(int index, T Value)
    {

        if (index >= _Size || _Size < 0)
        {
            return false;
        }

        OriginalArray[index] = Value;
        return true;

    }


    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);

    }

    void PrintList()

    {

        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << "\n";

    }
    void Resize(int NewSize)
    {

        if (NewSize < 0)
        {
            NewSize = 0;
        };

        _TempArray = new T[NewSize];

        //limit the original size to the new size if it is less.
        if (NewSize < _Size)
            _Size = NewSize;

        //copy all data from original array until the size
        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;

        delete[] OriginalArray;
        OriginalArray = _TempArray;

    }

    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }
    void Reverse()
    {
        _TempArray = new T[_Size];
        for (int i = _Size-1; i >=0; i--)
        {
            _TempArray[_Size-1-i] = OriginalArray[i];
        }
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }
    void Clear()
    {
        _Size = 0;
        _TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }
    /*bool DeleteItemAt(int Index)
    {
    if (index >= _Size || index < 0)
        {
            return false;
        }

        _Size--;
        _TempArray = new T[_Size];
        int Count = 0;
        for (int i = 0; i < _Size; i++)
        {
            if (Index == i)
            {
                Count++;
               
            }
            _TempArray[i] = OriginalArray[Count];
            Count++;
        }
        
        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;
    }*/

    bool DeleteItemAt(int index)
    {

        if (index >= _Size || index < 0)
        {
            return false;
        }

        _Size--;

        _TempArray = new T[_Size];

        //copy all before index
        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        //copy all after index
        for (int i = index + 1; i < _Size + 1; i++)
        {
            _TempArray[i - 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

    }
    //bool DeleteFirstItem()
    //{
    //    if (_Size < 0)
    //    {
    //        return false;
    //    }

    //    _TempArray = new T[_Size];
    //   
    //    for (int i = 1; i < _Size; i++)
    //    {
    //        _TempArray[i-1] = OriginalArray[i];
    //    }
    //    delete[] OriginalArray;
    //    OriginalArray = _TempArray;
    //    _Size--;
    //    return true;
    //}
    bool DeleteFirstItem()

    {
        return DeleteItemAt(0);
    }

    /*bool DeleteLastItem()
    {
        if(_Size<0)
        {
            return false;
        }
        _Size--;
        return true;
    }*/
    bool DeleteLastItem()
    {
        return DeleteItemAt(_Size - 1);

    }
    int Find(T Value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == Value)
            {
                return i;
            }
        }
        return -1;
    }
    bool DeleteItem(T Value)
    {
        int Index = Find(Value);
        if (Index == -1)
        {
            return false;
        }
        else
            return DeleteItemAt(Index);
    }
    bool InsertAt(int Index, T Value)
    {
        if (Index < 0||Index>_Size)
        {
            return false;
        }
        _Size++;
        _TempArray = new T[_Size];
        int Count = 0;
        for (int i = 0; i < _Size; i++)
        {
            if (Count == Index)
            {
                Count++;
                _TempArray[Index] = Value;
            }
            _TempArray[Count] = OriginalArray[i];
                Count++;
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;
    }

    //bool InsertAt(T index, T value) {

    //    if (index > _Size || index < 0)
    //    {
    //        return false;
    //    }

    //    _Size++;

    //    _TempArray = new T[_Size];

    //    //copy all before index
    //    for (int i = 0; i < index; i++)
    //    {
    //        _TempArray[i] = OriginalArray[i];
    //    }

    //    _TempArray[index] = value;

    //    //copy all after index
    //    for (int i = index; i < _Size - 1; i++)
    //    {
    //        _TempArray[i + 1] = OriginalArray[i];
    //    }

    //    delete[] OriginalArray;
    //    OriginalArray = _TempArray;
    //    return true;

    //}
    bool InsertAtBegining(T Value)
    {
        return InsertAt(0, Value);
    }
    bool InsertBefor(int Index, T value)
    {
        if (Index == 0)
        {
            return InsertAt(0, value);
        }
        return InsertAt(Index - 1, value);
    
    }
    bool InsertAfter(int index, T value)
    {
        if (index >= _Size)
            return InsertAt(_Size - 1, value);
        else
            return InsertAt(index + 1, value);

    }
    bool InsertAtEnd(T Value)
    {
        return InsertAt(_Size , Value);
    }

};
