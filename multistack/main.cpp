#include <iostream>
#include "TMultiStack.h"
#include "TQueue.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
  int CurrCount = 1;
  TMultiStack<int> mst(100, 10);
  mst.Put(0, 10);
  srand(1);
  int ms = 10, ns, code, temp, val = 0;
  cout << "N Stack System Testing" << endl;
  while (CurrCount != 50)
  {
    val++;
    if (val == 141)
      int a = 1;
    code = rand() % 4; // операция
    ns = rand() % ms; // номер стека
    if (code < 3)
    {
      CurrCount++;
      mst.Put(ns, val);
    }
    else if (!mst.IsEmpty(ns))
    {
      CurrCount--;
      temp = mst.Get(ns);
    }
    mst.Print();
    cout << "Cycles - " << val << ", Repacking - " << mst.GetRelocationCount() << endl;
    cout << "Currently in multistek: " << CurrCount << endl << "\n";


  }
  return 0;
}