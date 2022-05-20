// John Leeds
// 5/19/2022
// LinkedList.cpp
// Header file for class LinkedList

#ifndef LINKEDLIST_HDR
#define LINKEDLIST_HDR

#include "Node.h"

class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
    }

    void add(Node *n)
    {
        n->next = head;
        head = n;
    }

    void erase(Node *prevNode)
    {
        if (!prevNode)
        {
            eraseHead();
            return;
        }
        eraseMid(prevNode);
    }

private:
    Node *head;

    void eraseHead(){
        head = head->next;
    }

    void eraseMid(Node *prevNode){
        prevNode->next = prevNode->next->next;
    }
};

#endif