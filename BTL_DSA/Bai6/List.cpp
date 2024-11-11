#ifndef LIST_CPP
#define LIST_CPP
#include <bits/stdc++.h>
#include "iterator.cpp"
using namespace std;

template <typename T>
class MergeSort {
public:
    Node<T>* merge(Node<T>* left, Node<T>* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->getElem() <= right->getElem()) {
            left->setNext(merge(left->getNext(), right));
            return left;
        } else {
            right->setNext(merge(left, right->getNext()));
            return right;
        }
    }

    Node<T>* getMiddle(Node<T>* head) {
        if (!head) return head;

        Node<T>* slow = head;
        Node<T>* fast = head->getNext();

        while (fast != NULL) {
            fast = fast->getNext();
            if (fast != NULL) {
                slow = slow->getNext();
                fast = fast->getNext();
            }
        }
        return slow;
    }
    Node<T>* sort(Node<T>* head) {
        if (!head || !head->getNext()) return head;

        Node<T>* middle = getMiddle(head);
        Node<T>* nextOfMiddle = middle->getNext();

        middle->setNext(NULL);

        Node<T>* left = sort(head);
        Node<T>* right = sort(nextOfMiddle);

        return merge(left, right);
    }
};
template <typename T>
class s_list
{
private:
    Node<T> *head, *tail;
    int len;
    Node<T> *curr;


public:
    s_list() : head(NULL), tail(NULL), len(0) {}

    typedef Iterator<T> iterator;
    iterator begin() { return head; }
    iterator end() { return NULL; }

    int size()
    {
        return len;
    }
    bool empty()
    {
        if (len == 0)
            return 1;
        else
            return 0;
    }
    // front(), back() -> gtri dau, gtri cuoi
    // L.front() = 3
    T &front()
    {
        return head->getElem();
    }
    T &back()
    {
        return tail->getElem();
    }
    void push_front(T val)
    {
        head = new Node<T>(val, head);
        // tail
        // 0 phan tu -> 1
        len++;
        if (len == 1)
            tail = head;
    }
    void push_back(T val)
    {
        if (len == 0)
            push_front(val);
        else
        {
            tail->setNext(new Node<T>(val, NULL));
            tail = tail->getNext();
            ++len;
        }
    }
    void pop_front()
    {
        if (len == 0)
            return;
        if (len == 1)
            head = tail = NULL;
        else
        {
            head = head->getNext();
        }
        --len;
    }
    void pop_back()
    {
        if (len == 0)
            return;
        if (len == 1)
            head = tail = NULL;
        else
        {
            Node<T> *p = head;
            while (p->getNext() != tail)
                p = p->getNext();
            p->setNext(NULL);
            tail = p;
        }
        --len;
    }
    void add_elem(T x, int pos)
    {
        Node<T> *n = new Node<T>(x);
        if (len == 0 || pos == len + 1)
        {
            push_back(x);
            return;
        }
        if (pos == 1)
        {
            push_front(x);
            return;
        }
        if (pos > len || pos < 0)
        {
            cout << "Vi tri qua kich thuoc danh sach";
            return;
        }
        else
        {
            Node<T> *t = head;
            for (int i = 1; i < pos - 1; i++)
            {
                t = t->getNext();
            }
            n->getNext() = t->getNext();
            t->getNext() = n;
        }
    }
    int cout_elem(int x)
    {
        int cout = 0;
        Node<T> *t = head;
        while (t != NULL)
        {
            if (t->getElem() == x)
            {
                cout++;
            }
            t = t->getNext();
        }
        return cout;
    }

    void search_x() {
        Node<T> *t = head;
        int pos = 1;
        int ok = 0;
        while (t != NULL && t->getNext() != NULL && t->getNext()->getNext() != NULL) {
            if (t->getElem() % 2 == 0 && t->getNext()->getElem() % 2 == 0 && t->getNext()->getNext()->getElem() % 2 == 0) {
                cout << "\nCo 3 so chan duong dung canh nhau o vi tri " << pos << "," << pos + 1 << "," << pos + 2;
                ok++;
            }
            t = t->getNext();
            pos++;
        }
        if (ok == 0)
            cout << "\nDanh sach ko co 3 so duong ke nhau";
    }
    void sort() {
        MergeSort<T> sorter;
        head = sorter.sort(head);
        // Update tail after sorting
        Node<T>* temp = head;
        while (temp && temp->getNext()) {
            temp = temp->getNext();
        }
        tail = temp;
    }
    bool isPrime(int x) {
        if (x <= 1) {
            return false;
        }
        else {
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0)
                    return false;
            }
        }
        return true;
    }

    void removePrimes() {
        Node<T> *t = head;
        Node<T> *p = NULL;
        while (t != NULL) {
            if (isPrime(t->getElem())) {
                if (t == head) {
                    head = t->getNext();
                    delete t;
                    t = head;
                } else {
                    p->setNext(t->getNext());
                    Node<T> *temp = t;
                    t = t->getNext();
                    delete temp;
                }
            } else {
                p = t;
                t = t->getNext();
            }
        }
    }

    void removeDuplicates() {
    s_list<T> seen;  
    Node<T>* current = head;
    Node<T>* prev = NULL;

    while (current != NULL) {
        if (seen.cout_elem(current->getElem()) > 0) {
            prev->setNext(current->getNext());
            delete current;
            current = prev->getNext();
        } else {
            seen.push_back(current->getElem());
            prev = current;
            current = current->getNext();
        }
        }
    }

};
#endif