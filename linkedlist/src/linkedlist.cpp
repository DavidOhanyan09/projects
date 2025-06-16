#include <iostream>
#include "node.h"
#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
}
void LinkedList::InsertHead(int value)
{
    head->value = value;
    head->next = nullptr;
}

