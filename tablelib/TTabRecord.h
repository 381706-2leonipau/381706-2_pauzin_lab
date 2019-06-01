#ifndef __TTABRECORD_H__
#define __TTABRECORD_H__

#include <iostream>
#include <TExeption.h>
#include <TKey.h>
#include <string.h>

template <class T> class TScanTable;
template <class T> class TSortTable;
template <class T> class THashTable;
template <class T> class TListHash;

template<class T>
class TTabRecord
{
protected:
  TKey key;
  T* value;
  bool deletion;
public:
  TTabRecord(TKey k = "", T* val = NULL, bool del = true);
  TTabRecord(char*, T* val = NULL, bool del = false);
  TTabRecord(TTabRecord<T> &_str);
  void SetToDel(bool _deletion);
  void SetKey(TKey k);
  void SetValue(T* val);
  TKey GetKey();
  T* GetVal();
  ~TTabRecord();
  bool operator == (const TTabRecord& _str);
  bool operator > (const TTabRecord& _str);
  bool operator < (const TTabRecord& _str);
  TTabRecord& operator = (const TTabRecord& _str);
  friend class TScanTable<T>;
  friend class TSortTable<T>;
  friend class THashTable<T>;
  friend class TListHash<T>;
};

template<class T>
TTabRecord<T>::TTabRecord(TKey k, T* val, bool del)
{
  key = k;
  value = val;
  deletion = del;
}

template<class T>
TTabRecord<T>::TTabRecord(char * ch, T * val, bool del)
{
  key = ch;
  value = val;
  deletion = del;
}

template<class T>
TTabRecord<T>::TTabRecord(TTabRecord<T>& _str)
{
  deletion = 1;
  key = _str.key;
  if (_str.value != NULL)
  {
    value = new T();
    *value = *_str.value;
  }
  else
    value = NULL;
}

template<class T>
void TTabRecord<T>::SetToDel(bool _deletion)
{
  deletion = _deletion;
}

template<class T>
TTabRecord<T>::~TTabRecord()
{
  if (deletion)
    delete value;
}

template<class T>
void TTabRecord<T>::SetKey(TKey k)
{
  key = k;
}

template<class T>
void TTabRecord<T>::SetValue(T * val)
{
  value = val;
}

template<class T>
TKey TTabRecord<T>::GetKey()
{
  return key;
}

template<class T>
T * TTabRecord<T>::GetVal()
{
  return value;
}

template<class T>
bool TTabRecord<T>::operator==(const TTabRecord & _str)
{
  return(key == _str.key);
}

template<class T>
bool TTabRecord<T>::operator>(const TTabRecord & _str)
{
  return (key > _str.key);
}

template<class T>
bool TTabRecord<T>::operator<(const TTabRecord & _str)
{
  return (key < _str.key);
}

template<class T>
TTabRecord<T>& TTabRecord<T>::operator =(const TTabRecord & _str)
{
  key = _str.key;
  value = _str.value;
  return *this;
}
#endif
