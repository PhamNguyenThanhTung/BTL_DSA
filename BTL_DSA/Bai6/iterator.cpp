#include <bits/stdc++.h>
#include "node.cpp"
#ifndef ITERATOR_CPP
#define ITERATOR_CPP
using namespace std;
template <class T>
class Iterator
{
private:
    Node<T> *curr;

public:
    Iterator()
    {
        curr = NULL;
    }
    Iterator(Node<T> *x)
    {
        curr = x;
    }
    Node<T> *getCurr()
    {
        return curr;
    }
    Iterator<T> &operator=(Iterator<T> it)
    {
        this->curr = it.getCurr();
        return *this;
    }
    bool operator!=(Iterator<T> it)
    {
        return this->curr != it.getCurr();
    }
    Iterator operator++()
    {
        curr = curr->getNext();
        return curr;
    }
    Iterator operator++(int)
    {
        Node<T> *temp = curr;
        curr = curr->getNext();
        return temp;
    }
    T &operator*()
    {
        return curr->getElem();
    }
};
#endif