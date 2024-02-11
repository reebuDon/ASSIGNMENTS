#ifndef __STACKARR_H
#define __STACKARR_H
#include <memory>
#include <iostream>

using namespace std;

/* This is the array based Stack class */
template <class T>
class Stack
{
    T* arr;
    int capacity;
    int topInd;

  public:

    // Constructor
    Stack();

    // Copy Constructor
    Stack(Stack<T>& otherStack);

    // Destructor
    ~Stack();

    // Required Methods
    void push(T item);
    T top();
    T pop();
    int length();
    bool isEmpty();
    bool isFull();

    // Utility Method
    void printStack();;
};

#endif
