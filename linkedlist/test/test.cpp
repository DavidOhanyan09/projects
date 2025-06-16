#include <gtest/gtest.h>
#include "node.h"

TEST(empty_test, empty)
{

}

TEST(NODES, adding_one_node)
{
    Node* head = new Node(12);
    int expected = head->GetValue();
    ASSERT_EQ(12, expected);
}

// TEST(NODES, thepointer)
// {
//     Node* head = new Node(12);
//     Node* expected = head->GetNext();
//     ASSERT_EQ(nullptr, expected);
// }
