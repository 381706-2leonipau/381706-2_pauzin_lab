#include <TQueue.h>
#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  TQueue<int> st(100);
  int temp;
  cout << "Queue test \n" ;
  for (int i = 0; i<12; i++)
  {
    st.Put(i);
    cout << "Put elem " << i << endl;
  }
  while (!st.IsEmpty())
  {
    temp = st.Get();
    cout << "Get elem " << temp << endl;
  }
  return 0;
}