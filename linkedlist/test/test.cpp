#include <gtest/gtest.h>
#include "linkedlist.h"
TEST(empty_test, empty)
{

}


TEST(NODES, head_insert)
{
    LinkedList<int> list;
    list.InsertHead(12);
    int expected = list.Get(1);
    ASSERT_EQ(expected, 12);
}

TEST(NODES, INSERT)
{
    LinkedList<int> list;
    list.InsertHead(1);
    list.InsertTail(4);
    list.Insert(2, 2);
    list.Insert(3, 3);
    int expeced_3 = 3;
    int actual = list.Get(3);
    ASSERT_EQ(expeced_3, actual);
}

TEST(NODES, Tail)
{
    LinkedList<int> list;
    list.InsertHead(1);
    list.InsertTail(2);
    int expected = 2;
    int actual = list.Get(2);
    ASSERT_EQ(expected, actual);
}

TEST(NODES, Remove2)
{
    LinkedList<int> list;
    list.InsertHead(1);
    list.InsertTail(4);
    list.Insert(2,2);
    list.Insert(3,3);
    list.Remove(2);
    int expected = 3;
    int actual = list.Get(2);
    ASSERT_EQ(expected, actual);
}

TEST(NODES, RemoveTail)
{
    LinkedList<int> list;
    list.InsertHead(1);
    list.InsertTail(4);
    list.Insert(2, 2);
    list.Insert(3,3);
    list.Remove(4);
    int expected = 3;
    int actual = list.Get(3);
    ASSERT_EQ(expected, actual);
}

TEST(NODES, GetQ)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.InsertTail(15);
    list.Insert(2, 13);
    list.Insert(3, 14);
    int expected = list.GetQ();
    ASSERT_EQ(5, expected);
}

TEST(NODES, get)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.InsertTail(14);
    list.Insert(2, 13);
    int expected = list.Get(3);
    ASSERT_EQ(expected, 14);
}
TEST(NODES, headbug)
{
    LinkedList<int> list;
    list.Insert(1, 13);
    ASSERT_EQ(13, list.Get(1));
}
TEST(NODES, tailbug)
{
    LinkedList<int> list;
    list.InsertHead(1);
    list.Insert(2, 2);
    ASSERT_EQ(list.Get(2), 2);
}
TEST(NODES, tailbug2)
{
    LinkedList<int> list;
    list.InsertHead(1);
    list.InsertTail(4);
    list.Insert(2,2);
    list.Insert(3,3);
    list.Insert(123, 5);
    ASSERT_EQ(5, list.Get(5));
}
TEST(NODES, copy)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.Insert(2, 13);
    list.Insert(3, 14);
    LinkedList<int> listcopy(list);
    ASSERT_EQ(listcopy.Get(1), list.Get(1));
    ASSERT_EQ(listcopy.Get(2), list.Get(2));
    ASSERT_EQ(listcopy.Get(3), list.Get(3));
}
TEST(NODES, operatortest1)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.Insert(2,13);
    LinkedList<int> listcopy = list;
    ASSERT_EQ(list.Get(1), listcopy.Get(1));
    ASSERT_EQ(list.Get(2), listcopy.Get(2));
}

TEST(NODES, operatortest2)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.Insert(2, 14);
    list.Insert(3, 16);
    LinkedList<int> listcopy;
    listcopy.InsertHead(177);
    listcopy = list;
    ASSERT_EQ(list.Get(1), listcopy.Get(1));
}

TEST(NODES, templates)
{
    LinkedList<float> list;
    list.InsertHead(123.41234234);
    list.Insert(2, 123.862384762);
    LinkedList<float> listcopy;
    listcopy = list;
    ASSERT_EQ(list.Get(1), listcopy.Get(1));
    ASSERT_EQ(list.Get(2), listcopy.Get(2));
}

// TEST(NODES, move)
// {
//     LinkedList list;
//     list.InsertHead(12);
//     list.Insert(13,2);
//     LinkedList listcopy(std::move(list));
//     ASSERT_EQ(12, listcopy.Get(1));
//     ASSERT_EQ(13, listcopy.Get(2));
// }
TEST(NODES, twoheads)
{
    try
    {
    LinkedList<int> list;
    list.InsertHead(12);
    list.InsertHead(13);
    int expected = list.Get(2);
    ASSERT_EQ(expected, 13);
    }
    catch(...)
    {
        std::cout << "Head already exist!" << std::endl;
    }
}
