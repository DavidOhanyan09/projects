#include <algorithm>
#include <stdexcept>

template <typename T>
class LinkedList
{
private:
class Node 
{
public:
    T value;
    Node* next;
public:
    Node()
    {
        value = 0;
        next = nullptr;
    }
    Node(T data)
    {
        value = data;
        next = nullptr;
    }
};
private:
    Node* head;
public:
    LinkedList()
    {
        head = nullptr;
    }
    LinkedList(const LinkedList& other)
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
    LinkedList& operator=(const LinkedList& other)
    {
        if(this == &other)
        {
            return *this;
        }
        LinkedList temp(other);
        std::swap(this->head, temp.head);
        return *this;
    }
    LinkedList(LinkedList&& other)
    {
        head = other.head;
        other.head = nullptr;
    }
    LinkedList& operator=(LinkedList&& other)
    {
        if(this == &other)
        {
            return *this;
        }
        LinkedList temp(std::move(other));
        std::swap(this->head, temp.head);
        return *this;
    }
    ~LinkedList()
    {
        Node* temp = this->head;
        while(temp != nullptr)
        {
           Node* next = temp->next;
           delete temp;
           temp = next;
        }
        head = nullptr;
    }
    void InsertHead(T value)
    {
        if(head == nullptr)
        {
            head = new Node(value);
        }
        else
        {
            Node* new_head = new Node(value);
            new_head->next = head;
            head = new_head;
            return ;
        }
    }


    void Insert(int position, T value)
    {
        if(head == nullptr)
        {
            this->InsertHead(value);
            return;
        }
    if(position == 1)
    {
        this->InsertHead(value);
        return;
    }
    if(position == this->GetQ() + 1)
    {
        this->InsertTail(value);
        return;
    }
    if(position  > this->GetQ() + 1)
    {
        throw std::invalid_argument("Invalid Position!");
        return;
    }
    Node* NewNode = new Node(value);
    Node* temp = head;
    Node* prev = nullptr;
        
    for(int i = 1; i<position; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NewNode;
    NewNode->next = temp;
    return;
    }
    int Get(int position)
    {
        if(position > this->GetQ())
        {
            throw std::invalid_argument("There is no element in that position!");
        }
        Node* temp = head;
        for(int i = 1; i<position; i++)
        {
            temp = temp->next;
        }
        return temp->value;
    }
    void InsertTail(T value)
    {
        if(head == nullptr)
        {
            this->InsertHead(value);
            return;
        }
        Node* temp = head;
        Node* Tail = new Node(value);
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = Tail;
        return;
        }

    void Remove(int position)
    {
        Node* temp = head;
        Node* prev = nullptr;
        if(head == nullptr)
        {
            throw std::logic_error("There is no elements!");
        }
        if(position > this->GetQ())
        {
            throw std::invalid_argument("Invalid position!");
        }
        if(position == 1)
        {
           head = head->next;
           delete temp;
           return;
        }
        for(int i = 1; i<position; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
    int GetQ()
    {
        int quantity = 0;
        if(head == nullptr)
        {
            return quantity;
        }
        quantity++;
        Node* temp = head;
        while(temp->next != nullptr)
        {
            quantity++;
            temp = temp->next;
        }
        return quantity;
    }
};
