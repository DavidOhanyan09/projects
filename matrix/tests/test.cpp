#include <gtest/gtest.h>
#include <matrix.h>

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

