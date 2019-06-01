#ifndef __ARRLIST_H
#define __ARRLIST_H
#include <TExeption.h>
#include <iostream>

template<class ValType>
class TArrList
{
protected:
  ValType * mem; // ������ ��� �������� ������
  int* index; // ������� ��������� ���������
  int size; // ������������ ������ ������
  int count; // ����� ��������� � ������
  int firstInd; // ������ ������ ������
  int freeDataInd; // ������ ������� ������� �������� � �������
private:
  int NextFreeInd(); // ����� ��������� ����� � �������
public:
  TArrList(int n = 10); // ����������� � ����������
  TArrList(TArrList& al); // ����������� �����������
  ~TArrList(); // ����������
  void InsFirst(ValType val); // ���������� ������ ��������� ������
  void InsLast(ValType val); // ���������� ��������� ��������� ������
  ValType GetFirst(); // �������� �������� ������� �������� ������
  ValType GetDatValue(int num); // �������� �������� n-���� �������� ������
  ValType GetLast(); //  �������� �������� ���������� �������� ������
  void DelFirst(); // ������� ������ ������� ������
  void DelLast();// ������� ��������� ������� ������
  void Del(int num); // ������� n-��� ������� ������
  bool IsFull(); // ����� �� ������?
  int GetListLength(); // ������� ������������ ������ ������
  bool IsEmpty(); // ���� �� ������?
};

template<class ValType>
int TArrList<ValType>::NextFreeInd()
{
  for (int i = 0; i < size; i++)
    if (index[i] == -2)
    {
      return i;
    }
  return -2;
}

template<class ValType>
TArrList<ValType>::TArrList(int n)
{
  if (n < 0)
    throw TExeption(DataErr);
  else if (n == 0)
  {
    size = 0;
    count = 0;
    mem = 0;
    index = NULL;
    firstInd = -1;
    freeDataInd = 0;
  }
  else
  {
    size = n;
    count = 0;
    firstInd = -1;
    freeDataInd = 0;
    index = new int[size];
    for (int i = 0; i < size; i++)
      index[i] = -2;
    mem = new ValType[size];
  }
}

template<class ValType>
TArrList<ValType>::TArrList(TArrList & al)
{
  if (size == 0)
  {
    size = 0;
    count = 0;
    mem = NULL;
    index = NULL;
    firstInd = -1;
    freeDataInd = 0;
  }
  else
  {
    size = al.size;
    count = al.count;
    firstInd = al.firstInd;
    freeDataInd = al.freeDataInd;
    index = new int[size];
    mem = new ValType[size];
    for (int i = 0; i < size; i++)
    {
      index[i] = al.index[i];
      mem[i] = al.mem[i];
    }
  }
}

template<class ValType>
TArrList<ValType>::~TArrList()
{
  delete[]index;
  delete[]mem;
}

template<class ValType>
void TArrList<ValType>::InsFirst(ValType val)
{
  if (IsFull())
    throw TExeption(DataFull);
  mem[freeDataInd] = val;
  index[freeDataInd] = firstInd;
  firstInd = freeDataInd;
  freeDataInd = NextFreeInd();
  count++;
}
template<class ValType>
void TArrList<ValType>::InsLast(ValType val)
{
  if (IsFull())
    throw TExeption(DataFull);
  if (IsEmpty())
    InsFirst(val);
  else
  {
    int i = firstInd;
    while (index[i] != -1)
      i = index[i];
    mem[freeDataInd] = val;
    index[freeDataInd] = -1;
    index[i] = freeDataInd;
    freeDataInd = NextFreeInd();
    count++;
  }
}
template<class ValType>
ValType TArrList<ValType>::GetFirst()
{
  if (IsEmpty())
    throw TExeption(DataEmpty);
  return mem[firstInd];
}

template<class ValType>
ValType TArrList<ValType>::GetDatValue(int num)
{
  if ((num < 0) || (num > count - 1))
    throw TExeption(DataErr);
  int Ind = firstInd;
  for (int i = 0; i < num; i++)
  {
    Ind = index[Ind];
  }
  return mem[Ind];
}

template<class ValType>
ValType TArrList<ValType>::GetLast()
{
  int LastInd = firstInd;
  while (index[LastInd] != -1)
  {
    LastInd = index[LastInd];
  }
  return mem[LastInd];
}

template<class ValType>
void TArrList<ValType>::DelFirst()
{
  if (IsEmpty())
    throw TExeption(DataEmpty);
  int tmp = firstInd;
  firstInd = index[firstInd];
  index[tmp] = -2;
  count--;
}

template<class ValType>
void TArrList<ValType>::DelLast()
{
  int LastInd = firstInd;
  int PrevInd;
  while (index[LastInd] != -1)
  {
    PrevInd = LastInd;
    LastInd = index[LastInd];
  }
  index[LastInd] = -2;
  index[PrevInd] = -1;
  count--;
}

template<class ValType>
void TArrList<ValType>::Del(int num)
{
  if ((num < 0) || (num > count - 1))
    throw TExeption(DataErr);
  else if (num == 0)
    return DelFirst();
  int Ind = firstInd;
  int PrevInd;
  for (int i = 0; i < num, index[Ind] != -1; i++)
  {
    PrevInd = Ind;
    Ind = index[Ind];
  }
  index[Ind] = -2;
  index[PrevInd] = -1;
  count--;
}

template<class ValType>
bool TArrList<ValType>::IsFull()
{
  return (count == size);
}

template<class ValType>
int TArrList<ValType>::GetListLength()
{
  return size;
}

template<class ValType>
bool TArrList<ValType>::IsEmpty()
{
  return (firstInd == -1);
}
#endif