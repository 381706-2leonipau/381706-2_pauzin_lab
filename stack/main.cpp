#include <TStack.h>
#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
  TStack<int> st(100);
  int temp;
  cout << "Stack" << endl;
  for (int i = 0; i<12; i++)
  {
    st.Put(i);
    cout << "Put elem " << i << endl;
  }
  cout << "\n";
  while (!st.IsEmpty())
  {
    temp = st.Get();
    cout << "Get elem " << temp << endl;
  }
  return 0;
}