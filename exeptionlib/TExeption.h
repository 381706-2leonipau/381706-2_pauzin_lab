#ifndef __EXEPTION_H
#define __EXEPTION_H

#define DataErr -1
#define DataEmpty -101 // �� �����
#define DataFull -102 // �� �����������
#define DataNoMem -103 // ��� ������

class TExeption {
protected:
  int RetCode; // ��� ����������
public:
  TExeption(int);
};
#endif