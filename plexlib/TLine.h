#ifndef __CHARTLINE_H
#define __CHARTLINE_H
#include <TExeption.h>
#include <TPoint.h>
#include <TListStack.h>
#include <iostream>

using namespace std;

class TLine
{
protected:
  TPoint * a;
  TPoint* b;
public:
  TLine(TPoint * pA = NULL, TPoint * pB = NULL);
  TLine(TLine& cl);
  void SetA(TPoint*);
  void SetB(TPoint*);
  TPoint* GetA();
  TPoint* GetB();
  virtual void Show();
};
#endif