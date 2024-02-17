#include <gtest/gtest.h>

#include "matrix.hpp"

using namespace Task07;

struct MatrixTest : testing::Test {
    Matrix<int>* m1;
    Matrix<int>* m1transposed;
    Matrix<int>* m2;

    void TearDown() override {
        delete m1;
        delete m1transposed;
        delete m2;
    }
    void SetUp() override {
        m1 = new Matrix{{1,4,3},{6,2,5},{8,7,9}};

        m1transposed = new Matrix{{1,6,8},{4,2,7},{3,5,9}};

        m2 = new Matrix{{1,4,3},{6,2,5},{8,7,9}};
    }
};

TEST_F(MatrixTest, transposeEquals) {
    const Matrix actual = m1->transpose();
    ASSERT_EQ(*m1transposed, actual);
}