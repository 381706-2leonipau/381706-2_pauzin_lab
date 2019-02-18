#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <TExeption.h>

template <class ValType>
class TStack
{
protected: // ����
  ValType * mem; // ������ 
  int top; // ������ ���������� �������� � Mem
  int memSize;
public:
  TStack(int Size = 32);
  virtual ~TStack();
  int IsEmpty(); // �������� �������
  int IsFull(); // �������� ������������
  int GetSize();
  int GetCount();// ����� ��������� � �����
  void Put(const int Val); // �������� 
  ValType Get(); // ������� 
  void Print();
};

template<class ValType>
TStack<ValType>::TStack(int Size)
{
  if (Size < 0)
    throw TExeption(DataErr);
  else if (Size == 0)
    mem = NULL;
  else
    mem = new ValType[Size];
  top = -1;
  memSize = Size;
}

template<class ValType>
TStack<ValType>::~TStack()
{
  if(mem != NULL)
    delete[]mem;
  mem = NULL;
}

template<class ValType>
int TStack<ValType>::IsEmpty()
{
  return top == -1;
}

template<class ValType>
int TStack<ValType>::GetSize()
{
  return memSize;
}

template<class ValType>
int TStack<ValType>::GetCount()
{
  return top + 1;
}

template<class ValType>
int TStack<ValType>::IsFull()
{

  return top == (memSize - 1);
}

template<class ValType>
void TStack<ValType>::Put(const int Val)
{
  if (IsFull())
    throw TExeption(DataFull);
  mem[++top] = Val;
}

template<class ValType>
ValType TStack<ValType>::Get()
{
  if (IsEmpty())
    throw TExeption(DataEmpty);
  return mem[top--];
}

template <class ValType>
void TStack<ValType>::Print() { // ������ �������� �����
  for (int i = 0; i< top + 1; i++)
    std::cout << mem[i] << ' ';
  std::cout << std::endl;
}

#endif
