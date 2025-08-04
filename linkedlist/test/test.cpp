#include <gtest/gtest.h>
#include "linkedlist.h"
#include <stdexcept>

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
    ASSERT_EQ(list.Get(4), 4);
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
    ASSERT_EQ(4, expected);
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
    EXPECT_EQ(list.Get(4), 4);
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

TEST(NODES, templates)
{
    LinkedList<float> list;
    list.InsertHead(123.41234234);
    list.Insert(2, 123.862384762);
    LinkedList<float> listcopy(list);
    ASSERT_EQ(list.Get(1), listcopy.Get(1));
    ASSERT_EQ(list.Get(2), listcopy.Get(2));
}

TEST(NODES, headinsert)
{
    LinkedList<int> list;
    list.InsertHead(13);
    list.InsertHead(14);
    list.InsertHead(15);
    list.InsertHead(16);
    list.Insert(1, 20);
    ASSERT_EQ(20, list.Get(1));
}

TEST(NODES, copy_operator)
{
    LinkedList<int> list;
    list.InsertHead(13);
    list.Insert(2, 15);
    LinkedList<int> copy;
    copy.InsertHead(16);
    copy.Insert(2, 18);
    copy = list;
    ASSERT_EQ(list.Get(1), copy.Get(1));
}

TEST(NODES, operator2)
{
    LinkedList<int> list;
    list.InsertHead(13);
    list.Insert(2, 15);
    LinkedList<int> copy;
    copy.InsertHead(13);
    copy.Insert(2, 15);
    copy = list;
    ASSERT_EQ(list.Get(1), copy.Get(1));
}

TEST(NODES, move)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.Insert(2,13);
    LinkedList<int> listcopy(std::move(list));
    ASSERT_EQ(13, listcopy.Get(2));
}

TEST(NODES, moveoperator)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.Insert(2, 13);
    LinkedList<int> listcopy;
    listcopy.InsertHead(19);
    listcopy.Insert(2, 128);
    listcopy.Insert(3, 1238);
    listcopy = std::move(list);
    ASSERT_EQ(listcopy.Get(2), 13);
    ASSERT_EQ(listcopy.Get(1), 12);
}


TEST(NODES, random)
{
    LinkedList<int> list;
    list.InsertHead(1);
    list.Insert(2,2);
    list.Insert(2, 5);
    list.Insert(2, 4);
    EXPECT_EQ(list.Get(4), 2);
}

TEST(NODES, exception)
{
    LinkedList<int> list;
    list.InsertTail(17);
    list.Insert(2, 14);
    EXPECT_THROW(list.Get(3), std::invalid_argument);
}

TEST(NODES, random2)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.InsertHead(14);
    list.Insert(1, 100);
    list.InsertTail(19);
    list.Insert(5, 200);
    EXPECT_EQ(list.Get(1), 100);
    EXPECT_EQ(list.GetQ(), 5);
    EXPECT_EQ(list.Get(5), 200);
}

TEST(Nodes, insert_head)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.InsertHead(24);
    ASSERT_EQ(list.Get(1), 24);
}

TEST(Nodes, quantity)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.InsertHead(24);
    ASSERT_EQ(list.GetQ(), 2);
}

TEST(Nodes, tail)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.InsertHead(24);
    list.InsertTail(199);
    list.InsertTail(1231);
    ASSERT_EQ(list.Get(4), 1231);
}

TEST(Nodes, element)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.InsertHead(24);
    ASSERT_EQ(list.Get(2), 12);
}

TEST(Nodes, expception)
{
    LinkedList<int> list;
    list.InsertHead(12);
    EXPECT_THROW(list.Get(198), std::invalid_argument);
}

TEST(Nodes, rmv)
{
    LinkedList<int> list;
    EXPECT_THROW(list.Remove(1), std::logic_error);
}

TEST(Nodes, rmv2)
{
    LinkedList<int> list;
    list.InsertHead(12);
    list.InsertHead(14);
    list.InsertHead(15);
    list.Remove(3);
    ASSERT_EQ(list.Get(2), 14);
}

 TEST(Nodes, insert1)
 {
    LinkedList<int> list;
    list.Insert(1, 15);
    list.Insert(1, 199);
    list.Insert(3, 100);
    list.Insert(1, 1000);
    ASSERT_EQ(list.Get(4), 100);
 }


 TEST(Nodes, insert2)
 {
    LinkedList<int> list;
    list.InsertHead(19);
    list.InsertTail(100);
    list.Insert(3, 120);
    ASSERT_EQ(list.Get(3), 120);
 }

 TEST(Nodes, insert3)
 {
    LinkedList<int> list;
    list.InsertHead(20);
    list.InsertTail(1223);
    list.Insert(3, 10);
    list.Insert(2, 102);
    list.InsertHead(123123);
    list.Insert(3, 55);
    EXPECT_EQ(list.Get(3), 55);
    EXPECT_EQ(list.Get(4), 102);
    EXPECT_EQ(list.Get(5), 1223);
 }

 TEST(Nodes, Remove_Exception)
 {
    LinkedList<int> list;
    list.InsertHead(10);
    list.InsertTail(15);
    EXPECT_THROW(list.Remove(3), std::invalid_argument);
 }

 TEST(Nodes, Remove_Exception2)
 {
    LinkedList<int> list;
    EXPECT_THROW(list.Remove(1), std::logic_error);
 }