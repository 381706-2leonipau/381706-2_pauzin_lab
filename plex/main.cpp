#include "TPlex.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  const int c = 4;
  TPlex pl;
  TPoint p[c];
  TLine l;
  cout << "Enter " << c <<" Points" << endl;
  for (int i = 0; i < c; i++)
  {
    int buff;
	cout << "x" << i + 1 << " = ";
    cin >> buff;
    p[i].SetX(buff);
	cout << "y" << i + 1 << " = ";
    cin >> buff;
    p[i].SetY(buff);
  }
  for (int i = 0; i < c - 1; i++)
  {
    l.SetA(p + i);
    l.SetB(p + i + 1);
    pl += l;
  }
  pl.Show();
  return 0;
}