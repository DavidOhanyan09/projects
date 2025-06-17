#include <gtest/gtest.h>
#include "node.h"
#include "linkedlist.h"
TEST(empty_test, empty)
{

}

TEST(NODES, adding_one_node)
{
    Node* head = new Node(12);
    int expected = head->value;
    ASSERT_EQ(12, expected);
}

TEST(NODES, thepointer)
{
     Node* head = new Node(12);
     Node* expected = head->next;
     ASSERT_EQ(nullptr, expected);
}

TEST(NODES, head_insert)
{
    LinkedList* head = new LinkedList();
    head->InsertHead(12);
    int expected = head->GetHead()->value;
    ASSERT_EQ(expected, 12);
}

TEST(NODES, NodePosition)
{
    LinkedList* head = new LinkedList();
    head->InsertHead(12);
    int givven = head->Get(1);
    int expected = head->GetHead()->value;
    ASSERT_EQ(expected, givven);
}

TEST(NODES, INSERT)
{
    LinkedList* head = new LinkedList();
    head->InsertHead(1);
    head->InsertTail(4);
    head->Insert(2, 2);
    head->Insert(3, 3);
    int expeced_3 = 3;
    int actual = head->Get(3);
    ASSERT_EQ(expeced_3, actual);
}

TEST(NODES, Tail)
{
    LinkedList* head = new LinkedList();
    head->InsertHead(1);
    head->InsertTail(2);
    int expected = 2;
    int actual = head->Get(2);
    ASSERT_EQ(expected, actual);
}

