// John Leeds
// 5/19/2022
// LinkedList.h
// Header file for class LinkedList

#ifndef LINKEDLIST_HDR
#define LINKEDLIST_HDR

#include "Node.h"

class LinkedList
{
public:
    LinkedList();

    void add(Node *n);

    void erase(Node *prevNode);

private:
    Node *head;

    void eraseHead();

    void eraseMid(Node *prevNode);
};

#endif