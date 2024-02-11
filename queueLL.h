#ifndef __QUEUELL_H
#define __QUEUELL_H
#include "LinkedList.h"

/* This is the generic Queue class */
template <class T>
class Queue
{
    LinkedList<T> list;

  public:

    // Constructor
    Queue();

    // Copy Constructor
    Queue(Queue<T>& otherQueue);

    // Destructor
    ~Queue();

    // Required Methods
    void enqueue(T item);
    T front();
    T dequeue();
    int length();
    bool isEmpty();
};

#endif
