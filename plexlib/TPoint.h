#ifndef __CHART_H
#define __CHART_H
#include <TExeption.h>
#include <TListStack.h>
#include <iostream>

using namespace std;

class TPoint
{
protected:
  double x, y;
public:
  TPoint(double _x = 0, double _y = 0);
  TPoint(TPoint& cp);
  virtual void Show();
  void SetX(double _x);
  void SetY(double _y);
  double GetX();
  double GetY();
  int operator== (const TPoint&);
  int operator!= (const TPoint&);
};
#endif