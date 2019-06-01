#ifndef __CHARTPLEX_H
#define __CHARTPLEX_H
#include <TExeption.h>
#include <TPoint.h>
#include <TLine.h>
#include <TListStack.h>
#include <iostream>

using namespace std;

class TPlex : public TPoint
{
protected:
  TPoint* right;
  TPoint * left;
  virtual TPoint* Show(TPlex* p);
public:
  TPlex();
  TPlex(TPlex& cp);
  TPlex(TPoint* l, TPoint* r);
  TPlex& operator +=(TLine &line);
  TPoint* GetLeft();
  TPoint* GetRight();
  void SetLeft(TPoint*);
  void SetRight(TPoint*);
  virtual void Show();
};
#endif