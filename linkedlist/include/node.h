class Node 
{
private:
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
    int GetValue()
    {
        return this->value;
    }
    Node* GetNext()
    {
        return this->next;
    }
};