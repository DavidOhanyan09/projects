#include <gtest/gtest.h>
#include <matrix.h>
#include <iostream>

TEST(empty_test, empty)
{

}

TEST(Matrixes, GET_ELEM)
{
    Matrix<int> matrix(1,1);
    matrix.fill(1, 1, 15);
    ASSERT_EQ(15, matrix.Get(1, 1));
}

TEST(Matrixes, GET_ELEM2)
{
    Matrix<int> matrix(1,2);
    matrix.fill(1,1,10);
    matrix.fill(1,2,20);
    ASSERT_EQ(20, matrix.Get(1,2));
}

TEST(Matrixes, random1)
{
    Matrix<int> matrix(1,3);
    matrix.fill(1,1,5);
    EXPECT_THROW(matrix.Get(1,5), std::invalid_argument);
}

// TEST(Matrixes, copyconstructor)
// {
//     Matrix<int> matrix(1,1);
//     matrix.fill(1,1,100);
//     Matrix<int> copy(matrix);
//     ASSERT_EQ(copy.Get(1,1), 100);
// }