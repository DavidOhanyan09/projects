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