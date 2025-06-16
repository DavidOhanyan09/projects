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