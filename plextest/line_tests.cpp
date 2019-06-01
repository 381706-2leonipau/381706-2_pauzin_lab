#include <gtest.h>
#include <TLine.h>

TEST(TLine, can_create_line)
{
  ASSERT_NO_THROW(TLine l);
}

TEST(TLine, can_set_a)
{
  TLine l;
  TPoint a(0, 1);
  ASSERT_NO_THROW(l.SetA(&a));
}

TEST(TLine, can_set_b)
{
  TLine l;
  TPoint a(0, 1);
  ASSERT_NO_THROW(l.SetB(&a));
}

TEST(TLine, can_get_a)
{
  TLine l;
  TPoint a(0, 1);
  l.SetA(&a);
  EXPECT_EQ(*l.GetA() == a, 1);
}

TEST(TLine, can_get_b)
{
 
  TLine l;
  TPoint b(0, 1);
  l.SetB(&b);
  EXPECT_EQ(*l.GetB() == b, 1);
}