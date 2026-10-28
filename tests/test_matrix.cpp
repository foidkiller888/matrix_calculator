
#include "matrix.h"

#include <gtest/gtest.h>

TEST(MatrixTest, Addition)
{
    Matrix a = create_matrix(2, 2);
    Matrix b = create_matrix(2, 2);

    a.data[0][0] = 1;
    a.data[0][1] = 2;
    a.data[1][0] = 3;
    a.data[1][1] = 4;

    b.data[0][0] = 5;
    b.data[0][1] = 6;
    b.data[1][0] = 7;
    b.data[1][1] = 8;

    Matrix result = matrix_add(a, b);

    EXPECT_DOUBLE_EQ(result.data[0][0], 6);
    EXPECT_DOUBLE_EQ(result.data[0][1], 8);
    EXPECT_DOUBLE_EQ(result.data[1][0], 10);
    EXPECT_DOUBLE_EQ(result.data[1][1], 12);

    free_matrix(a);
    free_matrix(b);
    free_matrix(result);
}

TEST(MatrixTest, Multiplication)
{
    Matrix a = create_matrix(2, 2);
    Matrix b = create_matrix(2, 2);

    a.data[0][0] = 1;
    a.data[0][1] = 2;
    a.data[1][0] = 3;
    a.data[1][1] = 4;

    b.data[0][0] = 5;
    b.data[0][1] = 6;
    b.data[1][0] = 7;
    b.data[1][1] = 8;

    Matrix result = matrix_multiply(a, b);

    EXPECT_DOUBLE_EQ(result.data[0][0], 19);
    EXPECT_DOUBLE_EQ(result.data[0][1], 22);
    EXPECT_DOUBLE_EQ(result.data[1][0], 43);
    EXPECT_DOUBLE_EQ(result.data[1][1], 50);

    free_matrix(a);
    free_matrix(b);
    free_matrix(result);
}

TEST(MatrixTest, MinimumElement)
{
    Matrix m = create_matrix(2, 2);

    m.data[0][0] = 4;
    m.data[0][1] = -3;
    m.data[1][0] = 8;
    m.data[1][1] = 2;

    EXPECT_DOUBLE_EQ(matrix_min(m), -3);

    free_matrix(m);
}
