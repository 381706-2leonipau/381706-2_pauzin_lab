#ifndef __TSCANTABLE_H__
#define __TSCANTABLE_H__

#include <iostream>
#include <TTabRecord.h>
#include <TExeption.h>

template <class T> class TSortTable;

using namespace std;

template<class T>
class TScanTable
{
protected:
  int count;
  int size;
  TTabRecord<T>** pRecs;
public:
  TScanTable(int size = 2);
  TScanTable(TScanTable<T> &st);
  ~TScanTable();
  int GetTabSize();
  int GetDataCount();
  TTabRecord<T>* Search(TKey k);
  int Add(TTabRecord<T> *tr);
  void Delete(TKey k);
  T* operator[] (TKey k);
  friend ostream& operator<< (ostream &out, const TScanTable &A)
  {
    if (A.count == 0)
      return out;
    for (int i = 0; i < A.count - 1; i++)
    {
	  out << "Key :" << A.pRecs[i]->GetKey();
	  out << " data :" << *A.pRecs[i]->GetVal();
	  out << endl;
    }
	out << "Key :" << A.pRecs[A.count - 1]->GetKey();
	out << " data :" << *A.pRecs[A.count - 1]->GetVal();
    return out;
  }
  

  friend class TSortTable<T>;
};

template<class T>
TScanTable<T>::TScanTable(int _size)
{
  size = _size;
  count = 0;
  if (_size < 1)
    throw TExeption(DataErr);
  pRecs = new TTabRecord<T>*[_size];
  for (int i = 0; i < _size; i++)
  {
    pRecs[i] = NULL;
  }
}

template<class T>
TScanTable<T>::TScanTable(TScanTable<T> &st)
{
	count = st.count;
  size = st.size;
  pRecs = new TTabRecord<T>*[size];
  for (int i = 0; i < count; i++)
    pRecs[i] = new TTabRecord<T>(*pRecs[i]);
}

template<class T>
TScanTable<T>::~TScanTable()
{
  if (pRecs != NULL)
  {
    for (int i = 0; i < count; i++)
      delete pRecs[i];
    delete[]pRecs;
  }
}

template<class T>
void TScanTable<T>::Delete(TKey k)
{
	if (count == 0)
		throw TExeption(DataEmpty);
	for (int i = 0; i < count; i++) {
		if (pRecs[i]->key == k)
		{
			delete pRecs[i];
			pRecs[i] = NULL;
			for (int j = i; j < count - 1; j++)
				pRecs[j] = pRecs[j + 1];
		}
		count--;
	}
}

template<class T>
int TScanTable<T>::Add(TTabRecord<T>* tr)
{
  if (size == count - 1)
    throw TExeption(DataNoMem);
  pRecs[count] = tr;
  return count++;
}



template<class T>
TTabRecord<T> * TScanTable<T>::Search(TKey k)
{
  for (int i = 0; i < count; i++)
  {
    if (pRecs[i]->key == k)
      return pRecs[i];
  }
  return NULL;
}

template<class T>
int TScanTable<T>::GetTabSize()
{
	return size;
}

template<class T>
int TScanTable<T>::GetDataCount()
{
	return count;
}

template<class T>
T* TScanTable<T>::operator[](TKey k)
{
  TTabRecord<T>* res = Search(k);
  if (res == NULL) 
  {
    TTabRecord<T> *n = new TTabRecord<T>(k, NULL, true);
    Add(n);
    res = pRecs[count - 1];
  }
  return res->value;
}
#endif