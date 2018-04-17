#ifndef CIRCLELIST_H
#define CIRCLELIST_H
#include <iostream>
#include <stdexcept>
using namespace std;

#include "circlelistnode.h"
template <typename T>
class CircleList
{
public:
    CircleList();
    ~CircleList();
    void insert(T);
    void print() const;
    void rotateRight(unsigned int = 1);
    void rotateLeft(unsigned int = 1);
    T get_top();
    T get_at(int);
    T searchmax();
    T operator [](int) const;
private:
    CircleListNode<T> *currPtr;
    void deleteElem(int);
    bool isEmpty() const;
};


template <typename T>
CircleList<T>::CircleList() //creates list with start and end as NULL
{
    currPtr = NULL;
}

template <typename T>
CircleList<T>::~CircleList()
{
    if ( !isEmpty() ) // List is not empty
   {
      CircleListNode<T> *currentPtr = currPtr;
      CircleListNode<T> *tempPtr;
      currentPtr->prevPtr->nextPtr = 0;

      while ( currentPtr != 0 ) // delete remaining nodes
      {
         tempPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      }
   }
}

template <typename T>
bool CircleList<T>::isEmpty() const
{
    if(currPtr == NULL) //if the start pointer and end pointer are NULL then the list is empty
        return 1;
    else
        return 0;
}

template <typename T>
void CircleList<T>::insert(T dataIn)
{
    if(isEmpty()) //if the list is empty create first element of the list
    {
        CircleListNode<T> * newPtr = new CircleListNode<T>(dataIn); //creates new node
        currPtr = newPtr;
        currPtr->nextPtr = currPtr;
        currPtr->prevPtr = currPtr;
    }else //if node(s) exist in list insert additional object before the first
    {
        CircleListNode<T> * newPtr = new CircleListNode<T>(dataIn);
        newPtr->nextPtr = currPtr->nextPtr;
        newPtr->prevPtr = currPtr;
        currPtr->nextPtr->prevPtr = newPtr;
        currPtr->nextPtr = newPtr;
        
        
    }
}

template <typename T>
void CircleList<T>::print() const
{
    if(isEmpty())
    {
        cout << "The list is empty" << endl;

    }else
    {
        CircleListNode<T> * currentPtr = currPtr;

        cout << "The contents of the list is: ";
        do
        {
            cout << currentPtr->data << ' ';
            currentPtr = currentPtr->nextPtr; //moves to next node in list
        }while(currentPtr != currPtr);
        cout << endl;
    }
}

template <typename T>
void CircleList<T>::deleteElem(int pos)
{
    if(isEmpty()) throw runtime_error("List is empty\n");
    CircleListNode<T> * currentPtr = currPtr;
    if(currentPtr->nextPtr == currentPtr)
    {
        delete currPtr;
        currPtr = NULL;
        return;
    }
    if(pos < 0)
        for(int i = 0; i > pos; i--)
            currentPtr = currentPtr->prevPtr;
    else
        for(int i = 0; i < pos; i++)
            currentPtr = currentPtr->nextPtr;
    if(currentPtr == currPtr)
    {
        currPtr = currentPtr->nextPtr;
    }
    currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
    currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
    delete currentPtr;
}

template <typename T>
T CircleList<T>::get_top()
{
    if(isEmpty()) throw runtime_error("List is empty\n");
    T res = currPtr->getData();
    deleteElem(0);
    return res;
}

template <typename T>
T CircleList<T>::get_at(int pos)
{
    T res;
    if(isEmpty()) throw runtime_error("List is empty\n");
    CircleListNode<T> * currentPtr = currPtr;
    if(currentPtr->nextPtr == currentPtr) return get_top();
    if(pos < 0)
        for(int i = 0; i > pos; i--)
            currentPtr = currentPtr->prevPtr;
    else
        for(int i = 0; i < pos; i++)
            currentPtr = currentPtr->nextPtr;
    if(currentPtr == currPtr) return get_top();
    res = currentPtr->getData();
    deleteElem(pos);
    return res;
}
template <typename T>
T CircleList<T>::operator[](int pos) const
{
    if(isEmpty()) throw runtime_error("List is empty\n");
    CircleListNode<T> * currentPtr = currPtr;
    if(pos < 0)
        for(int i = 0; i > pos; i--)
            currentPtr = currentPtr->prevPtr;
    else
        for(int i = 0; i < pos; i++)
            currentPtr = currentPtr->nextPtr;
    return currentPtr->getData();

}
template <typename T>
T CircleList<T>::searchmax()
{
    T res;
    if(isEmpty()) throw runtime_error("List is empty\n");
    CircleListNode<T> * tempPtr = currPtr;
    CircleListNode<T> * currentPtr = currPtr;
    if(currentPtr->nextPtr == currentPtr) return get_top();
    do
    {
        if(currentPtr->data > tempPtr->data) tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr; 
    }while(currentPtr != currPtr);
    res = tempPtr->data;
    currPtr = tempPtr;
    get_top();
    currPtr = currPtr->prevPtr;
    return res;
}
template <typename T>
void CircleList<T>::rotateLeft(unsigned int r)
{
    if(isEmpty()) throw runtime_error("List is empty\n");
    for(unsigned int i = 0; i < r; i++)
        currPtr = currPtr->prevPtr;
}
template <typename T>
void CircleList<T>::rotateRight(unsigned int r)
{
    if(isEmpty()) throw runtime_error("List is empty\n");
    for(unsigned int i = 0; i < r; i++)
        currPtr = currPtr->nextPtr;
}
#endif // CIRCLELIST_H
