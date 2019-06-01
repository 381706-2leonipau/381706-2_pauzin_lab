#include <gtest.h>
#include <TPlex.h>


TEST(TPlex, can_create_plex)
{
  ASSERT_NO_THROW(TPlex pl);
}

TEST(TPlex, can_set_left)
{
  TPlex pl;
  TPoint a(0, 0);
  ASSERT_NO_THROW(pl.SetLeft(&a));
}

TEST(TPlex, can_set_right)
{
  TPlex pl;
  TPoint a(0, 0);
  ASSERT_NO_THROW(pl.SetRight(&a));
}

TEST(TPlex, can_get_left)
{
  TPlex pl;
  TPoint a(0, 0);
  pl.SetLeft(&a);
  EXPECT_EQ(*pl.GetLeft() == a, 1);
}

TEST(TPlex, can_get_right)
{
  TPlex pl;
  TPoint a(0, 0);
  pl.SetRight(&a);
  EXPECT_EQ(*pl.GetRight() == a, 1);
}

TEST(TPlex, can_add_line)
{
  TPlex pl;
  TPoint a(0, 0), b(1, 1), c(2, 1);
  TLine l1(&a, &b), l2(&c, &b);
  ASSERT_NO_THROW(pl += l1;);
}

TEST(TPlex, can_add_line_right_to_right)
{
  TPlex pl;
  TPoint a(0, 0), b(1, 1), c(2, 1);
  TLine l1(&a, &b), l2(&c, &b);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetLeft() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TPlex*>(pl.GetRight())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TPlex*>(pl.GetRight())->GetLeft())) == c, 1);
}

TEST(TPlex, can_add_line_right_to_left)
{
  TPlex pl;
  TPoint a(0, 0), b(1, 1), c(2, 1);
  TLine l1(&a, &b), l2(&b, &c);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetLeft() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TPlex*>(pl.GetRight())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TPlex*>(pl.GetRight())->GetLeft())) == c, 1);
}

TEST(TChartPlex, can_add_line_left_to_right)
{
  TPlex pl;
  TPoint a(0, 0), b(1, 1), c(2, 1);
  TLine l1(&b, &a), l2(&c, &b);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetRight() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TPlex*>(pl.GetLeft())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TPlex*>(pl.GetLeft())->GetLeft())) == c, 1);
}

TEST(TPlex, can_add_line_left_to_left)
{
  TPlex pl;
  TPoint a(0, 0), b(1, 1), c(2, 1);
  TLine l1(&b, &a), l2(&b, &c);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetRight() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TPlex*>(pl.GetLeft())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TPlex*>(pl.GetLeft())->GetLeft())) == c, 1);
}