#include "../../include/LinkedList.h"

// Time Complexity: O(1)
template <class T>
LinkedList<T>::LinkedList():head(NULL),tail(NULL)
{}

// Time Complexity: O(n)
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
    if(!otherLinkedList.head)
 {
    head = NULL;
 }
 else
 {
    insertAtHead(otherLinkedList.head->value);
    shared_ptr<ListItem<T>> current,ocurrent;
    ocurrent = otherLinkedList.head,current = head;
    while(ocurrent->next)
    {
        shared_ptr<ListItem<T>> newC(new ListItem<T>(ocurrent->next->value));
        newC->prev = current;current->next = newC;current = newC;
        ocurrent=ocurrent->next;
    }
    tail = current;
 }
}

// Time Complexity: O(1)
template <class T>
void LinkedList<T>::insertAtHead(T item)
{
    shared_ptr<ListItem<T>> newH(new ListItem<T>(item));
        if(!head)
        {
            head = newH;tail = head;
        }
        else
        {
            newH->next = head;head->prev =newH;head = newH;
        }
}

// Time Complexity: O(1)
template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    if(!head)
    {
        insertAtHead(item);
    }
    else
    {
        shared_ptr<ListItem<T>> newT(new ListItem<T>(item));
    newT->prev = tail;tail->next = newT;tail = newT;
    }
}

// Time Complexity: O(n)
template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
    shared_ptr<ListItem<T>> current;
    if(!head)
    {
       return;
    }
    else
    {
        current = head;
        while(current)
        {
            if(current->value == afterWhat)
            {
                shared_ptr<ListItem<T>> newN(new ListItem<T>(toInsert));
                if(current->next)
                {
                  shared_ptr<ListItem<T>> cNext = current->next;
                  newN->next = cNext;cNext->prev= newN;
                  newN->prev = current;current->next = newN;
                }
                else
                {
                    insertAtTail(toInsert);
                }
                return;
            }
            else
            {
                current = current->next;
            }
        }
    }
}

// Time Complexity: O(1)
template <class T>
shared_ptr<ListItem<T>> LinkedList<T>::getHead()
{
    if(!head)
    {
    return NULL;
    }
    return head;
}

// Time Complexity: O(1)
template <class T>
shared_ptr<ListItem<T>> LinkedList<T>::getTail()
{
    if(!head)
    {
        return NULL;
    }
    return tail;
}

// Time Complexity: O(n)
template <class T>
shared_ptr<ListItem<T>> LinkedList<T>::searchFor(T item)
{
    if(!head)
    {
       return NULL;
    }
    shared_ptr<ListItem<T>> searcher=head;
    while(searcher)
    {
        if(searcher->value ==item)
        return searcher;
        searcher = searcher->next;
    }
    return NULL;
}

// Time Complexity: O(n)
template <class T>
void LinkedList<T>::deleteElement(T item)
{
     if(!head)
    {
        return;
    }
    else if(!head->next)
    {
       deleteHead();return;
    }
    shared_ptr<ListItem<T>> current = head;
    while(current)
    {
        if(current->value == item)
        {
            if(!current->next)
            {
                deleteTail();return;
            }
          shared_ptr<ListItem<T>> n = current->next;
          current->prev->next = n;
          n->prev = current->prev;
          current=NULL; return;

        }
        current = current->next;
    }
}

// Time Complexity: O(1)
template <class T>
void LinkedList<T>::deleteHead()
{
    if(!head)
  {
    return;
  }
  else
  {
    if(!head->next)
    {
        tail=NULL;head=NULL;return;
    }
    head = head->next;
    head->prev=NULL;return;
  }
}

// Time Complexity: O(1)
template <class T>
void LinkedList<T>::deleteTail()
{
    if(!head)
    {
        return;
    }
    else if(!head->next)
    {
        deleteHead();
    }
    else
    {
        tail = tail->prev;
        tail->next=nullptr;
    }
}

// Time Complexity: O(n)
template <class T>
int LinkedList<T>::length()
{
    int length = 0;
    shared_ptr<ListItem<T>>current = head;
    while(current)
    {
        length++;
        current = current->next;
    }
    return length;
}