#include "TDatList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  srand(time(0));
  TDatList<int> st;
  int pVal;
  int temp;
  cout << "list test" << endl;
  for (int i = 0; i<12; i++)
  {
    pVal = rand() % 25;
    st.InsLast(pVal);
    cout << "Put elem " << pVal << endl;
  }
  cout << "\n";
  for (int i = 0; i < st.GetListLength(); i++) {
    pVal = st.GetDatValue(i);
    cout << "Get elem " << pVal << endl;
  }
  st.DelList();
  return 0;
}