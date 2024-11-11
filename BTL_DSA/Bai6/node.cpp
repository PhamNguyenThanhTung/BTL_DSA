#include <bits/stdc++.h>
#ifndef NODE_CPP
#define NODE_CPP
using namespace std;
template <class T>
class Node
{
private:
    T elem;
    Node *next;

public:
    Node()
    {
    }
    Node(T x, Node<T> *n = NULL)
    {
        elem = x;
        next = n;
    }
    void setElem(T x)
    {
        elem = x;
    }
    T &getElem()
    {
        return elem;
    }
    void setNext(Node<T> *n = NULL)
    {
        next = n;
    }
    Node<T> *&getNext()
    {
        return next;
    }
};
#endif