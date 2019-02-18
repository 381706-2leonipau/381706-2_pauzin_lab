#include <gtest.h>
#include <TMatrix.h>
#include <iostream>


TEST(TMatrix, can_create_matrix_with_positive_size)
{
  ASSERT_NO_THROW(TMatrix<int> v(3));
}

TEST(TMatrix, throw_when_negative_size)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-3));
}


TEST(TMatrix, can_add_matrix)
{
  const int size = 2;
  TMatrix<int> MyMt1(size), MyMt2(size), MyMt3(size);
  MyMt1[0][0] = 1;
  MyMt1[0][1] = 1;
  MyMt1[1][1] = 1;
  MyMt2[0][0] = 2;
  MyMt2[0][1] = 2;
  MyMt2[1][1] = 2;
  MyMt3[0][0] = 3;
  MyMt3[0][1] = 3;
  MyMt3[1][1] = 3;
  EXPECT_EQ(1, (MyMt3 == (MyMt2 + MyMt1)));
}

TEST(TMatrix, can_invert_matrix)
{
  TMatrix<double> test(4);
  TMatrix<double> E(4);
  E[0][0] = 1;
  E[1][1] = 1;
  E[2][2] = 1;
  E[3][3] = 1;
  test[0][0] = 3;
  test[0][1] = 1;
  test[0][2] = 2;
  test[0][3] = 1;
  test[1][1] = 8;
  test[1][2] = 3;
  test[1][3] = 2;
  test[2][2] = 6;
  test[2][3] = 4;
  test[3][3] = 4;
  EXPECT_EQ((test.invert() * test) == E, 1);
}

TEST(TMatrix, can_div_matrix)
{
  TMatrix<double> test1(4);
  TMatrix<double> test2(4);
  TMatrix<double> res(4);
  res[0][0] = 48;
  res[0][1] = 6;
  res[0][2] = 45;
  res[0][3] = 36;
  res[1][1] = 6;
  res[1][2] = 53;
  res[1][3] = -32;
  res[2][2] = 32;
  res[2][3] = -20;
  res[3][3] = 12;
  test2[0][0] = 144;
  test2[0][1] = 96;
  test2[0][2] = 384;
  test2[0][3] = 384;
  test2[1][1] = 48;
  test2[1][2] = 336;
  test2[1][3] = 96;
  test2[2][2] = 192;
  test2[2][3] = 48;
  test2[3][3] = 48;
  test1[0][0] = 3;
  test1[0][1] = 1;
  test1[0][2] = 2;
  test1[0][3] = 1;
  test1[1][1] = 8;
  test1[1][2] = 3;
  test1[1][3] = 2;
  test1[2][2] = 6;
  test1[2][3] = 4;
  test1[3][3] = 4;
  EXPECT_EQ(test2/test1 == res, 1);
}

TEST(TMatrix, can_assign_matrix_of_equal_size)
{
  TMatrix<int> MyM1(2), MyM2(2);
  for (int i = 0; i < MyM1.GetSize(); i++)
    for (int j = i; j < MyM1.GetSize(); j++)
    {
      MyM1[i][j] = i + j;
    }
  MyM2 = MyM1;

  EXPECT_EQ(2, MyM2[1][1]);
}

TEST(TMatrix, can_subtract_matrix)
{
  const int size = 2;
  TMatrix<int> MyMt1(size), MyMt2(size), MyMt3(size);
  MyMt1[0][0] = 1;
  MyMt1[0][1] = 1;
  MyMt1[1][1] = 1;
  MyMt2[0][0] = 2;
  MyMt2[0][1] = 2;
  MyMt2[1][1] = 2;
  MyMt3[0][0] = 3;
  MyMt3[0][1] = 3;
  MyMt3[1][1] = 3;
  EXPECT_EQ(1, (MyMt1 == (MyMt3 - MyMt2)));
}

TEST(TMatrix, can_multiply_matrix)
{
  const int size = 2;
  TMatrix<int> MyMt1(size), MyMt2(size), MyMt3(size);
  MyMt1[0][0] = 5;
  MyMt1[0][1] = 3;
  MyMt1[1][1] = 1;
  MyMt2[0][0] = 3;
  MyMt2[0][1] = 2;
  MyMt2[1][1] = 1;
  MyMt3[0][0] = 15;
  MyMt3[0][1] = 13;
  MyMt3[1][1] = 1;
  EXPECT_EQ(1, (MyMt3 == (MyMt1 * MyMt2)));
}

TEST(TMatrix, throws_when_add_diferrent_size_matrix)
{
  const int size = 2;
  TMatrix<int> MyMt1(size), MyMt2(size + 1);
  ASSERT_ANY_THROW(MyMt1 + MyMt2);
}

TEST(TMatrix, throws_when_subtract_diferrent_size_matrix)
{
  const int size = 2;
  TMatrix<int> MyMt1(size), MyMt2(size + 1);
  ASSERT_ANY_THROW(MyMt1 - MyMt2);
}

TEST(TMatrix, throws_when_myltiply_diferrent_size_matrix)
{
  const int size = 2;
  TMatrix<int> MyMt1(size), MyMt2(size + 1);
  ASSERT_ANY_THROW(MyMt1 * MyMt2);
}
