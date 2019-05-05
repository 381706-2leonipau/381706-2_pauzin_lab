#include <gtest.h>
#include <TPolinom.h>
#include <iostream>


TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p());
}

TEST(TPolinom, throw_when_add_different_size)
{
  TPolinom p1, p2, p;
  int ms1[] = { 1, 2, 3 };
  p1 += TMonom(5, 3, ms1);
  ASSERT_ANY_THROW(p = p1 + p2);
}

TEST(TPolinom, throw_when_sub_different_size)
{
  TPolinom p1, p2, p;
  int ms1[] = { 1, 2, 3 };
  p1 += TMonom(5, 3, ms1);
  ASSERT_ANY_THROW(p = p1 - p2);
}

TEST(TPolinom, can_add_polinom)
{
  TPolinom p1, p2, p3;
  for (int i = 0; i < 2; i++)
  {
    int ms1[] = { i + 1, i + 2, i + 3 };
    int ms2[] = { i + 1, i + 2, i + 3 };
    p1 += TMonom(i + 5, 3, ms1);
    p2 += TMonom(i + 6, 3, ms2);
  }
  p3 = p1 + p2;
  EXPECT_EQ(p3.GetDatValue(0).GetCoeff(), 11);
}

TEST(TPolinom, can_sub_polinom)
{
  TPolinom p1, p2, p3;
  for (int i = 0; i < 2; i++)
  {
    int ms1[] = { i + 1, i + 2, i + 3 };
    int ms2[] = { i + 1, i + 2, i + 3 };
    p1 += TMonom(i + 5, 3, ms1);
    p2 += TMonom(i + 6, 3, ms2);
  }
  p3 = p2 - p1;
  EXPECT_EQ(p3.GetDatValue(0).GetCoeff(), 1);
}

TEST(TPolinom, can_mult_polinom)
{
  TPolinom p1, p2, p3;
  for (int i = 0; i < 2; i++)
  {
    int ms1[] = { i + 1, i + 2, i + 3 };
    int ms2[] = { i + 1, i + 2, i + 3 };
    p1 += TMonom(i + 5, 3, ms1);
    p2 += TMonom(i + 6, 3, ms2);
  }
  p3 = p2 * p1;
  EXPECT_EQ(p3.GetDatValue(0).GetCoeff(), 30);
}


