#include "../../include/stackLL.h"

template <class T>
Stack<T>::Stack()
{}

// Time Complexity: O(n)    
template <class T>
Stack<T>::Stack(Stack<T>& otherStack)
{
    list = otherStack.list;
}

template <class T>
Stack<T>::~Stack()
{}

// Time Complexity: O(1)
template <class T> 
void Stack<T>::push(T item)
{
    list.insertAtHead(item);
}

// Time Complexity: O(1)
template <class T>
T Stack<T>::top()
{
    if(isEmpty())
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        shared_ptr<ListItem<T>> a = list.getHead();
        return a->value;
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
    else
    {
        shared_ptr<ListItem<T>> a =list.getHead();
        list.deleteHead();
        return a->value;
    }
}

// Time Complexity: O(n)
template <class T>
int Stack<T>::length()
{
    return list.length();
}

// Time Complexity: O(1)
template <class T>
bool Stack<T>::isEmpty()
{
    shared_ptr<ListItem<T>> t = list.getHead();
    if(!t)
    {
        return 1;
    }
    else return 0;
}
