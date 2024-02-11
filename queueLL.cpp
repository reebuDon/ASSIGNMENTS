#include "../../include/queueLL.h"

template <class T>
Queue<T>::Queue()
{}

// Time Complexity: O(n)    
template <class T>
Queue<T>::Queue(Queue<T>& otherQueue)
{
    list = otherQueue.list;
}

template <class T>
Queue<T>::~Queue()
{}

// Time Complexity: O(1)
template <class T>
void Queue<T>::enqueue(T item)
{
    list.insertAtTail(item);
}

// Time Complexity: O(1)
template <class T>
    T Queue<T>::front()
{
    if(!(isEmpty()))
    {
        shared_ptr<ListItem<T>> F = list.getHead();
        return F->value;
    }
    else
    {
        exit(EXIT_FAILURE);
        };
}

// Time Complexity: O(1)
template <class T>
T Queue<T>::dequeue()
{
    if(!(isEmpty()))
    {
        shared_ptr<ListItem<T>> F = list.getHead();list.deleteHead();
        return F->value;
    }
    else
    {
        cout<<"The queue is empty";
        exit(EXIT_FAILURE);
        };
}

// Time Complexity: O(n)
template <class T>
int Queue<T>::length()
{
    return list.length();
}

// Time Complexity: O(1)
template <class T>
bool Queue<T>::isEmpty()
{
    shared_ptr<ListItem<T>> head = list.getHead();
    if(head)
    {
        return 0;
    }
    else return 1;
}