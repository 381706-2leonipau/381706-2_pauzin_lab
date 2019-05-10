#include <iostream>
#include <TListStack.h>
#include <ctime>
#include <cstdlib>

int main()
{
  srand(time(NULL));
  int temp;
  cout << "Stack on List test" << endl << "\nEnter stack size: ";
  int n;
  cin >> n;
  TListStack<int> stack;
  for (int i = 1; i <= n; i++)
  {
    temp = rand() % 100 + 1;
    cout << "\nPut elem: " << temp;
    stack.Put(temp);
  }
  cout << "\n\n\nStack :\n";
  stack.Print();
  cout << endl << endl;
  while (!stack.IsEmpty())
    cout << "\nGet elem: " << stack.Get();
  cout << "\n\nStack is Empty" << endl;

  return 0;
}