#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  srand(time(0));
  TArrList<int> st(12);
  int pVal;
  int temp;
  cout << "Arrlist test" << endl;
  for (int i = 0; i<12; i++)
  {
    pVal = rand() % 25;
    st.InsLast(pVal);
    cout << "Put elem " << pVal << endl;
  }
  cout << "\n";
  // list output
  for (int i = 0; i < st.GetListLength(); i++)
  {
    pVal = st.GetDatValue(i);
    cout << "Get elem " << pVal << endl;
  }
  return 0;
}