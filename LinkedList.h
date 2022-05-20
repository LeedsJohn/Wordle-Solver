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

    void add(Word &newWord);

    void erase(Node *prevNode);

    Node* getHead() const;

    int getLength() const;

private:
    Node *head;
    int length;

    void eraseHead();

    void eraseMid(Node *prevNode);

    void incrementLength();

    void decrementLength();
};

#endif