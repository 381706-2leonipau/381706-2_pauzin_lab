#include <Stack.h>
#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  TStack<int> st(100);
  int temp;
  cout << "Stack" << endl;
  for (int i = 0; i<12; i++) {
    st.Put(i);
    cout << "Положили значение " << i << endl;
  }
  int k;
  while (!st.IsEmpty()) {
    temp = st.Get();
    cout << "Взяли значение " << temp << endl;
  }
  return 0;
}