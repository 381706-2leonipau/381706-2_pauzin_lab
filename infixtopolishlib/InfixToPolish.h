#ifndef __POLISH_H
#define __POLISH_H
#include <TExeption.h>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<TListStack.h>
#include<TStack.h>

using namespace std;

class TInfixToPolish {
protected:
  int GetOperationPrt(char op); // get operation priority
  int IsOperation(char op); // check on the sign of the operation
public:
  double Calculate(char* mem, int len);
  char* ConvertToPolish(char * exp, int len); // conversion to polish expression
};
#endif
