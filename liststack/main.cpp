#include <iostream>
#include <TListStack.h>
#include <ctime>
#include <cstdlib>

int main()
{
  srand(time(NULL));
  TListStack<int> mst;
  int code, temp, val = 0;
  cout << "liststack test" << endl;
  while (val < 100)
  {
    val++;
    code = rand() % 4;
    if (code<2)
      mst.Put(val);
    else if (!mst.IsEmpty())
      temp = mst.Get();
  }
  cout << "Stack output" << endl;
  mst.Print();
  return 0;
}