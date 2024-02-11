#include "../../include/queueArr.h"

template <class T>
Queue<T>::Queue():arr(NULL),capacity(0),rear(-1)
{}

// Time Complexity: O(n)    
template <class T>
Queue<T>::Queue(Queue<T>& otherQueue)
{
    capacity = otherQueue.capacity;rear = otherQueue.rear;
    arr =  new T[capacity];
    for(int i = 0;i<=rear;i++)
    {
        arr[i]=otherQueue.arr[i];
    }
}

template <class T>
Queue<T>::~Queue()
{}

// Time Complexity: O(1)
template <class T>
void Queue<T>::enqueue(T item)
{
    if(isEmpty())
   {
    capacity+=100;rear++;
    arr = new T[capacity];arr[rear] = item;
   }
   else if(isFull())
   {
    capacity*=2;
    T* newArr = new T[capacity];
    for(int i = 0;i<=rear;i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;arr=newArr;arr[++rear] = item;newArr = NULL; delete newArr;
   }
   else
   {
    arr[++rear]=item;
   }
}

// Time Complexity: O(1)
template <class T>
T Queue<T>::front()
{
    if(isEmpty())
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        return arr[0];
    }
}

// Time Complexity: O(1)
template <class T>
T Queue<T>::dequeue()
{
    if(isEmpty())
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        T magicNum = arr[0];
        for(int i = 0;i<rear;i++)
        {
            arr[i] = arr[i+1];
        }
        rear--;return magicNum;
    }
}

// Time Complexity: O(n)
template <class T>
int Queue<T>::length()
{
    return rear+1;
}

// Time Complexity: O(1)
template <class T>
bool Queue<T>::isEmpty()
{
    if(rear<0) return 1;else return 0;
}

// Time Complexity: O(1)
template <class T>
bool Queue<T>::isFull()
{if(rear==capacity-1) return 1;else return 0;}
