#include <TLine.h>

TLine::TLine(TPoint * pA, TPoint * pB)
{
  a = pA;
  b = pB;
}


TLine::TLine(TLine & cl)
{
  a = cl.a;
  b = cl.b;
}


void TLine::SetA(TPoint* p)
{
  a = p;
}

void TLine::SetB(TPoint* p)
{
  b = p;
}

TPoint * TLine::GetA()
{
  return a;
}

TPoint * TLine::GetB()
{
  return b;
}

void TLine::Show()
{
	cout << "a : ";
	a->Show();
	cout << endl << "b : ";
	b->Show();
}