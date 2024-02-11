#include "../../include/stackArr.h"

template <class T>
Stack<T>::Stack():arr(NULL),topInd(-1),capacity(0)
{}

// Time Complexity: O(n)    
template <class T>
Stack<T>::Stack(Stack<T>& otherStack)
{
    arr = new T[otherStack.capacity];
    capacity = otherStack.capacity;topInd = otherStack.topInd;
    for(int i = 0;i<=topInd;i++)
    {
        arr[i]=otherStack.arr[i];
    }
}

template <class T>
Stack<T>::~Stack()
{
    delete[] arr;
}

// Time Complexity: O(1)
template <class T> 
void Stack<T>::push(T item)
{
    if(!capacity)
   {
    capacity++;topInd++;
    arr = new T[capacity];arr[topInd] = item;
   }
   else if(isFull())
   {
    capacity*=2;
    T* newArr = new T[capacity];
    for(int i = 0;i<=topInd;i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;arr=newArr;arr[++topInd] = item;
   }
   else
   {
    arr[++topInd]=item;
   }
}

// Time Complexity: O(1)
template <class T>
T Stack<T>::top()
{
    if(isEmpty())
    {
        cout<<"The Stack is empty\n";
         exit(EXIT_FAILURE);
    }
    else
    {
      return arr[topInd];
    }
}

// Time Complexity: O(1)
template <class T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        exit(EXIT_FAILURE);
    }
    T magicNumber = arr[topInd--];
    return magicNumber;
}

// Time Complexity: O(n)
template <class T>
int Stack<T>::length()
{
    return topInd+1;
}

// Time Complexity: O(1)
template <class T>
bool Stack<T>::isEmpty()
{
    if(topInd<0) return 1; else return 0;
}

// Time Complexity: O(1)
template <class T>
bool Stack<T>::isFull()
{
     if(topInd==capacity-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class T>
void Stack<T>::printStack()
{
    for(int i = 0;i<=topInd;i++)
    {
        cout<<arr[i]<<endl;
    }
}