#ifndef __TTREETABLE_H__
#define __TTREETABLE_H__

#include <iostream>
#include <TTreeNode.h>
#include <TExeption.h>
#include <TListStack.h>

using namespace std;


template<class ValType>
class TTreeTable
{
private:
  TTreeNode<ValType>* node;
  TTreeNode<ValType>** ref;
  int count;
public:
  TTreeTable();
  ~TTreeTable();
  void Add(TTreeNode<ValType> *tr);
  void Delete(TKey _key);
  int Getcount();
  TTreeNode<ValType>* Search(TKey _key);
  ValType* operator[] (TKey _key);
  void Print();
  void Print(TTreeNode<ValType>* t);
};

template<class ValType>
TTreeTable<ValType>::TTreeTable()
{
  count = 0;
  node = NULL;
}

template<class ValType>
TTreeTable<ValType>::~TTreeTable()
{
  TListStack<TTreeNode<ValType>*> st;
  if (node == NULL)
    return;
  TTreeNode<ValType> *pDel = node;
  st.Put(pDel);
  while (!st.IsEmpty())
  {
    pDel = st.Get();
    if (pDel->pLeft)
      st.Put(pDel->pLeft);
    if(pDel->pRight)
      st.Put(pDel->pRight);
    delete pDel;
  }
}

template<class ValType>
void TTreeTable<ValType>::Add(TTreeNode<ValType>* tr)
{
  if (Search(tr->key))
    throw TExeption(DataErr);
  *ref = tr;
}

template<class ValType>
void TTreeTable<ValType>::Delete(TKey _key)
{
  if (!Search(_key))
    throw TExeption(DataErr);
  TTreeNode<ValType>* tmp = *ref;
  TTreeNode<ValType>** buff = ref;
  if (tmp->pLeft != NULL)
  {
    TTreeNode<ValType>* tmp3 = (*ref)->pRight;
    TTreeNode<ValType>* tmp4;
    TTreeNode<ValType>* buff = tmp->pLeft;
    delete *ref;
    *ref = buff;
    tmp = *ref;
    while ((tmp != NULL))
    {
      tmp4 = tmp->pRight;
      tmp->pRight = tmp3;
      tmp3 = tmp4;
      tmp = tmp->pLeft;
    }
  }
  else if (tmp->pRight != NULL)
  {
    **ref = *tmp->pRight;
    delete *ref;
  }
  else
  {
    delete *ref;
    *ref = NULL;
  }
}

template<class ValType>
int TTreeTable<ValType>::Getcount()
{
  return count;
}

template<class ValType>
TTreeNode<ValType>* TTreeTable<ValType>::Search(TKey _key)
{
  TTreeNode<ValType>* pTemp = node;
  ref = &node;
  while (pTemp != NULL)
  {
    if (pTemp->key == _key)
      return pTemp;
    if (pTemp->key > _key)
	  ref = &(pTemp->pRight);
    else
	  ref = &(pTemp->pLeft);
    pTemp = *ref;
  }
  return NULL;
}

template<class ValType>
ValType * TTreeTable<ValType>::operator[](TKey _key)
{
  TTreeNode<ValType>* res = Search(_key);
  if (res == NULL)
  {
    TTreeNode<ValType>* n = new TTreeNode<ValType>(_key, NULL);
    Add(n);
    return n->value;
  }
  return res->value;;
  return NULL;
}

template<class ValType>
void TTreeTable<ValType>::Print()
{
  Print(node);
}

template<class ValType>
void TTreeTable<ValType>::Print(TTreeNode<ValType>* t)
{
  if (t != NULL)
  {
    Print(t->pLeft);
    std::cout << "Key :" << t->GetKey();
    std::cout << " val :" << *t->GetVal();
    Print(t->pRight);
  }
}

#endif