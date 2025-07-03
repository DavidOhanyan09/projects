#include <algorithm>
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
        if(head == nullptr or head->next == nullptr)
        {
            head = new Node(value);
        }
        else
        {
            Node* new_head = new Node(value);
            new_head->next = head;
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
        int Get(int position)
        {
            Node* temp = head;
        for(int i = 1; i<position; i++)
        {
            temp = temp->next;
        }
        return temp->value;
    }
    void InsertTail(T value)
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
        void Remove(int position)
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
    int GetQ()
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
};



