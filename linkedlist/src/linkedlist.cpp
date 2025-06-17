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
void LinkedList::Insert(int position, int value)
{
    Node* NewNode = new Node(value);
    if(head == nullptr)
    {
        head = NewNode;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    for(int i = 1; i<position; i++)
    {
        if(temp->next == nullptr)
        {
            std::cout << "ERROR!";
            return;
        }
        prev = temp;
        temp = temp->next;
        
    }
    prev->next = NewNode;
    NewNode->next = temp; 
}

int LinkedList::Get(int position)
{
    Node* temp = head;

    for(int i = 1; i<position; i++)
    {
        temp = temp->next;
    }
    return temp->value;
}

void LinkedList::InsertTail(int value)
{
    Node* temp = head;
    Node* Tail = new Node(value);
    if(head == nullptr)
    {
        head = Tail;
        return;
    }
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = Tail;
}

void LinkedList::Remove(int position)
{
    Node* temp = head;
    Node* prev = nullptr;
    if(head == nullptr)
    {
        std::cout << "There is no Node in the List!";
        return ;
    }
    for(int i = 1; i<position; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}