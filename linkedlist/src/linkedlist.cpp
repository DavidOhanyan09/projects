#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList ()
{
    head = nullptr;
}

LinkedList::LinkedList (const LinkedList& other)
{
    if(other.head == nullptr)
    {
        this->head = nullptr;
        return;
    }
    this->head = new Node(other.head->value);
    Node* temp = this->head;
    Node* othertemp = other.head->next;
    while(othertemp != nullptr)
    {
        temp->next = new Node(othertemp->value);
        temp = temp->next;
        othertemp = othertemp->next;
    }
    return;
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if(other.head == nullptr)
    {
        this->head = nullptr;
        return *this;
    }
    this->head = new Node(other.head->value);
    Node* temp = this->head;
    Node* othertemp = other.head->next;
    while(othertemp != nullptr)
    {
        temp->next = new Node(othertemp->value);
        temp = temp->next;
        othertemp = othertemp->next;
    }
    return *this;
}

LinkedList::LinkedList (const LinkedList&& other)
{
    
}

LinkedList::~LinkedList()
{

}

void LinkedList::InsertHead(int value)
{
    if(head == nullptr)
    {
        head = new Node(value);
    }
    else
    {
        //exception
    }
    
}

void LinkedList::Insert(int position, int value)
{
    if(head == nullptr)
    {
        this->InsertHead(value);
        return;
    }
    Node* NewNode = new Node(value);
    Node* temp = head;
    Node* prev = nullptr;
    if(temp->next == nullptr)
    {
        this->InsertTail(value);
        return;
    }
    if(position + 1 > this->GetQ())
    {
        this->InsertTail(value);
        return;
    }
    for(int i = 1; i<position; i++)
    {
        if(temp->next == nullptr)
        {
            //exception
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
        //exception
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


int LinkedList::GetQ()
{
    int quantity = 1;
    Node* temp = head;
    while(temp != nullptr)
    {
        quantity++;
        temp = temp->next;
    }
    delete temp;
    return quantity;
}