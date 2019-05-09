#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  int n;
  srand(time(0));
  int pVal;
  cout << "Arrlist test" << endl << "Enter list size: ";
  cin >> n;
  TArrList<int> st(n); 
  for (int i = 0; i < n; i++)
  {
    pVal = rand() % 100 + 1;
    st.InsLast(pVal);
    cout << "Put elem " << pVal << endl;
  }

  cout << "\n";
  for (int i = 0; i < st.GetListLength(); i++)
  {
    pVal = st.GetDatValue(i);
    cout << "Get elem " << pVal << endl;
  }
	
  return 0;
}