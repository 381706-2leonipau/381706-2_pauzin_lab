#include "TPolynom.h"
#include <iostream>
#include <cstdlib>

int main() 
{
  cout << "Polynom test" << endl;
  TPolynom pol1;
  for (int i = 0; i < 3; i++)
  {
    int ms[] = { i+1, i+2, i+3 };
	TMonom m(i + 1, 3, ms);
    pol1 += m;
  }
  cout << "1st polynom:" << endl << pol1 << endl;
  TPolynom pol2;
  for (int i = 0; i < 3; i++)
  {
    int ms[] = { i + 1, i + 2, i + 3 };
    TMonom m(i + 5, 3, ms);
    pol2 += m;
  }
  cout << "2nd polynom:" << endl << pol2 << endl;
  TPolynom pSum = pol1 + pol2;
  cout << "polynom sum:" << endl << pSum << endl;
  
  TPolynom pDiff = pol2 - pol1;
  cout << "polynom difference:" << endl << pDiff << endl;

  pol2 = pol1;
  cout << "polynom assignment (2nd = 1st):" << endl << pol2 << endl;
  return 0;
}