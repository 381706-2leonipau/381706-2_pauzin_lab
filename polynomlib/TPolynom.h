#ifndef __POLYNOM_H
#define __POLYNOM_H
#include "TMonom.h"
#include "TDatList.h"

class TPolynom : public TDatList<TMonom> 
{
public:
  TPolynom();
  TPolynom(const TPolynom &q); 
  TPolynom(const TDatList<TMonom> &q); 
  TPolynom operator+(const TPolynom &q); 
  TPolynom operator-(const TPolynom &q); 
  TPolynom operator*(const TPolynom &q); 
  TPolynom & operator+=(const TMonom &m); 
  TMonom & operator[](int) const;
  TPolynom & operator=(const TPolynom &q); 
  friend ostream& operator<<(ostream &os, TPolynom &q);
};
#endif