#include <iostream>
#include "TMatrix.h"


int main(int argc, char* argv[]) 
{
  TMatrix<double> A(4), B(4);
  cout << "Matrix test" << endl;
  cout << "Enter first Matrix" << endl;
  cin >> A;
  cout << "\nEnter second Matrix" << endl;
  cin >> B;
  cout << "\nA * B:" << endl << (A * B) << endl;
  cout << "A / B:" << endl << (A / B) << endl;
  cout << "A + B" << endl << (A + B) << endl;
  return 0;
}