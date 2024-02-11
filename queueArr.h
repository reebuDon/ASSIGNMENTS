#ifndef __QUEUEARR_H
#define __QUEUEARR_H
#include <memory>

using namespace std;

/* This is the array based Queue class */
template <class T>
class Queue
{
    T* arr;
    int capacity;
    int rear;

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
    bool isFull();
};

#endif
