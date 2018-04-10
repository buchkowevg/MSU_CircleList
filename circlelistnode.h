#ifndef CIRCLE_LIST_NODE_H
#define CIRCLE_LIST_NODE_H

template <typename T>
class CircleList;

template <typename T>
class CircleListNode//nodes to be contained with a list
{
    friend class CircleList<T>;

public:
    CircleListNode(T);
    T getData();

private:
    T data; //templatized data stored in node
    CircleListNode* nextPtr; //pointer to the next node in list
};

template <typename T>
CircleListNode<T>::CircleListNode(T dataIn)
{
    data = dataIn; //stores data in node
    nextPtr = 0; //initializes point to next node to null
}

template <typename T>
T CircleListNode<T>::getData() //returns data stored in node
{
    return data;
}

#endif
