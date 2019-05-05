#include "InfixToPolish.h"
#include <iostream>

using namespace std;

int main()
{
  TInfixToPolish ExpConvertor;
  char Expression[80], *PolishExpression;
  cout << "Polish test" << endl;
  cout << "Enter expression" << endl;
  cin >> Expression;
  PolishExpression = ExpConvertor.ConvertToPolish(Expression, strlen(Expression));
  cout << "Infix expression: " << Expression << endl;
  cout << "Polish expression: " << PolishExpression << endl;
  cout << "Result: " << ExpConvertor.Calculate(PolishExpression, strlen(Expression)) << endl;
  delete PolishExpression;
}