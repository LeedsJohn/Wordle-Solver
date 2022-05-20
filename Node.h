// John Leeds
// 5/8/2022
// Node.h
// Header file for class Node

#ifndef NODE_HDR
#define NODE_HDR

#include "Word.h"

class Node
{
public:
    Node(Word &w);

    Word val;
    Node *next;
};

#endif