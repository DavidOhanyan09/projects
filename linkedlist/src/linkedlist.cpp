#include <iostream>
#include "node.h"
#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
}
void LinkedList::InsertHead(int value)
{
    head = new Node(value);
}
Node* LinkedList::GetHead()
{
    return head;
}
