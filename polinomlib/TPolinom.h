#ifndef __POLINOM_H
#define __POLINOM_H
#include "TMonom.h"
#include "TDatList.h"

class TPolinom : public TDatList<TMonom> 
{
public:
  TPolinom();
  TPolinom(const TPolinom &q); 
  TPolinom(const TDatList<TMonom> &q); 
  TPolinom operator+(const TPolinom &q); 
  TPolinom operator-(const TPolinom &q); 
  TPolinom operator*(const TPolinom &q); 
  TPolinom & operator+=(const TMonom &m); 
  TMonom & operator[](int) const;
  TPolinom & operator=(const TPolinom &q); 
  friend ostream& operator<<(ostream &os, TPolinom &q);
};
#endif