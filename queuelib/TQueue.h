#ifndef __QUEUE_H
#define __QUEUE_H
#include "TStack.h"
#include "TExeption.h"

template <class ValType>
class TQueue : public TStack<ValType>
{
protected:
  int li; //index of the first element of the structure
  int GetNextIndex(int index); // get next index
public:
  TQueue(int Size = 1) : TStack<ValType>(Size) { li = 0; };
  ValType Get(); // take from the queue with deletion
};

template<class ValType>
int TQueue<ValType>::GetNextIndex(int index)
{
  return (++index % this->memSize);
}

template<class ValType>
ValType TQueue<ValType>::Get()
{
  ValType temp;
  if (this->IsEmpty() == 1)
    throw TExeption(DataEmpty);
  temp = this->mem[li];
  li = GetNextIndex(li);
  this->top--;
  return temp;
}

#endif