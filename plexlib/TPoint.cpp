#include "TPoint.h"

TPoint::TPoint(double _x, double _y)
{
  x = _x;
  y = _y;
}

TPoint::TPoint(TPoint & cp)
{
  x = cp.x;
  y = cp.y;
}

void TPoint::Show()
{
  cout << "x = " << x;
  cout << " y = " << y;
}

void TPoint::SetX(double _x)
{
  x = _x;
}

void TPoint::SetY(double _y)
{
  y = _y;
}

int TPoint::operator==(const TPoint &p)
{
  if (x == p.x && y == p.y)
    return 1;
  return 0;
}

int TPoint::operator!=(const TPoint &p)
{
  return !(*this == p);
}

double TPoint::GetX()
{
  return x;
}

double TPoint::GetY()
{
  return y;
}