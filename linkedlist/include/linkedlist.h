class LinkedList
{
private:
    Node* head;
public:
    LinkedList();
    void InsertHead(int value);
    Node* GetHead();
    void Insert(int position, int value);
    int Get(int position);
    void InsertTail(int value);
    void Remove(int position);
};