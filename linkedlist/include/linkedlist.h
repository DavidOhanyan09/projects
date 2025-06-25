

class LinkedList
{
private:
class Node 
{
public:
    int value;
    Node* next;
public:
    Node()
    {
        value = 0;
        next = nullptr;
    }
    Node(int data)
    {
        value = data;
        next = nullptr;
    }
};
private:
    LinkedList::Node* head;
    
public:
    LinkedList();
    LinkedList(const LinkedList& );
    LinkedList& operator=(const LinkedList&);
    LinkedList(const LinkedList&& );
    ~LinkedList();
    void InsertHead(int value);
    void Insert(int position, int value);
    int Get(int position);
    void InsertTail(int value);
    void Remove(int position);
    int GetQ();
};