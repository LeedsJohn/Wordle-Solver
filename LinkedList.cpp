// John Leeds
// 5/19/2022
// LinkedList.cpp
// Implementation file for class LinkedList

#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::add(Word &newWord)
{
    incrementLength();
    Node *newNode = new Node(newWord);
    newNode->next = head;
    head = newNode;
}

void LinkedList::erase(Node *prevNode)
{
    decrementLength();
    if (!prevNode)
    {
        eraseHead();
        return;
    }
    eraseMid(prevNode);
}

Node *LinkedList::getHead() const
{
    return head;
}

int LinkedList::getLength() const
{
    return length;
}

void LinkedList::eraseHead()
{
    head = head->next;
}

void LinkedList::eraseMid(Node *prevNode)
{
    prevNode->next = prevNode->next->next;
}

void LinkedList::incrementLength()
{
    length++;
}

void LinkedList::decrementLength()
{
    length--;
}